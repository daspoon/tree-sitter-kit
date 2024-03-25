/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a functional expression.

indirect enum Expr : Equatable, ParsableByCases {
  case name(Name)
  case numb(Int)
  case apply(Expr, Expr)
  case lambda([Param], TypeExpr, Expr)
  case mu(Name, [Param], TypeExpr, Expr)
  case tuple([Expr])
  case project(Expr, Int)
  case match(Expr, [MatchCase])
  case block(Block)

  typealias MatchCaseList = SeparatedSequence<MatchCase, Comma>

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "name" :     "\(Name.self)",
      "numb" :     "\(Int.self)",
      "apply" :    .prec(.apply, "\(Expr.self) \(ExprList.self)"),
      "lambda" :   "! \(ParamList.self) -> \(TypeExpr.self) . \(Expr.self)",
      "mu" :       "! \(Name.self) \(ParamList.self) -> \(TypeExpr.self) . \(Expr.self)",
      "tuple" :    "\(ExprList.self)",
      "project" :  .prec(.proj, "\(Expr.self) . \(Int.self)"),
      "match" :    "match \(Expr.self) { \(MatchCaseList.self) }",
      "block" :    "{ \(Block.self) }",
      "eql" :      .prec(.eql,   "\(Expr.self) \("==") \(Expr.self)"),
      "or"  :      .prec(.or,    "\(Expr.self) \("||") \(Expr.self)"),
      "and" :      .prec(.and,   "\(Expr.self) \("&&") \(Expr.self)"),
      "add" :      .prec(.add,   "\(Expr.self) \("+", "-") \(Expr.self)"),
      "mul" :      .prec(.mult,  "\(Expr.self) \("*", "/", "%") \(Expr.self)"),
      "pow" :      .prec(.power, "\(Expr.self) \("^") \(Expr.self)"),
      "neg" :      .prec(.neg,   "\("-") \(Expr.self)"),
    ]
  }
}


/// *ExprList* parses a bracketed sequence of exprs, return either the sole element or a tuple consisting of zero, two or more elements.
struct ExprList : Parsable {
  static var syntaxExpression : TSExpression
    { [Expr].syntaxExpression }
  static func from(_ node: TSNode) -> Expr {
    let exprs = [Expr].from(node)
    return exprs.count == 1 ? exprs[0] : .tuple(exprs)
  }
}


extension Expr {
  static func eql(_ lhs: Expr, _ op: Name, _ rhs: Expr) -> Self
    { .apply(.name(op), .tuple([lhs, rhs])) }
  static func or(_ lhs: Expr, _ op: Name, _ rhs: Expr) -> Self
    { .apply(.name(op), .tuple([lhs, rhs])) }
  static func and(_ lhs: Expr, _ op: Name, _ rhs: Expr) -> Self
    { .apply(.name(op), .tuple([lhs, rhs])) }
  static func add(_ lhs: Expr, _ op: Name, _ rhs: Expr) -> Self
    { .apply(.name(op), .tuple([lhs, rhs])) }
  static func mul(_ lhs: Expr, _ op: Name, _ rhs: Expr) -> Self
    { .apply(.name(op), .tuple([lhs, rhs])) }
  static func pow(_ lhs: Expr, _ op: Name, _ rhs: Expr) -> Self
    { .apply(.name(op), .tuple([lhs, rhs])) }

  static func neg(_ op: Name, _ arg: Expr) -> Self
    { .apply(.name(op), arg) }
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
