/*

  Created by David Spooner

*/


/// *ParsableByCases* simplifies conformance to *Parsable* for types which require multiple production rules, such as enums. It provides a default implementation for *syntaxExpression* as a choice of sub-rule productions.
public protocol ParsableByCases : Parsable {
  /// Return the mapping of sub-rule names to syntax expressions.
  static var syntaxExpressionsByCaseName : [String: TSExpression] { get }
}

extension ParsableByCases {
  /// Return a choice of the productions for the sub-rules defined by *syntaxExpressionsByCaseName*.
  public static var syntaxExpression : TSExpression {
    .choice(syntaxExpressionsByCaseName.keys.sorted().map { .prod(ProductionRule(for: $0, of: Self.self)) })
  }
}

extension ParsableByCases {
  /// Override Parsable's implementation to make the production hidden.
  public static var productionRuleIsHidden : Bool
    { true }

  /// Return the syntax expression for the given rule name.
  static func syntaxExpression(for name: String) -> TSExpression
    { syntaxExpressionsByCaseName[name]! }
}
