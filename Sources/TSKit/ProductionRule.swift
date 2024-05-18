/*

  Created by David Spooner

*/


/// *ProductionRule* represents a tree-sitter grammar rule which produces a *Parsable* type.

public struct ProductionRule<T: Parsable> {
  // A syntax expression with parsable type captures built with string interpolation.
  public struct Descriptor {
    let syntaxExpression : TSExpression
    let fieldNames : [String]
    let captureTypes : [Any.Type]
  }

  let syntaxExpression : TSExpression
  let constructor : (TSNode, ParsingContext) throws -> T

  /// Create an instance with explict syntax expression and parse tree translation method.
  internal init(syntaxExpression e: TSExpression, constructor c: @escaping (TSNode, ParsingContext) throws -> T) {
    syntaxExpression = e
    constructor = c
  }

  /// Create an instance for a terminal symbol, with syntax expression given by a regular expression
  /// and constructor taking a matching string.
  public init(pattern p: String, constructor f: @escaping (String) -> T) {
    self.init(
      syntaxExpression: .pattern(p),
      constructor: { node, ctx in
        f(ctx.inputSource.text(for: node))
      }
    )
  }

  /// Create an instance for a non-terminal symbol, with syntax expression given by a custom string
  /// interpolation and constructor taking arguments of the types 'captured' by the interpolation.
  public init<each Q: Parsable>(descriptor: Descriptor, constructor f: @escaping (repeat each Q) throws -> T) {
    self.init(
      syntaxExpression: descriptor.syntaxExpression,
      constructor: { node, ctx in
        var i = 0
        return try f(repeat try (each Q).productionRule.constructor(node[descriptor.fieldNames[i.postincrement()]], ctx))
      }
    )
  }

  /// Return a type-erased representative of this rule for use in grammar generation.
  public var typeErased : AnyProductionRule {
    .init(symbol: .init(T.self), syntaxExpression: syntaxExpression, constructor: constructor)
  }
}


/// A type-erased *ProductionRule*.

public struct AnyProductionRule {
  let symbol : Symbol
  let syntaxExpression : TSExpression
  let constructor : (TSNode, ParsingContext) throws -> Any

  init(symbol s: Symbol, syntaxExpression e: TSExpression, constructor c: @escaping (TSNode, ParsingContext) throws -> Any) {
    symbol = s
    syntaxExpression = e
    constructor = c
  }
}


/// String interpolation of ProductionRule descriptors...

extension ProductionRule.Descriptor : ExpressibleByStringInterpolation {
  public struct StringInterpolation : StringInterpolationProtocol {
    var precedence : TSExpression.Prec?
    var components : [TSExpression] = []
    var fieldNames : [String] = []
    var captureTypes : [Any.Type] = []

    public init(literalCapacity: Int, interpolationCount: Int) {
    }

    private mutating func appendCapture(of type: Any.Type, with expr: TSExpression) {
      let fieldName = "\(captureTypes.count)"
      components.append(.field(fieldName, expr))
      fieldNames.append(fieldName)
      captureTypes.append(type)
    }

    public mutating func appendLiteral(_ literal: String) {
      let tokens = literal.split(whereSeparator: {$0.isWhitespace})
      components.append(contentsOf: tokens.map {.literal(String($0))})
    }

    /// Add a component to capture an instance of the given type.
    public mutating func appendInterpolation<C: Parsable>(_ type: C.Type) {
      appendCapture(of: type, with: .prod(C.self))
    }

    /// Add a component to capture an optional instance of the given type.
    public mutating func appendInterpolation<C: Parsable>(opt type: C.Type) {
      appendCapture(of: type, with: .optional(.prod(C.self)))
    }

    public mutating func appendInterpolation(lit literals: [String]) {
      appendCapture(of: String.self, with: .choice(literals.map {.literal($0)}))
    }

    public mutating func appendInterpolation(pat pattern: String) {
      appendCapture(of: String.self, with: .pattern(pattern))
    }

    /// Establish the precedence of the expression. This has no associated capture, has no effect the field labels of captures, and must be specified as the first interpolation segment.
    public mutating func appendInterpolation(prec: TSExpression.Prec) {
      assert(precedence == nil && components.count == 0)
      precedence = prec
    }

    var expression : TSExpression {
      let expr = components.count == 1 ? components[0] : .seq(components)
      return precedence.map {.prec($0, expr)} ?? expr
    }
  }

  public init(stringInterpolation interpolation: StringInterpolation) {
    self.init(syntaxExpression: interpolation.expression, fieldNames: interpolation.fieldNames, captureTypes: interpolation.captureTypes)
  }

  public init(stringLiteral literal: String) {
    self.init(syntaxExpression: .literal(literal), fieldNames: [], captureTypes: [])
  }
}
