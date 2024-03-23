/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a value definition.

struct Let : Equatable {
  let param : Param
  let expr : Expr
}

extension Let : Parsable {
  static var syntaxExpression : TSExpression
    { "let \(Param.self) = \(Expr.self)" }

  init(_ node: TSNode) {
    param = Param(node[1])
    expr = Expr(node[3])
  }
}