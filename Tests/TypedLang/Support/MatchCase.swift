/*

  Created by David Spooner

*/

import TSKit


@Parsable
struct MatchCase : Equatable, Parsable {
  let name : Name
  let params : [Name]
  let expr : Expr

  init(name n: Name, params ps: [Name] = [], expr e: Expr) {
    name = n
    params = ps
    expr = e
  }

  init(name n: Name, params ps: NameList?, expr e: Expr) {
    self.init(name: n, params: ps?.elements ?? [], expr: e)
  }

  typealias NameList = SeparatedSequence<Name, Comma, Parentheses>

  static var syntaxExpression : TSExpression
    { "\(Name.self) \(opt: NameList.self) => \(Expr.self)" }

}
