/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


/// A macro applied to struct types whose expansion implements the following requirement of *Parsable*:
///   - `init(parseTree node: TSNode)`
/// The target type must implement the following method to return a string literal:
///   - `var syntaxExpression : TSExpression`

public struct ParsableStruct {
  /// Given a struct declaration, return the source text for the required init method.
  static func declText(for decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> String? {
    guard let decl = decl.as(StructDeclSyntax.self)
      else { return nil }

    // Note whether or not the decl is 'public'

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
           \(decl.visibility) init(parseTree node: TSNode) {
              self\(initSignature.invocationText(for: "node"))
           }
           """
  }
}


extension ParsableStruct : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let text = try declText(for: decl, in: ctx)
      else { return [] }
    return [DeclSyntax(stringLiteral: text)]
  }
}


extension ParsableStruct : ExtensionMacro {
  public static func expansion(of node: AttributeSyntax, attachedTo decl: some DeclGroupSyntax, providingExtensionsOf type: some TypeSyntaxProtocol, conformingTo protocols: [TypeSyntax], in ctx: some MacroExpansionContext ) throws -> [ExtensionDeclSyntax] {
    guard let text = try declText(for: decl, in: ctx)
      else { return [] }
    return [
      try ExtensionDeclSyntax(
        """
        extension \(raw: decl.description) {
          \(raw: text)
        }
        """
      )
    ]
  }
}

