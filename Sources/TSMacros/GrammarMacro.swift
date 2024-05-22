/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct GrammarMacro : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard decl.is(StructDeclSyntax.self)
      else { throw Exception("unsupported declaration kind") }

    // Get the visibility of the affected declaration.
    let visibility = decl.visibility

    // Get the alias for the Root type.
    guard let rootType = decl.aliasType(for: "Root")
      else { throw Exception("\(decl.typeName ?? "?") requires a typealias for Root") }

    // Get the declaration of `static var productionRules : [ProductionRule]`
    guard let binding = decl.variableBindingWith(name: "productionRules", type: "[ProductionRule]", isStatic: true)
      else { throw Exception("requires implementation of 'static var productionRules : [ProductionRule]'") }
    // Ensure it returns an array literal
    guard let arrayExpr = binding.resultExpr?.as(ArrayExprSyntax.self)
      else { throw Exception("productionRule must return an array literal") }
    // Form a list of Rule instances from the list elements
    let rules = try arrayExpr.elements
      .map({try ProductionRuleImp($0.expression)})

    // Ensure that all symbol references are defined...
    let definedSymbolNames = Set(rules.map {$0.typeName})
    let referencedSymbolNames = rules.reduce(Set([])) { names, rule in names.union(rule.referencedSymbolNames) }
    let missingSymbolNames = referencedSymbolNames.subtracting(definedSymbolNames)
    guard missingSymbolNames.isEmpty
      else { throw Exception("missing rules for symbols \(missingSymbolNames)") }

    return [
//      DeclSyntax(stringLiteral: """
//        \(visibility) static var language : TSLanguage {
//          fatalError("todo")
//        }
//      """),
      DeclSyntax(stringLiteral: """
        \(visibility) static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root {
          extract\(rootType)(from: node, in: context)
        }
        """),
      DeclSyntax(stringLiteral: """
        \(visibility) static func isRuleHidden(for type: Any.Type) -> Bool {
          let hiddenTypes : Set<ObjectIdentifier> = [
            \(rules.compactMap({$0.isSymbolHidden ? ".init(\($0.typeName).self)" : nil})
              .joined(separator: ", "))
          ]
          return hiddenTypes.contains(ObjectIdentifier(type))
        }
        """),
    ] + rules.map { rule in
      DeclSyntax(stringLiteral: rule.extractionDeclText)
    }
  }
}
