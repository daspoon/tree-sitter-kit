/*

  Created by David Spooner

*/


/// *TSExpression* represents a syntax expression within a tree-sitter grammar.
public indirect enum TSExpression {
  /// A type specifying precedence and associativity.
  public enum Prec : ExpressibleByIntegerLiteral {
    case none(Int), left(Int), right(Int)
    public init(integerLiteral value: Int)
      { self = .none(value) }
  }

  /// A token matching a specific string; e.g. '('.
  case literal(String)
  /// A token matching a regular expression; e.g. /[a-z]+/.
  case pattern(String)
  /// A grammar rule of a given name and type; e.g. $.Expr.
  case rule(ParsableTypeProxy)
  /// A sequence of expressions; e.g. seq('(', $.Expr, ')').
  case seq([TSExpression])
  /// A choice of possible expressions; e.g. choice($.Name, $.Number).
  case choice([TSExpression])
  /// Specifies precedence, and optionally associativity, for a given expression.
  case prec(Prec, TSExpression)
  /// A possibly empty sequence of a parsable type, bracketed and separated by the given (literal) strings.
  case list(ParsableTypeProxy, (lhs: String, rhs: String), String)


  public static func rule<T: Parsable>(_ type: T.Type) -> Self
    { .rule(ParsableTypeProxy(T.self)) }

  public static func list<T: ParsableInSequence>(of type: T.Type) -> Self
    { .list(ParsableTypeProxy(T.self), T.bracketLiterals, T.separatorLiteral) }

  public static func infix<L: Parsable, R: Parsable>(_ prec: TSExpression.Prec, _ op: String..., lhs: L.Type, rhs: R.Type) -> Self
    { .prec(prec, .seq([.rule(L.self), .choice(op.map {.literal($0)}), .rule(R.self)])) }

  public static func prefix<T: Parsable>(_ prec: TSExpression.Prec, _ op: String..., arg: T.Type) -> Self
    { .prec(prec, .seq([.choice(op.map {.literal($0)}), .rule(T.self)])) }


  /// Return the receiver's javascript representation.
  public var javascript : String {
    switch self {
      case .literal(let literal) :
        return "'" + literal + "'"
      case .pattern(let pattern) :
        return "/" + pattern + "/"
      case .rule(let proxy) :
        return "$.\(proxy.symbolName)"
      case .seq(let elements) :
        return "seq(\(elements.map({$0.javascript}).joined(separator: ", ")))"
      case .choice(let elements) :
        return "choice(\(elements.map({$0.javascript}).joined(separator: ", ")))"
      case .prec(.none(let n), let expr) :
        return "prec(\(n), \(expr.javascript))"
      case .prec(.left(let n), let expr) :
        return "prec.left(\(n), \(expr.javascript))"
      case .prec(.right(let n), let expr) :
        return "prec.right(\(n), \(expr.javascript))"
      case .list(let proxy, let brackets, let separator) :
        return "seq('\(brackets.lhs)', optional(seq($.\(proxy.symbolName), repeat(seq('\(separator)', $.\(proxy.symbolName))))), '\(brackets.rhs)')"
    }
  }
}
