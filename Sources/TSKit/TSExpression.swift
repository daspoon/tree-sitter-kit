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
  case prod(ProductionRule)
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
    { .prod(ProductionRule(for: T.self)) }

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
      case .prod(let rule) :
        return "$.\(rule.symbolName)"
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


// Allow creating TSExpression from string literals with embedded captures.

extension TSExpression : ExpressibleByStringInterpolation {
  /// Build a sequence of literal and capture expressions. Captures are wrapped in field expressions named by increasing numeric indices (beginning at zero).
  public struct StringInterpolation : StringInterpolationProtocol {
    var precedence : Prec?
    var components : [TSExpression]
    var captureCount : Int

    public init(literalCapacity: Int, interpolationCount: Int) {
      components = []
      captureCount = 0
    }

    /// Called by each interpolation method to wrap the component expression in a field to enable extraction.
    private mutating func appendCapture(_ expr: TSExpression) {
      components.append(.field("\(captureCount)", expr))
      captureCount += 1
    }

    /// Add a literal component corresponding to the given string with leading and trailing whitespace removed.
    public mutating func appendLiteral(_ literal: String) {
      let literal = literal.trimmingCharacters(in: .whitespaces)
      if literal != "" {
        components.append(.literal(literal))
      }
    }

    /// Add a component to capture an instance of the given type.
    public mutating func appendInterpolation<T: Parsable>(_: T.Type) {
      appendCapture(.prod(T.self))
    }

    /// Add a component to capture a one of the given strings literals.
    public mutating func appendInterpolation(lit symbols: [String]) {
      appendCapture(.choice(symbols.map {.literal($0)}))
    }

    /// Add a component to capture an optional instance of the given type.
    public mutating func appendInterpolation<T: Parsable>(opt _: T.Type) {
      appendCapture(.optional(.prod(T.self)))
    }

    /// Establish the precedence of the expression. This has no associated capture, has no effect the field labels of captures, and must be specified as the first interpolation segment.
    public mutating func appendInterpolation(prec: Prec) {
      assert(precedence == nil && components.count == 0)
      precedence = prec
    }

    /// Return the sequence of accumulated components, or the sole component if there is exactly one.
    var expression : TSExpression {
      let expr = components.count == 1 ? components[0] : .seq(components)
      return precedence.map {.prec($0, expr)} ?? expr
    }
  }

  public init(stringInterpolation interpolation: StringInterpolation) {
    self = interpolation.expression
  }

  public init(stringLiteral literal: String) {
    self = .literal(literal)
  }
}
