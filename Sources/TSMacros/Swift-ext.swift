/*

  Created by David Spooner
  
*/


extension Collection {
  public var only : Element? {
    count == 1 ? first : nil
  }
}

// MARK: -

extension String {
  func removing(prefix p: String?, suffix s: String?) -> String {
    var trimmed = self
    if let prefix = p, let range = trimmed.range(of: prefix, options:.anchored) {
      trimmed = String(trimmed[range.upperBound ..< trimmed.endIndex])
    }
    if let suffix = s, let range = trimmed.range(of: suffix, options: [.anchored, .backwards]) {
      trimmed = String(trimmed[trimmed.startIndex ..< range.lowerBound])
    }
    return trimmed
  }
}
