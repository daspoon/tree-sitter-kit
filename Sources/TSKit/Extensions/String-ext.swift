/*

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

  /// Translate the given byte range into a character range for the given encoding. Return nil if either the given range does not correspond to a valid encoded sequence or the given encoding is not supported.
  public func characterRange(forByteRange byteRange: Range<Int>, encoding: Encoding) -> Range<Int>? {
    switch encoding {
      case .utf8 :
        utf8.characterRange(forByteRange: byteRange)
      case .utf16 :
        nil // TODO: ...
      default :
        nil
    }
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


extension String.UTF8View {
  /// Count the number of characters between `fromIndex` and `toIndex`, which default to `startIndex` and `endIndex` respectively.
  /// Return `nil` if the specified byte range is either lies outside the receiver's bounds or does not represent a valid utf8 character sequence.
  public func characterCount(fromIndex i: Index? = nil, toIndex n: Index? = nil) -> Int? {
    var (i, n) = (i ?? startIndex, n ?? endIndex)
    guard startIndex <= i && n <= endIndex else { return nil }
    var k = 0
    while i < n {
      let c = self[i]
      func validate(_ i: inout Index, trailingByteCount: Int, accumulatedCharCount: inout Int) -> Bool {
        guard index(i, offsetBy: trailingByteCount) < endIndex else { return false }
        i = index(i, offsetBy: 1)
        for _ in 0 ..< trailingByteCount {
          guard self[i] & 0xc0 == 0x80 else { return false }
          i = index(i, offsetBy: 1)
        }
        accumulatedCharCount += 1
        return true
      }
      if c & 0x80 == 0x00 {
        guard validate(&i, trailingByteCount: 0, accumulatedCharCount: &k) else { return nil }
      } else if c & 0xe0 == 0xc0 {
        guard validate(&i, trailingByteCount: 1, accumulatedCharCount: &k) else { return nil }
      } else if c & 0xf0 == 0xe0 {
        guard validate(&i, trailingByteCount: 2, accumulatedCharCount: &k) else { return nil }
      } else if c & 0xf8 == 0xf0 {
        guard validate(&i, trailingByteCount: 3, accumulatedCharCount: &k) else { return nil }
      } else {
        return nil
      }
    }
    return k
  }

  /// Return the character range for the given byte range, or nil if the given range does not correspond to a sequence of valid characters.
  public func characterRange(forIndexRange indexRange: Range<Index>) -> Range<Int>? {
    guard indexRange.upperBound <= endIndex
      else { return nil }
    guard let charStart = characterCount(toIndex: indexRange.lowerBound)
      else { return nil }
    guard let charCount = characterCount(fromIndex: indexRange.lowerBound, toIndex: indexRange.upperBound)
      else { return nil }
    return charStart ..< charStart + charCount
  }

  /// Return the character range for the given byte range, or nil if the given range does not correspond to a sequence of valid characters.
  public func characterRange(forByteRange byteRange: Range<Int>) -> Range<Int>? {
    let indexRange = index(startIndex, offsetBy: byteRange.lowerBound) ..< index(startIndex, offsetBy: byteRange.upperBound)
    return characterRange(forIndexRange: indexRange)
  }
}
