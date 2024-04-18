/*

  Created by David Spooner

*/

import TSKit


// A type representing variable names within expressions.

struct Name : Equatable {
  let text : String

  init(text t: String) {
    text = t
  }

  init(parseTree node: TSNode, context ctx: ParsingContext) {
    self.init(text: ctx.inputSource.text(for: node))
  }
}


// Allow implicit conversion from a string literal to make test cases more legible.

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral s: String) {
    self.init(text: s)
  }
}
