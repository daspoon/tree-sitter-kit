/*

*/

import TSKit
import TSLanguage


@Grammar
struct ExprLang : Grammar {
  typealias Root = Expr

  static var productionRules : [ProductionRule] {
    return [
      .init(Expr.self, choicesByName: [
        "name": .init(.sym(Name.self)) { name in .name(name) },
        "value": .init(.sym(Value.self)) { value in .value(value) },
        "add": .init(.prec(.left(1), .seq([.sym(Expr.self), .alt(["+", "-"]), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
        "mul": .init(.prec(.left(2), .seq([.sym(Expr.self), .alt(["*", "/"]), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
        "pow": .init(.prec(.right(3), .seq([.sym(Expr.self), .alt(["^"]), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
        "neg": .init(.prec(.left(4), .seq([.alt(["-"]), .sym(Expr.self)]))) { op, arg in .op(op, [arg]) },
        "apply": .init(.prec(5, .seq([.sym(Expr.self), "(", .opt(.sym(ExprList.self)), ")"]))) { fun, args in .apply(fun, args ?? []) },
        "paren": .init(.seq(["(", .sym(Expr.self), ")"])) { expr in expr },
      ]),
      .init(ExprList.self, .rep(.sym(Expr.self), .sep(","))) { exprs in exprs },
      .init(Name.self, .pat("[a-zA-Z_][0-9a-zA-Z_]*")) { string in Name(text: string) },
      .init(Value.self, .sym(Int.self)) { i in .init(int: i) },
      .init(Int.self, .pat("[0-9]+")) { string in Int(string)! },
    ]
  }

  static var word : String? {
    "([a-zA-Z_][0-9a-zA-Z_]* | [!#%&*+-/<=>^|~]+)"
  }
}


// MARK: -

indirect enum Expr : Equatable {
  case name(Name)
  case value(Value)
  case apply(Expr, [Expr])
  static func op(_ name: String, _ args: [Expr]) -> Self {
    .apply(.name(Name(text: name)), args)
  }
}

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(text: text))
  }
}

typealias ExprList = Array<Expr>


// MARK: -

struct Name : Equatable {
  let text : String
}

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral s: String) {
    self.init(text: s)
  }
}

// MARK: -

struct Value : Equatable {
  let int : Int
}

extension Value : ExpressibleByIntegerLiteral {
  init(integerLiteral i: Int) {
    self.init(int: i)
  }
}
