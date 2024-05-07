/*

  Created by David Spooner

*/

@testable import TSKit


protocol Op : Parsable {
  var text : String { get }
  init(text: String)
  static var candidates : [String] { get }
}

extension Op {
  var expr : Expr
    { .name(Name(text: text)) }

  static var productionRule : ProductionRule<Self> {
    .init(
      syntaxExpression: .choice(candidates.map {.literal($0)}),
      constructor: { node, ctx in
        Self(text: ctx.inputSource.text(for: node))
      }
    )
  }
}


struct OpCmp : Op {
  var text : String
  static var candidates : [String] { ["==", "<", ">", "<=", ">="] }
}

struct OpDisj : Op {
  var text : String
  static var candidates : [String] { ["||"] }
}

struct OpConj : Op {
  var text : String
  static var candidates : [String] { ["&&"] }
}

struct OpAdd : Op {
  var text : String
  static var candidates : [String] { ["+", "-"] }
}

struct OpMul : Op {
  var text : String
  static var candidates : [String] { ["*", "/", "%"] }
}

struct OpPow : Op {
  var text : String
  static var candidates : [String] { ["^"] }
}

struct OpNeg : Op {
  var text : String
  static var candidates : [String] { ["-"] }
}
