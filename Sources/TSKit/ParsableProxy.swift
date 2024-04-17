/*

  Created by David Spooner

*/


/// *ParsableProxy* acts as a representative for a *Parsable* type, allowing interaction with that type.
public struct ParsableProxy {
  private let type : Any.Type
  private let _productionRuleName : () -> String
  private let _syntaxExpression : () -> TSExpression

  public init<T: Parsable>(_ t: T.Type) {
    type = t
    _productionRuleName = { T.productionRuleName }
    _syntaxExpression = { T.syntaxExpression }
  }

  public var productionRuleName : String
    { _productionRuleName() }

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
