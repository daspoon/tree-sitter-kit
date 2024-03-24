/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct ParsableEnum {
  static func declText(for decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> String? {
    guard let decl = decl.as(EnumDeclSyntax.self)
      else { return nil }

    var casesText : [String] = []
    for enumCaseDecl in decl.memberBlock.members.compactMap({$0.decl.as(EnumCaseDeclSyntax.self)}) {
      for element in enumCaseDecl.elements {
        casesText += ["case \"\(element.name)\" : self = \(enumValueText(for: element))"]
      }
    }
    return """
           init(_ node: TSNode) {
               switch node.type {
               \(casesText.joined(separator: "\n"))
               default:
                   fatalError()
               }
           }
           """
  }

  static func enumValueText(for element: EnumCaseElementSyntax) -> String {
    switch element.parameterClause {
      case .some(let parameterClause) :
        var text = ".\(element.name)("
        for (i, parameter) in parameterClause.parameters.enumerated() {
          let p : EnumCaseParameterSyntax = parameter
          if i > 0 { text += ", " }
          text += "\(parameter.type.description)(node[\"\(i)\"])" //\(parameter.type.trimmed)(node)"
        }
        text += ")"
        return text

      case .none :
        return ".\(element.name)"
    }
  }
}


extension ParsableEnum : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let text = try declText(for: decl, in: ctx)
      else { return [] }
    return [DeclSyntax(stringLiteral: text)]
  }
}
