/*

  Created by David Spooner

*/

import TSKit


/// A type which represents the binding of a parameter name and type.

@Parsable
struct Param : Equatable, Parsable {
  let name : Name
  let type : TypeExpr

  init(name n: Name, type t: TypeExpr) {
    name = n
    type = t
  }

  static var syntaxExpression : TSExpression {
    "\(Name.self) : \(TypeExpr.self)"
  }

}


extension Param {
  init(_ n: Name, _ t: TypeExpr)
    { self.init(name: n, type: t) }
}
