/*

  Created by David Spooner

*/


/// A *Grammar* generates the javascript source for a tree-sitter grammar with a specified name. The production rules are determined by the *Root* type and each *Parsable* type reachable through its *syntaxExpression*.
public struct Grammar {
  /// The name assigned to the generated grammar.
  public let name : String
  /// The production rule for the root type.
  public let rootRule : ProductionRule

  public init<T: Parsable>(name n: String, rootType t: T.Type) {
    name = n
    rootRule = ProductionRule(for: t)
  }

  /// Return the symbol for the start rule for any instance.
  public static var startSymbol : String {
    "start"
  }

  /// Return the javascript representation of a tree-sitter grammar.
  public var javascript : String {
    // Form a list containing the root rule and each of its supporting rules sorted by ascending symbol name.
    let rules = [rootRule] + rootRule.supportingRules.sorted(by: {$0.name < $1.name})
    // Return the javascript source, with the start rule appearing first...
    return """
           module.exports = grammar({
               name: '\(name)',
               rules: {
                   \(Self.startSymbol): $ => $.\(rootRule.name),
                   \(rules.map({"\($0.javascript)"}).joined(separator: ",\n" + .space(8)))
               }
           })
           """
  }
}
