#if false

import XCTest
import SwiftTreeSitter


class ExprTests : XCTestCase
  {
    func testParsing() throws {
      let language = try STSLanguage(fromPreBundle: .funlang)
      let parser = STSParser(language: language)

      let examples : [(text: String, expr: Expr)] = [
        ("a", .name("a")),
        ("1", .numb(1)),
        ("a + b", .add(.name("a"), .name("b"))),
        ("-4", .neg(.numb(4))),
        ("(a)", .name("a")),
        ("1 + a * 3 ^ -b", .add(.numb(1), .mult(.name("a"), .pow(.numb(3), .neg(.name("b")))))),
      ]
      for eg in examples {
        let expr = try Expr(eg.text)
        XCTAssertEqual(expr, eg.expr)
      }
    }

    func testEvaluation() throws {
      let examples : [(text: String, value: Int)] = [
        ("2 * 3 + 4", 10),
        ("-2 * 4 ^ 2", -32),
        ("2 ^ 0", 1),
        ("2 ^ 1", 2),
        ("2 ^ 3", 8),
      ]
      for eg in examples {
        let expr = try Expr(eg.text)
        let value = try expr.evaluate()
        XCTAssertEqual(value, eg.value)
      }
    }
  }

#endif
