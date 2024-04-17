/*

  Created by David Spooner

*/

@testable import TSKit
import ExprLang2


// Define the Expr type which represents our abstract syntax.

@Parsable
indirect enum Expr : ParsableByCases {
  case name(Name)
  case apply(Expr, [Expr])

  static var syntaxExpressionsByCaseName : [String : TSExpression] {
    return [
      "name"   : "\(Name.self)",
      "add"    : "\(prec:  .left(1)) \(Expr.self) \(lit: ["+", "-"]) \(Expr.self)",
      "mul"    : "\(prec:  .left(2)) \(Expr.self) \(lit: ["*", "/"]) \(Expr.self)",
      "pow"    : "\(prec: .right(3)) \(Expr.self) \(lit: ["^"]) \(Expr.self)",
      "neg"    : "\(prec:  .none(4)) \(lit: ["-"]) \(Expr.self)",
      "apply"  : "\(prec:  .none(5)) \(Expr.self) ( \(opt: ExprList.self) )",
      "paren"  : "( \(Expr.self) )",
    ]
  }

  static func add(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), [lhs, rhs]) }
  static func mul(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), [lhs, rhs]) }
  static func pow(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), [lhs, rhs]) }
  static func neg(_ op: String, _ arg: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), [arg]) }
  static func apply(_ fun: Expr, _ args: ExprList?) -> Self
    { .apply(fun, args?.elements ?? []) }
  static func paren(_ expr: Expr) -> Self
    { expr }
}


// Define a method to create an expression by parsing a string.

extension Expr {
  init(text: String) throws {
    // Create a parser for the defined language.
    let parser = TSParser(TSLanguage(tree_sitter_ExprLang()))
    // Get the parse tree for the given text; this can return nil if parsing is cancelled.
    guard let tree = parser.parse(text)
      else { throw TSError("parser failed to return a syntax tree for '\(text)'") }
    // Throw if the parse tree contains errors.
    guard tree.rootNode.hasError == false
      else { throw TSError("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    // The root node of the tree must derive from the start rule and have a single child.
    let startNode = tree.rootNode
    guard startNode.type == Grammar.startSymbol, startNode.count == 1
      else { throw TSError("root node has unexpected type (\(startNode.type)) and/or count \(startNode.count)") }
    // Delegate to the initializer parse tree nodes...
    self.init(parseTree: startNode[0], source: tree.inputSource)
  }
}


// Define some convenience methods to make test cases more legible.

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(text: text))
  }
}


// Synthesize structual equality to enable comparing parsed and expected expressions.

extension Expr : Equatable {
}
