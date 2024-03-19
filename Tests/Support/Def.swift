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

  static var productionsByChoiceName : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Decl_typedef": (.prod(Typedef.self), { node in
        .typedef(Typedef(node[0]))
      }),
      "Decl_enum": (.prod(Enum.self), { node in
        .enum(Enum(node[0]))
      }),
      "Decl_let": (.prod(Let.self), { node in
        .let(Let(node[0]))
      }),
      "Decl_fun": (.prod(Fun.self), { node in
        .fun(Fun(node[0]))
      }),
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
