/*

  Created by David Spooner

*/

import TSKit
import TSLanguage
import XCTest
import TypedLang


// MARK: - language types -

struct Block : Equatable {
  let decls : [Def]
  let expr : Expr
}

enum Def : Equatable {
  case `typedef`(Typedef)
  case `enum`(Enum)
  case `let`(Let)
  case `fun`(Fun)
}

typealias DefList = [Def]

struct Enum : Equatable {
  let name : Name
  let cases : [EnumCase]
}

struct EnumCase : Equatable {
  let name : Name
  let params : [Param]
}

typealias EnumCaseList = [EnumCase]

indirect enum Expr : Equatable {
  case name(Name)
  case numb(Int)
  case apply(Expr, Expr)
  case lambda([Param], TypeExpr, Expr)
  case mu(Name, [Param], TypeExpr, Expr)
  case tuple([Expr])
  case project(Expr, Int)
  case match(Expr, [MatchCase])
  case block(Block)
  static func paren(_ exprs: [Expr]?) -> Self
    { {$0.count == 1 ? $0[0] : .tuple($0)}(exprs ?? []) }
  static func infix(_ lhs: Expr, _ op: String, _ rhs: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }
  static func prefix(_ op: String, _ arg: Expr) -> Self
    { .apply(.name(Name(stringLiteral: op)), arg) }
}

typealias ExprList = [Expr]

struct Fun : Equatable {
  let name : Name
  let params : [Param]
  let type : TypeExpr
  let expr : Expr
}

struct Let : Equatable {
  let param : Param
  let expr : Expr
}

struct MatchCase : Equatable {
  let name : Name
  let params : [Name]
  let expr : Expr
}

typealias MatchCaseList = [MatchCase]

struct Name : Equatable {
  let text : String
}

typealias NameList = [Name]

struct Param : Equatable {
  let name : Name
  let type : TypeExpr
}

typealias ParamList = [Param]

indirect enum TypeExpr : Equatable {
  case name(Name)
  case apply(Name, [TypeExpr])

  static func arrow(_ src: Self, _ trg: Self) -> Self {
    .apply("->", [src, trg])
  }
}

typealias TypeExprList = [TypeExpr]

struct Typedef : Equatable {
  let name : Name
  let type : TypeExpr
}


// MARK: - grammar -

@Grammar
struct TypedLang : Grammar {
  typealias Root = Block

