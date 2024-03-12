/*

  Created by David Spooner

*/

import Foundation
import TreeSitter


/// A wrapper for the tree-sitter's opaque *TSTree* type which maintains an association to the parsed text.
public class TSTree
  {
    let opaqueTree : OpaquePointer

    /// Intended for use by *TSParser* to initialize a new instance given the parsed text and the opaque parse tree.
    internal init(opaqueTree ptr: OpaquePointer, text: String) {
      opaqueTree = ptr
      Self.setText(text, for: ptr)
    }

    deinit {
      Self.setText(nil, for: opaqueTree)
      ts_tree_delete(opaqueTree)
    }

    /// The start node.
    public var rootNode : TSNode {
      ts_tree_root_node(opaqueTree)
    }

    // Maintain an association between opaque TSTree instances and their source text.
    // Note that associated objects don't work for this purpose.

    static var textByOpaqueTree : [OpaquePointer: String] = [:]
    static let semaphore = DispatchSemaphore(value: 1)

    internal static func getText(for opaqueTree: OpaquePointer) -> String? {
      semaphore.wait()
      let text = textByOpaqueTree[opaqueTree]
      semaphore.signal()
      return text
    }

    internal static func setText(_ textOrNil: String?, for opaqueTree: OpaquePointer) {
      semaphore.wait()
      switch textOrNil {
        case .some(let text) :
          textByOpaqueTree[opaqueTree] = text
        case .none :
          textByOpaqueTree.removeValue(forKey: opaqueTree)
      }
      semaphore.signal()
    }
  }
