/*

  Created by David Spooner

*/


#if false
public protocol ParsableAsDelimitedSequence<Element> : Parsable {
  associatedtype Element : Parsable
  static var delimiter : String { get }
  var elements : [Element] { get }
  init(elements: [Element])
}
#endif
