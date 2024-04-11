/*

  Created by David Spooner

*/

import TSKit


/// A type representing a function definition.

@Parsable
struct Fun : Equatable, Parsable {
  let name : Name
  let params : [Param]
  let type : TypeExpr
  let expr : Expr

  init(name n: Name, params ps: [Param], type t: TypeExpr, expr e: Expr)
    { name = n; params = ps; type = t; expr = e }

  init(name n: Name, params ps: ParamList, type t: TypeExpr, expr e: Expr)
    { self.init(name: n, params: ps.elements, type: t, expr: e) }

  static var syntaxExpression : TSExpression
    { "fun \(Name.self) \(ParamList.self) -> \(TypeExpr.self) { \(Expr.self) }" }

}
