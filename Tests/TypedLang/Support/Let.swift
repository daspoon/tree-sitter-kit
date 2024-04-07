/*

  Created by David Spooner

*/

import TSKit


/// A type representing a value definition.

@Parsable
struct Let : Equatable, Parsable {
  let param : Param
  let expr : Expr

  init(param p: Param, expr e: Expr)
    { param = p; expr = e }

  static var syntaxExpression : TSExpression
    { "let \(Param.self) = \(Expr.self)" }

}
