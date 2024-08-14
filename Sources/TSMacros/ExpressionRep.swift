/*

*/

import SwiftSyntax


/// Implements a syntax expression as a pairing of a tree structure and a signature indicating the sequence of captured symbols types.
struct Expression {
  // Corresponds to the client-side Expression type.
  indirect enum Node {
    case lit(String)
    case pat(String)
    case sym(String)
    case alt([String])
    case opt(Self)
    case rep(Self, Punctuation?=nil)
    case seq([Self])
    case prec(Precedence, Self)
  }

  let rootNode : Node
  let signature : Signature

  /// Convert the receiver into a raw expression. Type names in sym cases are translated
  /// to symbol names by the given function, and all captures are implicitly wrapped in
  /// fields with increasing numeric names.
  func getRawExpression(_ lookup: (String) throws -> String) throws -> RawExpression {
    var index : Int = 0
    func walk(_ expr: Node) throws -> RawExpression {
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
    return try walk(rootNode)
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
            self = .init(rootNode: .lit(string), signature: .empty)
          case ("pat", 1) :
            guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw ExpansionError(node: args[0].expression, message: "expecting string literal") }
            self = .init(rootNode: .pat(string), signature: .string)
          case ("sym", 1) :
            guard let name = try args[0].expression.typeName
              else { throw ExpansionError(node: args[0].expression, message: "expecting type reference") }
            self = .init(rootNode: .sym(name), signature: .symbol(name))
          case ("alt", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting array literal") }
            let literals = try arrayExpr.elements.map {
              guard let string = $0.expression.as(StringLiteralExprSyntax.self)?.stringLiteral
                else { throw ExpansionError(node: $0.expression, message: "expecting string literal") }
              return string
            }
            self = .init(rootNode: .alt(literals), signature: .string)
          case ("opt", 1) :
            let subexpr = try Self(exprSyntax: args[0].expression)
            let sig = switch subexpr.signature {
              case .symbol(let name) : Signature.tuple([(name, true)])
              case .tuple(let captures) : Signature.tuple(captures.map {($0.symbol, true)})
              default :
                throw ExpansionError(node: args[0].expression, message: "unsupported expression")
            }
            self = .init(rootNode: .opt(subexpr.rootNode), signature: sig)
          case ("rep", let n) where 0 < n && n < 3 :
            let subexpr = try Self(exprSyntax: args[0].expression)
            guard case .symbol(let symbolName) = subexpr.signature
              else { throw ExpansionError(node: args[0].expression, message: "unsupported expression") }
            let punc = n == 2 ? try Punctuation(exprSyntax: args[1].expression) : nil
            self = .init(rootNode: .rep(subexpr.rootNode, punc), signature: .array(symbolName, punc))
          case ("seq", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw ExpansionError(node: args[0].expression, message: "expecting array literal") }
            let (subtrees, captures) : ([Node], [Signature.Capture]) = try arrayExpr.elements.enumerated().reduce(into: ([],[])) { accum, elt in
              let eltexp = try Self(exprSyntax: elt.1.expression)
              switch eltexp.signature {
                case .symbol(let name) : accum.1 += [(name, false)]
                case .tuple(let elts) : accum.1 += elts
                default :
                  throw ExpansionError(node: elt.1, message: "unsupported expression")
              }
              accum.0 += [eltexp.rootNode]
            }
            self = .init(rootNode: .seq(subtrees), signature: .tuple(captures))
          case ("prec", 2) :
            let prec = try Precedence(exprSyntax: args[0].expression)
            let subexpr = try Self(exprSyntax: args[1].expression)
            self = .init(rootNode: .prec(prec, subexpr.rootNode), signature: subexpr.signature)
          case let other :
            throw ExpansionError(node: args[0].expression, message: "unsupported case: \(other)")
        }
      case .stringLiteralExpr :
        guard let string = exprSyntax.cast(StringLiteralExprSyntax.self).stringLiteral
          else { throw ExpansionError(node: exprSyntax, message: "expecting string literal") }
        self = .init(rootNode: .lit(string), signature: .empty)
      case let unsupported :
        throw ExpansionError(node: exprSyntax, message: "unsupported expression syntax: \(unsupported)")
    }
  }
}
