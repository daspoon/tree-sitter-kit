/*

  Created by David Spooner

*/

import TSLanguage


extension TSLexMode {
  public init(lex_state s: UInt16) {
    self.init(lex_state: s, external_lex_state: 0)
  }
}
