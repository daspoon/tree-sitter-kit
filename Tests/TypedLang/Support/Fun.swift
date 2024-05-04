/*

  Created by David Spooner

*/

import TSKit


/// A type representing a function definition.

struct Fun : Equatable {
  let name : Name
  let params : [Param]
  let type : TypeExpr
  let expr : Expr
}

extension Fun : Parsable {
  static var productionRule : ProductionRule<Fun> {
    .init(descriptor: "fun \(Name.self) \(ParamList.self) -> \(TypeExpr.self) { \(Expr.self) }") { name, plist, rtype, body in
      Self(name: name, params: plist.elements, type: rtype, expr: body)
    }
  }
}
