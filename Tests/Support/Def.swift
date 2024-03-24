/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a variety of symbol definitions.

enum Def : Equatable, ParsableByCases {
  case `typedef`(Typedef)
  case `enum`(Enum)
  case `let`(Let)
  case `fun`(Fun)

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "Decl_typedef": "\(Typedef.self)",
      "Decl_enum": "\(Enum.self)",
      "Decl_let": "\(Let.self)",
      "Decl_fun": "\(Fun.self)",
    ]
  }
}

extension Def {
  init(_ text: String) throws {
    // Parse a program with the declaration text followed by a trivial expression.
    let program = try Block(text + "; 1")
    guard program.decls.count == 1
      else { throw TSException("requires a single declaration") }
    self = program.decls[0]
  }
}
