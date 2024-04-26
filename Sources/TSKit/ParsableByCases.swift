/*

  Created by David Spooner

*/


/// *ParsableByCases* simplifies conformance to *Parsable* for types which require multiple
/// production rules, such as enums. It provides a default implementation for *syntaxExpression*
/// as a choice of sub-rules.
public protocol ParsableByCases : Parsable {
  /// Return the mapping of sub-rule names to syntax expressions. Required.
  static var syntaxExpressionsByCaseName : [String: TSExpression] { get }
}

extension ParsableByCases {
  /// Return a choice of the sub-rule productions defined by *syntaxExpressionsByCaseName*.
  public static var syntaxExpression : TSExpression {
    let subrules = syntaxExpressionsByCaseName.keys.sorted().map { name in
      ProductionRule(for: name, of: Self.self)
    }
    return .choice(subrules.map {rule in .prod(rule)})
  }

  /// Override Parsable's implementation to make the production hidden.
  public static var symbolIsHidden : Bool
    { true }
}

extension ParsableByCases {
  /// Return the syntax expression for the given rule name.
  static func syntaxExpression(for name: String) -> TSExpression
    { syntaxExpressionsByCaseName[name]! }
}
