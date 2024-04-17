/*

  Created by David Spooner

*/

import XCTest
import TSKit
import ExprLang2


class ExprLang2Tests : XCTestCase {

  /// Use this to generate the text of Sources/Xamples/TypedLang/grammar.js
  func testGenerateGrammar() throws {
    print(Grammar(name: "ExprLang", rootType: Expr.self).javascript)
  }

  /// Ensure the result of parsing is as expected for a variety of example terms...
  func testParsingSuccess() throws {
    let examples : [(text: String, term: Expr)] = [
      ("a",
        .name("a")),
      ("_aX2",
        .name("_aX2")),
      ("(a)",
        .name("a")),
      ("x + y",
        .apply("+", ["x", "y"])),
      ("x + y + z",
        .apply("+", [.apply("+", ["x", "y"]), "z"])),
      ("x + (y + z)",
        .apply("+", ["x", .apply("+", ["y", "z"])])),
      ("-x",
        .apply("-", ["x"])),
      ("--x",
        .apply("-", [.apply("-", ["x"])])),
      ("x + y * z ^ -w",
        .apply("+", ["x", .apply("*", ["y", .apply("^", ["z", .apply("-", ["w"])])])])),
      ("f()",
        .apply("f", [])),
      ("f(x)",
        .apply("f", ["x"])),
      ("g(x, y + z, w)",
        .apply("g", ["x", .apply("+", ["y", "z"]), "w"])),
      ("f(x)(y)",
        .apply(.apply("f", ["x"]), ["y"])),
      ("f() + g()",
        .apply("+", [.apply("f", []), .apply("g", [])])),
    ]
    for eg in examples {
      XCTAssertEqual(try Expr(text: eg.text), eg.term, eg.text)
    }
  }

  /// Ensure that parsing fails for various malformed strings...
  func testParsingFailure() throws {
    let examples : [String] = [
      "12",     // no numbers
      "x + ",   // missing rhs arg
      "x % y",  // unknown symbol '%'
      "()",     // no tuples
      "(a, b)", // no tuples
      "( x",
      "x )",
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
