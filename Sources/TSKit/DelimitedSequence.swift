/*

  Created by David Spooner

*/


/// *DelimitedSequence* produces an array of one or more elements delimited by a specific symbol.
public struct DelimitedSequence<Element: Parsable, Delimiter: Punctuation> {
  public let elements : [Element]
  public init(elements es: [Element]) {
    elements = es
  }
}

extension DelimitedSequence : Parsable {
  public static var typeName : String
    { "\(Element.typeName)SequenceDelimitedBy\(Delimiter.self)" }

  public static var productionRule : ProductionRule<Self> {
    let element = Element.productionRule.constructor
    return .init(
      syntaxExpression: .repeat1(.prod(Element.self), delimiter: Delimiter.symbol),
      constructor: { node, ctx in
        let n = node.count
        assert(n > 0 && n % 2 == 0)
        return try Self(elements: stride(from: 0, to: n, by: 2).map { i in try element(node[i], ctx) })
      }
    )
  }
}

extension DelimitedSequence : Equatable where Element : Equatable {
}
