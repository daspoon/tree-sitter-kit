/*

  Created by David Spooner

*/

import XCTest
import TreeSitterKit


class FunLangTests : XCTestCase
  {
    /// Use this to generate the text of Sources/FunLang/grammar.js
    func testGenerateGrammar() throws {
      print(Grammar.javascript(named: "FunLang", for: (Expr.self, Name.self, Int.self, [Expr].self)))
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
        ("a",
          .name("a")),
        ("1",
          .numb(1)),
        ("a + b",
          .infix_op("+", "a", "b")),
        ("-4",
          .prefix_op("-", 4)),
        ("(a)",
          .name("a")),
        ("1 + a * 3 ^ -b",
          .infix_op("+", 1, .infix_op("*", "a", .infix_op("^", 3, .prefix_op("-", "b"))))),
        ("f 1",
          .apply("f", 1)),
        ("f 1 2 3",
          .apply(.apply(.apply("f", 1), 2), 3)),
        ("f (g (h x))",
          .apply("f", .apply("g", .apply("h", "x")))),
        ("!x. x",
          .lambda("x", "x")),
        ("!x. x y",
          .lambda("x", .apply("x", "y"))),
        ("(!x.x + 1) 2",
          .apply(.lambda("x", .infix_op("+", "x", 1)), 2)),
        ("p.1 x",
          .apply(.project("p", 1), "x")),
        ("f p.1",
          .apply("f", .project("p", 1))),
        ("p.1 + p.2",
          .infix_op("+", .project("p", 1), .project("p", 2))),
      ]
      for eg in examples {
        let expr = try Expr(eg.text)
        XCTAssertEqual(expr, eg.expr, eg.text)
      }
    }
  }
