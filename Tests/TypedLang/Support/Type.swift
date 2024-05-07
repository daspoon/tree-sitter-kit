/*

  Created by David Spooner

*/

import TSKit


/// A type representing functional type expressions.

indirect enum TypeExpr : Equatable {
  case name(Name)
  case apply(Name, [TypeExpr])

  static func arrow(_ src: Self, _ trg: Self) -> Self {
    .apply("->", [src, trg])
  }
}

extension TypeExpr : ParsableByCases {
  typealias TypeExprList = SeparatedSequence<TypeExpr, Comma, NoBrackets>

  static var productionRulesByCaseName : [String: ProductionRule<Self>] {
    return [
      "name": .init(descriptor: "\(Name.self)") { name in
        .name(name)
      },
      "const": .init(descriptor: "\(prec: 1) \(Name.self) ( \(Optional<TypeExprList>.self) )") { (name, types: TypeExprList?) in
        .apply(name, types?.elements ?? [])
      },
      "tuple": .init(descriptor: "( \(Optional<TypeExprList>.self) )") { (types: TypeExprList?) in
        {$0.count == 1 ? $0[0] : .apply("()", $0)}(types?.elements ?? [])
      },
      "func": .init(descriptor: "\(prec: .right(1)) \(TypeExpr.self) -> \(TypeExpr.self)") { src, trg in
        .arrow(src, trg)
      },
    ]
  }

  static var typeName : String
    { "Type" }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
