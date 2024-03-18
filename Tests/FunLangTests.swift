/*

  Created by David Spooner

*/

import XCTest
import TreeSitterKit


class FunLangTests : XCTestCase
  {
    /// Use this to generate the text of Sources/FunLang/grammar.js
    func testGenerateGrammar() throws {
      print(Grammar<Expr>(name: "FunLang").javascript)
    }

    /// Use this as a convenience to print the parse trees for various expressions.
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
        ("()",
          .tuple([])),
        ("(a)",
          .name("a")),
        ("(a, b)",
          .tuple(["a", "b"])),
        ("1 + a * 3 ^ -b",
          .infix_op("+", 1, .infix_op("*", "a", .infix_op("^", 3, .prefix_op("-", "b"))))),
        ("f()",
          .apply("f", .tuple([]))),
        ("f(1)",
          .apply("f", 1)),
        ("f(1, 2, 3)",
          .apply("f", .tuple([1, 2, 3]))),
        ("f(g(x))",
          .apply("f", .apply("g", "x"))),
        ("!() -> Int. 1",
          .lambda([], "Int", 1)),
        ("!f() -> Int. 1",
          .mu("f", [], "Int", 1)),
        ("!(x:Int) -> Int. x + 1",
          .lambda([Param("x", "Int")], "Int", .infix_op("+", "x", 1))),
        ("!(f: Int -> Int, x: Int) -> Bool. f(x) == 0",
          .lambda([Param("f", .func("Int", "Int")), Param("x", "Int")], "Bool", .infix_op("==", .apply("f", "x"), 0))),
        ("!f(x:Int) -> Int. f(x)",
          .mu("f", [Param("x", "Int")], "Int", .apply("f", "x"))),
        ("(!(x: Int) -> Int. x + 1)(2)",
          .apply(.lambda([Param("x", "Int")], "Int", .infix_op("+", "x", 1)), 2)),
        ("p.1(x)",
          .apply(.project("p", 1), "x")),
        ("f(p.1)",
          .apply("f", .project("p", 1))),
        ("p.1 + p.2",
          .infix_op("+", .project("p", 1), .project("p", 2))),
        ("match f(x) { nil() => 1, cons(h,t) => 2 }",
          .match(.apply("f", "x"), [
            .init(name: "nil", expr: 1),
            .init(name: "cons", params: ["h", "t"], expr: 2),
          ])),
      ]
      for eg in examples {
        let expr = try Expr(eg.text)
        XCTAssertEqual(expr, eg.expr, eg.text)
      }
    }
  }
