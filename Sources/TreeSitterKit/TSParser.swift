/*

  Created by David Spooner

*/

import TreeSitter


public class TSParser
  {
    let ptr : OpaquePointer

    public init(_ language: OpaquePointer) {
      ptr = ts_parser_new()
      ts_parser_set_language(ptr, language)
    }

    deinit {
      ts_parser_delete(ptr)
    }

    public func parse(_ text: String, existingTree: TSTree? = nil) -> TSTree? {
      // Note: can return nil iff parsing was cancelled
      let rawTree = text.withCString {
        ts_parser_parse_string(ptr, existingTree?.opaqueTree, $0, UInt32(text.utf8.count))
      }
      return rawTree.map { TSTree(opaqueTree: $0, text: text) }
    }
  }
