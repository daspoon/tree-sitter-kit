/*

  Created by David Spooner

*/


#if false
/// Represents the grammar symbol for either a *Parsable* type or a specific case of a *ParsableByCases* type.

public struct Symbol {
  private let type : Any.Type
  private let rule : () -> AnyProductionRule
  public let name : String

  public init<T: Parsable>(_ t: T.Type) {
    type = t
    rule = { T.productionRule.typeErased }
    name = T.symbolName
  }

  public init<T: ParsableByCases>(_ t: T.Type, name n: String) {
    assert(T.productionRulesBySymbolName[n] != nil)
    type = t
    rule = { T.productionRulesBySymbolName[n]!.typeErased }
    name = n
  }

  public var productionRule : AnyProductionRule {
    rule()
  }
}

extension Symbol : Hashable {
  public func hash(into hasher: inout Hasher) {
    hasher.combine(ObjectIdentifier(type))
    hasher.combine(name)
  }
}

extension Symbol : Equatable {
  public static func == (lhs: Self, rhs: Self) -> Bool {
    lhs.type == rhs.type && lhs.name == rhs.name
  }
}

extension Symbol : Comparable {
  public static func < (lhs: Self, rhs: Self) -> Bool {
    lhs.name.removing(prefix: "_") < rhs.name.removing(prefix: "_")
  }
}
#endif
