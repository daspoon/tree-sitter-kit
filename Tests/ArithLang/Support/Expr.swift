/*

  Created by David Spooner

*/

import TSKit
import ArithLang


// Define the Expr type which represents our abstract syntax. Make it Equatable
// to provide a structural equality operator for testing purposes.

indirect enum Expr {
  case name(Name)
  case tuple([Expr])
  case apply(Expr, Expr)

  // Create an Expr from a parse tree node.

  init(parseTree node: TSNode) {
    assert(node.type == "Expr" && node.count == 1)
    let node = node[0]
    switch node.type {
      case "Expr_name" :
        self = .name(Name(parseTree: node))
      case "Expr_paren" :
        self = Expr(parseTree: node[1])
      case "Expr_add", "Expr_mul", "Expr_pow" :
        self = .apply(
          .name(Name(parseTree: node[1])),
          .tuple([Expr(parseTree: node[0]), Expr(parseTree: node[2])])
        )
      case "Expr_neg" :
        self = .apply(
          .name(Name(parseTree: node[0])),
          Expr(parseTree: node[1])
        )
      case "Expr_apply" :
        let args = node["args"]
        self = .apply(
          Expr(parseTree: node[0]),
          args.isNull ? .tuple([]) : ExprList(parseTree: args).expr
        )
      default :
        fatalError("unexpected node type: \(node.type)")
    }
  }
}


// Define a method to create an expression by parsing a string.

extension Expr {
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

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(text: text))
  }
}

extension Expr : ExpressibleByArrayLiteral {
  init(arrayLiteral terms: Expr...) {
    self = .tuple(terms)
  }
}


// Synthesize structual equality to enable comparing parsed and expected expressions.

extension Expr : Equatable {
}
