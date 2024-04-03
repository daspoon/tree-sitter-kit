/*

  Created by David Spooner

*/


/// *SeparatedSequence* produces an array of one or more elements separated by a specific symbol.
public struct SeparatedSequence<Element: Parsable, Separator: Punctuation, Bracket: Brackets> {
  public let elements : [Element]
  public init(elements es: [Element]) {
    elements = es
  }
}


extension SeparatedSequence : Parsable {
  public static var symbolName : String
    { "\(Element.symbolName)SequenceSeparatedBy\(Separator.self)" + (Bracket.symbols.map({_ in "BracketedBy\(Bracket.self)"}) ?? "") }

  public static var syntaxExpression : TSExpression
    {
      let inner = TSExpression.repeat1(.prod(Element.self), separator: Separator.symbol)
      switch Bracket.symbols {
        case .some((let lhs, let rhs)) :
          return .seq([.literal(lhs), .optional(inner), .literal(rhs)])
        case .none :
          return inner
      }
    }

  public init(parseTree node: TSNode)
    { elements = [Element](node, separator: Separator.symbol, brackets: Bracket.symbols) }
}


extension SeparatedSequence : Equatable where Element : Equatable {
}
