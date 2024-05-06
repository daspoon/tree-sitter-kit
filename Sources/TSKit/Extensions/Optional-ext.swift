/*

  Created by David Spooner

*/


extension Optional : Parsable where Wrapped : Parsable {
  public static var productionRule : ProductionRule<Self> {
    let wrappedRule = Wrapped.productionRule
    return .init(
      syntaxExpression: wrappedRule.syntaxExpression,
      constructor: { node, ctx in
        .some(try wrappedRule.constructor(node, ctx))
      }
    )
  }
  public static func translate(parseTree node: TSNode, in context: ParsingContext) throws -> Self {
    try Wrapped.translate(parseTree: node, in: context)
  }
}
