/*

  Created by David Spooner

*/

import TSKit


/// A type representing functional type expressions.

@ParsableEnum
indirect enum TypeExpr : Equatable, ParsableByCases {
  case name(Name)
  case apply(Name, [TypeExpr])

  static func const(_ name: Name, _ types: [TypeExpr]) -> Self
    { .apply(name, types) }

  static func `func`(_ src: TypeExpr, _ trg: TypeExpr) -> Self
    { .apply("->", [src, trg]) }

  static func tuple(_ types: [TypeExpr]) -> Self
    { types.count == 1 ? types[0] : .apply("()", types) }

  static var symbolName : String
    { "Type" }

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "name": "\(Name.self)",
      "const": "\(prec: 1) \(Name.self) \([TypeExpr].self)",
      "tuple": "\([TypeExpr].self)",
      "func": "\(prec: .right(1)) \(TypeExpr.self) -> \(TypeExpr.self)",
    ]
  }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
