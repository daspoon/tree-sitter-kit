/*

*/

import SwiftSyntax
import TSCommon


/// The 'implementation' of the client-side type of the same name.
indirect enum Expression {
  case lit(String)
  case pat(String)
  case sym(String)
  case alt([String])
  case opt(Expression)
  case rep(Expression, Punctuation?=nil)
  case seq([Expression])
  case prec(Precedence, Expression)

  /// Convert the receiver into a raw expression. Type names in sym cases are translated
  /// to symbol names by the given function, and all captures are implicitly wrapped in
  /// fields with increasing numeric names.
  func getRawExpression(_ lookup: (String) throws -> String) throws -> RawExpression {
    var index : Int = 0
    func walk(_ expr: Expression) throws -> RawExpression {
      switch expr {
        case .lit(let string) :
          .string(string)
        case .pat(let pattern) :
          .field("\(index.postincrement())", .pattern(pattern))
        case .sym(let typeName) :
          .field("\(index.postincrement())", .symbol(try lookup(typeName)))
        case .alt(let strings) :
          .field("\(index.postincrement())", .choice(strings.map {.string($0)}))
        case .opt(let expr) :
          .choice([try walk(expr), .blank])
        case .rep(let expr, .none) :
          {.seq([$0, .repeat($0)])}(try walk(expr))
        case .rep(let expr, .sep(let sep)) :
          {.seq([$0, .repeat(.seq([.string(sep), $0]))])}(try walk(expr))
        case .rep(let expr, .del(let del)) :
          {.seq([$0, .repeat($0)])}(.seq([try walk(expr), .string(del)]))
        case .seq(let exprs) :
          .seq(try exprs.map({try walk($0)}))
        case .prec(let prec, let expr) :
          .prec(prec, try walk(expr))
      }
    }
    return try walk(self)
  }
}


extension Expression {
  /// Attempt to create an instance from a Swift syntax expression.
  init(exprSyntax: ExprSyntax) throws {
    switch exprSyntax.kind {
      case .functionCallExpr :
        let (name, args) = try exprSyntax.caseComponents
        switch (name, args.count) {
          case ("lit", 1) :
            guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw ExpansionError(node: args[0].expression, message: "expecting string literal") }
            self = .lit(string)
          case ("pat", 1) :
            guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw ExpansionError(node: args[0].expression, message: "expecting string literal") }
            self = .pat(string)
          case ("sym", 1) :
            guard let name = try args[0].expression.typeName
              else { throw ExpansionError(node: args[0].expression, message: "expecting type reference") }
            self = .sym(name)
          case ("alt", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting array literal") }
            self = .alt(try arrayExpr.elements.map {
              guard let string = $0.expression.as(StringLiteralExprSyntax.self)?.stringLiteral
                else { throw ExpansionError(node: $0.expression, message: "expecting string literal") }
              return string
            })
          case ("opt", 1) :
            self = .opt(try Self(exprSyntax: args[0].expression))
          case ("rep", let n) where 0 < n && n < 3 :
            self = .rep(try Self(exprSyntax: args[0].expression), n == 2 ? try Punctuation(exprSyntax: args[1].expression) : nil)
          case ("seq", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting array literal") }
            self = .seq(try arrayExpr.elements.map { try Self(exprSyntax: $0.expression) })
          case ("prec", 2) :
            self = .prec(try Precedence(exprSyntax: args[0].expression), try Self(exprSyntax: args[1].expression))
          case let other :
            throw ExpansionError(node: args[0].expression, message: "unsupported case: \(other)")
        }
      case .stringLiteralExpr :
        guard let string = exprSyntax.cast(StringLiteralExprSyntax.self).stringLiteral
          else { throw ExpansionError(node: exprSyntax, message: "expecting string literal") }
        self = .lit(string)
      case let unsupported :
        throw ExpansionError(node: exprSyntax, message: "unsupported expression syntax: \(unsupported)")
    }
  }
}
