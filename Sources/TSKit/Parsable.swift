/*

  Created by David Spooner

*/

import Foundation


/// *Parsable* identifies types which implement language elements -- i.e. which have
/// a grammar production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The grammar production rule which defines the associated symbol, syntax expression
  /// and creation method. Required.
  static var productionRule : ProductionRule<Self> { get }

  /// Indicates whether or not this type's production rule is hidden. The default
  /// implementation returns *false*.
  static var symbolIsHidden : Bool { get }

  /// The name of this language element. The default implementation returns the name
  /// of the receiving type.
  static var typeName : String { get }

  /// Create an instance of this type from a parse tree node and a context which provides
  /// access to the language and underlying source text.
  static func translate(parseTree node: TSNode, in context: ParsingContext) throws -> Self
}


// Default implementations.

extension Parsable {

  /// The name of the production rule is the *typeName*, prefixed with an underscore
  /// iff *symbolIsHidden* returns *true*.
  public static var symbolName : String
    { (symbolIsHidden ? "_" : "") + typeName }

  public static var symbolIsHidden : Bool
    { false }

  public static var typeName : String
    { "\(Self.self)" }

  public static func translate(parseTree node: TSNode, in context: ParsingContext) throws -> Self
    { try productionRule.constructor(node, context) }
}


// Parsing interface

extension Parsable {
  /// Create an instance of this type by parsing the given input source according to the
  /// given language, which must have the receiver's type as its root type.
  public static func from(inputSource src: InputSource, language lng: TSLanguage) throws -> Self {
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
    guard Self.symbolIsHidden || lng.symbolName(for: rootNode) == Self.typeName // TODO: -> symbolName
      else { throw TSError("root node has unexpected type (\(lng.symbolName(for: rootNode)))") }
    // Delegate to the ingestion method, providing the necessary context...
    return try throwingCast(Self.productionRule.constructor(rootNode, ParsingContext(language: lng, inputSource: src)))
  }

  /// Create an instance of this type by parsing the given string according to the given language.
  public static func from(text: String, encoding: String.Encoding = .utf8, language: TSLanguage) throws -> Self {
    guard let source = StringInputSource(string: text)
      else { throw TSError("unsupported string encoding: \(encoding)") }
    return try Self.from(inputSource: source, language: language)
  }
}
