
// MARK: --

struct Name : Equatable {
  let text : String
}

extension Name : Parsable {
  static var productionRule : ProductionRule<Self> {
    .init(syntaxExpression: .pattern("[a-zA-Z_][0-9a-zA-Z_]*")) { node, ctx in
      Self(text: ctx.inputSource.text(for: node))
    }
  }
}

// MARK: --

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

// MARK: --

indirect enum Expr {
  case name(Name)
  case apply(Expr, [Expr])
}

extension Expr : ParsableByCases {
  typealias ExprList = SeparatedSequence<Expr, Comma, NoBrackets>

  static var productionRulesByCaseName : [String: ProductionRule<Self>] {
    return [
      "name": .init(descriptor: "\(Name.self)") { name in
        Expr.name(name)
      },
      "add": .init(descriptor: "\(prec:  .left(1)) \(Expr.self) \(OpAdd.self) \(Expr.self)") { (lhs: Expr, op: OpAdd, rhs: Expr) -> Expr in
        .apply(op.expr, [lhs, rhs])
      },
      "mul": .init(descriptor: "\(prec:  .left(2)) \(Expr.self) \(OpMul.self) \(Expr.self)") { (lhs: Expr, op: OpMul, rhs: Expr) -> Expr  in
        .apply(op.expr, [lhs, rhs])
      },
      "pow": .init(descriptor: "\(prec: .right(3)) \(Expr.self) \(OpPow.self) \(Expr.self)") { (lhs: Expr, op: OpPow, rhs: Expr) -> Expr  in
        .apply(op.expr, [lhs, rhs])
      },
      "neg": .init(descriptor: "\(prec:  .none(4)) \(OpNeg.self) \(Expr.self)") { (op: OpNeg, arg: Expr) -> Expr in
        .apply(op.expr, [arg])
      },
      "apply": .init(descriptor: "\(prec: .none(5)) \(Expr.self) ( \(Optional<ExprList>.self) )") { (fun: Expr, args: ExprList?) -> Expr in
        .apply(fun, args?.elements ?? [])
      },
      "paren": .init(descriptor: "( \(Expr.self) )") { expr in
        expr
      },
    ]
  }
}


