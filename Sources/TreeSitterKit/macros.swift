/*

  Created by David Spooner

*/

@attached(member, names: named(init(_:)))
public macro ParsableStruct() = #externalMacro(module: "Macros", type: "ParsableStruct")

@attached(member, names: named(syntaxExpression), named(init(_:)))
public macro ParsableEnum(subrules: [String: TSExpression]) = #externalMacro(module: "Macros", type: "ParsableEnum")
