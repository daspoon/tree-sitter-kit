/*

  Created by David Spooner

*/

import XCTest
import TreeSitterKit


class FunLangTests : XCTestCase
  {
    /// Use this to generate the text of Sources/FunLang/grammar.js
    func testGenerateGrammar() throws {
      print(Grammar.javascript(named: "FunLang", for: (Expr.self, Name.self, Int.self)))
    }

    /// Print the parse tree for various expressions.
    func testParseTree() throws {
      let examples : [String] = [
        "a + b * c"
      ]
      for text in examples {
        guard let tree = Expr.parser.parse(text)
          else { XCTFail("parser failed to return a syntax tree for '\(text)'"); continue }
        print("'\(text)' => \(tree.rootNode)")
      }
    }

    /// Test the translation of various parse trees into *Expr* instances.
    func testParsing() throws {
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
