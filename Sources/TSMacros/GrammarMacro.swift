/*

*/

import SwiftSyntax
import SwiftSyntaxMacros
import TSCommon


public struct GrammarMacro : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let decl = decl.as(StructDeclSyntax.self)
      else { throw ExpansionError(node: decl, message: "applicable only to struct declarations") }

    do {
      // Create a representative of the declared struct.
      let grammar = try GrammarRep.from(structDecl: decl)

      // Return the declarations for the generated methods...
      return grammar.definedRules.map {
        DeclSyntax(stringLiteral: $0.extractionDeclText)
      } + [
        DeclSyntax(stringLiteral: """
          \(grammar.visibility) static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root {
            extract\(grammar.rootType)(from: node, in: context)
          }
          """),
        DeclSyntax(stringLiteral: """
          \(grammar.visibility) static func isRuleHidden(for type: Any.Type) -> Bool {
            let hiddenTypes : Set<ObjectIdentifier> = [
              \(grammar.definedRules.compactMap({$0.isSymbolHidden ? ".init(\($0.typeName).self)" : nil})
                .joined(separator: ", "))
            ]
            return hiddenTypes.contains(ObjectIdentifier(type))
          }
          """),
        DeclSyntax(stringLiteral:
          grammar.languageSource
        ),
      ]
    }
    catch let error as ExpansionError {
      for issue in error.issues {
        ctx.addDiagnostics(from: Exception(issue.message), node: issue.node)
      }
      return Self.missingImplementations(with: decl.visibility)
    }
    catch {
      ctx.addDiagnostics(from: error, node: decl)
      return Self.missingImplementations(with: decl.visibility)
    }
  }


  // Return stubs for generated requirements to avoid non-conformance error on failed expansion...
  private static func missingImplementations(with visibility: String) -> [DeclSyntax] {
    let texts : [String] = [
      "\(visibility) static var language : UnsafePointer<TSLanguage> { fatalError() }",
      "\(visibility) static var symbolNames : [StaticString] { [] }",
      "\(visibility) static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root { fatalError() }",
      "\(visibility) static func isRuleHidden(for type: Any.Type) -> Bool { false }",
    ]
    return texts.map { DeclSyntax(stringLiteral: $0) }
  }
}
