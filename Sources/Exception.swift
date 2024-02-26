/*

  Created by David Spooner

*/


/// A simple concrete type of *Error*.
struct Exception : Error
  {
    let localizedDescription : String

    init(_ failureReason: String)
      { localizedDescription = failureReason }
  }
