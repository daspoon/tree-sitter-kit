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
  }
