/*

  Created by David Spooner

*/

import TreeSitterKit


struct Param : Equatable, Parsable, ParsableInSequence {
  let name : Name
  let type : TypeExpr

  init(_ n: Name, _ t: TypeExpr) {
    name = n
    type = t
  }

  static var productionRule : ProductionRule<Self> {
    .single(.seq([.rule(Name.self), .literal(":"), .rule(TypeExpr.self)]))
  }

  init(_ node: TSNode) {
    assert(node.count == 3 && node[1].type == ":")
    name = Name(node[0])
    type = TypeExpr(node[2])
  }
}
