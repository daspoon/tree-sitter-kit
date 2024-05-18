/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct Grammar : MemberMacro {

  static func text(for decl: StructDeclSyntax, in ctx: some MacroExpansionContext) throws -> String {
    // Get the type alias for Root
    guard let rootType = decl.aliasType(for: "Root")
      else { throw Exception("\(decl.typeName ?? "?") requires a typealias for Root") }

    // Collect the member types which correspond to grammar symbols
    let rules : [Rule] = try decl.memberBlock.members
      .compactMap({ member in member.decl.asProtocol(DeclGroupSyntax.self) })
      .compactMap({ decl in Rule.ruleClass(for: decl).map {type in (type, decl)} })
      .map({ type, decl in try type.init(decl: decl) })

    return """
      \(decl.visibility) static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root {
        extract\(rootType)(from: node, in: context)
      }

      \(rules.map({"\($0.extractionDeclText)"}).joined(separator: "\n\n"))
    """
  }


  // MARK: - MemberMacro -

  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let structDecl = decl.as(StructDeclSyntax.self)
      else { throw Exception("unsupported declaration kind") }

    return [DeclSyntax(stringLiteral: try text(for: structDecl, in: ctx))]
  }
}
