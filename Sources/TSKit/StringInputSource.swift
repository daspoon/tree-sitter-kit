/*

  Created by David Spooner

*/

import Foundation
import TreeSitter


/// An InputSource backed by a String.

public class StringInputSource : InputSource {

  let cstring : (buffer: UnsafePointer<CChar>, length: Int)
  let encoding : String.Encoding

  public init?(string: String, encoding e: String.Encoding = .utf8) {
    guard TSInputEncoding(e) != nil else { return nil }
    cstring = string.cstringBuffer
    encoding = e
  }

  deinit {
    cstring.buffer.deallocate()
  }

  public func text(in range: Range<UInt32>) -> String {
    guard range.upperBound <= cstring.length else { return "" }
    let ptr = cstring.buffer + Int(range.lowerBound)
    let len = Int(range.upperBound - range.lowerBound)
    let enc = encoding.rawValue
    return NSString(bytes: ptr, length: len, encoding: enc)! as String
  }

  public var tsinput : TSInput {
    return TSInput(
      payload: Unmanaged.passUnretained(self).toOpaque(),
      read: { payload, offset, _, count_p -> UnsafePointer<CChar>? in
        let this = Unmanaged<StringInputSource>.fromOpaque(payload!).takeUnretainedValue()
        let offset = min(Int(offset), this.cstring.length)
        count_p?.pointee = UInt32(this.cstring.length - offset)
        return this.cstring.buffer + offset
      },
      encoding: .init(encoding)!
    )
  }
}

