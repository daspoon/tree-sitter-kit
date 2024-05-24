/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


struct ProductionRuleImp {
  enum Precedence {
    case none(Int), left(Int), right(Int)
    var jsonType : String {
      switch self {
        case .none : "PREC"
        case .left : "PREC_LEFT"
        case .right : "PREC_RIGHT"
      }
    }
    var jsonValue : Int {
      switch self {
        case .none(let v) : v
        case .left(let v) : v
        case .right(let v) : v
      }
    }
  }

  enum Punctuation { case sep(String), del(String) }

  indirect enum RawExpression {
    case blank
    case string(String)
    case pattern(String)
    case symbol(String)
    case seq([RawExpression])
    case choice([RawExpression])
    case field(String, RawExpression)
    case prec(Precedence, RawExpression)
    case `repeat`(RawExpression)

    static var whitespace : Self {
      .pattern("\\\\s")
    }

    var json : String {
      switch self {
        case .blank : """
          {"type": "BLANK"}
          """
        case .string(let value) : """
          {"type": "STRING", "value": "\(value)"}
          """
        case .pattern(let value) : """
          {"type": "PATTERN", "value": "\(value)"}
          """
        case .symbol(let name) : """
          {"type": "SYMBOL", "name": "\(name)"}
          """
        case .choice(let members) : """
          {"type": "CHOICE", "members": [\(members.map(\.json).joined(separator: ", "))]}
          """
        case .seq(let members) : """
          {"type": "SEQ", "members": [\(members.map(\.json).joined(separator: ", "))]}
          """
        case .prec(let prec, let content) : """
          {"type": "\(prec.jsonType)", "value": \(prec.jsonValue), "content": \(content.json)}
          """
        case .field(let name, let content) : """
          {"type": "FIELD", "name": "\(name)", "content": \(content.json)}
          """
        case .repeat(let content) : """
          {"type": "REPEAT", "content": \(content.json)}
          """
      }
    }
  }

