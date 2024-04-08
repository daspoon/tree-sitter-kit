/*

  Created by David Spooner

*/

@testable import TSKit
import FuncLang


@Parsable
indirect enum Expr : Equatable, ParsableByCases {
  case numb(Int)
  case name(Name)
  case tuple([Expr])
  case apply(Expr, Expr)
  case lambda(Name?=nil, [Name], Expr)
  case cond(Expr, Expr, Expr)

  static var syntaxExpressionsByCaseName : [String : TSExpression] {
    return [
      "name"   : "\(Name.self)",
      "numb"   : "\(Int.self)",
      "paren"  : "\(ExprList.self)",
      "eql"    : "\(prec: .eql) \(Expr.self) \(lit: ["=="]) \(Expr.self)",
      "add"    : "\(prec: .add) \(Expr.self) \(lit: ["+", "-"]) \(Expr.self)",
      "mul"    : "\(prec: .mul) \(Expr.self) \(lit: ["*", "/"]) \(Expr.self)",
      "pow"    : "\(prec: .pow) \(Expr.self) \(lit: ["^"]) \(Expr.self)",
      "neg"    : "\(prec: .neg) \(lit: ["-"]) \(Expr.self)",
      "apply"  : "\(prec: .apply) \(Expr.self) \(ExprList.self)",
      "lambda" : "! \(opt: Name.self) \(NameList.self) . \(Expr.self)",
      "cond"   : "if \(Expr.self) { \(Expr.self) } else { \(Expr.self) }",
    ]
  }

  // Define constructors for production rules which are not enum case names...
  // Note that the static func 'apply' exists because case 'apply' has a different signature than the production rule.

  static func paren(_ list: ExprList) -> Self
    { list.elements.count == 1 ? list.elements[0] : .tuple(list.elements) }
  static func eql(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }
  static func add(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }
  static func mul(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }
  static func pow(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }
  static func neg(_ op: String, _ arg: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), arg) }
  static func apply(_ fun: Expr, _ args: ExprList) -> Self
    { .apply(fun, .paren(args)) }
  static func lambda(_ name: Name?, _ params: NameList, _ expr: Expr) -> Self
    { .lambda(name, params.elements, expr) }
}


// Define an auxiliary type to capture sequences of Expr separated by commas and enclosed in parentheses.
// Note that tree-sitter prohibits productions which can match the empty string, so the parentheses are specified here rather than in the calling production.

typealias ExprList = SeparatedSequence<Expr, Comma, Parentheses>


// Define operator precedence symbolically

extension TSExpression.Prec {
  static var eql : Self   {  .left(1) }
  static var add : Self   {  .left(2) }
  static var mul : Self   {  .left(3) }
  static var pow : Self   { .right(4) }
  static var neg : Self   {  .none(5) }
  static var apply : Self {  .left(6) }
}


// To simplify testing, define a method to create an Expr by parsing a string.

extension Expr {
  /// Create an instance by parsing a string, throwing if the string is malformed.
  init(text: String) throws {
    let parser = TSParser(tree_sitter_FuncLang())
    guard let tree = parser.parse(text)
      else { throw Exception("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw Exception("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self.init(parseTree: tree.rootNode)
  }
}


// Define some convenience methods to make test cases more legible.

/// Enable implicit conversion of a string literal to a 'name' Expr.
extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(stringLiteral: text))
  }
}

/// Enable implicit conversion of an integer literal to a 'numb' Expr.
extension Expr : ExpressibleByIntegerLiteral {
  init(integerLiteral value: Int) {
    self = .numb(value)
  }
}

/// Enable implicit conversion of a array literal to a 'tuple' Expr.
extension Expr : ExpressibleByArrayLiteral {
  init(arrayLiteral terms: Expr...) {
    self = .tuple(terms)
  }
}
