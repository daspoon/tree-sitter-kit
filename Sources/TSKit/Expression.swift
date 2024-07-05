/*

*/

/// An analogue of tree-sitter syntax expressions.
public indirect enum Expression {
  case lit(String)
  case pat(String)
  case sym(Any.Type)
  case alt([String])
  case opt(Expression)
  case rep(Expression, Punctuation?=nil)
  case seq([Expression])
  case prec(Precedence, Expression)
}


extension Expression : ExpressibleByStringLiteral {
  public init(stringLiteral s: String) {
    self = .lit(s)
  }
}
