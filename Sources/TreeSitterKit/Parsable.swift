/*

  Created by David Spooner

*/


/// *Parsable* identifies a language element which has a tree-sitter production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The name of the grammar symbol representing this language element. The default implementation returns the receiver's type name.
  static var symbolName : String { get }

  /// The production rule for this language element.
  static var productionRule : ProductionRule<Self> { get }

  /// The means to initialize an instance from a compatible parse tree node.
  init(_ node: TSNode)
}

extension Parsable {
  public static var symbolName : String
    { "\(Self.self)" }
}


/// *ParsableAsChoice* simplifies conformance to *Parsable* for types which require multiple production rules, such as enums.
public protocol ParsableAsChoice : Parsable {
  /// A mapping of sub-rule names to pairs of syntax expressions and instance constructors.
  static var productionRuleChoices : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] { get }
}

extension ParsableAsChoice
  {
    public static var productionRule : ProductionRule<Self>
      { .multiple(productionRuleChoices) }

    public init(_ node: TSNode)
      {
        precondition(node.type == Self.symbolName && node.count == 1)
        let child = node[0]
        guard let choice = Self.productionRuleChoices[child.type]
          else { fatalError() }
        self = choice.constructor(child)
      }
  }
