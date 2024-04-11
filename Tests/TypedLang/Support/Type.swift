/*

  Created by David Spooner

*/

import TSKit


/// A type representing functional type expressions.

@Parsable
indirect enum TypeExpr : Equatable, ParsableByCases {
  case name(Name)
  case apply(Name, [TypeExpr])

  static func const(_ name: Name, _ types: TypeExprList?) -> Self
    { .apply(name, types?.elements ?? []) }

  static func `func`(_ src: TypeExpr, _ trg: TypeExpr) -> Self
    { .apply("->", [src, trg]) }

  static func tuple(_ types: TypeExprList?) -> Self
    { {$0.count == 1 ? $0[0] : .apply("()", $0)}(types?.elements ?? []) }

  static var symbolName : String
    { "Type" }

  typealias TypeExprList = SeparatedSequence<TypeExpr, Comma, NoBrackets>

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "name": "\(Name.self)",
      "const": "\(prec: 1) \(Name.self) ( \(opt: TypeExprList.self) )",
      "tuple": "( \(opt: TypeExprList.self) )",
      "func": "\(prec: .right(1)) \(TypeExpr.self) -> \(TypeExpr.self)",
    ]
  }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
