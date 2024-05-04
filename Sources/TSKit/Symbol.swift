/*

  Created by David Spooner

*/


/// Represents a gramma symbol...

public enum Symbol {
  /// The primary rule for a *Parsable* type.
  case value(ParsableProxy)
  /// An auxiliary rule for one alternative of a *ParsableByCases* type; the associated string is the rule name.
  case value_case(ParsableByCasesProxy, String)


  public init<T: Parsable>(_ type: T.Type) {
    self = .value(.init(type))
  }

  public init<T: ParsableByCases>(_ type: T.Type, `case`: String) {
    self = .value_case(.init(type), `case`)
  }


  public var name : String {
    switch self {
      case .value(let proxy) :
        return proxy.symbolName
      case .value_case(let proxy, let name) :
        return proxy.symbolName(for: name)
    }
  }

  public var productionRule : AnyProductionRule {
    switch self {
      case .value(let proxy) :
        return proxy.productionRule
      case .value_case(let proxy, let name) :
        return proxy.productionRule(for: name)
    }
  }
}


extension Symbol : Hashable {
  public func hash(into hasher: inout Hasher) {
    switch self {
      case .value(let proxy) :
        hasher.combine(ObjectIdentifier(proxy.type))
      case .value_case(let proxy, let name) :
        hasher.combine(ObjectIdentifier(proxy.type))
        hasher.combine(name)
    }
  }
}


extension Symbol : Equatable {
  public static func == (lhs: Self, rhs: Self) -> Bool {
    switch (lhs, rhs) {
      case (.value(let lhs_proxy), .value(let rhs_proxy)) :
        return lhs_proxy.type == rhs_proxy.type
      case (.value_case(let lhs_proxy, let lhs_name), .value_case(let rhs_proxy, let rhs_name)) :
        return lhs_proxy.type == rhs_proxy.type && lhs_name == rhs_name
      default :
        return false
    }
  }
}
