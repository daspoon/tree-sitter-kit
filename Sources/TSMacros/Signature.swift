/*

  Created by David Spooner

*/

import TSCommon


/// *Signature* represents the 'type signature' of a syntax expression as an array of
/// type names with an indication of optionality.
enum Signature {
  typealias Capture = (symbol: String, optional: Bool)

  case symbol(String)
  case array(String, Punctuation?)
  case tuple([Capture])

  /// Attempt to create an instance for a given expression, throwing if the form of
  /// the expression is not supported.
  init(expression e: Expression) throws {
    switch e {
      case .lit : self = .tuple([])
      case .pat : self = .symbol("String")
      case .sym(let name) : self = .symbol(name)
      case .alt : self = .symbol("String")
      case .opt(let e1) :
        switch try Self(expression: e1) {
          case .symbol(let name) : self = .tuple([(name, true)])
          case .tuple(let sigs) : self = .tuple(sigs.map {s in (s.symbol, true)})
          default :
            throw Exception("unsupported expression")
        }
      case .rep(let e1, let p) :
        guard case .symbol(let name) = try Signature(expression: e1)
          else { throw Exception("unsupported expression") }
        self = .array(name, p)
      case .seq(let es) :
        self = .tuple(try es.reduce([]) { accum, ei in
          switch try Self(expression: ei) {
            case .symbol(let name) : accum + [(name, false)]
            case .tuple(let elts) : accum + elts
            default :
              throw Exception("unsupported expression")
          }
        })
      case .prec(_, let e1) :
        self = try Self(expression: e1)
    }
  }

  /// Return the number of elements captured by the associated syntax expression.
  var captureCount : Int {
    switch self {
      case .symbol : 1
      case .array : 1
      case .tuple(let captures) : captures.count
    }
  }
}
