/*

  Created by David Spooner

*/

import TSKit


/// A type representing a function definition.

@ParsableStruct
struct Fun : Equatable, Parsable {
  let name : Name
  let params : [Param]
  let type : TypeExpr
  let expr : Expr

  init(name n: Name, params ps: [Param], type t: TypeExpr, expr e: Expr)
    { name = n; params = ps; type = t; expr = e }

  static var syntaxExpression : TSExpression
    { "fun \(Name.self) \([Param].self) -> \(TypeExpr.self) { \(Expr.self) }" }

}
