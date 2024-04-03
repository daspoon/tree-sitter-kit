/*

  Created by David Spooner

*/

import XCTest
import TSKit
import ArithLang


class ArithLangTests : XCTestCase {
  /// Ensure the result of parsing is as expected for a variety of example terms...
  func testParsingSuccess() throws {
    let examples : [(text: String, term: Expr)] = [
      ("0",
        .numb(0)),
      ("123",
        .numb(123)),
      ("(42)",
        .numb(42)),
      ("1 + 2",
        .apply("+", [1, 2])),
      ("1 + 2 + 3",
        .apply("+", [.apply("+", [1, 2]), 3])),
      ("1 + (2 + 3)",
        .apply("+", [1, .apply("+", [2, 3])])),
      ("-4",
        .apply("-", 4)),
      ("--5",
        .apply("-", .apply("-", 5))),
      ("1 + 2 * 3 ^ -4",
        .apply("+", [1, .apply("*", [2, .apply("^", [3, .apply("-", 4)])])])),
    ]
    for eg in examples {
      XCTAssertEqual(try Expr(text: eg.text), eg.term, eg.text)
    }
  }

  /// Ensure that parsing fails for various malformed strings...
  func testParsingFailure() throws {
    let examples : [String] = [
      "x",      // no variables
      "1 + ",   // missing rhs arg
      "()",     // no empty tuples
      "(1, 2)", // no tuples
      "3 % 1",  // unknown symbol '%'
    ]
    for text in examples {
      do {
        _ = try Expr(text: text)
        XCTFail("Failed to reject '\(text)'")
      }
      catch {
        continue
      }
    }
  }
}
