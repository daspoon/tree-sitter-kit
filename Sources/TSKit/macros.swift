/*

  Created by David Spooner

*/


// Make the 'Grammar' macro defined in the TSMacros target publicly available in this target by the same name.
// Note: in addition to 'language', @Grammar generates declarations of `static func extractT(from: TSNode, in: ParsingContext) -> T` for each parsable type T reachable through the root type's production rule.
@attached(member, names: named(language), arbitrary)
public macro Grammar() = #externalMacro(module: "TSMacros", type: "Grammar")
