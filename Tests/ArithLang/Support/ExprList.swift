/*

  Created by David Spooner

*/

import TSKit


// A non-empty sequence of Expr separated by commas.

struct ExprList {
  let elements : [Expr]

  init(elements: [Expr]) {
    self.elements = elements
  }

  init(parseTree node: TSNode) {
    let n = node.count
    assert(n > 0 && n % 2 == 1)
    elements = stride(from: 0, to: n, by: 2)
      .map { i in Expr(parseTree: node[i]) }
  }

  /// The represented expression is either the sole element or a tuple of two or more elements.
  var expr : Expr {
    elements.count == 1 ? elements[0] : .tuple(elements)
  }
}
