/*

*/

import XCTest
import TSKit
import TSCommon


class ExprLangTests : XCTestCase {

  /// Ensure the result of parsing is as expected for a variety of example terms...
  func testParsingSuccess() throws {
    let examples : [(text: String, term: Expr)] = [
      ("a",
        .name("a")),
      ("_aX2",
        .name("_aX2")),
      ("42",
        .value(42)),
      ("(a)",
        .name("a")),
      ("x + y",
        .apply("+", ["x", "y"])),
      ("x + y + z",
        .apply("+", [.apply("+", ["x", "y"]), "z"])),
      ("x + (y + z)",
        .apply("+", ["x", .apply("+", ["y", "z"])])),
      ("x ^ y ^ z",
        .apply("^", ["x", .apply("^", ["y", "z"])])),
      ("(x ^ y) ^ z",
        .apply("^", [.apply("^", ["x", "y"]), "z"])),
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
      XCTAssertEqual(try ExprLang.parse(text: eg.text), eg.term, eg.text)
    }
  }

  /// Ensure that parsing fails for various malformed strings...
  func testParsingFailure() throws {
    let examples : [String] = [
      "x + ",   // missing rhs arg
      "x % y",  // unknown symbol '%'
      "()",     // no tuples
      "(a, b)", // no tuples
      "( x",
      "x )",
    ]
    for text in examples {
      do {
        _ = try ExprLang.parse(text: text)
        XCTFail("Failed to reject '\(text)'")
      }
      catch {
        continue
      }
    }
  }

  /// Ensure simple syntax errors are reported as expected...
  func testSyntaxErrors() throws {
    guard let sym_Expr = ExprLang.symbol(for: Expr.self)
      else { throw Exception("No Expr symbol?") }

    let examples : [(text: String, error: SyntaxError)] = [
      ("x +", .init(range: 3 ..< 3, kind: .missing(sym_Expr))),
      ("()", .init(range: 1 ..< 1, kind: .missing(sym_Expr))),
    ]
    let parser = TSParser(ExprLang.language)
    for eg in examples {
      let tree = parser.parse(eg.text)!
      let errors = ExprLang.syntaxErrors(in: tree, for: eg.text)
      XCTAssertEqual(errors, [eg.error])
    }
  }
}