  static var productionRules : [ProductionRule] {
    return [
      .init(Block.self, .seq([.opt(.sym(DefList.self)), .sym(Expr.self)])) { defs, expr in
        Block(decls: defs ?? [], expr: expr)
      },
      .init(Def.self, choicesByName: [
        "typedef": .init(.seq([.sym(Typedef.self)])) { x in Def.typedef(x) },
        "enum": .init(.seq([.sym(Enum.self)])) { x in Def.enum(x) },
        "let": .init(.seq([.sym(Let.self)])) { x in Def.let(x) },
        "fun": .init(.seq([.sym(Fun.self)])) { x in Def.fun(x) },
      ]),
      .init(DefList.self, .rep(.sym(Def.self), .del(";"))) { defs in
        defs
      },
      .init(Enum.self, .seq(["enum", .sym(Name.self), "{", .sym(EnumCaseList.self), "}"])) { name, caselist in
        Enum(name: name, cases: caselist)
      },
      .init(EnumCase.self, .seq([.sym(Name.self), .opt(.seq(["(", .sym(ParamList.self), ")"]))])) { name, plist in
        EnumCase(name: name, params: plist ?? [])
      },
      .init(EnumCaseList.self, .rep(.sym(EnumCase.self), .sep(","))) { exprs in
        exprs
      },
      .init(Expr.self, choicesByName: [
        "name": .init(.sym(Name.self)) { name in
          .name(name)
        },
        "numb" : .init(.sym(Int.self)) { int in
          .numb(int)
        },
        "call" : .init(.prec(.left(9), .seq([.sym(Expr.self), "(", .opt(.sym(ExprList.self)), ")"]))) { fun, args in
          .apply(fun, .paren(args))
        },
        "lambda" : .init(.seq(["!", "(", .opt(.sym(ParamList.self)), ")", "->", .sym(TypeExpr.self), ".", .sym(Expr.self)])) { plist, rtype, expr in
          .lambda(plist ?? [], rtype, expr)
        },
        "mu" : .init(.seq(["!", .sym(Name.self), "(", .opt(.sym(ParamList.self)), ")", "->", .sym(TypeExpr.self), ".", .sym(Expr.self)])) { name, plist, rtype, expr in
          .mu(name, plist ?? [], rtype, expr)
        },
        "paren" : .init(.seq(["(", .opt(.sym(ExprList.self)), ")"])) { elist in
          .paren(elist)
        },
        "project" : .init(.prec(.left(8), .seq([.sym(Expr.self), ".", .sym(Int.self)]))) { expr, index in
          .project(expr, index)
        },
        // match f(x) { nil() => 1, cons(h,t) => 2 }
        "match" : .init(.seq(["match", .sym(Expr.self), "{", .sym(MatchCaseList.self), "}"])) { expr, caselist in
          .match(expr, caselist)
        },
        "block" : .init(.seq(["{", .sym(Block.self), "}"])) { block in
          .block(block)
        },
        "eql" : .init(.prec(.left(1), .seq([.sym(Expr.self), .alt(["==", "<", ">", "<=", ">="]), .sym(Expr.self)]))) { lhs, op, rhs in
          .infix(lhs, op, rhs)
        },
        "or"  : .init(.prec(.left(2), .seq([.sym(Expr.self), .alt(["|", "|"]), .sym(Expr.self)]))) { lhs, op, rhs in
          .infix(lhs, op, rhs)
        },
        "and" : .init(.prec(.left(3), .seq([.sym(Expr.self), .alt(["&&"]), .sym(Expr.self)]))) { lhs, op, rhs in
          .infix(lhs, op, rhs)
        },
        "add" : .init(.prec(.left(4), .seq([.sym(Expr.self), .alt(["+", "-"]), .sym(Expr.self)]))) { lhs, op, rhs in
          .infix(lhs, op, rhs)
        },
        "mul" : .init(.prec(.left(5), .seq([.sym(Expr.self), .alt(["*", "/", "%"]), .sym(Expr.self)]))) { lhs, op, rhs in
          .infix(lhs, op, rhs)
        },
        "pow" : .init(.prec(.right(6), .seq([.sym(Expr.self), .alt(["^"]), .sym(Expr.self)]))) { lhs, op, rhs in
          .infix(lhs, op, rhs)
        },
        "neg" : .init(.prec(7, .seq([.alt(["-"]), .sym(Expr.self)]))) { op, arg in
          .prefix(op, arg)
        },
      ]),
      .init(ExprList.self, .rep(.sym(Expr.self), .sep(","))) { exprs in
        exprs
      },
      .init(Fun.self, .seq(["fun", .sym(Name.self), "(", .opt(.sym(ParamList.self)), ")", "->", .sym(TypeExpr.self), "{", .sym(Expr.self), "}"])) { name, params, rtype, body in
        Fun(name: name, params: params ?? [], type: rtype, expr: body)
      },
      .init(Int.self, .pat("[0-9]+")) { string in
        Int(string)!
      },
      .init(Let.self, .seq(["let", .sym(Param.self), "=", .sym(Expr.self)])) { param, expr in
        Let(param: param, expr: expr)
      },
      .init(MatchCase.self, .seq([.sym(Name.self), "(", .opt(.sym(NameList.self)), ")", "=>", .sym(Expr.self)])) { name, params, expr in
        MatchCase(name: name, params: params ?? [], expr: expr)
      },
      .init(MatchCaseList.self, .rep(.sym(MatchCase.self), .sep(","))) { cases in
        cases
      },
      .init(Name.self, .pat("[a-zA-Z_][0-9a-zA-Z_]*")) { string in
        Name(text: string)
      },
      .init(NameList.self, .rep(.sym(Name.self), .sep(","))) { names in
        names
      },
      .init(Param.self, .seq([.sym(Name.self), ":", .sym(TypeExpr.self)])) { name, type in
        Param(name: name, type: type)
      },
      .init(ParamList.self, .rep(.sym(Param.self), .sep(","))) { params in
        params
      },
      .init(TypeExpr.self, choicesByName: [
        "name": .init(.sym(Name.self)) { name in
          .name(name)
        },
        "const": .init(.prec(1, .seq([.sym(Name.self), "(", .opt(.sym(TypeExprList.self)), ")"]))) { name, types in
          .apply(name, types ?? [])
        },
        "tuple": .init(.seq(["(", .opt(.sym(TypeExprList.self)), ")"])) { types in
          {$0.count == 1 ? $0[0] : .apply("()", $0)}(types ?? [])
        },
        "func": .init(.prec(.right(1), .seq([.sym(TypeExpr.self), "->", .sym(TypeExpr.self)]))) { src, trg in
          .arrow(src, trg)
        },
      ]),
      .init(TypeExprList.self, .rep(.sym(TypeExpr.self), .sep(","))) { texprs in
        texprs
      },
      .init(Typedef.self, .seq(["typedef", .sym(Name.self), "=", .sym(TypeExpr.self)])) { name, type in
        Typedef(name: name, type: type)
      }
    ]
  }

  static var word : String? {
    "([a-zA-Z_][0-9a-zA-Z_]* | [!#%&*+-/<=>^|~]+)"
  }
}


#if false
// Note: we can no longer use static properties to define precedence values,
// because our macro has no means of interpeting those property names.
// As an alternative we can either:
//   - provide a tie-in with TS precedence groups
//   - extend Grammar with a means of defining precedence values by name...
extension ProductionRule.Precedence {
  static var eql : Self   {  .left(1) }
  static var or  : Self   {  .left(2) }
  static var and : Self   {  .left(3) }
  static var add : Self   {  .left(4) }
  static var mult : Self  {  .left(5) }
  static var power : Self { .right(6) }
  static var neg : Self   {  .none(7) }
  static var proj : Self  {  .left(8) }
  static var apply : Self {  .left(9) }
}
#endif


// MARK: - testing convenience -

extension Block {
  init(_ text: String) throws {
    self = try TypedLang.parse(text: text)
  }
}

extension Def {
  init(_ text: String) throws {
    // Parse a block with the declaration text followed by a trivial expression.
    let block = try Block(text + "; 1")
    guard block.decls.count == 1
      else { throw TSError("requires a single declaration") }
    self = block.decls[0]
  }
}

extension Expr {
  init(_ text: String) throws {
    self = try Block(text).expr
  }

  static func infix_op(_ op: String, _ lhs: Self, _ rhs: Self) -> Self
    { .apply(.name(Name(stringLiteral: op)), .tuple([lhs, rhs])) }

  static func prefix_op(_ op: String, _ arg: Self) -> Self
    { .apply(.name(Name(stringLiteral: op)), arg) }
}

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}

extension Expr : ExpressibleByIntegerLiteral {
  init(integerLiteral n: Int)
    { self = .numb(n) }
}

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral: StringLiteralType) {
    text = stringLiteral
  }
}

extension Param {
  init(_ n: Name, _ t: TypeExpr)
    { self.init(name: n, type: t) }
}

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
