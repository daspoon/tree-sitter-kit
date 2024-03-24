/*

  Created by David Spooner

*/

import TreeSitterKit


/// A type representing functional type expressions.

indirect enum TypeExpr : Equatable {
  case name(Name)
  case apply(Name, [TypeExpr])

  static func tuple(_ types: [TypeExpr]) -> Self
    { .apply("()", types) }

  static func `func`(_ src: TypeExpr, _ trg: TypeExpr) -> Self
    { .apply("->", [src, trg]) }
}

extension TypeExpr : ParsableByCases {
  static var symbolName : String
    { "Type" }

// TODO: TypeExpr => TypeTuple
  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "name": "\(Name.self)",
      "const": .prec(1, "\(Name.self) \([TypeExpr].self)"),
      "tuple": "\([TypeExpr].self)", // { node in { ts in ts.count == 1 ? ts[0] : .tuple(ts) }([TypeExpr](node))
      "func": .prec(.right(1), "\(TypeExpr.self) -> \(TypeExpr.self)"),
    ]
  }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
