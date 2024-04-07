/*

  Created by David Spooner

*/


/// *Exception* is used to signal error conditions in macro expansion.

struct Exception : Error, CustomStringConvertible {
  let description : String
  init(_ failureReason: String) {
    description = failureReason
  }
}
