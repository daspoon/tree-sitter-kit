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


extension MatchCase : Parsable {
  static var syntaxExpression : TSExpression {
    "\(Name.self) \([Name].self) => \(Expr.self)"
  }

  init(_ node: TSNode) {
    name = Name(node[0])
    params = [Name](node[1])
    expr = Expr(node[3])
  }
}
