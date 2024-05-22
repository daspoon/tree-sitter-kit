/*

  Created by David Spooner

*/


#if false
/// *Brackets* is used to specify a pair of symbols enclosing a parsed sequence.
public protocol Brackets {
  static var symbols : (lhs: String, rhs: String)? { get }
}

public struct NoBrackets : Brackets {
  public static var symbols : (lhs: String, rhs: String)? { nil }
}

public struct Parentheses : Brackets {
  public static var symbols : (lhs: String, rhs: String)? { ("(", ")") }
}
#endif
