/*

  Created by David Spooner

*/


/// *Exception* is used to signal error conditions in macro expansion.

public struct Exception : Error {
  public let code : Int
  public let failureReason : String

  public init(code k: Int, failureReason r: String) {
    code = k
    failureReason = r
  }

  public init(_ failureReason: String) {
    self.init(code: -1, failureReason: failureReason)
  }
}

extension Exception : CustomStringConvertible {
  public var description : String {
    failureReason
  }
}
