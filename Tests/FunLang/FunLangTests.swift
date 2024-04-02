/*

  Created by David Spooner

*/

import XCTest
import TSKit


class FunLangTests : XCTestCase
  {
    /// Use this to generate the text of Sources/FunLang/grammar.js
    func testGenerateGrammar() throws {
      print(Grammar<Block>(name: "FunLang").javascript)
    }

    /// Test the translation of various parse trees into *Expr* instances.
    func testExpr() throws {
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
        ("{ 1 }",
          .block(.init(decls: [], expr: 1))),
        ("{ let x: Int = 1; x + 2 }",
          .block(.init(decls: [.let(.init(param: .init("x", "Int"), expr: 1))], expr: .infix_op("+", "x", 2)))),
      ]
      for eg in examples {
        let expr = try Expr(eg.text)
        XCTAssertEqual(expr, eg.expr, eg.text)
      }
    }

    func testDecl() throws {
      let examples : [(text: String, decl: Def)] = [
        // Let
        ("let x: Int = 1 + 2",
          .let(.init(param: .init("x", "Int"), expr: .infix_op("+", 1, 2)))),
        // Fun
        ("fun f() -> Int { 1 }",
          .fun(.init(name: "f", params: [], type: "Int", expr: 1))),
        ("fun f(x: X) -> X { f(x) }",
          .fun(.init(name: "f", params: [.init("x", "X")], type: "X", expr: .apply("f", "x")))),
        ("fun f(x: X, y: Y) -> Z { x + y }",
          .fun(.init(name: "f", params: [.init("x", "X"), .init("y", "Y")], type: "Z", expr: .infix_op("+", "x", "y")))),
        // Enum
        ("enum Bool { false, true }",
          .enum(.init(name: "Bool", cases: [
            .init(name: "false", params: []),
            .init(name: "true", params: []),
          ]))),
        ("enum OptionT { none, some(x: T) }",
          .enum(.init(name: "OptionT", cases: [
            .init(name: "none", params: []),
            .init(name: "some", params: [.init("x", "T")])
          ]))),
        ("enum ListT { nil, cons(head: T, tail: ListT) }",
          .enum(.init(name: "ListT", cases: [
            .init(name: "nil", params: []),
            .init(name: "cons", params: [.init("head", "T"), .init("tail", "ListT")])
          ]))),
        ("typedef MyType = Int",
          .typedef(.init(name: "MyType", type: "Int"))),
      ]
      for eg in examples {
        let decl = try Def(eg.text)
        XCTAssertEqual(decl, eg.decl, eg.text)
      }
    }

    func testBlock() throws {
      let examples : [(text: String, block: Block)] = [
        ("x * 2",
          .init(decls: [], expr: .infix_op("*", "x", 2))),
        ("let x: Int = 1; x + 2",
          .init(decls: [.let(.init(param: .init("x", "Int"), expr: 1))],
                expr: .infix_op("+", "x", 2))),
        ("let x: Int = 1; let y: Int = 2; x + y",
          .init(decls: [
                  .let(.init(param: .init("x", "Int"), expr: 1)),
                  .let(.init(param: .init("y", "Int"), expr: 2)),
                ],
                expr: .infix_op("+", "x", "y"))),
      ]
      for eg in examples {
        let block = try Block(eg.text)
        XCTAssertEqual(block, eg.block, eg.text)
      }
    }
  }
