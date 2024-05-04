/*

  Created by David Spooner

*/


/// *TSExpression* represents a syntax expression within a tree-sitter grammar.
public indirect enum TSExpression {
  /// A token matching a specific string.
  case literal(String)
  /// A token matching a regular expression.
  case pattern(String)
  /// A production rule for a specific *Parsable* type.
  case prod(Symbol)
  /// A sequence of expressions.
  case seq([TSExpression])
  /// A choice of possible expressions.
  case choice([TSExpression])
  /// An optional expression.
  case optional(TSExpression)
  /// Zero or more repetitions of an expression.
  case `repeat`(TSExpression)
  /// Specifies precedence, and optionally associativity, for a given expression.
  case prec(Prec, TSExpression)
  /// Annotate an expression with a field name.
  case field(String, TSExpression)

  /// A type specifying precedence and associativity.
  public enum Prec {
    case none(Int), left(Int), right(Int)
  }
}


extension TSExpression {
  /// Return an expression which matches a value of the given type.
  public static func prod<T: Parsable>(_ type: T.Type) -> Self
    { .prod(.value(.init(T.self))) }

  /// Return an expression which matches a non-empty sequence of the given expression, with elements separated by the given string literal. E.g. "a, b, c".
  public static func repeat1(_ expr: Self, separator: String) -> Self
    { .seq([expr, .repeat(.seq([.literal(separator), expr]))]) }

  /// Return an expression which matches a non-empty sequence of the given expression, with elements delimited by the given string literal. E.g. "a; b;".
  public static func repeat1(_ expr: Self, delimiter: String) -> Self
    { .seq([expr, .literal(delimiter), .repeat(.seq([expr, .literal(delimiter)]))]) }

  /// Return the receiver's javascript representation.
  public var javascript : String {
    switch self {
      case .literal(let literal) :
        return "'" + literal + "'"
      case .pattern(let pattern) :
        return "/" + pattern + "/"
      case .prod(let symbol) :
        return "$.\(symbol.name)"
      case .seq(let elements) :
        return "seq(\(elements.map({$0.javascript}).joined(separator: ", ")))"
      case .choice(let elements) :
        return "choice(\(elements.map({$0.javascript}).joined(separator: ", ")))"
      case .optional(let expr) :
        return "optional(\(expr.javascript))"
      case .repeat(let expr) :
        return "repeat(\(expr.javascript))"
      case .prec(.none(let n), let expr) :
        return "prec(\(n), \(expr.javascript))"
      case .prec(.left(let n), let expr) :
        return "prec.left(\(n), \(expr.javascript))"
      case .prec(.right(let n), let expr) :
        return "prec.right(\(n), \(expr.javascript))"
      case .field(let name, let expr) :
        return "field('\(name)', \(expr.javascript))"
    }
  }
}


// Allow creating Prec with associativity *none* as integer literals.

extension TSExpression.Prec : ExpressibleByIntegerLiteral {
  public init(integerLiteral value: Int)
    { self = .none(value) }
}
