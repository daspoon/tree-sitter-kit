/*

  Created by David Spooner

*/

@attached(member, names: named(from(_:)))
public macro ParsableStruct() = #externalMacro(module: "Macros", type: "ParsableStruct")

@attached(member, names: named(from(_:)))
public macro ParsableEnum() = #externalMacro(module: "Macros", type: "ParsableEnum")
