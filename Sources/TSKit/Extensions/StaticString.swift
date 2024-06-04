/*

  Created by David Spooner

*/

extension StaticString {
  /// Return the address of the first ascii code unit. Accessing this property when isASCII is false triggers a runtime error.
  public var asciiStart : UnsafePointer<CChar> {
    precondition(isASCII)
    return UnsafeRawPointer(utf8Start).bindMemory(to: CChar.self, capacity: utf8CodeUnitCount + 1)
  }

  /// Compare a static string with an ordinary string.
  public static func == (lhs: Self, rhs: String) -> Bool {
    let lhsCount = lhs.utf8CodeUnitCount
    let rhsChars = rhs.utf8
    guard rhsChars.count == lhsCount
      else { return false }
    return lhs.withUTF8Buffer { lhsChars in
      rhsChars.enumerated().allSatisfy({i, c in lhsChars[i] == c})
    }
  }

  enum Order { case ascending, equal, descending }
  static func compare(_ lhs: Self, _ rhs: Self) -> Order {
    let (lhsCount, rhsCount) = (lhs.utf8CodeUnitCount, rhs.utf8CodeUnitCount)
    return lhs.withUTF8Buffer { lhsChars in
      rhs.withUTF8Buffer { rhsChars in
        for i in 0 ..< min(lhsCount, rhsCount) {
          let diff = Int(rhsChars[i]) - Int(lhsChars[i])
          if diff != 0 {
            return diff > 0 ? .ascending : .descending
          }
        }
        let diff = rhsCount - lhsCount
        return diff > 0 ? .ascending : diff < 0 ? .descending : .equal
      }
    }
  }
}

extension StaticString : Equatable {
  public static func == (lhs: Self, rhs: Self) -> Bool {
    compare(lhs, rhs) == .equal
  }
}

extension StaticString : Comparable {
  public static func < (lhs: Self, rhs: Self) -> Bool {
    compare(lhs, rhs) == .ascending
  }

  public static func <= (lhs: Self, rhs: Self) -> Bool {
    compare(lhs, rhs) != .descending
  }

  public static func >= (lhs: Self, rhs: Self) -> Bool {
    compare(lhs, rhs) != .ascending
  }
}
