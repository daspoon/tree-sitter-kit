/*

  Created by David Spooner

*/

import TreeSitter


/// A wrapper for the tree-sitter's *TSParser* struct.
public class TSParser
  {
    public let language : TSLanguage
    let ptr : OpaquePointer

    public init(_ language: TSLanguage) {
      self.language = language
      ptr = ts_parser_new()
      ts_parser_set_language(ptr, language.ptr)
    }

    deinit {
      ts_parser_delete(ptr)
    }

    /// Parse text from the given input source to produce a tree which is optionally an alteration of an existing tree. May return *nil*if parsing was cancelled.
    public func parse(_ source: InputSource, existingTree: TSTree? = nil) -> TSTree? {
      let opaqueTree = ts_parser_parse(ptr, existingTree?.opaqueTree, source.tsinput)
      return TSTree(opaqueTree: opaqueTree, inputSource: source)
    }

    /// Parse the given string to produce a tree which is optionally an alteration of an existing tree. May return *nil*if parsing was cancelled.
    public func parse(_ text: String, existingTree: TSTree? = nil) -> TSTree? {
      guard let source = StringInputSource(string: text)
        else { return nil }
      return parse(source)
    }
  }
