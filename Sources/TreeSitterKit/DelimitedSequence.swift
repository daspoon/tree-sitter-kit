/*

  Created by David Spooner

*/


/// *DelimitedSequence* produces an array of one or more elements delimited by a specific symbol.
public struct DelimitedSequence<Element: Parsable, Delimiter: Punctuation> where Element.Result == Element {
  public let elements : [Element]
  public init(elements es: [Element]) {
    elements = es
  }
}

extension DelimitedSequence : Parsable {
  public static var symbolName : String
    { "\(Element.symbolName)SequenceDelimitedBy\(Delimiter.self)" }

  public static var syntaxExpression : TSExpression
    { .repeat1(.prod(Element.self), delimiter: Delimiter.symbol) }

  public static func from(_ node: TSNode) -> [Element]
    { [Element](node, delimiter: Delimiter.symbol) }
}

extension DelimitedSequence : Equatable where Element : Equatable {
}
