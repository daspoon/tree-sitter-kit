/*

  Created by David Spooner

*/

struct Exception : Error, CustomStringConvertible {
  let description : String
  init(_ failureReason: String) {
    description = failureReason
  }
}
