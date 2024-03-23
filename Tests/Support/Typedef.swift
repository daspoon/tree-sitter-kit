/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a type alias.

struct Typedef : Equatable {
  let name : Name
  let type : TypeExpr
}

extension Typedef : Parsable {
  static var syntaxExpression : TSExpression
    { "typedef \(Name.self) = \(TypeExpr.self)" }

  init(_ node: TSNode) {
    name = Name(node[1])
    type = TypeExpr(node[3])
  }
}