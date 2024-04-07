/*

  Created by David Spooner

*/

import TSKit


// A type representing variable names within expressions.

struct Name : Equatable {
  let text : String

  init(text: String) {
    self.text = text
  }

  init(parseTree node: TSNode) {
    self.init(text: node.stringValue!)
  }
}


// Allow implicit conversion from a string literal to make test cases more legible.

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral: StringLiteralType) {
    self.init(text: stringLiteral)
  }
}
