/*

  Created by David Spooner

*/

import TreeSitterKit


struct Param : Equatable, Parsable {
  let name : Name
  let type : TypeExpr

  init(_ n: Name, _ t: TypeExpr) {
    name = n
    type = t
  }

  static var syntaxExpression : TSExpression {
    .seq([.prod(Name.self), ":", .prod(TypeExpr.self)])
  }

  init(_ node: TSNode) {
    assert(node.count == 3 && node[1].type == ":")
    name = Name(node[0])
    type = TypeExpr(node[2])
  }
}
