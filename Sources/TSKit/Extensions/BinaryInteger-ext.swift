/*

  Created by David Spooner

*/


extension BinaryInteger {
  public mutating func postincrement() -> Self {
    defer { self += 1 }
    return self
  }
}
