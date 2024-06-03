/*

  Created by David Spooner

*/

import TSLanguage


extension TSSymbolMetadata {
  public init(visible v: Bool, named n: Bool) {
    self.init(visible: v, named: n, supertype: false)
  }
}
