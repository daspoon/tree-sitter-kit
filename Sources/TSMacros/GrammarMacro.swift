/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


public struct GrammarMacro : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard decl.is(StructDeclSyntax.self)
      else { throw Exception("unsupported declaration kind") }

    // The grammar name is the name of the type of the affected declaration.
    guard let name = decl.typeName
      else { throw Exception("no type name") }

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
    // Form a map of type names to symbol names
    let symbolNames = try Dictionary(rules.map {($0.typeName, $0.symbolName)}) {t,_ in throw Exception("multiple rules for '\(t)'")}
    func symbolLookup(_ typeName: String) throws -> String {
      guard let symbolName = symbolNames[typeName] else { throw Exception("no rule for type '\(typeName)'") }
      return symbolName
    }

    // Get the symbol for the root type
    let rootSymbol = try symbolLookup(rootType.text)

    // Get the word symbol name from the declaration of `static var word : String?`, defaulting to nil.
    let word : (symbol: String, pattern: String)?
    if let wordBinding = decl.variableBindingWith(name: "word", type: "String?", isStatic: true) {
      guard let pattern = wordBinding.resultExpr?.as(StringLiteralExprSyntax.self)?.stringLiteral
        else { throw Exception("word must return a string literal") }
      word = ("Word", pattern)
    }
    else {
      word = nil
    }

    // Form the list of symbol names and syntax expression pairs from the defined rules, prepending
    // an implicit start rule and optionally appending the Word rule.
    let symbolNamesAndRawExpressions
      = [("start", ProductionRuleImp.RawExpression.symbol(rootSymbol))]
      + (try rules.flatMap({try $0.getSymbolNamesAndRawExpressions(symbolLookup)}))
      + (word.map {[($0.symbol, ProductionRuleImp.RawExpression.pattern($0.pattern))]} ?? [])

    // Create a json representation of the grammar; this has the consequence of ensuring that production rules
    // exist for all referenced types.
    let jsonText = """
      \"\"\"
      {
        "name": "\(name)",
        "rules": {
          \(
            symbolNamesAndRawExpressions
              .map({"\"\($0)\": " + $1.json})
              .joined(separator: ",\n    ")
          )
        },
        \(word.map {"\"word\": \"\($0.symbol)\","} ?? "")
        "extras": [\(ProductionRuleImp.RawExpression.whitespace.json)],
        "conflicts": [],
        "precedences": [],
        "externals": [],
        "inline": [],
        "supertypes": []
      }
    \"\"\"
    """

    return [
      DeclSyntax(stringLiteral: """
        \(visibility) static var jsonText : String {
          \(jsonText)
        }
        """),
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
