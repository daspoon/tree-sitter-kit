/*

  Created by David Spooner

*/


extension Int : Parsable {
  public static var productionRule : ProductionRule<Self> {
    .init(
      syntaxExpression: .pattern("[0-9]+"),
      constructor: { node, ctx in
        Self(ctx.inputSource.text(for: node))!
      }
    )
  }
}
