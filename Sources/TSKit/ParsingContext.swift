/*

*/

import TSLanguage


/// Aggregate the data required to translate parse trees into instances of *Parsable* types.

public struct ParsingContext {
  public let inputSource : InputSource

  public init(inputSource s: InputSource) {
    inputSource = s
  }

  /// Return the portion of source text for the given node.
  public func text(for node: TSNode) -> String {
    inputSource.text(in: node.sourceByteRange)
  }
}
