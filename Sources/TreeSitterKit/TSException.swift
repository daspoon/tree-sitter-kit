/*

  Created by David Spooner

*/


/// A simple concrete type of *Error*.
public struct TSException : Error
  {
    let localizedDescription : String

    init(_ failureReason: String)
      { localizedDescription = failureReason }
  }
