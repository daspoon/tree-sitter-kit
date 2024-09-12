/*

*/

import Foundation


public struct SyntaxError : Error, Equatable {
  public enum Kind : Equatable {
    case expecting(Set<TSSymbol>)
    case incomplete([TSSymbol])
    case missing(TSSymbol)
    case unacceptable
  }

  public let range : Range<Int>
  public let kind : Kind

  public init(range r: Range<Int>, kind k: Kind) {
    range = r
    kind = k
  }

  // Describe a syntax error with respect to a given grammar.
  public func describe<G: Grammar>(using _: G) -> String {
    switch kind {
      case .empty :
        return "input text is empty"
      case .expecting(let symbols) :
        return "expecting \(symbols.sorted().map({G.symbolName(for: $0).description}).joined(separator: " "))"
      case .incomplete(let symbols) :
        return "incomplete production: \(symbols.map({G.symbolName(for: $0).description}).joined(separator: " "))"
      case .missing(let symbol) :
        return "missing \(G.symbolName(for: symbol).description)"
      case .unacceptable :
        return "unacceptable characters"
    }
  }
}
