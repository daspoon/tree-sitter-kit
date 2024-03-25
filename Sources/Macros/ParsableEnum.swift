/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct ParsableEnum {
  static func declText(for decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> String? {
    guard let decl = decl.as(EnumDeclSyntax.self)
      else { return nil }

    return """
           static func from(_ node: TSNode) -> Self {
               switch node.type {
               \(decl.enumCaseElements.map(switchCaseText(for:)).joined(separator: "\n"))
               default:
                   fatalError()
               }
           }
           """
  }

  static func switchCaseText(for element: EnumCaseElementSyntax) -> String {
    var argumentText = ""
    if let parameterClause = element.parameterClause {
      argumentText += "("
      for (i, parameter) in parameterClause.parameters.enumerated() {
        if i > 0 { argumentText += ", " }
        argumentText += "\(parameter.type.description).from(node[\"\(i)\"])"
      }
      argumentText += ")"
    }
    return "case \"\(element.name)\" : return .\(element.name)\(argumentText)"
  }
}


extension ParsableEnum : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let text = try declText(for: decl, in: ctx)
      else { return [] }
    return [DeclSyntax(stringLiteral: text)]
  }
}
