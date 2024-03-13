/*

  Created by David Spooner

*/

import TreeSitterKit
import FunLang


// A parsable type of arithmetic expressions.

indirect enum Expr : Equatable, ParsableAsChoice {
  case name(Name)
  case numb(Int)
  case apply(Expr, Expr)
  case lambda(Name, Expr)
  case tuple([Expr])
  case project(Expr, Int)

  static var productionRuleChoices : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Expr_name": (.rule(Name.self), { node in
        .name(Name(node))
      }),
      "Expr_numb": (.rule(Int.self), { node in
        .numb(Int(node))
      }),
      "Expr_apply": (.prec(.apply, .seq([.rule(Expr.self), .rule(Expr.self)])), { node in
        .apply(Expr(node[0]), Expr(node[1]))
      }),
      "Expr_lambda": (.seq([.literal("!"), .rule(Name.self), .literal("."), .rule(Expr.self)]), { node in
        .lambda(Name(node[1]), Expr(node[3]))
      }),
      "Expr_tuple": (.rule([Expr].self), { node in
        { exprs in exprs.count == 1 ? exprs[0] : .tuple(exprs) }([Expr](node[0]))
      }),
      "Expr_project": (.prec(.proj, .seq([.rule(Expr.self), .literal("."), .rule(Int.self)])), { node in
        .project(Expr(node[0]), Int(node[2]))
      }),
      "Expr_add": (.prec(.add, .seq([.rule(Expr.self), .literal("+"), .rule(Expr.self)])), { node in
        .apply(.name(Name(node[1])), .tuple([Expr(node[0]), Expr(node[2])]))
      }),
      "Expr_mul": (.prec(.mult, .seq([.rule(Expr.self), .literal("*"), .rule(Expr.self)])), { node in
        .apply(.name(Name(node[1])), .tuple([Expr(node[0]), Expr(node[2])]))
      }),
      "Expr_pow": (.prec(.power, .seq([.rule(Expr.self), .literal("^"), .rule(Expr.self)])), { node in
        .apply(.name(Name(node[1])), .tuple([Expr(node[0]), Expr(node[2])]))
      }),
      "Expr_neg": (.prec(.neg, .seq([.literal("-"), .rule(Expr.self)])), { node in
        .apply(.name(Name(node[0])), Expr(node[1]))
      }),
    ]
  }
}


// Define operator precedence symbolically

extension TSExpression.Prec {
  static var apply : Self {  .left(1) }
  static var add : Self   {  .left(2) }
  static var mult : Self  {  .left(3) }
  static var power : Self { .right(4) }
  static var neg : Self   {  .none(5) }
  static var proj : Self  {  .left(6) }
}


// Define a method to create an Expr from text.

extension Expr {
  static let parser = TSParser(tree_sitter_FunLang())

  init(_ text: String) throws {
    guard let tree = Self.parser.parse(text)
      else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw TSException("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self.init(tree.rootNode)
  }
}


// Define some constructors to make tests more concise.

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}

extension Expr : ExpressibleByIntegerLiteral {
  init(integerLiteral n: Int)
    { self = .numb(n) }
}

extension Expr {
  static func infix_op(_ op: String, _ lhs: Self, _ rhs: Self) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }

  static func prefix_op(_ op: String, _ arg: Self) -> Self
    { .apply(.name(Name(stringLiteral: op)), arg) }
}
