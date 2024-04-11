/*

  Created by David Spooner

*/


extension Array where Element : Parsable {
  /// Create an array of *Parsable* elements from a parse tree node matching a *list* production rule.
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
