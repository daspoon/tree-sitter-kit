/*

  Created by David Spooner

*/

import TSKit


/// A type representing an enumerated type definition.

struct Enum : Equatable {
  let name : Name
  let cases : [EnumCase]
}

extension Enum : Parsable {
  typealias EnumCaseList = SeparatedSequence<EnumCase, Comma, NoBrackets>
  static var productionRule : ProductionRule<Self> {
    .init(descriptor: "enum \(Name.self) { \(EnumCaseList.self) }") { name, cases in
      Self(name: name, cases: cases.elements)
    }
  }
}


// MARK: -

struct EnumCase : Equatable {
  let name : Name
  let params : [Param]
}

extension EnumCase : Parsable {
  static var productionRule : ProductionRule<Self> {
    .init(descriptor: "\(Name.self) \(Optional<ParamList>.self)") { name, params in
      Self(name: name, params: params?.elements ?? [])
    }
  }
}


typealias ParamList = SeparatedSequence<Param, Comma, Parentheses>
