/*

  Created by David Spooner

*/


#if false
/// *ParsableByCases* identifies types which are parsable by more than one grammar
/// productions rule, such as enums. It implements *productionRule* as a hidden
/// rule mapping to a choice of sub-rules.
public protocol ParsableByCases : Parsable {
  /// The mapping of case names to alternate production rules. Required.
  static var productionRulesByCaseName : [String: ProductionRule<Self>] { get }
}

extension ParsableByCases {
  /// Return the mapping of symbol names to production rules formed by prefixing
  /// the keys of *productionRulesByCaseName* with `"\(typeName)_"`.
  static var productionRulesBySymbolName : [String: ProductionRule<Self>] {
    let typeName = Self.typeName
    return Dictionary(uniqueKeysWithValues: productionRulesByCaseName.map { name, rule in
      ("\(typeName)_\(name)", rule)
    })
  }

  /// Override Parsable's implementation to make the production hidden.
  public static var symbolIsHidden : Bool
    { true }
}
#endif
