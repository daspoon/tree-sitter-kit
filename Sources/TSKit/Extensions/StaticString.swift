/*

  Created by David Spooner

*/


extension StaticString {
  /// Return the address of the first ascii code unit. Accessing this property when isASCII is false triggers a runtime error.
  public var asciiStart : UnsafePointer<CChar> {
    precondition(isASCII)
    return UnsafeRawPointer(utf8Start).bindMemory(to: CChar.self, capacity: utf8CodeUnitCount + 1)
  }
}
