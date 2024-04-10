/*

  Created by David Spooner

*/

import TSKit


// A type representing variable names within expressions.

struct Name : Equatable, Parsable {
  let text : String

  init(text t: String) {
    text = t
  }

  static var syntaxExpression : TSExpression {
    .pattern("[a-zA-Z_][0-9a-zA-Z_]*")
  }

  init(parseTree node: TSNode) {
    self.init(text: node.stringValue!)
  }
}


// Allow implicit conversion from a string literal to make test cases more legible.

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral s: String) {
    self.init(text: s)
  }
}