  indirect enum Expression {
    case lit(String)
    case pat(String)
    case sym(String)
    case alt([String])
    case opt(Expression)
    case rep(Expression, Punctuation?=nil)
    case seq([Expression])
    case prec(Precedence, Expression)

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

  enum Signature {
    typealias Capture = (symbol: String, optional: Bool)
    case symbol(String)
    case array(String, Punctuation?)
    case tuple([Capture])
    init(expression e: Expression) throws {
      switch e {
        case .lit : self = .tuple([])
        case .pat : self = .symbol("String")
        case .sym(let name) : self = .symbol(name)
        case .alt : self = .symbol("String")
        case .opt(let e1) :
          switch try Self(expression: e1) {
            case .symbol(let name) : self = .tuple([(name, true)])
            case .tuple(let sigs) : self = .tuple(sigs.map {s in (s.symbol, true)})
            default :
              throw Exception("unsupported expression")
          }
        case .rep(let e1, let p) :
          guard case .symbol(let name) = try Signature(expression: e1)
            else { throw Exception("unsupported expression") }
          self = .array(name, p)
        case .seq(let es) :
          self = .tuple(try es.reduce([]) { accum, ei in
            switch try Self(expression: ei) {
              case .symbol(let name) : accum + [(name, false)]
              case .tuple(let elts) : accum + elts
              default :
                throw Exception("unsupported expression")
            }
          })
        case .prec(_, let e1) :
          self = try Self(expression: e1)
      }
    }
    var captureCount : Int {
      switch self {
        case .symbol : 1
        case .array : 1
        case .tuple(let captures) : captures.count
      }
    }
  }

  struct Choice {
    let expression : Expression
    let signature : Signature
    let constructor : ClosureExprSyntax

    init(expression e: Expression, constructor c: ClosureExprSyntax) throws {
      guard let parameterCount = c.signature?.parameterCount
        else { throw Exception("trailing closure must have explicit parameter names") }
      expression = e
      signature = try Signature(expression: e)
      constructor = c
      guard signature.captureCount == parameterCount
        else { throw Exception("expression capture count (\(signature.captureCount)) does not match constructor parameter count (\(parameterCount))") }
    }

    /// Return the text for an invocation of the constructor with argument values extracted
    /// from an implicit parse tree 'node' and 'context'...
    var invocationText : String {
      "\(constructor)(\(invocationArgumentsText))"
    }

    var invocationArgumentsText : String {
      switch signature {
        case .symbol(let type) :
          extractionText(for: type)
        case .array(let eltType, .sep(let sep)) :
          "Array<\(eltType)>.extractElements(separatedBy: \"\(sep)\", from: node, in: context, using: {\(extractionText(for: eltType, with: "$0", in: "$1"))})"
        case .array(let eltType, .del(let del)) :
          "Array<\(eltType)>.extractElements(delimitedBy: \"\(del)\", from: node, in: context, using: {\(extractionText(for: eltType, with: "$0", in: "$1"))})"
        case .array(let eltType, .none) :
          "Array<\(eltType)>.extractElements(from: node, in: context, using: {\(extractionText(for: eltType, with: "$0", in: "$1"))})"
        case .tuple(let captures) :
          captures.enumerated()
            .map({ index, capture in
              let nodeText = "node[\"\(index)\"]"
              return capture.optional
                ? "{$0.isNull ? nil : \(extractionText(for: capture.symbol, with: "$0"))}(\(nodeText))"
                : extractionText(for: capture.symbol, with: nodeText)
            })
            .joined(separator: ", ")
      }
    }

    /// Return the text used to create an instance of the given type from the given node.
    func extractionText(for typeName: String, with nodeText: String = "node", in contextText: String = "context") -> String {
      "extract\(typeName)(from: \(nodeText), in: \(contextText))"
    }
  }

  enum Form {
    case single(Choice), multiple([String: Choice])
  }

  let typeName : String
  let form : Form


  /// Return the text which defines the function to extract an instance of the associated type from a parse tree node and context.
  var extractionDeclText : String {
    """
    private static func extract\(typeName)(from node: TSNode, in context: ParsingContext) -> \(typeName) {
      \(extractionBodyText)
    }
    """
  }

  var isSymbolHidden : Bool {
    if case .multiple = form { true } else { false }
  }

  var symbolName : String {
    isSymbolHidden ? "_" + typeName : typeName
  }

  var extractionBodyText : String {
    switch form {
      case .single(let choice) :
        choice.invocationText
      case .multiple(let choicesByName) :
        """
        switch context.language.symbolName(for: node) {
          \(
            choicesByName.map({ key, choice in
              "case \"\(typeName)_\(key)\" : \(choice.invocationText)"
            })
            .joined(separator: "\n")
          )
          case let other:
            fatalError("unexpected symbol: \\(other)")
        }
        """
    }
  }

  func getSymbolNamesAndRawExpressions(_ lookup: (String) throws -> String) throws -> [(symbolName: String, rawExpression: RawExpression)] {
    return switch form {
      case .single(let choice) :
        [(symbolName, try choice.expression.getRawExpression(lookup))]
      case .multiple(let choicesByName) :
        [(symbolName, .choice(choicesByName.map({name, _ in .symbol(typeName + "_" + name)})))]
          + (try choicesByName.map({ name, choice in (typeName + "_" + name, try choice.expression.getRawExpression(lookup)) }))
    }
  }
}


extension ProductionRuleImp.Precedence {
  init(exprSyntax: ExprSyntax) throws {
    switch exprSyntax.kind {
      case .functionCallExpr :
        guard let (name, args) = try exprSyntax.caseComponents
          else { throw Exception("expecting Precedence syntax") }
        switch (name, args.count) {
          case ("left", 1) :
            self = .left(try Int(exprSyntax: args[0].expression))
          case ("right", 1) :
            self = .left(try Int(exprSyntax: args[0].expression))
          default :
            throw Exception("invalid Precedence syntax")
        }
      case .integerLiteralExpr :
        self = .none(try Int(exprSyntax: exprSyntax))
      default :
        throw Exception("invalid Precedence syntax")
    }
  }
}


extension ProductionRuleImp.Punctuation {
  init(exprSyntax: ExprSyntax) throws {
    guard let (name, args) = try exprSyntax.caseComponents, args.count == 1
      else { throw Exception("expecting Punctuation syntax") }
    guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
      else { throw Exception("expecting string literal argument") }
    switch (name, args.count) {
      case ("sep", 1) :
        self = .sep(string)
      case ("del", 1) :
        self = .del(string)
      default :
        throw Exception("invalid Punctuation syntax")
    }
  }
}


extension ProductionRuleImp.Expression {
  init(exprSyntax: ExprSyntax) throws {
    switch exprSyntax.kind {
      case .functionCallExpr :
        guard let (name, args) = try exprSyntax.caseComponents
          else { throw Exception("expecting baseless member access") }
        switch (name, args.count) {
          case ("lit", 1) :
            guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw Exception("expecting string literal") }
            self = .lit(string)
          case ("pat", 1) :
            guard let string = args[0].expression.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw Exception("expecting string literal") }
            self = .pat(string)
          case ("sym", 1) :
            guard let name = try args[0].expression.typeName
              else { throw Exception("expecting type reference") }
            self = .sym(name)
          case ("alt", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw Exception("expecting array argument") }
            self = .alt(try arrayExpr.elements.map {
              guard let string = $0.expression.as(StringLiteralExprSyntax.self)?.stringLiteral
                else { throw Exception("expecting string literal: \($0.kind); \($0)") }
              return string
            })
          case ("opt", 1) :
            self = .opt(try Self(exprSyntax: args[0].expression))
          case ("rep", let n) where 0 < n && n < 3 :
            self = .rep(try Self(exprSyntax: args[0].expression), n == 2 ? try ProductionRuleImp.Punctuation(exprSyntax: args[1].expression) : nil)
          case ("seq", 1) :
            guard let arrayExpr = args[0].expression.as(ArrayExprSyntax.self)
              else { throw Exception("expecting array argument") }
            self = .seq(try arrayExpr.elements.map { try Self(exprSyntax: $0.expression) })
          case ("prec", 2) :
            self = .prec(try ProductionRuleImp.Precedence(exprSyntax: args[0].expression), try Self(exprSyntax: args[1].expression))
          case let other :
            throw Exception("unsupported case: \(other)")
        }
      case .stringLiteralExpr :
        guard let string = exprSyntax.cast(StringLiteralExprSyntax.self).stringLiteral
          else { throw Exception("expecting string literal") }
        self = .lit(string)
      default :
        throw Exception("invalid expression syntax")
    }
  }
}


