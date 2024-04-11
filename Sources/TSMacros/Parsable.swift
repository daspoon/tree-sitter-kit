/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


/// A member macro applied to struct types whose expansion implements the following requirement of the *Parsable* protocol:
///   - `init(parseTree: TSNode, source: InputSource)`
/// If the target type is a struct, it must implement the following method to return a string literal:
///   - `var syntaxExpression : TSExpression`
/// If the target type is an enum, it must instead implement the following method to return a dictionary literal with string literal keys and values:
///   - `static var syntaxExpressionsByCaseName: [String: TSSyntaxExpression]`

public struct Parsable : MemberMacro {

  /// Return the source text of `init(parseTree: TSNode, source: InputSource)` for the given struct declaration.
  static func structInitializerText(for decl: StructDeclSyntax, in ctx: some MacroExpansionContext) throws -> String {
    // Gather the constructors for this type (both init methods and static functions returning Self) and form a dictionary indexed by their identifiers.
    let initMethods = decl.initMethods.map({Signature(initializerDecl: $0)})
    let staticConstructors = decl.staticFunctionsReturningSelf.map({Signature(functionDecl: $0)})
    let signaturesById = try Dictionary((initMethods + staticConstructors).map {($0.identifier, $0)}) { c, _ in
      throw Exception("multiple constructors with signature \(c.identifier)")
    }

    // Create a signature for this type's implementation of 'syntaxExpression'
    guard let ruleBinding = decl.variableBindingWith(name: "syntaxExpression", type: "TSExpression", isStatic: true)
      else { throw Exception("requires implementation of 'syntaxExpression'") }
    guard let ruleExpr = ruleBinding.resultExpr?.as(StringLiteralExprSyntax.self)
      else { throw Exception("'syntaxExpression' must be implemented as a string literal") }
    let ruleSignature = try Signature(name: "init", syntaxExpression: ruleExpr)

    // Get the constructor matching the rule signature, throwing if there is none.
    guard let initSignature = signaturesById[ruleSignature.identifier]
      else { throw Exception("no constructor matching production rule: \(ruleSignature.identifier)") }

    return """
     \(decl.visibility) init(parseTree node: TSNode, source src: InputSource) {
        self\(initSignature.invocationText(for: ("node", "src")))
     }
     """
  }

  /// Return the source text of `init(parseTree: TSNode, source: InputSource)` for the given enum declaration. Throw if the declaration lacks an appropriate definition of *syntaxExpressionsByCaseName*.
  static func enumInitializerText(for decl: EnumDeclSyntax, in ctx: some MacroExpansionContext) throws -> String {
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
    guard let binding = decl.variableBindingWith(name: "syntaxExpressionsByCaseName", type: "[String: TSExpression]", isStatic: true)
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

    /// Return the initializer text, constructing a switch case for each production rule. Make each subrule name  'unique' by prefixing the target type's *symbolName*.
    return """
       \(decl.visibility) init(parseTree node: TSNode, source src: InputSource) {
           assert(node.type == "\(symbolName)" && node.count == 1)
           let node = node[0]
           switch node.type {
             \(
               rules.map({ rule in
                 return "case \"\(symbolName)_\(rule.name)\" : self = \(rule.invocationText(for: ("node", "src")))"
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
    let initializerText : String
    switch decl.kind {
      case .structDecl :
        initializerText = try structInitializerText(for: decl.cast(StructDeclSyntax.self), in: ctx)
      case .enumDecl :
        initializerText = try enumInitializerText(for: decl.cast(EnumDeclSyntax.self), in: ctx)
      default :
        throw Exception("unsupported declaration kind")
    }
    return [DeclSyntax(stringLiteral: initializerText)]
  }
}
