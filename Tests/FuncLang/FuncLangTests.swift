/*

  Created by David Spooner

*/

import XCTest
import TSKit
import FuncLang


class FuncLangTests : XCTestCase {

  /// Use this to generate the text of Sources/Xamples/FuncLang/grammar.js
  func testGenerateGrammar() throws {
    print(Grammar<Expr>(name: "FuncLang").javascript)
  }

  /// Ensure the result of parsing is as expected for a variety of example terms...
  func testParsingSuccess() throws {
    let examples : [(text: String, term: Expr)] = [
      ("()",
        .tuple([])),
      ("(42)",
        .numb(42)),
      ("(1, 2, 3)",
        .tuple([1, 2, 3])),
      ("f()",
        .apply("f", [])),
      ("f(1)",
        .apply("f", 1)),
      ("f(1, 2, 3)",
        .apply("f", [1, 2, 3])),
      ("1 + 2 == 3",
        .apply("==", [.apply("+", [1, 2]), 3])),
      ("if yes { 1 } else { 0 }",
        .cond("yes", 1, 0)),
      ("!().1",
        .lambda(nil, [], 1)),
      ("!(x, y, z).x * y + z",
        .lambda(nil, ["x", "y", "z"], .apply("+", [.apply("*", ["x", "y"]), "z"]))),
      ("!f(x).f(x)",
        .lambda("f", ["x"], .apply("f", "x"))),
      ("(!f(n).if n == 0 {1} else {n * f(n-1)})(5)",
        .apply(.lambda("f", ["n"], .cond(.apply("==", ["n", 0]), 1, .apply("*", ["n", .apply("f", .apply("-", ["n", 1]))]))), 5)),
    ]
    for eg in examples {
      XCTAssertEqual(try Expr(text: eg.text), eg.term, eg.text)
    }
  }

  /// Ensure that parsing fails for various malformed strings...
  func testParsingFailure() throws {
    let examples : [String] = [
      "a b",
      "1 + ",
      "3 % 1",
      "(a b)",
      "(a, )",
      "( a",
      "a )",
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
