/*

  Created by David Spooner

*/

@testable import TSKit
import ExprLang1


// Define the Expr type which represents our abstract syntax.

indirect enum Expr {
  case name(Name)
  case apply(Expr, [Expr])

  /// Create an Expr from a parse tree node.
  init(parseTree node: TSNode, context ctx: ParsingContext) {
    // Decide which case is represented based on the structure of the node...
    assert(ctx.language.symbolName(for: node) == "Expr" && node.count == 1)
    let node = node[0]
    switch ctx.language.symbolName(for: node) {
      case "Expr_name" :
        self = .name(Name(parseTree: node, context: ctx))
      case "Expr_add", "Expr_mul", "Expr_pow" :
        self = .apply(
          .name(Name(parseTree: node[1], context: ctx)),
          [Expr(parseTree: node[0], context: ctx), Expr(parseTree: node[2], context: ctx)]
        )
      case "Expr_neg" :
        self = .apply(
          .name(Name(parseTree: node[0], context: ctx)),
          [Expr(parseTree: node[1], context: ctx)]
        )
      case "Expr_apply" :
        let args = node["args"]
        self = .apply(
          Expr(parseTree: node[0], context: ctx),
          args.isNull ? [] : ExprList(parseTree: args, context: ctx).elements
        )
      case "Expr_paren" :
        self = Expr(parseTree: node[1], context: ctx)
      case let unexpected :
        fatalError("unexpected node type: \(unexpected)")
    }
  }
}


// Define a method to create an expression by parsing a string.

extension Expr {
  init(text: String, encoding: String.Encoding = .utf8) throws {
    let language = TSLanguage(tree_sitter_ExprLang())
    let parser = TSParser(language: language)
    guard let source = StringInputSource(string: text, encoding: encoding)
      else { throw TSError("unsupported string encoding: \(encoding)") }
    guard let tree = parser.parse(source)
      else { throw TSError("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw TSError("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self.init(parseTree: tree.rootNode, context: ParsingContext(language: language, inputSource: source))
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
