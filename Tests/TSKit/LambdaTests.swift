/*

*/

import XCTest
import TSKit


@Grammar
fileprivate struct LambdaCalculus : Grammar {
  typealias Root = Term
  static var productionRules : [ProductionRule] {
    return [
      .init(Term.self, choicesByName: [
        "name": .init(.sym(Name.self)) { x in
          .name(x)
        },
        "apply": .init(.prec(.left(1), .seq([.sym(Term.self), .sym(Term.self)]))) { t, u in
          .apply(t, u)
        },
        "lambda": .init(.seq(["λ", .sym(Name.self), ".", .sym(Term.self)])) { x, t in
          .lambda(x, t)
        },
        "paren": .init(.seq(["(", .sym(Term.self), ")"])) { t in
          t
        },
      ]),
      .init(Name.self, .pat("[a-zA-Z_]+")) { s
        in Name(text: s)
      },
    ]
  }
}

// --------------------------------------------------------------------------------

class LambdaTests : XCTestCase {
  func testBuild() throws {
  }

  func testSuccess() throws {
    let examples : [(text: String, term: Term)] = [
      ("x", "x"),
      ("x y", .apply("x", "y")),
      ("(x)", "x"),
      ("x y z", .apply(.apply("x", "y"), "z")),
      ("x (y z)", .apply("x", .apply("y", "z"))),
      ("λx. y", .lambda("x", "y")),
      ("λx. y z", .lambda("x", .apply("y", "z"))),
      ("(λx.y) z", .apply(.lambda("x", "y"), "z")),
    ]
    for eg in examples {
      let term = try LambdaCalculus.parse(text: eg.text)
      XCTAssertEqual(eg.term, term, eg.text)
    }
  }
}

// --------------------------------------------------------------------------------

fileprivate indirect enum Term : Equatable {
  case name(Name)
  case apply(Term, Term)
  case lambda(Name, Term)
}

fileprivate struct Name : Equatable {
  let text : String
}

// --------------------------------------------------------------------------------

extension Term : ExpressibleByStringLiteral {
  init(stringLiteral: String) {
    self = .name(Name(text: stringLiteral))
  }
}

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral: String) {
    text = stringLiteral
  }
}
