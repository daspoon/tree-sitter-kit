/*

  Created by David Spooner

*/


extension String {
  /// Construct a string from a parse tree node. Note that we can't conform to *Parsable* without choosing an arbitrary syntax expression,
  /// but we want to enable use of *String* in the constructors for *Parsable* types.
  public init(parseTree node: TSNode, context ctx: ParsingContext)
    { self = ctx.inputSource.text(for: node) }

  /// Return the concatenation of a number of newline characters, defaulting to 1.
  static func newline(_ n: Int = 1) -> String
    { .init(repeating: "\n", count: n) }

  /// Return the concatenation of a number of space characters, defaulting to 1.
  static func space(_ n: Int) -> String
    { .init(repeating: " ", count: n) }

  /// Return a copy of the receiver with each non-initial line prefixed by the given number of space characters.
  func indented(_ n: Int) -> String
    { components(separatedBy: String.newline()).joined(separator: .newline() + .space(n)) }

  /// Return a buffer containing the receiver's utf8 representation along with its length. The buffer contains a null terminator which does not contribute to the returned length. The caller is responsible for deallocating the buffer.
  var cstringBuffer : (UnsafePointer<CChar>, Int) {
    let v = utf8
    let n = v.count
    let buf = UnsafeMutablePointer<UInt8>.allocate(capacity: n + 1)
    for (i, c) in v.enumerated() {
      buf[i] = c
    }
    buf[n] = 0
    return (UnsafePointer(UnsafeRawPointer(buf).bindMemory(to: CChar.self, capacity: n)), n)
  }
}
