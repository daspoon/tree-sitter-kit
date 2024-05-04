/*

  Created by David Spooner

*/

import TSKit


/// A parsable type representing identifier names within expressions.

struct Name : Equatable {
  let text : String
}


extension Name : Parsable {
  static var productionRule : ProductionRule<Name> {
    .init(
      syntaxExpression: .pattern("[a-zA-Z_]+[0-9a-zA-Z_]*"),
      constructor: { node, ctx in
        Self(text: ctx.inputSource.text(for: node))
      }
    )
  }
}


// Allow initialization by string literal to make test cases more legible.
extension Name : ExpressibleByStringLiteral {
  init(stringLiteral: StringLiteralType) {
    text = stringLiteral
  }
}
