/*

  Created by David Spooner

*/

import TSKit


// A type representing variable names within expressions.

struct Name : Equatable {
  let text : String
}


extension Name : Parsable {
  static var productionRule : ProductionRule<Self> {
    .init(syntaxExpression: .pattern("[a-zA-Z_][0-9a-zA-Z_]*")) { node, ctx in
      Self(text: ctx.inputSource.text(for: node))
    }
  }
}


// Allow implicit conversion from a string literal to make test cases more legible.

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral s: String) {
    self.init(text: s)
  }
}
