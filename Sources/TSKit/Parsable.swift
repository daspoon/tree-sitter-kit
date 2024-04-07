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
  init(parseTree node: TSNode)
}


extension Parsable {
  /// Default implementation.
  public static var symbolName : String
    { "\(Self.self)" }
}
