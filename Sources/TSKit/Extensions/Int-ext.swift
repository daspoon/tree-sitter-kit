/*

  Created by David Spooner

*/


extension Int : Parsable {
  public static var syntaxExpression : TSExpression
    { .pattern("[0-9]+") }

  public init(parseTree node: TSNode, source: InputSource)
    { self.init(source.text(for: node))! }
}
