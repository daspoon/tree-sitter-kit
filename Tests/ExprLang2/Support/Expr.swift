/*

  Created by David Spooner

*/

@testable import TSKit
import ExprLang2


// Define the Expr type which represents our abstract syntax.

indirect enum Expr {
  case name(Name)
  case apply(Expr, [Expr])
}


extension Expr : ParsableByCases {
  static var productionRulesByCaseName : [String: ProductionRule<Self>] {
    return [
      "name": .init(descriptor: "\(Name.self)") { name in
        Expr.name(name)
      },
      "add": .init(descriptor: "\(prec:  .left(1)) \(Expr.self) \(["+", "-"]) \(Expr.self)") { lhs, op, rhs in
        .apply(.name(Name(stringLiteral: op)), [lhs, rhs])
      },
      "mul": .init(descriptor: "\(prec:  .left(2)) \(Expr.self) \(["*", "/"]) \(Expr.self)") { lhs, op, rhs in
        .apply(.name(Name(stringLiteral: op)), [lhs, rhs])
      },
      "pow": .init(descriptor: "\(prec: .right(3)) \(Expr.self) \(["^"]) \(Expr.self)") { lhs, op, rhs in
        .apply(.name(Name(stringLiteral: op)), [lhs, rhs])
      },
      "neg": .init(descriptor: "\(prec:  .none(4)) \(["-"]) \(Expr.self)") { op, arg in
        .apply(.name(Name(stringLiteral: op)), [arg])
      },
      "apply": .init(descriptor: "\(prec:  .none(5)) \(Expr.self) ( \(opt: ExprList.self) )") { fun, args in
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


// Synthesize structual equality to enable comparing parsed and expected expressions.

extension Expr : Equatable {
}
