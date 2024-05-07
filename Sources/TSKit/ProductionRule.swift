/*

  Created by David Spooner

*/


/// *ProductionRule* represents a tree-sitter grammar rule which produces a *Parsable* type.

public struct ProductionRule<T: Parsable> {
  // A syntax expression with parsable type captures built with string interpolation.
  public struct Descriptor<each P: Parsable> {
    let syntaxExpression : TSExpression
    let captureIndices : [Int]
  }

  let syntaxExpression : TSExpression
  let constructor : (TSNode, ParsingContext) throws -> T

  /// Create an instance with explict syntax expression and parse tree translation method.
  public init(syntaxExpression e: TSExpression, constructor c: @escaping (TSNode, ParsingContext) throws -> T) {
    syntaxExpression = e
    constructor = c
  }

  /// Create an instance with a syntax expression given by a custom string interpolation
  /// and a constructor taking arguments of the types 'captured' by the interpolation.
  public init<each Q: Parsable>(descriptor: Descriptor<repeat each Q>, constructor f: @escaping (repeat each Q) throws -> T) {
    self.init(
      syntaxExpression: descriptor.syntaxExpression,
      constructor: { node, ctx in
        var i = 0
        return try f(repeat try throwingCast((each Q).productionRule.constructor(node[descriptor.captureIndices[i.postincrement()]], ctx)))
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
    var captureTypes : [Any.Type] = []
    var captureIndices : [Int] = []

    public init(literalCapacity: Int, interpolationCount: Int) {
      _ = (repeat (captureTypes.append((each P).self)))
    }

    private mutating func appendCapture(of type: Any.Type, with expr: TSExpression) {
      let captureIndex = captureIndices.count
      guard captureIndex < captureTypes.count
        else { fatalError("capture index out of bounds: \(captureIndex)") }
      guard captureTypes[captureIndex] == (type as Any.Type)
        else { fatalError("capture type mismatch: \(type) != \(captureTypes[captureIndex])") }
      components.append(.field("\(captureIndex)", expr))
      captureIndices.append(captureIndex)
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
    public mutating func appendInterpolation<C: Parsable>(_ type: Optional<C>.Type) {
      appendCapture(of: type, with: .optional(.prod(C.self)))
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
    self.init(syntaxExpression: interpolation.expression, captureIndices: interpolation.captureIndices)
  }

  public init(stringLiteral literal: String) {
    self.init(syntaxExpression: .literal(literal), captureIndices: [])
  }
}
