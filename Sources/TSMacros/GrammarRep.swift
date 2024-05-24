/*

  Created by David Spooner

*/

import SwiftSyntax


struct GrammarRep {
  // The type name of the declaration given on initialization.
  let name : String
  // The name of the 'Root' typealias, indicating the top-level language element.
  let rootType : String
  // The defined production rules.
  let definedRules : [ProductionRuleImp]
  // The symbol name and patter for the `word` attribute, if any.
  let word : (symbol: String, pattern: String)?
  // Return the complete list of production rules as pairs of symbols and syntax expressions.
  let allRules : [(symbol: String, expression: ProductionRuleImp.RawExpression)]

  // Initialize an instance from a struct declaration which conforms to the Grammar protocol.
  init(structDecl decl: StructDeclSyntax) throws {
    name = decl.name.text

    // Get the name of the Root typealias.
    rootType = try decl.aliasType(for: "Root")?.text
      ?? { throw Exception("\(decl.name) requires a typealias for `Root`") }()

    // Get the pattern for the 'word' symbol, if any.
    if let wordBinding = decl.variableBindingWith(name: "word", type: "String?", isStatic: true) {
      guard let pattern = wordBinding.resultExpr?.as(StringLiteralExprSyntax.self)?.stringLiteral
        else { throw Exception("`word` must return a string literal") }
      word = ("Word", pattern)
    }
    else {
      word = nil
    }

    // Get the list of production rules from `static var productionRules : [ProductionRule]`,
    // which must be an array literal of calls to the ProductionRule init method.
    guard let rulesBinding = decl.variableBindingWith(name: "productionRules", type: "[ProductionRule]", isStatic: true)
      else { throw Exception("`productionRules` is required") }
    guard let arrayExpr = rulesBinding.resultExpr?.as(ArrayExprSyntax.self)
      else { throw Exception("`productionRules` must return an array literal") }
    definedRules = try arrayExpr.elements.map({try ProductionRuleImp($0.expression)})

    // Define a mapping of type names to symbol names for those production rules, along with
    // a translation method which throws for undefined types.
    let symbolsByType = try Dictionary(definedRules.map {($0.typeName, $0.symbolName)}) {t, _ in throw Exception("multiple rules for '\(t)'")}
    func symbolLookup(_ typeName: String) throws -> String {
      try symbolsByType[typeName] ?? { throw Exception("no rule for type '\(typeName)'") }()
    }

    allRules = [("start", ProductionRuleImp.RawExpression.symbol(try symbolLookup(rootType)))]
      + (try definedRules.flatMap({try $0.getSymbolNamesAndRawExpressions(symbolLookup(_:))}))
      + (word.map {[($0.symbol, ProductionRuleImp.RawExpression.pattern($0.pattern))]} ?? [])
  }


  /// Return the text of grammar.json.
  var jsonText : String {
    """
    \"\"\"
    {
      "name": "\(name)",
      "rules": {
        \(
          allRules
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
  }
}
