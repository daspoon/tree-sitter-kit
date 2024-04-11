/*

  Created by David Spooner

*/


// Make the 'Parsable' macro defined in the TSMacros target publicly available in this target by the same name.

@attached(member, names: named(init(parseTree:source:)))
public macro Parsable() = #externalMacro(module: "TSMacros", type: "Parsable")
