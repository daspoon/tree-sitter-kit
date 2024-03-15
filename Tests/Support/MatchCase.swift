/*

  Created by David Spooner

*/

import TreeSitterKit


struct MatchCase : Equatable {
  let name : Name
  let params : [Name]
  let expr : Expr

  init(name n: Name, params ps: [Name] = [], expr e: Expr) {
    name = n
    params = ps
    expr = e
  }
}


extension MatchCase : ParsableAsArray {
  static var productionRule : ProductionRule<Self>
    { .single(.seq([.rule(Name.self), .rule([Name].self), .literal("=>"), .rule(Expr.self)])) }

  init(_ node: TSNode) {
    name = Name(node[0])
    params = [Name](node[1])
    expr = Expr(node[3])
  }

  static var bracketLiterals : (lhs: String, rhs: String) = ("{", "}")
}
