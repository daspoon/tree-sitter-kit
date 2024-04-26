/*

  Created by David Spooner

*/


/// *ParsableProxy* acts as a representative for a *Parsable* type, allowing interaction
/// with that type.
public struct ParsableProxy {
  private let type : Any.Type
  private let _symbolName : () -> String
  private let _syntaxExpression : () -> TSExpression

  public init<T: Parsable>(_ t: T.Type) {
    type = t
    _symbolName = { T.symbolName }
    _syntaxExpression = { T.syntaxExpression }
  }

  public var symbolName : String
    { _symbolName() }

  public var syntaxExpression : TSExpression
    { _syntaxExpression() }
}


// Enable ProductionRule to be Hashable
extension ParsableProxy : Hashable {
  public func hash(into hasher: inout Hasher)
    { hasher.combine(ObjectIdentifier(type)) }
  public static func == (lhs: Self, rhs: Self) -> Bool
    { lhs.type == rhs.type }
}
