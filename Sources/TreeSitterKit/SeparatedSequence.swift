/*

  Created by David Spooner

*/


/// *DelimitedSequence* produces an array of one or more elements separated by a specific symbol.
public struct SeparatedSequence<Element: Parsable, Separator: Punctuation> where Element.Result == Element {
  public let elements : [Element]
  public init(elements es: [Element]) {
    elements = es
  }
}

extension SeparatedSequence : Parsable {
  public static var symbolName : String
    { "\(Element.symbolName)SequenceSeparatedBy\(Separator.self)" }

  public static var syntaxExpression : TSExpression
    { .repeat1(.prod(Element.self), separator: Separator.symbol) }

  public static func from(_ node: TSNode) -> [Element]
    { [Element](node, separator: Separator.symbol) }
}

extension SeparatedSequence : Equatable where Element : Equatable {
}
