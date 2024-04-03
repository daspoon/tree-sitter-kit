/*

  Created by David Spooner

*/

import TSKit
import ArithLang


// Define the Expr type which represents our abstract syntax. Make it Equatable
// to provide a structural equality operator for testing purposes.

indirect enum Expr : Equatable {
  case numb(Int)
  case tuple([Expr])
  case apply(String, Expr)
}


// Define a method to create an Expr from a parse tree node.

extension Expr {
  /// Create an Expr from a parse tree node.
  init(parseTree node: TSNode) {
    assert(node.type == "Expr" && node.count == 1)
    let node = node[0]
    switch node.type {
      case "Expr_numb" : // -> Int
        self = .numb(Int(parseTree: node))

      case "Expr_paren" : // -> '(' Expr ')'
        self = Expr(parseTree: node[1])

      case "Expr_add", "Expr_mul", "Expr_pow" : // -> Expr Op Expr
        self = .apply(
          String(parseTree: node[1]),
          .tuple([Expr(parseTree: node[0]), Expr(parseTree: node[2])])
        )

      case "Expr_neg" : // -> Op Expr
        self = .apply(
          String(parseTree: node[0]),
          Expr(parseTree: node[1])
        )

      default :
        fatalError("unexpected node type: \(node.type)")
    }
  }
}


// To simplify testing, define a method to create an Expr by parsing a string.

extension Expr {
  /// Create an instance by parsing a string, throwing if the string is malformed.
  init(text: String) throws {
    let parser = TSParser(tree_sitter_ArithLang())
    guard let tree = parser.parse(text)
      else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw TSException("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self.init(parseTree: tree.rootNode)
  }
}


// Define some convenience methods to make test cases more legible.

/// Enable implicit conversion of an integer literal to a 'numb' Expr.
extension Expr : ExpressibleByIntegerLiteral {
  init(integerLiteral value: Int) {
    self = .numb(value)
  }
}

/// Enable implicit conversion of a array literal to a 'tuple' Expr.
extension Expr : ExpressibleByArrayLiteral {
  init(arrayLiteral terms: Expr...) {
    self = .tuple(terms)
  }
}
