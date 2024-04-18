/*

  Created by David Spooner

*/

import TSKit


/// A parsable type representing identifier names within expressions.

struct Name : Equatable, Parsable {
  let text : String

  static var syntaxExpression : TSExpression {
    .pattern("[a-zA-Z_]+[0-9a-zA-Z_]*")
  }

  init(parseTree node: TSNode, context ctx: ParsingContext) {
    self.init(stringLiteral: ctx.inputSource.text(for: node))
  }
}


// Allow initialization by string literal to make test cases more legible.
extension Name : ExpressibleByStringLiteral {
  init(stringLiteral: StringLiteralType) {
    text = stringLiteral
  }
}
