/*

  Created by David Spooner

*/


extension Array where Element : Parsable {
  /// Create an array of *Parsable* elements from a parset tree node matching a *list* production rule.
  public init(_ node: TSNode, bracketed: Bool = true) {
    let n = node.count - (bracketed ? 2 : 0)
    let d = bracketed ? 1 : 0
    assert(n >= 0)
    switch n {
      case 0 : self = []
      default :
        assert(n % 2 == 1)
        self = stride(from: 0, to: n, by: 2).map { i in Element(node[d+i]) }
    }
  }
}


extension Int : Parsable {
  public static var syntaxExpression : TSExpression
    { .pattern("[0-9]+") }

  public init(_ node: TSNode)
    { self.init(node.stringValue!)! }
}


extension String {
  /// Return the concatenation of a number of newline characters, defaulting to 1.
  static func newline(_ n: Int = 1) -> String
    { .init(repeating: "\n", count: n) }

  /// Return the concatenation of a number of space characters, defaulting to 1.
  static func space(_ n: Int) -> String
    { .init(repeating: " ", count: n) }

  /// Return a copy of the receiver with each non-initial line prefixed by the given number of space characters.
  func indented(_ n: Int) -> String
    { components(separatedBy: String.newline()).joined(separator: .newline() + .space(n)) }
}
