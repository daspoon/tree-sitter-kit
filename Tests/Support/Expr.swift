/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a functional expression.

indirect enum Expr : Equatable {
  case name(Name)
  case numb(Int)
  case apply(Expr, Expr)
  case lambda([Param], TypeExpr, Expr)
  case mu(Name, [Param], TypeExpr, Expr)
  case tuple([Expr])
  case project(Expr, Int)
  case match(Expr, [MatchCase])
  case block(Block)
}

typealias ExprList = [Expr]


extension Expr : ParsableByCases {
  typealias MatchCaseList = SeparatedSequence<MatchCase, Comma>

  static var productionsByChoiceName : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Expr_name": ("\(Name.self)", { node in
        .name(Name(node))
      }),
      "Expr_numb": ("\(Int.self)", { node in
        .numb(Int(node))
      }),
      "Expr_apply": (.prec(.apply, "\(Expr.self) \(ExprList.self)"), { node in
        .apply(Expr(node[0]), .parenthesized(node[1]))
      }),
      "Expr_lambda": ("! \(ParamList.self) -> \(TypeExpr.self) . \(Expr.self)", { node in
        .lambda([Param](node[1]), TypeExpr(node[3]), Expr(node[5]))
      }),
      "Expr_mu": ("! \(Name.self) \(ParamList.self) -> \(TypeExpr.self) . \(Expr.self)", { node in
        .mu(Name(node[1]), [Param](node[2]), TypeExpr(node[4]), Expr(node[6]))
      }),
      "Expr_tuple": ("\(ExprList.self)", { node in
        .parenthesized(node[0])
      }),
      "Expr_project": (.prec(.proj, "\(Expr.self) . \(Int.self)"), { node in
        .project(Expr(node[0]), Int(node[2]))
      }),
      "Expr_match": ("match \(Expr.self) { \(MatchCaseList.self) }", { node in
        .match(Expr(node[1]), MatchCaseList(node[3]).elements)
      }),
      "Expr_block": ("{ \(Block.self) }", { node in
        .block(.init(node[1]))
      }),
      "Expr_eql": (.prec(.eql,   "\(Expr.self) \("==") \(Expr.self)"), { .infix($0) }),
      "Expr_or" : (.prec(.or,    "\(Expr.self) \("||") \(Expr.self)"), { .infix($0) }),
      "Expr_and": (.prec(.and,   "\(Expr.self) \("&&") \(Expr.self)"), { .infix($0) }),
      "Expr_add": (.prec(.add,   "\(Expr.self) \("+", "-") \(Expr.self)"), { .infix($0) }),
      "Expr_mul": (.prec(.mult,  "\(Expr.self) \("*", "/", "%") \(Expr.self)"), { .infix($0) }),
      "Expr_pow": (.prec(.power, "\(Expr.self) \("^") \(Expr.self)"), { .infix($0) }),
      "Expr_neg": (.prec(.neg,   "\("-") \(Expr.self)"), { .prefix($0) }),
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
  init(_ text: String) throws {
    self = try Block(text).expr
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
