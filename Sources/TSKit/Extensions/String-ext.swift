/*

  Created by David Spooner

*/


extension String {
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


  /// Return a copy of the receiver with the given prefix and/or suffix removed.
  func removing(prefix: String? = nil, suffix: String? = nil) -> String {
    var trimmed = self
    if let prefix, let range = trimmed.range(of: prefix, options:.anchored) {
      trimmed = String(trimmed[range.upperBound ..< trimmed.endIndex])
    }
    if let suffix, let range = trimmed.range(of: suffix, options: [.anchored, .backwards]) {
      trimmed = String(trimmed[trimmed.startIndex ..< range.lowerBound])
    }
    return trimmed
  }
}
