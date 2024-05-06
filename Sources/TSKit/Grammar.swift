/*

  Created by David Spooner

*/


/// A *Grammar* generates the javascript source for a tree-sitter grammar with a specified name.
/// The production rules are determined by the *Root* type and each *Parsable* type reachable
/// through its *productionRule*.
public struct Grammar {
  /// The name assigned to the generated grammar.
  public let name : String
  /// The production rule for the root type.
  public let rootRule : AnyProductionRule
  /// Optionally specify the grammar's word rule.
  public let wordRule : AnyProductionRule?

  public init<T: Parsable>(name n: String, rootType t: T.Type) {
    name = n
    rootRule = T.productionRule.typeErased
    wordRule = nil
  }

  public init<Root: Parsable, Word: Parsable>(name n: String, rootType: Root.Type, wordType: Word.Type) {
    guard case .pattern = wordType.syntaxExpression else { preconditionFailure("\(Word.self).syntaxExpression must be a pattern") }
    name = n
    rootRule = Root.productionRule.typeErased
    wordRule = Word.productionRule.typeErased
  }

  /// Return the symbol for the start rule for any instance.
  public static var startSymbol : String {
    "start"
  }

  /// Return the javascript representation of a tree-sitter grammar.
  public var javascript : String {
    // Form a list containing the root rule, each of its supporting rules sorted by ascending symbol name,
    // and the word rule if specified and not among the supporting rules.
    let supportingRules = rootRule.supportingRules
    var rules = [rootRule] + supportingRules.sorted(by: {$0.symbolName < $1.symbolName})
    if let wordRule, supportingRules.contains(where: {$0.symbol == wordRule.symbol}) == false {
      rules.append(wordRule)
    }
    // Return the javascript source, with the start rule appearing first...
    return """
           module.exports = grammar({
               name: '\(name)',
               \(wordRule.map { "word: $ => $.\($0.symbolName)," } ?? "")
               rules: {
                   \(Self.startSymbol): $ => $.\(rootRule.symbolName),
                   \(rules.map({"\($0.javascript)"}).joined(separator: ",\n" + .space(8)))
               }
           })
           """
  }
}
