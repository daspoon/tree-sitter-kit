/*

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

    /// Return a list of the byte ranges which have changed from the given previous tree to the receiver.
    public func getChangedRanges(from previous: TSTree?) -> [Range<Int>] {
      var len : UInt32 = 0
      guard let buf = ts_tree_get_changed_ranges(opaqueTree, previous?.opaqueTree, &len)
        else { print("ts_tree_get_changed_ranges returned nil"); return [] }
      defer { free(buf) }
      return Array(unsafeUninitializedCapacity: Int(len)) { arr, count in
        print("input count is \(count)")
        for i in 0 ..< Int(len) {
          let tsrange = buf[i]
          arr[i] = Range(uncheckedBounds: (Int(tsrange.start_byte), Int(tsrange.end_byte)))
        }
        count = Int(len)
      }
    }
  }
