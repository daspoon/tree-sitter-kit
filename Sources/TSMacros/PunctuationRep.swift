/*

*/

import SwiftSyntax
import TSCommon


enum Punctuation {
  case sep(String)
  case del(String)
}


extension Punctuation {
  /// Attempt to create an instance from a Swift syntax expression.
  init(exprSyntax: ExprSyntax) throws {
    guard let (name, args) = try exprSyntax.caseComponents, args.count == 1
      else { throw Exception("expecting Punctuation syntax") }
    guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
      else { throw Exception("expecting string literal argument") }
    switch (name, args.count) {
      case ("sep", 1) :
        self = .sep(string)
      case ("del", 1) :
        self = .del(string)
      default :
        throw Exception("invalid Punctuation syntax")
    }
  }
}
