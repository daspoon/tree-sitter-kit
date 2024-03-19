/*

  Created by David Spooner

*/

import TreeSitterKit


/// A parsable type representing identifier names within expressions.

struct Name : Equatable, Parsable {
  let text : String

  static var syntaxExpression : TSExpression {
    .pattern("[a-zA-Z_]+[0-9a-zA-Z_]*")
  }

  init(_ node: TSNode) {
    text = node.stringValue!
  }
}


// Allow initialization by string literal to make test cases more legible.
extension Name : ExpressibleByStringLiteral {
  init(stringLiteral: StringLiteralType) {
    text = stringLiteral
  }
}
