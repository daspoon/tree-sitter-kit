/*

  Created by David Spooner

*/

import TSKit


/// A type representing a type alias.

struct Typedef : Equatable {
  let name : Name
  let type : TypeExpr
}

extension Typedef : Parsable {
  static var productionRule : ProductionRule<Self> {
    .init(descriptor: "typedef \(Name.self) = \(TypeExpr.self)") { name, type in
      Self(name: name, type: type)
    }
  }
}
