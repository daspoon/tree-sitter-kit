/*

  Created by David Spooner

*/

import TreeSitterKit


indirect enum TypeExpr : Equatable, ParsableByCases {
  case name(Name)
  case apply(Name, [TypeExpr])


  static func tuple(_ types: [TypeExpr]) -> Self
    { .apply("()", types) }

  static func `func`(_ src: TypeExpr, _ trg: TypeExpr) -> Self
    { .apply("->", [src, trg]) }


  // Parsable

  static var symbolName : String
    { "Type" }

  static var productionsByChoiceName : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] {
    return [
      "Type_name": (.prod(Name.self), { node in
        .name(Name(node))
      }),
      "Type_const": (.seq([.prod(Name.self), .list(TypeExpr.self)]), { node in
        .apply(Name(node[0]), [TypeExpr](node[1]))
      }),
      "Type_tuple": (.list(TypeExpr.self), { node in
        { ts in ts.count == 1 ? ts[0] : .tuple(ts) }([TypeExpr](node))
      }),
      "Type_func": (.prec(.right(1), .seq([.prod(TypeExpr.self), "->", .prod(TypeExpr.self)])), { node in
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
