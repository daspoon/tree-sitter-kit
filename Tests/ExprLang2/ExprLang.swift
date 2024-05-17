/*

  Created by David Spooner

*/

import TSKit
import XCTest


class TmpTest : XCTestCase {
  func testIt() throws { }
}

@Grammar
struct ExprLang : Grammar {
  typealias Root = Expr

  struct Name : Equatable, Parsable {
    let text : String
    static var productionRule : ProductionRule<Self> {
      .init(descriptor: "\(pat: "[a-zA-Z_][0-9a-zA-Z_]*")") {s in .init(text: s)}
    }
  }

  indirect enum Expr : Equatable, ParsableByCases {
    case name(Name)
    case apply(Expr, [Expr]?)
    static var productionRulesByCaseName : [String: ProductionRule<Self>] {
      return [
        "name": .init(descriptor: "\(Name.self)") { name in
          .name(name)
        },
        "add": .init(descriptor: "\(prec: .left(1)) \(Expr.self) \(lit: ["+", "-"]) \(Expr.self)") { lhs, op, rhs in
          .apply(.op(op), [lhs, rhs])
        },
        "mul": .init(descriptor: "\(prec:  .left(2)) \(Expr.self) \(lit: ["*", "/"]) \(Expr.self)") { lhs, op, rhs  in
          .apply(.op(op), [lhs, rhs])
        },
        "pow": .init(descriptor: "\(prec: .right(3)) \(Expr.self) \(lit: ["^"]) \(Expr.self)") { lhs, op, rhs  in
          .apply(.op(op), [lhs, rhs])
        },
        "neg": .init(descriptor: "\(prec:  .none(4)) \(lit: ["-"]) \(Expr.self)") { op, arg -> Expr in
          .apply(.op(op), [arg])
        },
        "apply": .init(descriptor: "\(prec: .none(5)) \(Expr.self) ( \(opt: ExprList.self) )") { (fun, args: ExprList?) in
          .apply(fun, args?.elements)
        },
        "paren": .init(descriptor: "( \(Expr.self) )") { expr in
          expr
        },
      ]
    }
    static func op(_ text: String) -> Self {
      .name(Name(text: text))
    }
  }

  struct ExprList : Equatable, ParsableAsSeparatedSequence {
    typealias Element = Expr
    static var separator : String { "," }
    let elements : [Element]
  }
}