extension ProductionRuleImp {
  init(_ expr: ExprSyntax) throws {
    guard let funcall = expr.as(FunctionCallExprSyntax.self), funcall.arguments.count == 2
      else { throw Exception("expecting function call with two arguments") }

    // Get the produced type from the first argument, which must be of the form `T.self`
    guard let name = try funcall.arguments[0].expression.typeName
      else { throw Exception("expecting type reference") }
    typeName = name

    // Distinguish single and multiple clause initializers
    let arg2 = funcall.arguments[1]
    switch arg2.label?.text {
      case .none : // init<T, each A>(_ type: T.Type, _ expression: Expression, constructor f: (repeat each A) throws -> T)
        guard let closure = funcall.trailingClosure
          else { throw Exception("expecting trailing closure") }
        form = .single(try Choice(expression: try Expression(exprSyntax: arg2.expression), constructor: closure))
      case "choicesByName" : // init<T>(_ type: T.Type, choicesByName: [String: Choice<T>])
        guard let dict = arg2.expression.as(DictionaryExprSyntax.self), case .elements(let elements) = dict.content
          else { throw Exception("'syntaxExpressionsByCaseName' must return a non-empty dictionary") }
        let namesWithClauses = try elements
          .map({ element in
            guard let name = element.key.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw Exception("dictionary keys must be string literals") }
            guard let funcall = element.value.as(FunctionCallExprSyntax.self), funcall.arguments.count == 1
              else { throw Exception("expecting a single FunctionCallExpr argument") }
            guard let closure = funcall.trailingClosure
              else { throw Exception("expecting a trailing closure") }
            let expr = try Expression(exprSyntax: funcall.arguments[0].expression)
            return (name, try Choice(expression: expr, constructor: closure))
          })
        form = .multiple(Dictionary(uniqueKeysWithValues: namesWithClauses))
      case .some(let other) :
        throw Exception("invalid argument label: \(other)")
    }
  }
}
