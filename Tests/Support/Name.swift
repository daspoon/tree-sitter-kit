/*

  Created by David Spooner

*/

import TreeSitterKit


// A parsable type representing identifier names within expressions.
struct Name : Equatable, ParsableInSequence {
  let text : String

  static var productionRule : ProductionRule<Self> {
    .single(.pattern("[a-z]+"))
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
