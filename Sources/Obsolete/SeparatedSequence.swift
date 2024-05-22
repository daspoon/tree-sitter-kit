/*

  Created by David Spooner

*/


#if false
public protocol ParsableAsSeparatedSequence<Element> : Parsable {
  associatedtype Element : Parsable
  static var separator : String { get }
  static var brackets : (lhs: String, rhs: String)? { get }
  var elements : [Element] { get }
  init(elements: [Element])
}

extension ParsableAsSeparatedSequence {
  public static var brackets : (lhs: String, rhs: String)?
    { nil }
}
#endif
