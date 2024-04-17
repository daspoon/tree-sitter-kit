/*

  Created by David Spooner

*/


/// *ParsableByCasesProxy* acts as a representative for a *ParsableByCases* type, allowing interaction with that type.
public struct ParsableByCasesProxy {
  private let type : Any.Type
  private let _symbolName : () -> String
  private let _syntaxExpressionFor : ((String) -> TSExpression)!

  public init<T: ParsableByCases>(_ t: T.Type) {
    type = t
    _symbolName = { T.symbolName }
    _syntaxExpressionFor = { T.syntaxExpression(for: $0) }
  }

  public func productionRuleName(for name: String) -> String
    { _symbolName() + "_" + name }

  public func syntaxExpression(for name: String) -> TSExpression
    { _syntaxExpressionFor(name) }
}


// Enable ProductionRule to be Hashable
extension ParsableByCasesProxy : Hashable {
  public func hash(into hasher: inout Hasher)
    { hasher.combine(ObjectIdentifier(type)) }
  public static func == (lhs: Self, rhs: Self) -> Bool
    { lhs.type == rhs.type }
}
