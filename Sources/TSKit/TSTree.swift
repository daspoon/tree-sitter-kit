/*

  Created by David Spooner

*/

import TreeSitter


public class TSTree
  {
    let ptr : OpaquePointer

    internal init(_ ptr: OpaquePointer) {
      self.ptr = ptr
    }

    deinit {
      ts_tree_delete(ptr)
    }

    public var rootNode : TSNode {
      ts_tree_root_node(ptr)
    }
  }
