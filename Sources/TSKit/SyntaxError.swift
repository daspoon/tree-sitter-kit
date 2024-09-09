/*

*/

import Foundation


public struct SyntaxError : Error, Equatable {
  public enum Kind : Equatable {
    case bug(String)
    case eof
    case expecting(Set<TSSymbol>)
    case missing(TSSymbol)
  }

  public let range : Range<Int>
  public let kind : Kind

  public init(range r: Range<Int>, kind k: Kind) {
    range = r
    kind = k
  }
}
