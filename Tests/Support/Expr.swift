/*

  Created by David Spooner

*/

import TreeSitterKit
import FunLang


// A parsable type of arithmetic expressions.

indirect enum Expr : Equatable, ParsableByCases {
  case name(Name)
  case numb(Int)
  case apply(Expr, Expr)
  case lambda([Param], TypeExpr, Expr)
  case mu(Name, [Param], TypeExpr, Expr)
  case tuple([Expr])
  case project(Expr, Int)
  case match(Expr, [MatchCase])

  static var productionsByChoiceName : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Expr_name": (.prod(Name.self), { node in
        .name(Name(node))
      }),
      "Expr_numb": (.prod(Int.self), { node in
        .numb(Int(node))
      }),
      "Expr_apply": (.prec(.apply, .seq([.prod(Expr.self), .list(Expr.self)])), { node in
        .apply(Expr(node[0]), .parenthesized(node[1]))
      }),
      "Expr_lambda": (.seq(["!", .list(Param.self), "->", .prod(TypeExpr.self), ".", .prod(Expr.self)]), { node in
        .lambda([Param](node[1]), TypeExpr(node[3]), Expr(node[5]))
      }),
      "Expr_mu": (.seq(["!", .prod(Name.self), .list(Param.self), "->", .prod(TypeExpr.self), ".", .prod(Expr.self)]), { node in
        .mu(Name(node[1]), [Param](node[2]), TypeExpr(node[4]), Expr(node[6]))
      }),
      "Expr_tuple": (.list(Expr.self), { node in
        .parenthesized(node[0])
      }),
      "Expr_project": (.infix(.proj, ".", lhs: Expr.self, rhs: Int.self), { node in
        .project(Expr(node[0]), Int(node[2]))
      }),
      "Expr_match": (.seq(["match", .prod(Expr.self), .list(MatchCase.self, brackets: .curly)]), { node in
        .match(Expr(node[1]), [MatchCase](node[2]))
      }),
      "Expr_eql": (.infix(.eql, "==", lhs: Expr.self, rhs: Expr.self), { .infix($0) }),
      "Expr_or" : (.infix(.or, "||", lhs: Expr.self, rhs: Expr.self), { .infix($0) }),
      "Expr_and": (.infix(.and, "&&", lhs: Expr.self, rhs: Expr.self), { .infix($0) }),
      "Expr_add": (.infix(.add, "+", "-", lhs: Expr.self, rhs: Expr.self), { .infix($0) }),
      "Expr_mul": (.infix(.mult, "*", "/", "%", lhs: Expr.self, rhs: Expr.self), { .infix($0) }),
      "Expr_pow": (.infix(.power, "^", lhs: Expr.self, rhs: Expr.self), { .infix($0) }),
      "Expr_neg": (.prefix(.neg, "-", arg: Expr.self), { .prefix($0) }),
    ]
  }
}


// Define methods to make grammar spec more concise

extension Expr {
  /// Given a node representing a bracketed sequence of exprs, return either the sole element or a tuple consisting of zero, two or more elements.
  static func parenthesized(_ node: TSNode) -> Self {
    let exprs = [Expr](node)
    return exprs.count == 1 ? exprs[0] : .tuple(exprs)
  }

  /// Create an application expr from a node representing an infix operator.
  static func infix(_ node: TSNode) -> Self {
    .apply(.name(Name(node[1])), .tuple([Expr(node[0]), Expr(node[2])]))
  }

  /// Create an application expr from a node representing an prefix operator.
  static func prefix(_ node: TSNode) -> Self {
    .apply(.name(Name(node[0])), Expr(node[1]))
  }
}


// Define operator precedence symbolically

extension TSExpression.Prec {
  static var eql : Self   {  .left(1) }
  static var or  : Self   {  .left(2) }
  static var and : Self   {  .left(3) }
  static var add : Self   {  .left(4) }
  static var mult : Self  {  .left(5) }
  static var power : Self { .right(6) }
  static var neg : Self   {  .none(7) }
  static var proj : Self  {  .left(8) }
  static var apply : Self {  .left(9) }
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
