/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing a block -- i.e. a sequence of definitions followed by an expression.

struct Block : Equatable {
  let decls : [Def]
  let expr : Expr
}

extension Block : Parsable {
  typealias DefList = DelimitedSequence<Def, Semicolon>

  static var syntaxExpression : TSExpression {
    "\(optional: "\(DefList.self)") \(Expr.self)"
  }

  static func from(_ node: TSNode) -> Self {
    let k = node.count; assert(k == 1 || k == 2)
    return .init(
      decls: k == 2 ? [Def](node[0], delimiter: Semicolon.symbol) : [],
      expr: Expr.from(node[k == 2 ? 1 : 0])
    )
  }
}

extension Block {
  /// A convenience method for initializing an instance by parsing text.
  init(_ text: String) throws {
    guard let tree = FunLang.parser.parse(text)
      else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw TSException("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self = Self.from(tree.rootNode)
  }
}
