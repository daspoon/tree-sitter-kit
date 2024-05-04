/*

  Created by David Spooner

*/

import TSKit


/// A type representing a value definition.

struct Let : Equatable {
  let param : Param
  let expr : Expr
}

extension Let : Parsable {
  static var productionRule : ProductionRule<Let> {
    return .init(descriptor: "let \(Param.self) = \(Expr.self)") { param, expr in
      Self(param: param, expr: expr)
    }
  }
}
