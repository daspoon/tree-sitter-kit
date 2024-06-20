/*

  Created by David Spooner

  Methods added to various types from the Swift standard library.

*/

import SwiftSyntax
import TSCommon


extension BinaryInteger {
  public mutating func postincrement() -> Self {
    defer { self += 1 }
    return self
  }
}

// MARK: -

extension Collection {
  public var only : Element? {
    count == 1 ? first : nil
  }
}

// MARK: -

extension Int {
  init(exprSyntax: ExprSyntax) throws {
    guard let literal = exprSyntax.as(IntegerLiteralExprSyntax.self)?.literal
      else { throw Exception("expecting integer literal") }
    guard let intValue = Self(literal.text)
      else { throw Exception("failed to interpret integer literal: \(literal)") }
    self = intValue
  }
}
