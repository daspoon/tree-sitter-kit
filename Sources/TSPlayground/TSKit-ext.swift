/*

*/

import Foundation
import TSKit


extension Grammar {
  func createParser() -> TSParser {
    TSParser(Self.language)
  }
  func syntaxErrors(in tree: TSTree, for text: String, encoding e: String.Encoding = .utf8) -> [SyntaxError] {
    Self.syntaxErrors(in: tree, for: text, encoding: e)
  }
  func symbolName(for node: TSNode) -> StaticString {
    Self.symbolName(for: node)
  }
}


// Extend tree-sitter's TSNode to enable use in SwiftUI's OutlineGroup.
extension TSNode {
  // SwiftUI views which present collections require collection elements to have a stable identity...
  var identifier : UnsafeRawPointer {
    id
  }

  // OutlineGroup requires its content objects implement this method to distinguish leaves from expandable nodes.
  var children : [Self]? {
    let count = self.count
    guard count > 0 else { return nil }
    return (0 ..< count).map { self[$0] }
  }
}


// For debugging purposes

import TreeSitter

extension TSNode {
  var symbolName : String {
    String(cString: ts_node_grammar_type(self))
  }
}
