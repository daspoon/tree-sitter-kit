/*

  Created by David Spooner

*/

@attached(member, names: named(init(parseTree:)))
public macro ParsableStruct() = #externalMacro(module: "TSMacros", type: "ParsableStruct")

@attached(member, names: named(init(parseTree:)))
public macro ParsableEnum() = #externalMacro(module: "TSMacros", type: "ParsableEnum")
