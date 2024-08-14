/*

*/

import SwiftSyntax


struct ExpansionError : Error {
  typealias Issue = (node: any SyntaxProtocol, message: String)
  let issues : [Issue]

  init(issues: [Issue]) {
    self.issues = issues
  }

  init(node: some SyntaxProtocol, message: String) {
    issues = [(node, message)]
  }

  static func combining(_ fst: Self, _ snd: Self) -> Self {
    .init(issues: fst.issues + snd.issues)
  }
}
