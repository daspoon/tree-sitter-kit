/*

  Created by David Spooner

*/


/// *Parsable* identifies a language element which has a tree-sitter production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The name of the grammar symbol representing this language element. The default implementation returns the receiver's type name.
  static var symbolName : String { get }

  /// Indicates whether or not the corresponding production rule is hidden. The default implementation returns *false*.
  static var productionRuleIsHidden : Bool { get }

  /// The name of the production rule for this language element. The default implementation returns *symbolName*, prefixed with an underscore if *productionRuleIsHidden* returns *true*.
  static var productionRuleName : String { get }

  /// Return the syntax expression for instances of this type. Required.
  static var syntaxExpression : TSExpression { get }

  /// Initialize an instance from a compatible parse tree node. Required.
  init(parseTree: TSNode, source: InputSource)
}


// Default implementations.

extension Parsable {
  public static var symbolName : String
    { "\(Self.self)" }

  public static var productionRuleIsHidden : Bool
    { false }

  public static var productionRuleName : String
    { (productionRuleIsHidden ? "_" : "") + symbolName }
}
