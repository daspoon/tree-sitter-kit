/*

  Created by David Spooner

*/

import Foundation
import TreeSitter


public typealias TSInputEncoding = TreeSitter.TSInputEncoding


extension TSInputEncoding {
  /// Create an instance from a Swift string encoding, returning *nil* if that encoding is not supported.
  public init?(_ encoding: String.Encoding) {
    switch encoding {
      case .utf8  : self = TSInputEncodingUTF8
      case .utf16 : self = TSInputEncodingUTF16
      default:
        return nil
    }
  }
}
