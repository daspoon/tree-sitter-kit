/*

  Created by David Spooner

*/

import TSLanguage


/// Aggregate the data required to translate parse trees into instances of *Parsable* types.

public struct ParsingContext {
  public let language : UnsafePointer<TSLanguage>
  public let inputSource : InputSource

  public init(language l: UnsafePointer<TSLanguage>, inputSource s: InputSource) {
    language = l
    inputSource = s
  }
}
