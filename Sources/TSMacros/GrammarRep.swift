/*

*/

import SwiftSyntax
import TSCommon


struct GrammarRep {
  // The type name of the declaration given on initialization.
  let name : String
  // The struct access modifier
  let visibility : String
  // The name of the 'Root' typealias, indicating the top-level language element.
  let rootType : String
  // The defined production rules.
  let definedRules : [ProductionRule]
  // The JSON grammar representation
  let jsonText : String
  // The generated text defining the TSLanguage structure
  let languageSource : String


  // Initialize an instance from a struct declaration which conforms to the Grammar protocol.
  static func from(structDecl decl: StructDeclSyntax) throws -> Self {
    let name = decl.name.text
    let visibility = decl.visibility

    // Get the name of the Root typealias.
    let rootType = try decl.aliasType(for: "Root")?.text
      ?? { throw ExpansionError(node: decl, message: "missing typealias for `Root`") }()

    // Get the pattern for the 'word' symbol, if any.
    let word : (symbol: String, pattern: String)?
    if let wordBinding = decl.variableBindingWith(name: "word", type: "String?", isStatic: true) {
      guard let pattern = wordBinding.resultExpr?.as(StringLiteralExprSyntax.self)?.stringLiteral
        else { throw ExpansionError(node: wordBinding, message: "`word` must return a string literal") }
      word = ("Word", pattern)
    }
    else {
      word = nil
    }

    // Get the list of tokens for the 'extras' property, if any.
    let extras : [RawExpression]?
    if let extrasBinding = decl.variableBindingWith(name: "extras", type: "[Token]", isStatic: true) {
      guard let array = extrasBinding.resultExpr?.as(ArrayExprSyntax.self)
        else { throw ExpansionError(node: extrasBinding, message: "`extras` must return an array literal") }
      extras = try array.elements.map { element in
        let token = try Token(expr: element.expression)
        return token.rawExpression
      }
    }
    else {
      extras = nil
    }

    // Get the list of production rules from `static var productionRules : [ProductionRule]`,
    // which must be an array literal of calls to the ProductionRule init method.
    guard let rulesBinding = decl.variableBindingWith(name: "productionRules", type: "[ProductionRule]", isStatic: true)
      else { throw ExpansionError(node: decl, message: "missing static var `productionRules`") }
    guard let arrayExpr = rulesBinding.resultExpr?.as(ArrayExprSyntax.self)
      else { throw ExpansionError(node: rulesBinding, message: "`productionRules` must return an array literal") }
    let definedRules = try arrayExpr.elements.map({try ProductionRule($0.expression)})

    // Define a mapping of type names to symbol names for those production rules, along with
    // a translation method which throws for undefined types.
    let symbolsByType = try Dictionary(definedRules.map {($0.typeName, $0.symbolName)}) {t, _ in throw ExpansionError(node: rulesBinding, message: "multiple rules for '\(t)'")}
    func symbolLookup(_ typeName: String) throws -> String {
      try symbolsByType[typeName] ?? { throw ExpansionError(node: rulesBinding, message: "missing rule for type '\(typeName)'") }()
    }

    // Form a list of all production rules
    let allRules = [("start", RawExpression.symbol(try symbolLookup(rootType)))]
      + (try definedRules.flatMap({try $0.getSymbolNamesAndRawExpressions(symbolLookup(_:))}))
      + (word.map {[($0.symbol, RawExpression.pattern($0.pattern))]} ?? [])

    // Construct the JSON representation of the grammar for tree-sitter
    let jsonText =
      """
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
        "extras": [\(extras.map {$0.map(\.json).joined(separator: ", ")} ?? RawExpression.whitespace.json)],
        "conflicts": [],
        "precedences": [],
        "externals": [],
        "inline": [],
        "supertypes": []
      }
      """

    // Call tree-sitter generate
    let languageSource = try generateParserSource(for: jsonText, accessModifier: visibility)

    return Self(
      name: name,
      visibility: visibility,
      rootType: rootType,
      definedRules: definedRules,
      jsonText: jsonText,
      languageSource: languageSource
    )
  }
}
