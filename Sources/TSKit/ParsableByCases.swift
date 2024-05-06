/*

  Created by David Spooner

*/


/// *ParsableByCases* identifies types which are parsable by more than one grammar
/// productions rule, such as enums. It implements *productionRule* as a hidden
/// rule mapping to a choice of sub-rules.
public protocol ParsableByCases : Parsable {
  /// The mapping of case names to alternate production rules. Required.
  static var productionRulesByCaseName : [String: ProductionRule<Self>] { get }
}

extension ParsableByCases {
  /// Return a production rule corresponding to a choice of the alternate production
  /// rules specified by *productionRulesByCaseName*.
  public static var productionRule : ProductionRule<Self>
    { .init() }

  /// Override Parsable's implementation to make the production hidden.
  public static var symbolIsHidden : Bool
    { true }
}
