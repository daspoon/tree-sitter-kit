/*

  Created by David Spooner

*/


/// The *ProductionRule* type serves as a syntax for specifying production rules for language elements,
/// pairing syntax expressions with instance constructors.
public struct ProductionRule {
  /// An analogue of tree-sitter syntax expressions.
  public indirect enum Expression {
    case lit(String)
    case pat(String)
    case sym(Any.Type)
    case alt([String])
    case opt(Expression)
    case rep(Expression, Punctuation?=nil)
    case seq([Expression])
    case prec(Precedence, Expression)
  }

  /// An analogue of tree-sitter precedence specifications.
  public enum Precedence {
    case none(Int), left(Int), right(Int)
  }

  public enum Punctuation { case sep(String), del(String) }

  /// Specify a production rule for language element `T` as a single syntax expression along
  /// a constructor for `T` (i.e. a function taking the captures of the syntax expression and
  /// returning an instance of `T`).
  public init<T, each A>(_ type: T.Type, _ expression: Expression, constructor f: (repeat each A) throws -> T) { }

  /// Specify a production rule for language element `T` as a choice of syntax expressions
  /// along with the corresponding constructors.
  public init<T>(_ type: T.Type, choicesByName: [String: Choice<T>]) { }

  /// A pairing of syntax expression and constructor.
  public struct Choice<T> {
    public init<each A>(_ expression: Expression, _ constructor: (repeat each A) throws -> T) { }
  }
}


extension ProductionRule.Expression : ExpressibleByStringLiteral {
  public init(stringLiteral s: String) {
    self = .lit(s)
  }
}


extension ProductionRule.Precedence : ExpressibleByIntegerLiteral {
  public init(integerLiteral i: Int)
    { self = .none(i) }
}
