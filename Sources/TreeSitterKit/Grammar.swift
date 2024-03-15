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
    // Form a list starting with Root and followed by all supporting types in order of ascending symbol name.
    let proxies : [ParsableTypeProxy] = [.init(Root.self)] + Root.supportingTypeProxies.sorted(by: {$0.symbolName < $1.symbolName})
    return """
           module.exports = grammar({
               name: '\(name)',
               rules: {
                   \(proxies.map({"\($0.productionRuleJavascript(indent: 4).indented(8))"}).joined(separator: ",\n\n" + .space(8)))
               }
           })
           """
  }
}
