/*

  Created by David Spooner

*/

import Foundation
import TreeSitter


/// A wrapper for the tree-sitter's opaque *TSTree* type which maintains an association to the parsed text.
public class TSTree
  {
    let opaqueTree : OpaquePointer
    public let inputSource : InputSource

    /// Intended for use by *TSParser* to initialize a new instance given the opaque parse tree and the text input source.
    internal init?(opaqueTree ptr: OpaquePointer?, inputSource src: InputSource) {
      guard let ptr else { return nil }
      opaqueTree = ptr
      inputSource = src
    }

    deinit {
      ts_tree_delete(opaqueTree)
    }

    /// The start node.
    public var rootNode : TSNode {
      ts_tree_root_node(opaqueTree)
    }
  }
