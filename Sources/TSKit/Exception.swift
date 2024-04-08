/*

  Created by David Spooner

*/


/// Used to signal error conditions within this package.
internal struct Exception : Error {
  let failureReason : String
  init(_ text: String)
    { failureReason = text }
}
