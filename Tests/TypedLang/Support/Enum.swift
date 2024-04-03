/*

  Created by David Spooner

*/

import TSKit


/// A type representing an enumerated type definition.

@ParsableStruct
struct Enum : Equatable, Parsable {
  let name : Name
  let cases : [EnumCase]

  init(name n: Name, cases cs: [EnumCase])
    { name = n; cases = cs }

  init(name n: Name, cases cs: EnumCaseList)
    { name = n; cases = cs.elements }

  typealias EnumCaseList = SeparatedSequence<EnumCase, Comma, NoBrackets>
  static var syntaxExpression : TSExpression
    { "enum \(Name.self) { \(EnumCaseList.self) }" }

}



// MARK: -

@ParsableStruct
struct EnumCase : Equatable, Parsable {
  let name : Name
  let params : [Param]

  init(name n: Name, params ps: [Param]?)
    { name = n; params = ps ?? [] }

  static var syntaxExpression : TSExpression
    { "\(Name.self) \(opt: [Param].self)" }

}

