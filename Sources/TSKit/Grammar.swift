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
    guard case .pattern = wordType.productionRule.syntaxExpression
      else { preconditionFailure("\(Word.self).syntaxExpression must be a pattern") }
    name = n
    rootRule = Root.productionRule.typeErased
    wordRule = Word.productionRule.typeErased
  }

  /// Return the symbol for the start rule for any instance.
  public static var startSymbol : String {
    "start"
  }

  /// Return the set of rules reachable from the receiver, excluding the receiver itself.
  private var supportingRules : [AnyProductionRule] {
    var accumulatedRules : [AnyProductionRule] = []
    var visitedSymbols : Set<Symbol> = []
    var remainingSymbols : Set<Symbol> = [rootRule.symbol]
    while remainingSymbols.isEmpty == false {
      let symbol = remainingSymbols.removeFirst()
      let rule = symbol.productionRule
      visitedSymbols.insert(symbol)
      if symbol != rootRule.symbol {
        accumulatedRules.append(rule)
      }
      func walk(_ expr: TSExpression) {
        switch expr {
          case .prod(let supportingSymbol) :
            guard visitedSymbols.contains(supportingSymbol) == false else { break }
            remainingSymbols.insert(supportingSymbol)
          case .seq(let exprs), .choice(let exprs) :
            exprs.forEach { walk($0) }
          case .field(_, let expr), .optional(let expr), .prec(_, let expr), .repeat(let expr) :
            walk(expr)
          case .literal, .pattern :
            break
        }
      }
      walk(rule.syntaxExpression)
    }
    return accumulatedRules
  }

  /// Return the javascript representation of a tree-sitter grammar.
  public var javascript : String {
    // Form a list containing the root rule, each of its supporting rules sorted by ascending symbol name,
    // and the word rule if specified and not among the supporting rules.
    let supportingRules = self.supportingRules
    var rules = [rootRule] + supportingRules.sorted(by: {$0.symbol.name < $1.symbol.name})
    if let wordRule, supportingRules.contains(where: {$0.symbol == wordRule.symbol}) == false {
      rules.append(wordRule)
    }
    // Return the javascript source, with the start rule appearing first...
    return """
           module.exports = grammar({
               name: '\(name)',
               \(wordRule.map { "word: $ => $.\($0.symbol.name)," } ?? "")
               rules: {
                   \(Self.startSymbol): $ => $.\(rootRule.symbol.name),
                   \(rules.map({"\($0.symbol.name): $ => \($0.syntaxExpression.javascript)"})
                      .joined(separator: ",\n" + .space(8)))
               }
           })
           """
  }
}
