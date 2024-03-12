/*

  Created by David Spooner

*/


public struct Grammar {

  /// Return the javascript representation of a tree-sitter grammar for the given sequence of *Parsable* data types. Note that the first type determines the start symbol.
  public static func javascript<each T: Parsable>(named name: String, for types: (repeat (each T).Type)) -> String {
    var components : [String] = []
    repeat components.append(javascript(for: each types).indented(8))
    return """
           module.exports = grammar({
               name: '\(name)',
               rules: {
                   \(components.joined(separator: ",\n\n" + .space(8)))
               }
           })
           """
  }

  public static func javascript<T: Parsable>(for t: T.Type) -> String {
    t.productionRule.javascript(indent: 4)
  }
}
