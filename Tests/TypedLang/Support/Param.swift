/*

  Created by David Spooner

*/

import TSKit


/// A type which represents the binding of a parameter name and type.

struct Param : Equatable {
  let name : Name
  let type : TypeExpr
}


extension Param : Parsable {
  static var productionRule : ProductionRule<Param> {
    .init(descriptor: "\(Name.self) : \(TypeExpr.self)") { name, type in
      Self(name: name, type: type)
    }
  }
}


extension Param {
  init(_ n: Name, _ t: TypeExpr)
    { self.init(name: n, type: t) }
}
