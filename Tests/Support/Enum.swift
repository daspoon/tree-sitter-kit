/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing an enumerated type definition.

@ParsableStruct
struct Enum : Equatable, Parsable {
  typealias EnumCaseList = SeparatedSequence<EnumCase, Comma>

  let name : Name
  let cases : EnumCaseList

  init(name n: Name, cases cs: [EnumCase])
    { name = n; cases = .init(elements: cs) }

  static var syntaxExpression : TSExpression
    { "enum \(Name.self) { \(EnumCaseList.self) }" }

}



// MARK: -

@ParsableStruct
struct EnumCase : Equatable, Parsable {
  let name : Name
  let params : [Param]

  init(name n: Name, params ps: [Param])
    { name = n; params = ps }

  static var syntaxExpression : TSExpression
    { "\(Name.self) \(optional: .prod(ParamList.self))" }

}

