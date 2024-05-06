/*

  Created by David Spooner

*/

@testable import TSKit
import ExprLang2


indirect enum Expr : Equatable {
  case name(Name)
  case apply(Expr, [Expr])
}


extension Expr : ParsableByCases {
  static var productionRulesByCaseName : [String: ProductionRule<Self>] {
    return [
      "name": .init(descriptor: "\(Name.self)") { name in
        Expr.name(name)
      },
      "add": .init(descriptor: "\(prec:  .left(1)) \(Expr.self) \(OpAdd.self) \(Expr.self)") { (lhs: Expr, op: OpAdd, rhs: Expr) -> Expr in
        .apply(op.expr, [lhs, rhs])
      },
      "mul": .init(descriptor: "\(prec:  .left(2)) \(Expr.self) \(OpMul.self) \(Expr.self)") { (lhs: Expr, op: OpMul, rhs: Expr) -> Expr  in
        .apply(op.expr, [lhs, rhs])
      },
      "pow": .init(descriptor: "\(prec: .right(3)) \(Expr.self) \(OpPow.self) \(Expr.self)") { (lhs: Expr, op: OpPow, rhs: Expr) -> Expr  in
        .apply(op.expr, [lhs, rhs])
      },
      "neg": .init(descriptor: "\(prec:  .none(4)) \(OpNeg.self) \(Expr.self)") { (op: OpNeg, arg: Expr) -> Expr in
        .apply(op.expr, [arg])
      },
      "apply": .init(descriptor: "\(prec: .none(5)) \(Expr.self) ( \(Optional<ExprList>.self) )") { (fun: Expr, args: ExprList?) -> Expr in
        .apply(fun, args?.elements ?? [])
      },
      "paren": .init(descriptor: "( \(Expr.self) )") { expr in
        expr
      },
    ]
  }
}


// Create a wrapper for the language structure defined by parser.c

fileprivate let language = TSLanguage(tree_sitter_ExprLang())


// Define a method to create an expression by parsing a string.

extension Expr {
  init(text: String) throws {
    self = try Self.from(text: text, language: language)
  }
}


// Define some convenience methods to make test cases more legible.

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(text: text))
  }
}
