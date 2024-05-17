/*

  Created by David Spooner

*/


import Foundation


/// A *Grammar* generates the javascript source for a tree-sitter grammar with a specified name. The production rules are determined by the *Root* type and each *Parsable* type reachable through its *syntaxExpression*.

public protocol Grammar<Root> {
  associatedtype Root : Parsable

  /// The grammar/language name. The default implementation returns the receiver's type name.
  static var name : String { get }

  /// The shared instance of the language structure. Implementation provided.
  static var language : TSLanguage { get }
}


extension Grammar {
  public static var name : String
    { "\(Self.self)" }
}


//
extension Grammar {
  public static func extractString(from node: TSNode, in context: ParsingContext) -> String {
    context.inputSource.text(for: node)
  }
}


extension Grammar {
  /// Create an instance of the root type from the given input source.
  public static func parse(inputSource src: InputSource) throws -> Root {
    // Create a parser for the given language
    let parser = TSParser(language)
    // Get the parse tree for the input source; this can return nil if parsing is cancelled.
    guard let tree = parser.parse(src)
      else { throw TSError("parsing was cancelled") }
    // Throw if the parse tree contains errors.
    guard tree.rootNode.hasError == false
      else { throw TSError("error in parse tree: \(tree.rootNode.description)") }
    // Ensure the root node corresponds to the start rule and has a single child.
    let startNode = tree.rootNode
    guard language.symbolName(for: startNode) == "start", startNode.count == 1
      else { throw TSError("start node has unexpected type (\(language.symbolName(for: startNode))) and/or count \(startNode.count)") }
    // Ensure the sole child of the start node either corresponds to a production of this type or is hidden (e.g. corresponds to an enum case).
    let rootNode = startNode[0]
    guard Root.symbolIsHidden || language.symbolName(for: rootNode) == Root.typeName
      else { throw TSError("root node has unexpected type (\(language.symbolName(for: rootNode)))") }
    // Delegate to the ingestion method, providing the necessary context...
    let context = ParsingContext(language: language, inputSource: src)
    return context.translator(for: Root.self)(rootNode, context)
  }

  /// Create an instance of the root type from the given text.
  public static func parse(text: String, encoding: String.Encoding = .utf8) throws -> Root {
    guard let source = StringInputSource(string: text)
      else { throw TSError("unsupported string encoding: \(encoding)") }
    return try parse(inputSource: source)
  }
}
