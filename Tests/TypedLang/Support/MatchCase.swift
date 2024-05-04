/*

  Created by David Spooner

*/

import TSKit


struct MatchCase : Equatable {
  let name : Name
  let params : [Name]
  let expr : Expr
}

extension MatchCase : Parsable {
  typealias NameList = SeparatedSequence<Name, Comma, Parentheses>
  static var productionRule : ProductionRule<MatchCase> {
    ProductionRule(descriptor: "\(Name.self) \(Optional<NameList>.self) => \(Expr.self)") { (name: Name, nlist: NameList?, expr: Expr) -> MatchCase in
      Self(name: name, params: nlist?.elements ?? [], expr: expr)
    }
  }
}
