/*

  Created by David Spooner

*/

import TSKit


/// A type representing a functional expression.

@Parsable
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

  static func paren(_ exprs: [Expr]) -> Self
    { exprs.count == 1 ? exprs[0] : .tuple(exprs) }

  static func call(_ fun: Expr, _ args: [Expr]) -> Self
    { .apply(fun, .paren(args)) }

  static func match(_ expr: Expr, _ seq: MatchCaseList) -> Self
    { .match(expr, seq.elements) }

  static func infix(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }

  static func eql(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .infix(lhs, op, rhs) }
  static func or(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .infix(lhs, op, rhs) }
  static func and(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .infix(lhs, op, rhs) }
  static func add(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .infix(lhs, op, rhs) }
  static func mul(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .infix(lhs, op, rhs) }
  static func pow(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .infix(lhs, op, rhs) }

  static func prefix(_ op: String, _ arg: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), arg) }

  static func neg(_ op: String, _ arg: Expr) -> Self
    { .prefix(op, arg) }

  typealias MatchCaseList = SeparatedSequence<MatchCase, Comma, NoBrackets>

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "name" :     "\(Name.self)",
      "numb" :     "\(Int.self)",
      "call" :     "\(prec: .apply)\(Expr.self) \([Expr].self)",
      "lambda" :   "! \([Param].self) -> \(TypeExpr.self) . \(Expr.self)",
      "mu" :       "! \(Name.self) \([Param].self) -> \(TypeExpr.self) . \(Expr.self)",
      "paren" :    "\([Expr].self)",
      "project" :  "\(prec: .proj)\(Expr.self) . \(Int.self)",
      "match" :    "match \(Expr.self) { \(MatchCaseList.self) }",
      "block" :    "{ \(Block.self) }",
      "eql" :      "\(prec: .eql)\(Expr.self) \(lit: ["=="]) \(Expr.self)",
      "or"  :      "\(prec: .or)\(Expr.self) \(lit: ["||"]) \(Expr.self)",
      "and" :      "\(prec: .and)\(Expr.self) \(lit: ["&&"]) \(Expr.self)",
      "add" :      "\(prec: .add)\(Expr.self) \(lit: ["+", "-"]) \(Expr.self)",
      "mul" :      "\(prec: .mult)\(Expr.self) \(lit: ["*", "/", "%"]) \(Expr.self)",
      "pow" :      "\(prec: .power)\(Expr.self) \(lit: ["^"]) \(Expr.self)",
      "neg" :      "\(prec: .neg)\(lit: ["-"]) \(Expr.self)",
    ]
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
