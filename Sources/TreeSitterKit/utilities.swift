/*

  Created by David Spooner

*/


extension Array where Element : Parsable, Element.Result == Element {
  /// Create an array of *Parsable* elements from a parset tree node matching a *list* production rule.
  public init(_ node: TSNode, separator: String, brackets: (String, String)? = nil) {
    let n = node.count - (brackets != nil ? 2 : 0)
    let d = brackets != nil ? 1 : 0
    switch n {
      case 0 : self = []
      default :
        assert(n > 0 && n % 2 == 1)
        self = stride(from: 0, to: n, by: 2).map { i in Element.from(node[d+i]) }
    }
  }

  public init(_ node: TSNode, delimiter: String) {
    let n = node.count
    assert(n > 0 && n % 2 == 0)
    self = stride(from: 0, to: n, by: 2).map { i in Element.from(node[i]) }
  }
}


extension Array : Parsable where Element : Parsable, Element.Result == Element {
  public static var symbolName : String
    { "\(Element.symbolName)Array" }

  public static var syntaxExpression : TSExpression
    { .seq([.literal("("), .optional(.repeat1(.prod(Element.self), separator: ",")), .literal(")")]) }

  public static func from(_ node: TSNode) -> Self
    { .init(node, separator: ",", brackets: ("(", ")")) }
}


extension Int : Parsable {
  public static var syntaxExpression : TSExpression
    { .pattern("[0-9]+") }

  public static func from(_ node: TSNode) -> Self
    { .init(node.stringValue!)! }
}


extension String {
  // Note: we can't make String conform to Parsable without choosing an arbitrary syntax expression,
  // but we want to enable use of String in the constructors for Parsable types...
  public static func from(_ node: TSNode) -> Self
    { node.stringValue! }
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
