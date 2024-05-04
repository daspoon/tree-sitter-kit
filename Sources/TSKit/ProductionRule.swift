/*

  Created by David Spooner

*/


/// *ProductionRule* represents a tree-sitter grammar rule of various forms.

public struct AnyProductionRule {
  let symbol : Symbol
  let syntaxExpression : TSExpression
  let constructor : (TSNode, ParsingContext) throws -> Any

  init(symbol s: Symbol, syntaxExpression e: TSExpression, constructor c: @escaping (TSNode, ParsingContext) throws -> Any) {
    symbol = s
    syntaxExpression = e
    constructor = c
  }

  /// Return the defined symbol name.
  public var symbolName : String {
    symbol.name
  }

  /// Return the set of rules reachable from the receiver, excluding the receiver itself.
  public var supportingRules : [Self] {
    var accumulatedRules : [Self] = []
    var visitedSymbols : Set<Symbol> = []
    var remainingSymbols : Set<Symbol> = [self.symbol]
    while remainingSymbols.isEmpty == false {
      let symbol = remainingSymbols.removeFirst()
      let rule = symbol.productionRule
      visitedSymbols.insert(symbol)
      if symbol != self.symbol {
        accumulatedRules.append(rule)
      }
      func walk(_ expr: TSExpression) {
        switch expr {
          case .prod(let supportingSymbol) :
            guard visitedSymbols.contains(supportingSymbol) == false else { break }
            remainingSymbols.insert(supportingSymbol)
          case .seq(let exprs), .choice(let exprs) :
            exprs.forEach { walk($0) }
          case .field(_, let expr), .optional(let expr), .prec(_, let expr), .repeat(let expr) :
            walk(expr)
          case .literal, .pattern :
            break
        }
      }
      walk(rule.syntaxExpression)
    }
    return accumulatedRules
  }

  /// Return the javascript representation of the form "*name*: => *syntaxExpression*".
  public var javascript : String {
    "\(symbol.name): $ => \(syntaxExpression.javascript)"
  }
}


public struct ProductionRule<T: Parsable> {
  let syntaxExpression : TSExpression
  let constructor : (TSNode, ParsingContext) throws -> T

  ///
  public init(syntaxExpression e: TSExpression, constructor c: @escaping (TSNode, ParsingContext) throws -> T) {
    syntaxExpression = e
    constructor = c
  }

  /// 
  public init<each Q: Parsable>(descriptor: Descriptor<repeat each Q>, constructor f: @escaping (repeat each Q) throws -> T) {
    self.init(
      syntaxExpression: descriptor.syntaxExpression,
      constructor: { node, ctx in
        var i = 0
        return try f(repeat try throwingCast((each Q).productionRule.constructor(node[descriptor.captureIndices[i.postincrement()]], ctx)))
      }
    )
  }

  /// 
  public init() where T : ParsableByCases {
    let subrulesByCaseName = T.productionRulesByCaseName
    print("\(#function) -- \(subrulesByCaseName.keys)")
    self.init(
      syntaxExpression: .choice(subrulesByCaseName.map {name, _ in .prod(.init(T.self, case: name))}),
      constructor: { node, ctx in
        let caseName = ctx.language.symbolName(for: node)
        guard let subrule = subrulesByCaseName[caseName]
          else { throw TSError("unexpected node type: \(caseName)") }
        return try subrule.constructor(node, ctx)
      }
    )
  }

  ///
  public var typeErased : AnyProductionRule {
    .init(symbol: .init(T.self), syntaxExpression: syntaxExpression, constructor: constructor)
  }
}


extension ProductionRule {
  public struct Descriptor<each P: Parsable> {
    let syntaxExpression : TSExpression
    let captureIndices : [Int]
  }
}

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

    public mutating func appendInterpolation<C: Parsable>(_ type: C.Type) {
      appendCapture(of: type, with: .prod(C.self))
    }

    public mutating func appendInterpolation<C: Parsable>(_ type: Optional<C>.Type) {
      appendCapture(of: type, with: .optional(.prod(C.self)))
    }

    public mutating func appendInterpolation(_ literals: [String]) {
      appendCapture(of: String.self, with: .choice(literals.map {.literal($0)}))
    }

    var expression : TSExpression {
      components.count == 1 ? components[0] : .seq(components)
    }
  }

  public init(stringInterpolation interpolation: StringInterpolation) {
    self.init(syntaxExpression: interpolation.expression, captureIndices: interpolation.captureIndices)
  }

  public init(stringLiteral literal: String) {
    self.init(syntaxExpression: .literal(literal), captureIndices: [])
  }
}
