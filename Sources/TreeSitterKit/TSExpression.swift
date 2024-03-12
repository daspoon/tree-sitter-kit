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
  case rule(String, Any.Type)
  /// A sequence of expressions; e.g. seq('(', $.Expr, ')').
  case seq([TSExpression])
  /// A choice of possible expressions; e.g. choice($.Name, $.Number).
  case choice([TSExpression])
  /// Specifies precedence, and optionally associativity, for a given expression.
  case prec(Prec, TSExpression)

  public static func rule<T: Parsable>(_ type: T.Type) -> Self
    { .rule(T.symbolName, T.self) }

  /// Return the receiver's javascript representation.
  public var javascript : String {
    switch self {
      case .literal(let literal) :
        return "'" + literal + "'"
      case .pattern(let pattern) :
        return "/" + pattern + "/"
      case .rule(let name, _) :
        return "$.\(name)"
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
    }
  }
}
