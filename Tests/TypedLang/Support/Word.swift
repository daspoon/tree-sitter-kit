/*

  Created by David Spooner

*/

import TSKit


// Used to specify the 'word' rule as the name of either an identifier or an operator.

struct Word : Parsable {
  static var productionRule : ProductionRule<Self> {
    .init(syntaxExpression: .pattern("([a-zA-Z_][0-9a-zA-Z_]* | [!#%&*+-/<=>^|~]+)")) { node, ctx in
      return Self()
    }
  }
}
