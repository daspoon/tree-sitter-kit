/*

  Created by David Spooner

*/

import XCTest


// MARK: --

/// The *Rule* type serves as a syntax for specifying production rules for language elements,
/// pairing syntax expressions with instance constructors.
public struct GrammarRule {
  /// An analogue of tree-sitter syntax expressions.
  public indirect enum Expression {
    public enum Punctuation { case sep(String), del(String) }
    case lit(String)
    case pat(String)
    case sym(Any.Type)
    case opt(Expression)
    case rep(Expression, Punctuation?=nil)
    case seq([Expression])
    case prec(Precedence, Expression)
  }
  /// An analogue of tree-sitter precedence specifications.
  public enum Precedence : ExpressibleByIntegerLiteral {
    case none(Int), left(Int), right(Int)
    public init(integerLiteral i: Int)
      { self = .none(i) }
  }

  /// Specify a production rule for language element `T` as a single syntax expression along
  /// a constructor for `T` (i.e. a function taking the captures of the syntax expression and
  /// returning an instance of `T`).
  public init<T, each A>(_ type: T.Type, _ expression: Expression, constructor f: @escaping (repeat each A) throws -> T) { }

  /// Specify a production rule for language element `T` as a choice of syntax expressions
  /// along with the corresponding constructors.
  public init<T>(_ type: T.Type, choicesByName: [String: Choice<T>]) { }

  /// A pairing of syntax expression and constructor.
  public struct Choice<T> {
    public init<each A>(_ expression: Expression, _ constructor: (repeat each A) throws -> T) { }
  }
}


extension GrammarRule.Expression {
  indirect enum Capture : CustomStringConvertible {
    case sym(Any.Type)
    case opt(Capture)
    case arr(Capture)
    case tup([Capture])
    var description : String {
      return switch self {
        case .sym(let type) : "\(type)"
        case .opt(let captype) : "Optional<\(captype.description)>"
        case .arr(let captype) : "Array<\(captype.description)>"
        case .tup(let captypes) : "(" + captypes.map({$0.description}).joined(separator: ", ") + ")"
      }
    }
  }
  var capture : Capture? {
    return switch self {
      case .lit : nil
      case .pat : .sym(String.self)
      case .sym(let t) : .sym(t)
      case .opt(let e) : e.capture.map { .opt($0) }
      case .rep(let e, _) : e.capture.map { .arr($0) }
      case .seq(let es) : {$0.count > 0 ? .tup($0) : nil}(es.compactMap {$0.capture})
      case .prec(_, let e) : e.capture
    }
  }
}


// MARK: --

struct ExampleGrammar {
  indirect enum Expr : Equatable {
    case name(Name)
    case value(Int)
    case apply(Expr, [Expr])
    static func op(_ name: String, _ args: [Expr]) -> Self {
      .apply(.name(Name(text: name)), args)
    }
  }

  struct ExprList : Equatable {
    typealias Element = Expr
    static var separator : String { "," }
    let elements : [Element]
  }

  struct Name : Equatable {
    let text : String
  }

  struct Value : Equatable {
    let int : Int
  }

  static var productionRules : [GrammarRule] = [
    .init(Expr.self, choicesByName: [
      "name": .init(.sym(Name.self)) { name in .name(name) },
      "add": .init(.prec(.left(1), .seq([.sym(Expr.self), .pat("(+|-)"), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
      "mul": .init(.prec(.left(2), .seq([.sym(Expr.self), .pat("(*|/)"), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
      "pow": .init(.prec(.right(3), .seq([.sym(Expr.self), .pat("(^)"), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
      "neg": .init(.prec(.left(4), .seq([.pat("-"), .sym(Expr.self)]))) { op, arg in .op(op, [arg]) },
      "call": .init(.prec(5, .seq([.sym(Expr.self), .lit("("), .opt(.sym(ExprList.self)), .lit(")")]))) { (fun, args: ExprList?) in .apply(fun, args?.elements ?? []) },
      "paren": .init(.seq([.lit("("), .sym(Expr.self), .lit(")")])) { expr in expr },
    ]),
    .init(ExprList.self, .rep(.sym(Expr.self), .sep(","))) { exprs in .init(elements: exprs) },
    .init(Name.self, .pat("[a-zA-Z_][0-9a-zA-Z_]*")) { string in Name(text: string) },
    .init(Value.self, .sym(Value.self)) { i in .init(int: i) },
    .init(Int.self,  .pat("[0-9]+")) { string in Int(string)! },
  ]
}
