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

  /// Used to specify the bracket symbols which enclose list elements.
  public struct Brackets : Hashable {
    public let name : String
    public let lhs : String
    public let rhs : String
    public init(name n: String, lhs l: String, rhs r: String)
      { name = n; lhs = l; rhs = r }
  }

  /// Used to specify the symbols separating list elements.
  public struct Separator : Hashable {
    public let name : String
    public let text : String
    public init(name n: String, text t: String)
      { name = n; text = t }
  }

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


  public static func prod<T: Parsable>(_ type: T.Type) -> Self
    { .prod(.value(ParsableProxy(T.self))) }


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
    }
  }
}


extension TSExpression.Brackets {
  public static let angle = Self(name: "angle", lhs: "<", rhs: ">")
  public static let curly = Self(name: "curly", lhs: "{", rhs: "}")
  public static let round = Self(name: "round", lhs: "(", rhs: ")")
  public static let square = Self(name: "square", lhs: "[", rhs: "]")
}


extension TSExpression.Separator {
  public static let comma = Self(name: "comma", text: ",")
  public static let semicolon = Self(name: "semicolon", text: ";")
}


extension TSExpression : ExpressibleByStringInterpolation {
  /// Build a sequence of literal and production expressions...
  public struct StringInterpolation : StringInterpolationProtocol {
    var components : [TSExpression]

    public init(literalCapacity: Int, interpolationCount: Int) {
      components = []
    }

    /// Add a literal component corresponding to the given string with leading and trailing whitespace removed.
    public mutating func appendLiteral(_ literal: String) {
      let literal = literal.trimmingCharacters(in: .whitespaces)
      if literal != "" {
        components.append(.literal(literal))
      }
    }

    /// Add a production component for the given type.
    public mutating func appendInterpolation<T: Parsable>(_: T.Type) {
      components.append(.prod(T.self))
    }

    /// Add a choice of literals  matching any of the given strings.
    public mutating func appendInterpolation(_ symbols: String...) {
      components.append(.choice(symbols.map {.literal($0)}))
    }

    /// Add an optional expression.
    public mutating func appendInterpolation(optional expr: TSExpression) {
      components.append(.optional(expr))
    }

    /// Return the sequence of accumulated components, or the sole component if there is exactly one.
    var expression : TSExpression {
      components.count == 1 ? components[0] : .seq(components)
    }
  }

  public init(stringInterpolation interpolation: StringInterpolation) {
    self = interpolation.expression
  }

  public init(stringLiteral literal: String) {
    self = .literal(literal)
  }
}
