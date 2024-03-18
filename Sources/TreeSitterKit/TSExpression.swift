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

  public static func list<T: Parsable>(_ t: T.Type, separator: Separator = .comma, brackets: Brackets? = .round) -> Self
    { .prod(.list(ParsableProxy(T.self), separator, brackets)) }


  public static func infix<L: Parsable, R: Parsable>(_ prec: TSExpression.Prec, _ op: String..., lhs: L.Type, rhs: R.Type) -> Self
    { .prec(prec, .seq([.prod(L.self), .choice(op.map {.literal($0)}), .prod(R.self)])) }

  public static func prefix<T: Parsable>(_ prec: TSExpression.Prec, _ op: String..., arg: T.Type) -> Self
    { .prec(prec, .seq([.choice(op.map {.literal($0)}), .prod(T.self)])) }


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
