/*

  Created by David Spooner

*/


/// *ParsableProxy* acts as a representative for a *Parsable* type, allowing interaction
/// with that type.
public struct ParsableProxy {
  internal let type : Any.Type
  private let _symbolName : () -> String
  private let _productionRule : () -> AnyProductionRule

  public init<T: Parsable>(_ t: T.Type) {
    type = t
    _symbolName = { T.symbolName }
    _productionRule = { T.productionRule.typeErased }
  }

  public var symbolName : String
    { _symbolName() }

  public var productionRule : AnyProductionRule
    { _productionRule() }
}
