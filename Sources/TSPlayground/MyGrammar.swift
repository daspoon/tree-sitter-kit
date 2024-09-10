/*

*/

import TSKit


@Grammar
struct MyGrammar : Grammar {
  typealias Root = Expr
  static var productionRules : [ProductionRule] {
    return [
      .init(Digits.self, .pat("[0-9]+")) { digits in digits },
      .init(Expr.self, choicesByName: [
        "num": .init(.sym(Digits.self)) { digits in .num(digits) },
        "add": .init(.prec(.left(1), .seq([.sym(Expr.self), "+", .sym(Expr.self)]))) { lhs, rhs in .add(lhs, rhs) },
        "mul": .init(.prec(.left(2), .seq([.sym(Expr.self), "*", .sym(Expr.self)]))) { lhs, rhs in .mul(lhs, rhs) },
        "paren": .init(.seq(["(", .sym(Expr.self), ")"])) { expr in expr },
      ]),
    ]
  }
}


typealias Digits = String

indirect enum Expr {
  case num(Digits)
  case add(Expr, Expr)
  case mul(Expr, Expr)
}
