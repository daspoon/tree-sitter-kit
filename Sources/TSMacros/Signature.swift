/*

*/


/// *Signature* represents the 'type signature' of a syntax expression as an array of
/// type names with an indication of optionality.
enum Signature {
  typealias Capture = (symbol: String, optional: Bool)

  case symbol(String)
  case array(String, Punctuation?)
  case tuple([Capture])

  static var empty : Self
    { .tuple([]) }

  static var string : Self
    { .symbol("String") }

  /// Return the number of elements captured by the associated syntax expression.
  var captureCount : Int {
    switch self {
      case .symbol : 1
      case .array : 1
      case .tuple(let captures) : captures.count
    }
  }
}
