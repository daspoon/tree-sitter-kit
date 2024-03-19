/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a function definition.

struct Fun : Equatable {
  let name : Name
  let params : [Param]
  let type : TypeExpr
  let expr : Expr
}


extension Fun : Parsable {
  static var syntaxExpression : TSExpression
    { .seq(["fun", .prod(Name.self), .list(Param.self), "->", .prod(TypeExpr.self), "{", .prod(Expr.self), "}"]) }

  init(_ node: TSNode) {
    name = Name(node[1])
    params = [Param](node[2])
    type = TypeExpr(node[4])
    expr = Expr(node[6])
  }
}
