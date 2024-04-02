/*

  Created by David Spooner

*/

import SwiftCompilerPlugin
import SwiftSyntaxMacros


@main
struct MacroPlugin : CompilerPlugin
  {
    let providingMacros: [Macro.Type] = [
      ParsableEnum.self,
      ParsableStruct.self,
    ]
  }
