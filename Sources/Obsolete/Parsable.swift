/*

  Created by David Spooner

*/

#if false
import Foundation


/// *Parsable* identifies types which implement language elements -- i.e. which have
/// a grammar production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The grammar production rule which defines the associated symbol, syntax expression
  /// and creation method. Required.
  static var productionRule : ProductionRule<Self> { get }

  /// Indicates whether or not this type's production rule is hidden. The default
  /// implementation returns *false*.
  static var symbolIsHidden : Bool { get }

  /// The name of this language element. The default implementation returns the name
  /// of the receiving type.
  static var typeName : String { get }
}


// Default implementations.

extension Parsable {
  public static var productionRule : ProductionRule<Self>
    { fatalError() }

  /// The name of the production rule is the *typeName*, prefixed with an underscore
  /// iff *symbolIsHidden* returns *true*.
  public static var symbolName : String
    { (symbolIsHidden ? "_" : "") + typeName }

  public static var symbolIsHidden : Bool
    { false }

  public static var typeName : String
    { "\(Self.self)" }
}
#endif
