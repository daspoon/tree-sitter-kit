/*

  Created by David Spooner

*/


/// A simple concrete type of *Error*.
public struct TSException : Error
  {
    public let localizedDescription : String

    public init(_ failureReason: String)
      { localizedDescription = failureReason }
  }
