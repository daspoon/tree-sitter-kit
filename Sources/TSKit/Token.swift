/*

*/


/// A restricted class of syntax expression which can be collapsed to a single token.

public indirect enum Token {
  case lit(String)
  case pat(Regex<Substring>)
  case seq([Token])
  case choice([Token])
}


extension Token : ExpressibleByStringLiteral {
  public init(stringLiteral s: String) {
    self = .lit(s)
  }
}
