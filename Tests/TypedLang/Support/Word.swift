/*

  Created by David Spooner

*/

import TSKit


// Used to specify the 'word' rule as the name of either an identifier or an operator.

struct Word : Parsable {
  static var syntaxExpression : TSExpression {
    .pattern("([a-zA-Z_][0-9a-zA-Z_]* | [!#%&*+-/<=>^|~]+)")
  }

  init(parseTree node: TSNode, context ctx: ParsingContext) {
    fatalError("this can't happen")
  }
}
