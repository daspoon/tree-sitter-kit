/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct ParsableStruct {
  static func declText(for decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> String? {
    guard let decl = decl.as(StructDeclSyntax.self)
      else { return nil }

    let argumentsText = decl.storedProperties.enumerated()
      .map({i, v in "\(v.name): \(v.type.description).from(node[\"\(i)\"])"})
      .joined(separator: ", ")

    return """
           static func from(_ node: TSNode) -> Self {
               .init(\(argumentsText))
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

