/*

  Created by David Spooner

*/


extension UnsafeBufferPointer {
  /// Return a buffer containing the given number of elements initialized with the given constructor.
  public static func initialized(count: Int, constructor: (Int) -> Element) -> Self {
    let umrbp = UnsafeMutableRawBufferPointer.allocate(byteCount: count * MemoryLayout<Element>.stride, alignment: MemoryLayout<Element>.alignment)
    let umbp = umrbp.bindMemory(to: Element.self)
    for i in 0 ..< count {
      umbp[i] = constructor(i)
    }
    return Self(umbp)
  }

  /// Return a buffer containing (copies of) the given elements.
  public static func initialized(with elements: [Element]) -> Self {
    initialized(count: elements.count) { elements[$0] }
  }
}


extension UnsafeBufferPointer where Element == UnsafePointer<CChar>? {
  typealias CString = UnsafePointer<CChar>?
  /// Allocate and initialize a buffer containing the C string pointers for the given array of strings.
  /// A runtime error will occur unless all given strings satisfy both `hasPointerRepresentation` and `isASCII`.
  public static func arrayOfAsciiCSrings(_ strings: [StaticString?]) -> Self {
    let ptrbuf = UnsafeMutableRawBufferPointer.allocate(byteCount: strings.count * MemoryLayout<CString>.stride, alignment: MemoryLayout<CString>.alignment)
      .bindMemory(to: CString.self)
    for (i, string) in strings.enumerated() {
      ptrbuf[i] = string?.asciiStart
    }
    return Self(ptrbuf)
  }

  public static func arrayOfAsciiCSrings(_ strings: [StaticString]) -> Self {
    arrayOfAsciiCSrings(strings.map {$0 as StaticString?})
  }
}
