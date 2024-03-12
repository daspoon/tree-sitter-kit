/*

  Created by David Spooner

*/

import TreeSitterKit
import FunLang


// A parsable type of arithmetic expressions; for testing purposes.

indirect enum Expr : Equatable, ParsableAsChoice {
  case name(Name)
  case numb(Int)
  case add(Expr, Expr)
  case mult(Expr, Expr)
  case pow(Expr, Expr)
  case neg(Expr)

  static var productionRuleChoices : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Expr_name": (.rule(Name.self), { node in
        .name(Name(node))
      }),
      "Expr_numb": (.rule(Int.self), { node in
        .numb(Int(node))
      }),
      "Expr_add": (.prec(.left(3), .seq([.rule(Expr.self), .literal("+"), .rule(Expr.self)])), { node in
        .add(Expr(node[0]), Expr(node[2]))
      }),
      "Expr_mul": (.prec(.left(4), .seq([.rule(Expr.self), .literal("*"), .rule(Expr.self)])), { node in
        .mult(Expr(node[0]), Expr(node[2]))
      }),
      "Expr_pow": (.prec(.right(5), .seq([.rule(Expr.self), .literal("^"), .rule(Expr.self)])), { node in
        .pow(Expr(node[0]), Expr(node[2]))
      }),
      "Expr_neg": (.prec(6, .seq([.literal("-"), .rule(Expr.self)])), { node in
        .neg(Expr(node[1]))
      }),
      "Expr_paren": (.seq([.literal("("), .rule(Expr.self), .literal(")")]), { node in
        Expr(node[1])
      }),
    ]
  }
}


// Define a convenience method to initialize an Expr instance from text.

extension Expr {
  static let parser = TSParser(tree_sitter_FunLang())

  init(_ text: String) throws {
    guard let tree = Self.parser.parse(text)
      else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
    self.init(tree.rootNode)
  }
}


// Define an evaluation method

extension Expr
  {
    public func evaluate() throws -> Int {
      switch self {
        case .numb(let v) :
          return v
        case .name(_) :
          throw TSException("not implemented")
        case .add(let lhs, let rhs) :
          return (try lhs.evaluate()) + (try rhs.evaluate())
        case .mult(let lhs, let rhs) :
          return (try lhs.evaluate()) * (try rhs.evaluate())
        case .pow(let lhs, let rhs) :
          return Self.power(try lhs.evaluate(), try rhs.evaluate())
        case .neg(let arg) :
          return -(try arg.evaluate())
      }
    }

  private static func power(_ i: Int, _ j: Int) -> Int
    {
      var result = 1
      for _ in 0 ..< j { result *= i }
      return result
    }
}
