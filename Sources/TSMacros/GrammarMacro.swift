/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct GrammarMacro : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let decl = decl.as(StructDeclSyntax.self)
      else { throw Exception("unsupported declaration kind") }

    // Create a representative of the declaration.
    let grammar = try GrammarRep(structDecl: decl)

    // Get the visibility of the affected declaration.
    let visibility = decl.visibility

    // Return the declarations for the generated methods...
    return [
      DeclSyntax(stringLiteral:
        """
        \(visibility) static var jsonText : String {
          \(grammar.jsonText)
        }
        """
      ),
//      DeclSyntax(stringLiteral: """
//        \(visibility) static var language : TSLanguage {
//          fatalError("todo")
//        }
//      """),
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
      DeclSyntax(stringLiteral: """
        \(visibility) static func symbolName(for symbol: TSSymbol) -> StaticString {
          symbolNames[Int(symbol)]
        }
        """),
    ] + grammar.definedRules.map { rule in
      DeclSyntax(stringLiteral: rule.extractionDeclText)
    }
  }
}
