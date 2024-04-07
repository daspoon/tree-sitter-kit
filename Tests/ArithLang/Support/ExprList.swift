/*

  Created by David Spooner

*/

import TSKit


// A non-empty sequence of Expr separated by commas
// The represented expression is either the sole element or the tuple of zero, two or more elements.

struct ExprList {
  let elements : [Expr]

  init(elements: [Expr]) {
    self.elements = elements
  }

  init(parseTree node: TSNode) {
    switch node.count {
      case 0 :
        elements = []
      case let n :
        assert(n > 0 && n % 2 == 1)
        elements = stride(from: 0, to: n, by: 2)
          .map { i in Expr(parseTree: node[i]) }
    }
  }

  var expr : Expr {
    elements.count == 1 ? elements[0] : .tuple(elements)
  }
}
