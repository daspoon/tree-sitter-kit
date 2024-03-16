/*

  Created by David Spooner

*/

import TreeSitterKit


indirect enum TypeExpr : Equatable, ParsableByMultipleChoice, ParsableInSequence {
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
      "Type_name": (.rule(Name.self), { node in
        .name(Name(node))
      }),
      "Type_const": (.seq([.rule(Name.self), .rule([TypeExpr].self)]), { node in
        .apply(Name(node[0]), [TypeExpr](node[1]))
      }),
      "Type_tuple": (.rule([TypeExpr].self), { node in
        { ts in ts.count == 1 ? ts[0] : .tuple(ts) }([TypeExpr](node))
      }),
      "Type_func": (.prec(.right(1), .seq([.rule(TypeExpr.self), .literal("->"), .rule(TypeExpr.self)])), { node in
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
