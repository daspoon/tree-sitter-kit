/*

  Created by David Spooner

*/

import TreeSitterKit


@ParsableStruct
struct MatchCase : Equatable, Parsable {
  let name : Name
  let params : [Name]
  let expr : Expr

  init(name n: Name, params ps: [Name] = [], expr e: Expr) {
    name = n
    params = ps
    expr = e
  }

  static var syntaxExpression : TSExpression
    { "\(Name.self) \([Name].self) => \(Expr.self)" }

}
