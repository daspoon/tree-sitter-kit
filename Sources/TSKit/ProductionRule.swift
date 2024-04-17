/*

  Created by David Spooner

*/


/// *ProductionRule* represents a tree-sitter grammar rule of various forms.
public enum ProductionRule : Hashable {
  /// The primary rule for a *Parsable* type.
  case value(ParsableProxy)
  /// An auxiliary rule for one alternative of a *ParsableByChoice* type; the associated string is the rule name.
  case value_case(ParsableByCasesProxy, String)
}


extension ProductionRule {
  /// Convenience initializer
  public init<T: Parsable>(for type: T.Type) {
    self = .value(.init(type))
  }

  /// Convenience initializer
  public init<T: ParsableByCases>(for alternative: String, of type: T.Type) {
    self = .value_case(.init(type), alternative)
  }

  /// Return the defined symbol name.
  public var name : String {
    switch self {
      case .value(let proxy) :
        return proxy.productionRuleName
      case .value_case(let proxy, let name) :
        return proxy.productionRuleName(for: name)
    }
  }

  /// Return the syntax expression for the receiver's expansion.
  public var syntaxExpression : TSExpression {
    switch self {
      case  .value(let proxy) :
        return proxy.syntaxExpression
      case .value_case(let proxy, let name) :
        return proxy.syntaxExpression(for: name)
    }
  }

  /// Return the set of rules reachable from the receiver, excluding the receiver itself.
  public var supportingRules : Set<Self> {
    var visited : Set<Self> = []
    var remaining : Set<Self> = [self]
    while remaining.isEmpty == false {
      let rule = remaining.removeFirst()
      visited.insert(rule)
      func walk(_ expr: TSExpression) {
        switch expr {
          case .prod(let support) :
            guard visited.contains(support) == false else { break }
            remaining.insert(support)
          case .seq(let exprs), .choice(let exprs) :
            exprs.forEach { walk($0) }
          case .field(_, let expr), .optional(let expr), .prec(_, let expr), .repeat(let expr) :
            walk(expr)
          case .literal, .pattern :
            break
        }
      }
      walk(rule.syntaxExpression)
    }
    visited.remove(self)
    return visited
  }

  /// Return the javascript representation of the form "*name*: => *syntaxExpression*".
  public var javascript : String {
    "\(name): $ => \(syntaxExpression.javascript)"
  }
}
