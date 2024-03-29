/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


/// A macro applied to enum types whose expansion implements the following requirements of *ParsableByCases*:
///   - `init(parseTree node: TSNode)`
/// The target type must implement the following method to return a dictionary literal with string literal keys and values:
///   - `static var syntaxExpressionsByCaseName: [String: TSSyntaxExpression]`
/// If the target type requires a symbol name other than its type name, if must implement the following method to return
/// a string literal:
///   - `static var symbolName : String`

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

    // Create a dictionary containing the signatures of this type's constructors (viz. enum cases or static
    // functions returning Self) keyed by their identifiers. Throw if any constructors have the same key,
    // which can occur because parameter names do not contribute to the identifiers.
    let caseConstructors = decl.enumCaseElements.map({Signature(case: $0, of: decl)})
    let staticConstructors = decl.staticFunctionsReturningSelf.map({Signature(functionDecl: $0)})
    let signaturesById = try Dictionary((caseConstructors + staticConstructors).map {($0.identifier, $0)}) { c, _ in
      throw Exception("multiple constructors with signature \(c.identifier)")
    }

    // Determine this type's symbol name, either from an explicit declaration of `symbolName` or as its name.
    let symbolName : String
    if let symbolNameBinding = decl.variableBindingWith(name: "symbolName", type: "String", isStatic: true) {
      guard let stringLiteral = symbolNameBinding.resultExpr?.as(StringLiteralExprSyntax.self)
        else { throw Exception("'symbolName' must be implemented as a single getter returning a string literal") }
      symbolName = stringLiteral.text
    }
    else {
      symbolName = decl.name.text
    }

    // Create a list of the production rules specified by `syntaxExpressionsByCaseName`, each represented as
    // a Signature. Note: explicitly check that each production matches a constructor because Swift macro
    // expansion involving enums is fragile and crashes in response to unknown constructor names and argument
    // type mismatches...
    guard let binding = decl.variableBindingWith(name: "syntaxExpressionsByCaseName", type: TypeSyntax(stringLiteral: "[String: TSExpression]"), isStatic: true)
      else { throw Exception("requires implementation of 'syntaxExpressionsByCaseName'") }
    guard let dictionaryExpr = binding.resultExpr?.as(DictionaryExprSyntax.self)
      else { throw Exception("'syntaxExpressionsByCaseName' must be implemented as a single getter returning a dictionary literal") }
    guard case .elements(let dictionaryElementList) = dictionaryExpr.content
      else { throw Exception("'syntaxExpressionsByCaseName' must return a non-empty dictionary") }
    let rules = try dictionaryElementList.map {
      let rule = try Signature(dictionaryElement: $0)
      guard signaturesById[rule.identifier] != nil else { throw Exception("no constructor matching \(rule.identifier)") }
      return rule
    }

    // Return the initializer text, constructing a switch case for each production rule.
    return """
       init(parseTree node: TSNode) {
           assert(node.type == "\(symbolName)" && node.count == 1)
           let node = node[0]
           switch node.type {
             \(
               rules.map({ rule in
                 return "case \"\(symbolName)_\(rule.name)\" : self = \(rule.invocationText(for: "node"))"
               })
               .joined(separator: "\n")
             )
           default:
               fatalError()
           }
       }
       """
  }

  // MARK: - MemberMacro

  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    return [DeclSyntax(stringLiteral: try declText(for: decl, in: ctx))]
  }
}
