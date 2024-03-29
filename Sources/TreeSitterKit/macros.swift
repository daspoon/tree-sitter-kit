/*

  Created by David Spooner

*/

@attached(member, names: named(init(parseTree:)))
public macro ParsableStruct() = #externalMacro(module: "Macros", type: "ParsableStruct")

@attached(member, names: named(init(parseTree:)))
public macro ParsableEnum() = #externalMacro(module: "Macros", type: "ParsableEnum")
