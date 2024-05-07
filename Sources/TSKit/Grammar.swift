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
  public let rootSymbol : Symbol
  /// Optionally specify the grammar's word rule.
  public let wordSymbol : Symbol?

  public init<Root: Parsable>(name n: String, rootType: Root.Type) {
    name = n
    rootSymbol = .init(rootType)
    wordSymbol = nil
  }

  public init<Root: Parsable, Word: Parsable>(name n: String, rootType: Root.Type, wordType: Word.Type) {
    guard case .pattern = wordType.productionRule.syntaxExpression
      else { preconditionFailure("\(Word.self).syntaxExpression must be a pattern") }
    name = n
    rootSymbol = .init(rootType)
    wordSymbol = .init(wordType)
  }

  /// Return the symbol for the start rule for any instance.
  public static var startSymbol : String {
    "start"
  }

  /// Return the set of symbols reachable from the root symbol; include the 'word' rule,
  /// but exclude the root symbol.
  private var supportingSymbols : Set<Symbol> {
    var visitedSymbols : Set<Symbol> = []
    var remainingSymbols : Set<Symbol> = [rootSymbol]
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
    var symbols : Set<Symbol> = []
    while remainingSymbols.isEmpty == false {
      let symbol = remainingSymbols.removeFirst()
      let rule = symbol.productionRule
      visitedSymbols.insert(symbol)
      if symbol != rootSymbol {
        symbols.insert(symbol)
      }
      walk(rule.syntaxExpression)
    }
    return wordSymbol.map {symbols.union([$0])} ?? symbols
  }

  /// Return the javascript representation of a tree-sitter grammar.
  public var javascript : String {
    // Form a list containing the root rule and each of the supporting rules (including
    // the 'word') sorted by ascending symbol name.
    let symbols = [rootSymbol] + supportingSymbols.sorted(by: {$0.name < $1.name})

    // Return the javascript source, with the start rule appearing first...
    return """
           module.exports = grammar({
               name: '\(name)',
               \(wordSymbol.map { "word: $ => $.\($0.name)," } ?? "")
               rules: {
                   \(Self.startSymbol): $ => $.\(rootSymbol.name),
                   \(symbols.map({"\($0.name): $ => \($0.productionRule.syntaxExpression.javascript)"})
                      .joined(separator: ",\n" + .space(8)))
               }
           })
           """
  }
}
