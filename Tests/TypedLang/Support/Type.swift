/*

  Created by David Spooner

*/

import TSKit


/// A type representing functional type expressions.

indirect enum TypeExpr : Equatable {
  case name(Name)
  case apply(Name, [TypeExpr])
}

extension TypeExpr : ParsableByCases {
  static var productionRulesByCaseName : [String: ProductionRule<Self>] {
    return [
      "name": .init(descriptor: "\(Name.self)") { name in
        .name(name)
      },
      "const": .init(descriptor: "\(prec: 1) \(Name.self) ( \(opt: TypeExprList.self) )") { name, types in
        .apply(name, types?.elements ?? [])
      },
      "tuple": .init(descriptor: "( \(opt: TypeExprList.self) )") { types in
        {$0.count == 1 ? $0[0] : .apply("()", $0)}(types?.elements ?? [])
      },
      "func": .init(descriptor: "\(prec: .right(1)) \(TypeExpr.self) -> \(TypeExpr.self)") { src, trg in
        .apply("->", [src, trg])
      },
    ]
  }

  static var typeName : String
    { "Type" }

  typealias TypeExprList = SeparatedSequence<TypeExpr, Comma, NoBrackets>

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "": ,
      "": ,
      "": ,
    ]
  }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
