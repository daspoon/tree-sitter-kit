/*

  Created by David Spooner

*/

import TSLanguage


extension TSLexMode {
  public init(lex_state s: UInt16) {
    self.init(lex_state: s, external_lex_state: 0)
  }

  public static var zero : Self {
    .init()
  }

  public static var endOfNonTerminalExtra : Self {
    .init(lex_state: .max, external_lex_state: .max)
  }
}
