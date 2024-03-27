/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


/// A macro applied to enum types whose expansion implements the following requirements of *ParsableByCases*:
///   - `static func from(_ node: TSNode) -> Self`
/// The target type must provide its own implementation of `static var syntaxExpressionsByCaseName: [String: TSSyntaxExpression]`
/// as a computed dictionary literal with string literal keys.

public struct ParsableEnum : MemberMacro {
  /// Used to distinguish the two means of constructing elements of the target type: an inherent case vs a static function returning *Self*.
  enum Constructor { case `case`(EnumCaseElementSyntax), `func`(FunctionDeclSyntax) }

  /// Given an enum declaration, return the source text for the required initializer. The method body is a switch statement mapping subrule names
  /// to instances of this type, with the number and content of switch cases are determined by the static property *syntaxExpressionsByCaseName*.
  /// Each subrule name is made 'unique' by prefixing the receiver's *symbolName*, which defaults to the type name but can be overridden by an
  /// explcit implementation which returns a string literal. Throw if the declaration does not represent an enum or lacks an appropriate definition of *syntaxExpressionsByCaseName*.
  static func declText(for decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> String {
    guard let decl = decl.as(EnumDeclSyntax.self)
      else { throw Exception("applicable only to enum declarations") }

    // Determine this type's symbol name, either from an explicit declaration of `symbolName` or as its name.
    let symbolName : String
    if let symbolNameBinding = decl.variableBindingWith(name: "symbolName", type: "String", isStatic: true) {
      guard let stringLiteral = symbolNameBinding.resultExpr?.as(StringLiteralExprSyntax.self)
        else { throw Exception("'symbolName' must be implemented as a single getter returning a string literal") }
      symbolName = stringLiteral.text
    }
    else {
      symbolName = "\(decl.name.trimmed)"
    }

    // Get the mapping of case names to syntax expressions from the implementation of `syntaxExpressionsByCaseName`,
    // which is required to return a dictionary literal.
    guard let binding = decl.variableBindingWith(name: "syntaxExpressionsByCaseName", type: TypeSyntax(stringLiteral: "[String: TSExpression]"), isStatic: true)
      else { throw Exception("requires implementation of 'syntaxExpressionsByCaseName'") }
    guard let dictionaryExpr = binding.resultExpr?.as(DictionaryExprSyntax.self)
      else { throw Exception("'syntaxExpressionsByCaseName' must be implemented as a single getter returning a dictionary literal") }
    guard case .elements(let dictionaryElementList) = dictionaryExpr.content
      else { throw Exception("'syntaxExpressionsByCaseName' must return a non-empty dictionary") }

    // Create lists pairing the this type's defined enum elements and static functions with their names,
    // and then combine those lists to form a dictionary mapping constructor names to Constructor instances,
    // stripping backquotes from those names. The dictionary gives preference to enum elements over static
    // functions of the same name.
    // TODO: the dictionary keys should incorporate parameter names and types to account for overloading.
    let enumCaseElements : [(name: String, constructor: Constructor)] = decl.memberBlock.members
      .compactMap({$0.decl.as(EnumCaseDeclSyntax.self)})
      .reduce([]) { $0 + $1.elements }
      .map({($0.name.text, .case($0))})
    let staticFunctionDecls : [(name: String, constructor: Constructor)] = decl.memberBlock.members
      .compactMap({$0.decl.as(FunctionDeclSyntax.self)})
      .filter({$0.isStatic})
      .filter({
        guard let rtype = $0.signature.returnClause?.type else { return false }
        return rtype == "Self"
      })
      .map({($0.name.text, .func($0))})
    let constructorsByName : [String: Constructor] = Dictionary((enumCaseElements + staticFunctionDecls).map({($0.0.removing(prefix: "`", suffix: "`"), $0.1)}),
      uniquingKeysWith: {v, _ in v}
    )

    // Return the initializer text, constructing a switch case for each element of `syntaxExpressionsByCaseName`.
    return """
       static func from(_ node: TSNode) -> Self {
           assert(node.type == "\(symbolName)" && node.count == 1)
           let node = node[0]
           switch node.type {
           \(
             try dictionaryElementList
               // Ensure each element has a string literal key, and reformat as a string/expr pair.
               .compactMap({ element in
                 guard let key = element.key.as(StringLiteralExprSyntax.self)
                   else { throw Exception("'syntaxExpressionsByCaseName' must return a dictionary with string literal keys") }
                 return (key.text, element.value)
               })
               // Produce a switch case for each key/expr pair which returns the key as a constructor name optionally applied to an argument list according to the corresponding declaration.
               .compactMap({ key, expr in
                 let argsText : String?
                 switch constructorsByName[key] {
                   case .case(let enumCaseElement) :
                     argsText = argumentsText(for: enumCaseElement)
                   case .func(let functionDecl) :
                     argsText = argumentsText(for: functionDecl)
                   default :
                     return nil
                 }
                 return "case \"\(symbolName)_\(key)\" : return .\(key)\(argsText.map {"(" + $0 + ")"} ?? "")"
               })
               .joined(separator: "\n")
           )
           default:
               fatalError()
           }
       }
       """
  }

  static func argumentsText(for functionDecl: FunctionDeclSyntax) -> String? {
    let parameterClause = functionDecl.signature.parameterClause
    return parameterClause.parameters.enumerated()
      .map({"\($1.type.description).from(node[\"\($0)\"])"})
      .joined(separator: ", ")
  }

  static func argumentsText(for element: EnumCaseElementSyntax) -> String? {
    guard let parameterClause = element.parameterClause
      else { return nil }
    return parameterClause.parameters.enumerated()
      .map({"\($1.type.description).from(node[\"\($0)\"])"})
      .joined(separator: ", ")
  }

  // MARK: - MemberMacro

  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    return [DeclSyntax(stringLiteral: try declText(for: decl, in: ctx))]
  }
}
