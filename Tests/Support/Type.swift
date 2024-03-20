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

  static var productionsByChoiceName : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Type_name": ("\(Name.self)", { node in
        .name(Name(node))
      }),
      "Type_const": (.prec(1, "\(Name.self) \([TypeExpr].self)"), { node in
        .apply(Name(node[0]), [TypeExpr](node[1]))
      }),
      "Type_tuple": ("\([TypeExpr].self)", { node in
        { ts in ts.count == 1 ? ts[0] : .tuple(ts) }([TypeExpr](node))
      }),
      "Type_func": (.prec(.right(1), "\(TypeExpr.self) -> \(TypeExpr.self)"), { node in
        .func(TypeExpr(node[0]), TypeExpr(node[2]))
      }),
    ]
  }
}


// Define some constructors to make tests more concise.

extension TypeExpr : ExpressibleByStringLiteral {
  init(stringLiteral s: String)
    { self = .name(.init(stringLiteral: s)) }
}
