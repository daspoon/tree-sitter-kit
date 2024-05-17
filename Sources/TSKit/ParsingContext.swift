/*

  Created by David Spooner

*/


/// Aggregate the data required to translate parse trees into instances of *Parsable* types.

public struct ParsingContext {
  public let language : TSLanguage
  public let inputSource : InputSource

  public init(language l: TSLanguage, inputSource s: InputSource) {
    language = l
    inputSource = s
  }

  public func translator<T: Parsable>(for type: T.Type = T.self) -> (TSNode, Self) -> T {
    fatalError("todo")
  }
}
