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
  /// Return the mapping of symbol names to production rules formed by prefixing
  /// the keys of *productionRulesByCaseName* with `"\(typeName)_"`.
  static var productionRulesBySymbolName : [String: ProductionRule<Self>] {
    let typeName = Self.typeName
    return Dictionary(uniqueKeysWithValues: productionRulesByCaseName.map { name, rule in
      ("\(typeName)_\(name)", rule)
    })
  }

  /// Return a production rule corresponding to a choice of the alternate production
  /// rules specified by *productionRulesBySymbolName*.
  public static var productionRule : ProductionRule<Self> {
    let productionRulesBySymbolName = Self.productionRulesBySymbolName
    return ProductionRule(
      syntaxExpression: .choice(productionRulesBySymbolName.map { name, _ in
        .prod(.init(Self.self, name: name))
      }),
      constructor: { node, ctx in
        let symbolName = ctx.language.symbolName(for: node)
        guard let subrule = productionRulesBySymbolName[symbolName]
          else { throw TSError("unexpected node type: \(symbolName)") }
        return try subrule.constructor(node, ctx)
      }
    )
  }

  /// Override Parsable's implementation to make the production hidden.
  public static var symbolIsHidden : Bool
    { true }
}
