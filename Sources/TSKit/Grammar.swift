/*

*/

import TreeSitter
import TreeSitterCLI
import TSCommon
import Foundation


/// The *Grammar* protocol, in conjunction with the same-named macro, enables synthesis of a
/// tree-sitter parser from a list of production rules.

public protocol Grammar<Root> {
  associatedtype Root

  /// The grammar/language name. The default implementation returns the receiver's type name.
  static var name : String { get }

  /// The set of production rules. Implementation required.
  static var productionRules : [ProductionRule] { get }

  /// Specifies the pattern for the word rule. The default implementation returns nil, indicating there is no special treatment of words.
  static var word : String? { get }

  /// Specifies the tokens which are ignored. The default implementation returns nil, indicating the tree-sitter default (whitespace is ignored).
  static var extras : [Token]? { get }

  /// The shared instance of the language structure. Implementation provided by @Grammar.
  static var language : UnsafePointer<TSLanguage> { get }

  /// The array of symbol names, excluding the built-in errorSymbol and errorRepeatSymbol. Implementation provided by @Grammar.
  static var symbolNames : [StaticString] { get }

  /// Produce an instance of the root type from the the root node of a parse tree. Implementation provided by @Grammar.
  static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root

  /// Return *true* if the rule for the given type is hidden. Implementation provided by @Grammar.
  static func isRuleHidden(for type: Any.Type) -> Bool

  /// Translate alternate rule symbols to their corresponding production rule symbols, leaving other symbols intact. Implementation provided by @Grammar.
  static func representative(for symbol: TSSymbol) -> TSSymbol

  /// Return the symbol for the given type, if any.
  static func symbol(for type: Any.Type) -> TSSymbol?
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
  named(representative(for:)),
  named(symbol(for:)),
  arbitrary
)
public macro Grammar() = #externalMacro(module: "TSMacros", type: "GrammarMacro")


/// Default implementations.

extension Grammar {
  public static var name : String
    { "\(Self.self)" }

  public static var word : String?
    { nil }

  public static var extras : [Token]?
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

  /// Return the string representation of the given symbol identifier.
  public static func symbolName(for symbol: TSSymbol) -> StaticString {
    switch symbol {
      case TSLanguage.errorSymbol : "error"
      case TSLanguage.errorRepeatSymbol : "errorRepeat"
      default :
        symbolNames[Int(symbol)]
    }
  }

  /// Return the 'type' of the given symbol.
  public static func symbolType(for symbol: TSSymbol) -> TSSymbolType {
    ts_language_symbol_type(language, symbol)
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

  /// Return the list of syntax errors.
  public static func syntaxErrors(in tree: TSTree, for text: String, encoding e: String.Encoding = .utf8) -> [SyntaxError] {
    var errors : [SyntaxError] = []

    func report(node: TSNode, kind k: SyntaxError.Kind) {
      guard let r = text.characterRange(forByteRange: node.sourceByteRange, encoding: e)
        else { fatalError("failed to translate byte range \(node.sourceByteRange) for encoding \(e)") }
      errors.append(SyntaxError(range: r, kind: k))
    }

    // Report errors in the given subtree; return true iff no error exists.
    func walk(_ node: TSNode) -> Bool {
      // Do nothing and return true if there is no embedded error.
      guard node.hasError || node.isError
        else { return true }

      // Nodes with no text range are deemed missing; process these before recursion to ensure reporting the highest-level symbol.
      if node.isEmpty {
        report(node: node, kind: .missing(representative(for: node.symbol)))
        return false
      }

      // Recurse over children, returning false if an error is found.
      guard (0 ..< node.count).reduce(true, {ok, i in walk(node[i]) && ok})
        else { return false }

      // Terminal error nodes represent invaild character sequences.
      if node.isError && node.count == 0 {
        report(node: node, kind: .unacceptable)
        return false
      }

      // Nodes whose state is .max appear to represent reductions which are potentially incomplete...
      if node.isError || node.state == .max {
        var pendingSymbols : [TSSymbol] = []
        for i in 0 ..< node.count {
          let child = node[i]
          if child.isError {
            for j in 0 ..< child.count {
              let grandchild = child[j]
              if grandchild.isError == false {
                pendingSymbols.append(representative(for: grandchild.symbol))
              }
            }
          }
          else {
            pendingSymbols.append(representative(for: child.symbol))
          }
        }
        if pendingSymbols != [] {
          report(node: node, kind: .incomplete(pendingSymbols))
        }
        return false
      }

      return true
    }

    let root = tree.rootNode
    if root.isError && root.count == 0 {
      report(node: root, kind: .empty)
    }
    else {
      _ = walk(root)
    }

    return errors
  }
}
