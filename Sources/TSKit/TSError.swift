/*

  Created by David Spooner

*/


/// Used to signal error conditions within this package.
public struct TSError : Error {
  public let failureReason : String
  public init(_ text: String)
    { failureReason = text }
}
