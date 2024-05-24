/*

  Created by David Spooner

*/

import Foundation


extension Character {
  /// Return the unicode scalar representation, or nil if the character is composed of multiple unicode scalars.
  public var unicodeScalar : Unicode.Scalar? {
    unicodeScalars.count == 1 ? unicodeScalars[unicodeScalars.startIndex] : nil
  }
}


extension CharacterSet {
  /// Return true iff the receiver contains the given character, which must be represented by a single unicode scalar.
  public func contains(_ character: Character) -> Bool  {
    guard let unicodeScalar = character.unicodeScalar else { return false }
    return self.contains(unicodeScalar)
  }
}
