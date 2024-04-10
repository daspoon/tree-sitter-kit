/*

  Created by David Spooner

*/

@testable import TSKit
import ExprLang1


// Define the Expr type which represents our abstract syntax.

indirect enum Expr {
  case name(Name)
  case apply(Expr, [Expr])

  /// Create an Expr from a parse tree node.
  init(parseTree node: TSNode) {
    // Decide which case is represented based on the structure of the node...
    assert(node.type == "Expr" && node.count == 1)
    let node = node[0]
    switch node.type {
      case "Expr_name" :
        self = .name(Name(parseTree: node))
      case "Expr_add", "Expr_mul", "Expr_pow" :
        self = .apply(
          .name(Name(parseTree: node[1])),
          [Expr(parseTree: node[0]), Expr(parseTree: node[2])]
        )
      case "Expr_neg" :
        self = .apply(
          .name(Name(parseTree: node[0])),
          [Expr(parseTree: node[1])]
        )
      case "Expr_apply" :
        let args = node["args"]
        self = .apply(
          Expr(parseTree: node[0]),
          args.isNull ? [] : ExprList(parseTree: args).elements
        )
      case "Expr_paren" :
        self = Expr(parseTree: node[1])
      default :
        fatalError("unexpected node type: \(node.type)")
    }
  }
}


// Define a method to create an expression by parsing a string.

extension Expr {
  init(text: String) throws {
    let parser = TSParser(tree_sitter_ExprLang())
    guard let tree = parser.parse(text)
      else { throw Exception("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw Exception("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self.init(parseTree: tree.rootNode)
  }
}


// Define some convenience methods to make test cases more legible.

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(text: text))
  }
}


// Synthesize structual equality to enable comparing parsed and expected expressions.

extension Expr : Equatable {
}
