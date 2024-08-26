/*

*/

import XCTest
import TSKit


class StringTests : XCTestCase {
  /// Ensure that our custom character count method agrees with the built-in functionality on whole strings.
  func testUTF8ByteCount() throws {
    // Strings with different-length UTF8 encodings (from https://en.wikipedia.org/wiki/UTF-8)
    let examples : [String] = [
      // 1 byte
      "$",
      // 2 bytes
      "£",
      "И",
      // 3 bytes
      "ह",
      "€",
      "한",
      // 4 bytes
      "𐍈",
      "\u{1096B3}",
      // ...
      "",
      "heynow",
      "$£Иह€한𐍈",
    ]
    for string in examples {
      let charCount = string.count
      let byteCount = string.utf8.count
      let charRange = string.characterRange(forByteRange: 0 ..< byteCount, encoding: .utf8)
      XCTAssertEqual(charRange, 0 ..< charCount, string)
    }
  }

  /// Ensure our character count method fails on invalid character ranges.
  func testUTF8ByteCountFailure() throws {
    let examples : [String] = [
      "£",
      "€",
      "𐍈",
    ]
    for s in examples {
      XCTAssertTrue(s.count == 1)
      let k = s.utf8.count
      XCTAssertEqual(s.characterRange(forByteRange: 0 ..< k, encoding: .utf8), 0 ..< 1)
      for i in 1 ..< k {
        XCTAssertEqual(s.characterRange(forByteRange: i ..< k, encoding: .utf8), nil)
      }
    }
  }
}
