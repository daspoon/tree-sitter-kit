/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a type alias.

@ParsableStruct
struct Typedef : Equatable, Parsable {
  let name : Name
  let type : TypeExpr

  init(name n: Name, type t: TypeExpr)
    { name = n; type = t }

  static var syntaxExpression : TSExpression
    { "typedef \(Name.self) = \(TypeExpr.self)" }

}
