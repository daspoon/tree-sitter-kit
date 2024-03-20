/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type which represents the binding of a parameter name and type.

struct Param : Equatable, Parsable {
  let name : Name
  let type : TypeExpr

  init(_ n: Name, _ t: TypeExpr) {
    name = n
    type = t
  }

  static var syntaxExpression : TSExpression {
    "\(Name.self) : \(TypeExpr.self)"
  }

  init(_ node: TSNode) {
    name = Name(node[0])
    type = TypeExpr(node[2])
  }
}


typealias ParamList = [Param]
