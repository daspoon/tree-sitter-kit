/*

  Created by David Spooner

*/


extension Int : Parsable {
  public static var syntaxExpression : TSExpression
    { .pattern("[0-9]+") }

  public init(parseTree node: TSNode, context ctx: ParsingContext)
    { self.init(ctx.inputSource.text(for: node))! }
}
