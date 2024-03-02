/*

  Created by David Spooner

*/

import TreeSitter


extension TSNode
  {
    /// Return the receiver's type.
    public var type : String {
      // TODO: avoid allocating String instances by maintaining a mapping of type-id to string in the associated language...
      return String(cString: ts_node_type(self)!)
    }

    /// Return the range represented by the receiver in the given text.
    public func range(in text: String) -> Range<String.Index> {
      let lb = text.index(text.startIndex, offsetBy: Int(ts_node_start_byte(self)))
      let ub = text.index(text.startIndex, offsetBy: Int(ts_node_end_byte(self)))
      return Range(uncheckedBounds: (lb, ub))
    }

    /// Return the string represented by the receiver in the given text.
    public func stringValue(in text: String) -> String
      { String(text[range(in: text)]) }

    /// Return the number of child nodes.
    public var count : Int {
      Int(ts_node_child_count(self))
    }

    /// Return the child node at the specified index, which is assumed to be between *0* and *count*.
    public subscript (_ index: Int) -> TSNode {
      ts_node_child(self, UInt32(index))
    }

    /// Return the receiver's parent node, or *nil* if it has none.
    public var parent : TSNode? {
      let parent = ts_node_parent(self)
      return ts_node_is_null(parent) ? nil : parent
    }

    /// Return the index of the given node within the receiver's subnodes, or *nil* if it doesn't exist.
    public func index(of subnode: TSNode) -> Int? {
      for i in 0 ..< count {
        if self[i] == subnode {
          return i
        }
      }
      return nil
    }

    /// Return *true* if the receiver represents a syntax error.
    public var isError : Bool {
      ts_node_is_error(self)
    }

    /// Return *true* if the receiver or any of its descendants represents a syntax error.
    public var hasError : Bool {
      ts_node_has_error(self)
    }
  }


extension TSNode : Equatable
  {
    public static func == (lhs: Self, rhs: Self) -> Bool {
      ts_node_eq(lhs, rhs)
    }
  }
