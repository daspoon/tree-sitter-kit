/*

  Created by David Spooner

*/


/// *ParsableByCases* simplifies conformance to *Parsable* for types which require multiple
/// production rules, such as enums. It provides a default implementation for *productionRule*
/// as a choice of sub-rules.
public protocol ParsableByCases : Parsable {
  /// Return the mapping of sub-rule names to syntax expressions. Required.
  static var productionRulesByCaseName : [String: ProductionRule<Self>] { get }
}

extension ParsableByCases {
  /// Return a production rule corresponding to a choice
  public static var productionRule : ProductionRule<Self>
    { .init() }

  /// Override Parsable's implementation to make the production hidden.
  public static var symbolIsHidden : Bool
    { true }
}
