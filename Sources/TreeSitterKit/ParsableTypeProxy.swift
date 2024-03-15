/*

  Created by David Spooner

*/


/// A *ParsableTypeProxy* acts as a representative for an arbitrary *Parsable* type, allowing interaction with that type.
public struct ParsableTypeProxy {
  private let type : Any.Type
  private let _symbolName : () -> String
  private let _syntaxExpression : () -> TSExpression
  private let _productionRuleJavascript : (Int) -> String

  public init<T: Parsable>(_ t: T.Type) {
    type = t
    _symbolName = { T.symbolName }
    _syntaxExpression = { T.syntaxExpression }
    _productionRuleJavascript = { T.productionRule.javascript(indent: $0) }
  }

  public var symbolName : String
    { _symbolName() }

  public var syntaxExpression : TSExpression
    { _syntaxExpression() }

  public func productionRuleJavascript(indent i: Int) -> String
    { _productionRuleJavascript(i) }
}


extension ParsableTypeProxy : Hashable {
  public func hash(into hasher: inout Hasher)
    { hasher.combine(ObjectIdentifier(type)) }
  public static func == (lhs: Self, rhs: Self) -> Bool
    { lhs.type == rhs.type }
}


extension ParsableTypeProxy : CustomStringConvertible {
  public var description : String {
    "\(type)"
  }
}
