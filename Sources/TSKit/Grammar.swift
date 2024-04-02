/*

  Created by David Spooner

*/


/// A *Grammar* generates the javascript source for a tree-sitter grammar with a specified name. The production rules are determined by the *Root* type and each *Parsable* type reachable through its *syntaxExpression*.
public struct Grammar<Root: Parsable> {
  /// The name assigned to the generated grammar.
  public let name : String

  public init(name n: String) {
    name = n
  }

  /// Return the javascript representation of a tree-sitter grammar.
  public var javascript : String {
    // The start rule is determined by the Root type.
    let startRule = ProductionRule(for: Root.self)
    // Form a list beginning with the start rule and followed by the supporting rules sorted by ascending symbol name.
    let rules = [startRule] + startRule.supportingRules.sorted(by: {$0.symbolName < $1.symbolName})
    return """
           module.exports = grammar({
               name: '\(name)',
               rules: {
                   \(rules.map({"\($0.javascript)"}).joined(separator: ",\n" + .space(8)))
               }
           })
           """
  }
}
