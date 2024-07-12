/*

*/

import SwiftSyntax
import SwiftSyntaxMacros
import TSCommon


public struct GrammarMacro : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let decl = decl.as(StructDeclSyntax.self)
      else { throw Exception("unsupported declaration kind") }

    // Create a representative of the declaration.
    let grammar = try GrammarRep(structDecl: decl)

    // Get a JSON (string) representation of the grammar.
    let grammarText = grammar.jsonText

    // Create the Swift source which defines the corresponding TSLanguage instance.
    let languageDefinitionText = try generateParserSource(for: grammarText)

    // Get the visibility of the affected declaration.
    let visibility = decl.visibility

    // Return the declarations for the generated methods...
    return grammar.definedRules.map {
      DeclSyntax(stringLiteral: $0.extractionDeclText)
    } + [
      DeclSyntax(stringLiteral: """
        \(visibility) static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root {
          extract\(grammar.rootType)(from: node, in: context)
        }
        """),
      DeclSyntax(stringLiteral: """
        \(visibility) static func isRuleHidden(for type: Any.Type) -> Bool {
          let hiddenTypes : Set<ObjectIdentifier> = [
            \(grammar.definedRules.compactMap({$0.isSymbolHidden ? ".init(\($0.typeName).self)" : nil})
              .joined(separator: ", "))
          ]
          return hiddenTypes.contains(ObjectIdentifier(type))
        }
        """),
      DeclSyntax(stringLiteral:
        languageDefinitionText
      ),
    ]
  }
}
