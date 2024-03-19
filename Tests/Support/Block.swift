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
  static var syntaxExpression : TSExpression {
    .seq([.optional(.listd(Def.self, .semicolon)), .prod(Expr.self)])
  }

  init(_ node: TSNode) {
    let k = node.count; assert(k == 1 || k == 2)
    decls = k == 2 ? [Def](node[0], delimiter: .semicolon) : []
    expr = Expr(node[k == 2 ? 1 : 0])
  }
}

extension Block {
  /// A convenience method for initializing an instance by parsing text.
  init(_ text: String) throws {
    guard let tree = FunLang.parser.parse(text)
      else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw TSException("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    self.init(tree.rootNode)
  }
}
