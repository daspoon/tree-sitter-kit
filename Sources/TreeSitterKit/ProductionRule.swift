/*

  Created by David Spooner

*/


/// *ProductionRule* represents a tree-sitter grammar rule of various forms.
public enum ProductionRule : Hashable {
  /// The primary rule for a *Parsable* type.
  case value(ParsableProxy)
  /// An auxiliary rule for one alternative of a *ParsableByChoice* type; the associated string is the rule name.
  case value_case(ParsableProxyCase, String)
  /// An auxiliary rule for a sequence of *Parsable* type, with specified separator and brackets.
  case list(ParsableProxy, TSExpression.Separator, TSExpression.Brackets?)
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
  public var symbolName : String {
    switch self {
      case .value(let proxy) :
        return proxy.symbolName
      case .value_case(_, let name) :
        return name
      case .list(let proxy, let separator, let brackets) :
        return "\(proxy.symbolName)_Array_\(separator.name)" + (brackets.map {"_\($0.name)"} ?? "")
    }
  }

  /// Return the syntax expression for the receiver's expansion.
  public var expandedSyntaxExpression : TSExpression {
    switch self {
      case  .value(let proxy) :
        return proxy.syntaxExpression
      case .value_case(let proxy, let name) :
        return proxy.syntaxExpression(for: name)
      case .list(let proxy, let separator, .none) :
        return .seq([.prod(.value(proxy)), .repeat(.seq([.literal(separator.text), .prod(.value(proxy))]))])
      case .list(let proxy, let separator, .some(let brackets)) :
        return .seq([.literal(brackets.lhs), .optional(.seq([.prod(.value(proxy)), .repeat(.seq([.literal(separator.text), .prod(.value(proxy))]))])), .literal(brackets.rhs)])
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
          case .prec(_, let expr), .optional(let expr), .repeat(let expr) :
            walk(expr)
          case .literal, .pattern :
            break
        }
      }
      walk(rule.expandedSyntaxExpression)
    }
    visited.remove(self)
    return visited
  }

  /// Return the javascript representation of the form "*symbolName*: => *expandedSyntaxExpression*".
  public var javascript : String {
    "\(symbolName): $ => \(expandedSyntaxExpression.javascript)"
  }
}
