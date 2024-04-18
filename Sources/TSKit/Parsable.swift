/*

  Created by David Spooner

*/

import Foundation


/// *Parsable* identifies a language element which has a tree-sitter production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The name of the grammar symbol representing this language element. The default implementation returns the receiver's type name.
  static var symbolName : String { get }

  /// Indicates whether or not the corresponding production rule is hidden. The default implementation returns *false*.
  static var productionRuleIsHidden : Bool { get }

  /// The name of the production rule for this language element. The default implementation returns *symbolName*, prefixed with an underscore if *productionRuleIsHidden* returns *true*.
  static var productionRuleName : String { get }

  /// Return the syntax expression for instances of this type. Required.
  static var syntaxExpression : TSExpression { get }

  /// Initialize an instance from a compatible parse tree node. Required.
  init(parseTree: TSNode, context: ParsingContext)
}


// Default implementations.

extension Parsable {
  public static var symbolName : String
    { "\(Self.self)" }

  public static var productionRuleIsHidden : Bool
    { false }

  public static var productionRuleName : String
    { (productionRuleIsHidden ? "_" : "") + symbolName }

  /// Create an instance of this type by parsing the given input source according to the given language,
  /// which must have the receiver's type as its root type.
  public init(inputSource src: InputSource, language lng: TSLanguage) throws {
    // Create a parser for the given language
    let parser = TSParser(lng)
    // Get the parse tree for the input source; this can return nil if parsing is cancelled.
    guard let tree = parser.parse(src)
      else { throw TSError("parsing was cancelled") }
    // Throw if the parse tree contains errors.
    guard tree.rootNode.hasError == false
      else { throw TSError("error in parse tree: \(tree.rootNode.description)") }
    // Ensure the root node corresponds to the start rule and has a single child.
    let startNode = tree.rootNode
    guard lng.symbolName(for: startNode) == Grammar.startSymbol, startNode.count == 1
      else { throw TSError("start node has unexpected type (\(lng.symbolName(for: startNode))) and/or count \(startNode.count)") }
    // Ensure the sole child of the start node either corresponds to a production of this type or is hidden (e.g. corresponds to an enum case).
    let rootNode = startNode[0]
    guard Self.productionRuleIsHidden || lng.symbolName(for: rootNode) == Self.symbolName
      else { throw TSError("root node has unexpected type (\(lng.symbolName(for: rootNode)))") }
    // Delegate to the ingestion method, providing the necessary context...
    self.init(parseTree: rootNode, context: ParsingContext(language: lng, inputSource: src))
  }

  /// Create an instance of this type by parsing the given string according to the given language.
  public init(text: String, encoding: String.Encoding = .utf8, language: TSLanguage) throws {
    guard let source = StringInputSource(string: text)
      else { throw TSError("unsupported string encoding: \(encoding)") }
    try self.init(inputSource: source, language: language)
  }
}
