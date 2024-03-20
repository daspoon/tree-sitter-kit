/*

  Created by David Spooner

*/


/// *DelimitedSequence* produces an array of one or more elements separated by a specific symbol.
public struct SeparatedSequence<Element: Parsable, Separator: Punctuation> {
  public let elements : [Element]
}

extension SeparatedSequence : Parsable {
  public static var symbolName : String
    { "\(Element.symbolName)SequenceSeparatedBy\(Separator.self)" }

  public static var syntaxExpression : TSExpression
    { .repeat1(.prod(Element.self), separator: Separator.symbol) }

  public init(_ node: TSNode) {
    elements = [Element](node, separator: Separator.symbol)
  }
}
