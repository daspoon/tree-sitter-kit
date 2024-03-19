/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing an enumerated type definition.

struct Enum : Equatable {
  let name : Name
  let cases : [EnumCase]
}

extension Enum : Parsable {
  static var syntaxExpression : TSExpression
    { .seq(["enum", .prod(Name.self), .list(EnumCase.self, .comma, .curly)]) }

  init(_ node: TSNode) {
    name = Name(node[1])
    cases = [EnumCase](node[2])
  }
}


// MARK: -

struct EnumCase : Equatable {
  let name : Name
  let params : [Param]
}


extension EnumCase : Parsable {
  static var syntaxExpression : TSExpression
    { .seq([.prod(Name.self), .optional(.list(Param.self))]) }

  init(_ node: TSNode) {
    name = Name(node[0])
    params = node.count > 1 ? [Param](node[1]) : []
  }
}
