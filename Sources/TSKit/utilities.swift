/*

  Created by David Spooner

*/


extension Array where Element : Parsable {
  /// Create an array of *Parsable* elements from a parset tree node matching a *list* production rule.
  public init(_ node: TSNode, source: InputSource, separator: String, brackets: (String, String)? = nil) {
    let n = node.count - (brackets != nil ? 2 : 0)
    let d = brackets != nil ? 1 : 0
    switch n {
      case 0 : self = []
      default :
        assert(n > 0 && n % 2 == 1)
        self = stride(from: 0, to: n, by: 2).map { i in Element(parseTree: node[d+i], source: source) }
    }
  }

  public init(_ node: TSNode, source: InputSource, delimiter: String) {
    let n = node.count
    assert(n > 0 && n % 2 == 0)
    self = stride(from: 0, to: n, by: 2).map { i in Element(parseTree: node[i], source: source) }
  }
}


extension Array : Parsable where Element : Parsable {
  public static var symbolName : String
    { "\(Element.symbolName)Array" }

  public static var syntaxExpression : TSExpression
    { .seq([.literal("("), .optional(.repeat1(.prod(Element.self), separator: ",")), .literal(")")]) }

  public init(parseTree node: TSNode, source src: InputSource)
    { self.init(node, source: src, separator: ",", brackets: ("(", ")")) }
}


extension Int : Parsable {
  public static var syntaxExpression : TSExpression
    { .pattern("[0-9]+") }

  public init(parseTree node: TSNode, source: InputSource)
    { self.init(source.text(for: node))! }
}


extension String {
  // Note: we can't make String conform to Parsable without choosing an arbitrary syntax expression,
  // but we want to enable use of String in the constructors for Parsable types...
  public init(parseTree node: TSNode, source: InputSource)
    { self = source.text(for: node) }
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

  /// Return a buffer containing the receiver's utf8 representation along with its length. The buffer contains a null terminator which does not contribute to the returned length. The caller is responsible for deallocating the buffer.
  var cstringBuffer : (UnsafePointer<CChar>, Int) {
    let v = utf8
    let n = v.count
    let buf = UnsafeMutablePointer<UInt8>.allocate(capacity: n + 1)
    for (i, c) in v.enumerated() {
      buf[i] = c
    }
    buf[n] = 0
    return (UnsafePointer(UnsafeRawPointer(buf).bindMemory(to: CChar.self, capacity: n)), n)
  }
}
