/*

  Created by David Spooner

*/

import TreeSitterKit


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
    { .apply("()", types) }

  static var symbolName : String
    { "Type" }

  static var syntaxExpressionsByCaseName : [String: TSExpression] {
    return [
      "name": "\(Name.self)",
      "const": .prec(1, "\(Name.self) \(TypeExprList.self)"),
      "tuple": "\(TypeExprList.self)",
      "func": .prec(.right(1), "\(TypeExpr.self) -> \(TypeExpr.self)"),
    ]
  }
}

/// *TypeList* parses a bracketed sequence of exprs, return either the sole element or a tuple consisting of zero, two or more elements.
struct TypeExprList : Parsable {
  static var syntaxExpression : TSExpression
    { [TypeExpr].syntaxExpression }
  static func from(_ node: TSNode) -> TypeExpr {
    let types = [TypeExpr].from(node)
    return types.count == 1 ? types[0] : .tuple(types)
  }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
