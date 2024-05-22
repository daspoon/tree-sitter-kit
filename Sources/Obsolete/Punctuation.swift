/*

  Created by David Spooner

*/


#if false
/// *Puncutation* is used to define delimiters and separators for *Parsable* sequence types.
public protocol Punctuation {
  static var symbol : String { get }
}


public struct Comma : Punctuation {
  public static var symbol : String { "," }
}

public struct Semicolon : Punctuation {
  public static var symbol : String { ";" }
}
#endif
