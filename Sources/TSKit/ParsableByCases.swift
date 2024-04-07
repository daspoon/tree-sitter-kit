/*

  Created by David Spooner

*/


/// *ParsableByCases* simplifies conformance to *Parsable* for types which require multiple production rules, such as enums.
public protocol ParsableByCases : Parsable {
  /// Return the mapping of rule names to syntax expressions.
  static var syntaxExpressionsByCaseName : [String: TSExpression] { get }
}

extension ParsableByCases {
  public static var syntaxExpression : TSExpression {
    .choice(syntaxExpressionsByCaseName.keys.sorted().map { .prod(ProductionRule(for: $0, of: Self.self)) })
  }
}

extension ParsableByCases {
  /// Return the syntax expression for the given rule name.
  static func syntaxExpression(for name: String) -> TSExpression
    { syntaxExpressionsByCaseName[name]! }
}
