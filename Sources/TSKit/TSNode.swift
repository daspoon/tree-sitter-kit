/*

  Created by David Spooner

*/

import TreeSitter


public typealias TSNode = TreeSitter.TSNode


extension TSNode
  {
    /// Return *true* iff the receiver is the 'null' node.
    public var isNull : Bool {
      ts_node_is_null(self)
    }

    /// Return *true* iff the receiver represents a named production (as opposed to a string literal).
    public var isNamed : Bool {
      ts_node_is_named(self)
    }

    /// Return the range of the parsed text represented by the receiver.
    public var sourceByteRange : Range<UInt32> {
      ts_node_start_byte(self) ..< ts_node_end_byte(self)
    }

    /// Return the number of child nodes.
    public var count : Int {
      Int(ts_node_child_count(self))
    }

    /// Return the child node at the specified index, which is assumed to be between *0* and *count*.
    public subscript (_ index: Int) -> TSNode {
      ts_node_child(self, UInt32(index))
    }

    /// Return the child node with the given field name.
    public subscript (_ name: String) -> TSNode {
      name.withCString { cstr in
        ts_node_child_by_field_name(self, cstr, UInt32(strlen(cstr)))
      }
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


extension TSNode : CustomStringConvertible
  {
    public var description : String {
      guard let buffer = ts_node_string(self)
        else { return "?" }
      defer { free(buffer) }
      return String(cString: buffer)
    }
  }


extension TSNode : Equatable
  {
    public static func == (lhs: Self, rhs: Self) -> Bool {
      ts_node_eq(lhs, rhs)
    }
  }
