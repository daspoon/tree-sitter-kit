/*

  Created by David Spooner

*/


/// *ParsableProxyChoice* acts as a representative for a *ParsableByCases* type, allowing interaction with that type.
public struct ParsableProxyCase {
  public let superproxy : ParsableProxy
  private let _syntaxExpressionFor : ((String) -> TSExpression)!

  public init<T: ParsableByCases>(_ type: T.Type) {
    superproxy = .init(type)
    _syntaxExpressionFor = { T.syntaxExpression(for: $0) }
  }

  public func symbolName(for name: String) -> String
    { superproxy.symbolName + "_" + name }

  public func syntaxExpression(for name: String) -> TSExpression
    { _syntaxExpressionFor(name) }
}


// Enable ProductionRule to be Hashable
extension ParsableProxyCase : Hashable {
  public func hash(into hasher: inout Hasher)
    { superproxy.hash(into: &hasher) }
  public static func == (lhs: Self, rhs: Self) -> Bool
    { lhs.superproxy == rhs.superproxy }
}
