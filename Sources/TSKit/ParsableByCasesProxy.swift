/*

  Created by David Spooner

*/


/// *ParsableByCasesProxy* acts as a representative for a *ParsableByCases* type, allowing interaction with that type.
public struct ParsableByCasesProxy {
  internal let type : Any.Type
  private let _typeName : () -> String
  private let _productionRuleFor : ((String) -> AnyProductionRule)!

  public init<T: ParsableByCases>(_ t: T.Type) {
    type = t
    _typeName = { T.typeName }
    _productionRuleFor = { T.productionRulesByCaseName[$0]!.typeErased }
  }

  public func symbolName(for name: String) -> String
    { _typeName() + "_" + name }

  public func productionRule(for name: String) -> AnyProductionRule
    { _productionRuleFor(name) }
}
