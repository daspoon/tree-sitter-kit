/*

  Created by David Spooner

*/


extension Array : Parsable where Element : Parsable {
  public static var symbolName : String
    { "ArrayOf\(Element.symbolName)" }

  public static var productionRule : ProductionRule<Self>
    { .single(.list(of: Element.self, bracketedBy: ("(", ")"), separatedBy: ",")) }

  public init(_ node: TSNode)
    { self = stride(from: 1, to: node.count, by: 2).map { i in Element(node[i]) } }
}


extension Int : Parsable {
  public static var productionRule : ProductionRule<Self>
    { .single(.pattern("[0-9]+")) }

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
