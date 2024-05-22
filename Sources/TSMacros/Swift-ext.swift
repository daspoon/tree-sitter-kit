/*

  Created by David Spooner

  Methods added to various types from the Swift standard library.

*/

import SwiftSyntax


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

// MARK: -

extension String {
  func removing(prefix p: String? = nil, suffix s: String? = nil) -> String {
    var trimmed = self
    if let prefix = p, let range = trimmed.range(of: prefix, options:.anchored) {
      trimmed = String(trimmed[range.upperBound ..< trimmed.endIndex])
    }
    if let suffix = s, let range = trimmed.range(of: suffix, options: [.anchored, .backwards]) {
      trimmed = String(trimmed[trimmed.startIndex ..< range.lowerBound])
    }
    return trimmed
  }
}
