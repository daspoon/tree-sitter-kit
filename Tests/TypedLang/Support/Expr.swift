/*

  Created by David Spooner

*/

import TSKit


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

extension Expr : ParsableByCases {
  typealias MatchCaseList = SeparatedSequence<MatchCase, Comma, NoBrackets>

  static var productionRulesByCaseName : [String : ProductionRule<Expr>] {
    return [
      "name" : .init(descriptor: "\(Name.self)") { name in
        .name(name)
      },
      "numb" : .init(descriptor: "\(Int.self)") { int in
        .numb(int)
      },
      "call" : .init(descriptor: "\(prec: .apply)\(Expr.self) ( \(opt: ExprList.self) )") { fun, args in
        .apply(fun, .paren(args))
      },
      "lambda" : .init(descriptor: "! \(ParamList.self) -> \(TypeExpr.self) . \(Expr.self)") { plist, rtype, expr in
        .lambda(plist.elements, rtype, expr)
      },
      "mu" : .init(descriptor: "! \(Name.self) \(ParamList.self) -> \(TypeExpr.self) . \(Expr.self)") { name, plist, rtype, expr in
        .mu(name, plist.elements, rtype, expr)
      },
      "paren" : .init(descriptor: "( \(Optional<ExprList>.self) )") { elist in
        .paren(elist)
      },
      "project" : .init(descriptor: "\(prec: .proj)\(Expr.self) . \(Int.self)") { expr, index in
        .project(expr, index)
      },
      "match" : .init(descriptor: "match \(Expr.self) { \(MatchCaseList.self) }") { expr, caselist in
        .match(expr, caselist.elements)
      },
      "block" : .init(descriptor: "{ \(Block.self) }") { x in
      },
      "eql" : .init(descriptor: "\(prec: .eql)\(Expr.self) \("==") \(Expr.self)") { lhs, op, rhs in
        .infix(lhs, op, rhs)
      },
      "or"  : .init(descriptor: "\(prec: .or)\(Expr.self) \("||") \(Expr.self)") { lhs, op, rhs in
        .infix(lhs, op, rhs)
      },
      "and" : .init(descriptor: "\(prec: .and)\(Expr.self) \("&&") \(Expr.self)") { lhs, op, rhs in
        .infix(lhs, op, rhs)
      },
      "add" : .init(descriptor: "\(prec: .add)\(Expr.self) \("+", "-") \(Expr.self)") { lhs, op, rhs in
        .infix(lhs, op, rhs)
      },
      "mul" : .init(descriptor: "\(prec: .mult)\(Expr.self) \("*", "/", "%") \(Expr.self)") { lhs, op, rhs in
        .infix(lhs, op, rhs)
      },
      "pow" : .init(descriptor: "\(prec: .power)\(Expr.self) \("^") \(Expr.self)") { lhs, op, rhs in
        .infix(lhs, op, rhs)
      },
      "neg" : .init(descriptor: "\(prec: .neg)\("-") \(Expr.self)") { op, arg in
        .prefix(op, arg)
      },
    ]
  }

  static func paren(_ list: ExprList?) -> Self
    { {$0.count == 1 ? $0[0] : .tuple($0)}(list?.elements ?? []) }

  static func infix(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }

  static func prefix(_ op: String, _ arg: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), arg) }

}


typealias ExprList = SeparatedSequence<Expr, Comma, NoBrackets>


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
