/*

  Created by David Spooner

*/

import XCTest
import TSKit
import ArithLang


class ArithLangTests : XCTestCase {
  /// Define a method to create an Expr by parsing a string.
  func parseExpr(_ text: String) throws -> Expr {
    let parser = TSParser(tree_sitter_ArithLang())
    guard let tree = parser.parse(text)
      else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
    guard tree.rootNode.hasError == false
      else { throw TSException("error in parse tree for '\(text)': \(tree.rootNode.description)") }
    return Expr(parseTree: tree.rootNode)
  }

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
      XCTAssertEqual(try parseExpr(eg.text), eg.term, eg.text)
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
        _ = try parseExpr(text)
        XCTFail("Failed to reject '\(text)'")
      }
      catch {
        continue
      }
    }
  }
}
