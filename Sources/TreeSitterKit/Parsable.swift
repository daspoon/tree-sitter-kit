/*

  Created by David Spooner

*/


/// *Parsable* identifies a language element which has a tree-sitter production rule and can be initialized with a parse tree.
public protocol Parsable<Result> {
  associatedtype Result

  /// The name of the grammar symbol representing this language element. The default implementation returns the receiver's type name.
  static var symbolName : String { get }

  /// Return the syntax expression for instances of this type. Required.
  static var syntaxExpression : TSExpression { get }

  /// Initialize an instance from a compatible parse tree node. Required.
  static func from(_ node: TSNode) -> Result
}


extension Parsable {
  /// Default implementation.
  public static var symbolName : String
    { "\(Self.self)" }
}


/// *ParsableByCases* simplifies conformance to *Parsable* for types which require multiple production rules, such as enums.
public protocol ParsableByCases : Parsable {
  /// A mapping of enum case names to syntax expressions.
  static var syntaxExpressionsByCaseName : [String: TSExpression] { get }
}

extension ParsableByCases {
  public static var syntaxExpression : TSExpression {
    .choice(syntaxExpressionsByCaseName.keys.sorted().map { .prod(ProductionRule(for: $0, of: Self.self)) })
  }
}

extension ParsableByCases {
  static func syntaxExpression(for alt: String) -> TSExpression
    { syntaxExpressionsByCaseName[alt]! }
}
