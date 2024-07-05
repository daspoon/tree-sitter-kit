/*

*/

/// An analogue of tree-sitter precedence specifications.
public enum Precedence {
  case none(Int)
  case left(Int)
  case right(Int)
}


extension Precedence : ExpressibleByIntegerLiteral {
  public init(integerLiteral i: Int)
    { self = .none(i) }
}
