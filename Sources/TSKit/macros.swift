/*

  Created by David Spooner

*/


/// The Grammar macro is intended to be applied to structures conforming to the Grammar protocol.
/// It adds the following protocol requirements
///   ```
///   static var language : TSLanguage
///   static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root
///   ```
/// along with methods of the following form for each symbol type `T` reachable from the `Root`
/// type's production rule:
///   `static func extractT(from: TSNode, in: ParsingContext) -> T`

@attached(member, names: /*named(language), */named(translate(parseTree:context:)), arbitrary)
public macro Grammar() = #externalMacro(module: "TSMacros", type: "Grammar")
