/*

  Created by David Spooner

*/


extension Optional : Parsable where Wrapped : Parsable {
  public static var productionRule : ProductionRule<Self> {
    let wrappedRule = Wrapped.productionRule
    return .init(
      syntaxExpression: wrappedRule.syntaxExpression,
      constructor: { node, ctx in
        node.isNull ? .none : .some(try wrappedRule.constructor(node, ctx))
      }
    )
  }
}
