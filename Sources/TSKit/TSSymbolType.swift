/*

  Created by David Spooner

*/

import TreeSitter


extension TSSymbolType {
  public static var regular : Self
    { .init(rawValue: 0) }
  public static var anonymous : Self
    { .init(rawValue: 1) }
  public static var auxiliary : Self
    { .init(rawValue: 2) }
}

extension TSSymbolType : CustomStringConvertible {
  public var description : String {
    switch self {
      case .regular : return "regular"
      case .anonymous : return "anonymous"
      case .auxiliary : return "auxiliary"
      default :
        return "unknown(\(rawValue))"
    }
  }
}
