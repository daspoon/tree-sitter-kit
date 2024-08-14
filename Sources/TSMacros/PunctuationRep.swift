/*

*/

import SwiftSyntax


enum Punctuation {
  case sep(String)
  case del(String)
}


extension Punctuation {
  /// Attempt to create an instance from a Swift syntax expression.
  init(exprSyntax: ExprSyntax) throws {
    let (name, args) = try exprSyntax.caseComponents
    guard args.count == 1, let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
      else { throw ExpansionError(node: args[0].expression, message: "expecting one string literal argument") }
    switch (name, args.count) {
      case ("sep", 1) :
        self = .sep(string)
      case ("del", 1) :
        self = .del(string)
      default :
        throw ExpansionError(node: exprSyntax, message: "unsupported Punctuation syntax")
    }
  }
}
