/*

  Created by David Spooner

*/

@testable import TSKit


/// A type representing a variety of symbol definitions.

enum Def : Equatable {
  case `typedef`(Typedef)
  case `enum`(Enum)
  case `let`(Let)
  case `fun`(Fun)
}


extension Def : ParsableByCases {
  static var productionRulesByCaseName : [String: ProductionRule<Self>] {
    return [
      "typedef": .init(descriptor: "\(Typedef.self)") { Def.typedef($0) },
      "enum": .init(descriptor: "\(Enum.self)") { Def.enum($0) },
      "let": .init(descriptor: "\(Let.self)") { Def.let($0) },
      "fun": .init(descriptor: "\(Fun.self)") { Def.fun($0) },
    ]
  }
}


extension Def {
  init(_ text: String) throws {
    // Parse a program with the declaration text followed by a trivial expression.
    let program = try Block(text + "; 1")
    guard program.decls.count == 1
      else { throw TSError("requires a single declaration") }
    self = program.decls[0]
  }
}
