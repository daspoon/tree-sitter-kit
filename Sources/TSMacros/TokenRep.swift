/*

*/

import SwiftSyntax


indirect enum Token {
  case lit(String)
  case pat(String)
  case seq([Token])
  case choice([Token])

  /// Convert the receiver into a raw expression. Type names in sym cases are translated
  /// to symbol names by the given function, and all captures are implicitly wrapped in
  /// fields with increasing numeric names.
  var rawExpression : RawExpression {
    switch self {
      case .lit(let string) :
        .string(string)
      case .pat(let pattern) :
        .pattern(pattern)
      case .seq(let tokens) :
        .seq(tokens.map({$0.rawExpression}))
      case .choice(let tokens) :
        .choice(tokens.map({$0.rawExpression}))
    }
  }
}


extension Token {
  init(expr: ExprSyntax) throws {
    switch expr.kind {
      case .functionCallExpr :
        let (name, args) = try expr.caseComponents
        switch (name, args.count) {
          case ("lit", 1) :
            guard let argExpr = args[0].expression.as(StringLiteralExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting string literal") }
            self = try .init(stringLiteralExpr: argExpr)
          case ("pat", 1) :
            guard let argExpr = args[0].expression.as(RegexLiteralExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting regex literal") }
            self = .init(regexLiteralExpr: argExpr)
          case ("seq", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting array argument") }
            self = .seq(try arrayExpr.elements.map { try Self(expr: $0.expression) })
          case ("choice", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting array argument") }
            self = .choice(try arrayExpr.elements.map { try Self(expr: $0.expression) })
          case let other :
            throw ExpansionError(node: expr, message: "unsupported case: \(other)")
        }
      case .stringLiteralExpr :
        self = try .init(stringLiteralExpr: expr.cast(StringLiteralExprSyntax.self))
      case .regexLiteralExpr :
        self = .init(regexLiteralExpr: expr.cast(RegexLiteralExprSyntax.self))
      default :
        throw ExpansionError(node: expr, message: "unexpected expression syntax")
    }
  }

  init(stringLiteralExpr expr: StringLiteralExprSyntax) throws {
    guard let content = expr.stringLiteral
      else { throw ExpansionError(node: expr, message: "unsupported string literal expression") }
    self = .lit(content)
  }

  init(regexLiteralExpr expr: RegexLiteralExprSyntax) {
    let pattern = expr.regex.text.reduce(into: "") { result, char in
      if char == "\\" {
        result.append("\\\\")
      }
      else {
        result.append(char)
      }
    }
    self = .pat(pattern)
  }
}
