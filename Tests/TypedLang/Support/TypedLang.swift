/*

  Created by David Spooner

  Note: this should be generated within a language target, but would require SPM to support mixed-language targets.

*/

import TSKit
import TypedLang


public struct TypedLang {
  public static let parser = TSParser(tree_sitter_TypedLang())
}
