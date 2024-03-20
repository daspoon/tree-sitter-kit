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
  typealias EnumCaseList = SeparatedSequence<EnumCase, Comma>

  static var syntaxExpression : TSExpression
    { "enum \(Name.self) { \(EnumCaseList.self) }" }

  init(_ node: TSNode) {
    name = Name(node[1])
    cases = EnumCaseList(node[3]).elements
  }
}


// MARK: -

struct EnumCase : Equatable {
  let name : Name
  let params : [Param]
}

extension EnumCase : Parsable {
  static var syntaxExpression : TSExpression
    { "\(Name.self) \(optional: .prod(ParamList.self))" }

  init(_ node: TSNode) {
    name = Name(node[0])
    params = node.count > 1 ? [Param](node[1]) : []
  }
}
