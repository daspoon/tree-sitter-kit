/*

*/

import TreeSitter
import TSCommon
import TSLanguage
import Foundation


/// The *Grammar* protocol, in conjunction with the same-named macro, enables synthesis of a
/// tree-sitter parser from a list of production rules.

public protocol Grammar<Root> {
  associatedtype Root

  /// The grammar/language name. The default implementation returns the receiver's type name.
  static var name : String { get }

  /// The set of production rules. Implementation required.
  static var productionRules : [ProductionRule] { get }

  /// Optionally specifies the pattern for the word rule. The default implementation returns nil.
  static var word : String? { get }

  /// The shared instance of the language structure. Implementation provided by @Grammar.
  static var language : UnsafePointer<TSLanguage> { get }

  /// Produce an instance of the root type from the the root node of a parse tree. Implementation provided by @Grammar.
  static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root

  /// Return *true* if the rule for the given type is hidden. Implementation provided by @Grammar.
  static func isRuleHidden(for type: Any.Type) -> Bool

  /// Return the string representation of the given symbol identifier. Implementation provided by @Grammar.
  static func symbolName(for symbol: TSSymbol) -> StaticString
}


/// The Grammar macro is intended to be applied to structures conforming to the Grammar protocol.
/// It implements the named protocol requirements, along with an extraction method of the following
/// form for each symbol type `T` reachable from the production rule of the `Root` type:
///   `private static func extractT(from: TSNode, in: ParsingContext) -> T

@attached(member, names:
  named(language),
  named(isRuleHidden(for:)),
  named(translate(parseTree:context:)),
  named(symbolName(for:)),
  arbitrary
)
public macro Grammar() = #externalMacro(module: "TSMacros", type: "GrammarMacro")


/// Default implementations.

extension Grammar {
  public static var name : String
    { "\(Self.self)" }

  public static var word : String?
    { nil }
}


/// Utility methods.

extension Grammar {
  /// Extract the text for the given node. This enables String to be treated as a parsable types within with respect to production rule captures.
  public static func extractString(from node: TSNode, in context: ParsingContext) -> String {
    context.text(for: node)
  }

  /// Return the symbol name for the given node.
  public static func symbolName(for node: TSNode) -> StaticString {
    symbolName(for: ts_node_grammar_symbol(node))
  }

  /// Create an instance of the root type from the given input source.
  public static func parse(inputSource src: InputSource) throws -> Root {
    // Create a parser for the given language
    let parser = TSParser(language)
    // Get the parse tree for the input source; this can return nil if parsing is cancelled.
    guard let tree = parser.parse(src)
      else { throw Exception("parsing was cancelled") }
    // Throw if the parse tree contains errors.
    guard tree.rootNode.hasError == false
      else { throw Exception("error in parse tree: \(tree.rootNode.description)") }
    // Ensure the root node corresponds to the start rule and has a single child.
    let startNode = tree.rootNode
    guard symbolName(for: startNode) == "start", startNode.count == 1
      else { throw Exception("start node has unexpected type (\(symbolName(for: startNode))) and/or count \(startNode.count)") }
    // Ensure the sole child of the start node either corresponds to a production of this type or is hidden (e.g. corresponds to an enum case).
    let rootNode = startNode[0]
    guard isRuleHidden(for: Root.self) || symbolName(for: rootNode) == "\(Root.self)"
      else { throw Exception("root node has unexpected type (\(symbolName(for: rootNode)))") }
    // Delegate to the ingestion method, providing the necessary context...
    return translate(parseTree: rootNode, in: ParsingContext(inputSource: src))
  }

  /// Create an instance of the root type from the given text.
  public static func parse(text: String, encoding: String.Encoding = .utf8) throws -> Root {
    guard let source = StringInputSource(string: text, encoding: encoding)
      else { throw Exception("unsupported string encoding: \(encoding)") }
    return try parse(inputSource: source)
  }
}
