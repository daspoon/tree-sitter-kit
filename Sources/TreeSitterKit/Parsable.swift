/*

  Created by David Spooner

*/


/// *Parsable* identifies a language element which has a tree-sitter production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The name of the grammar symbol representing this language element. The default implementation returns the receiver's type name.
  static var symbolName : String { get }

  /// Return the syntax expression for instances of this type. Required.
  static var syntaxExpression : TSExpression { get }

  /// Initialize an instance from a compatible parse tree node. Required.
  init(_ node: TSNode)
}

extension Parsable {
  /// Default implementation.
  public static var symbolName : String
    { "\(Self.self)" }
}


/// *ParsableByCases* simplifies conformance to *Parsable* for types which require multiple production rules, such as enums.
public protocol ParsableByCases : Parsable {
  /// A mapping of sub-rule names to pairs of syntax expressions and instance constructors.
  static var productionsByChoiceName : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] { get }
}

extension ParsableByCases {
  public static var syntaxExpression : TSExpression {
    .choice(productionsByChoiceName.keys.sorted().map { .prod(ProductionRule(for: $0, of: Self.self)) })
  }

  public init(_ node: TSNode) {
    precondition(node.type == Self.symbolName && node.count == 1)
    let child = node[0]
    guard let choice = Self.productionsByChoiceName[child.type]
      else { fatalError() }
    self = choice.constructor(child)
  }
}

extension ParsableByCases {
  static func syntaxExpression(for alt: String) -> TSExpression
    { productionsByChoiceName[alt]!.expression }
}
