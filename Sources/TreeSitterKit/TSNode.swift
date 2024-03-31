/*

  Created by David Spooner

*/

import TreeSitter


public typealias TSNode = TreeSitter.TSNode


extension TSNode
  {
    /// Return the receiver's type.
    public var type : String {
      // TODO: avoid allocating String instances by maintaining a mapping of type-id to string in the associated language...
      return String(cString: ts_node_type(self)!)
    }

    public func hasType(_ type: String) -> Bool {
      type.withCString { ptr in
        strcmp(ptr, ts_node_type(self)) == 0
      }
    }

    /// Return *true* iff the receiver is the 'null' node.
    public var isNull : Bool {
      ts_node_is_null(self)
    }

    /// Return the substring of the parsed text which is represented by the receiver.
    public var substringValue : Substring! {
      guard let tree, let text = TSTree.getText(for: tree)
        else { print("no text for tree \(tree)"); return nil }
      let lb = text.index(text.startIndex, offsetBy: Int(ts_node_start_byte(self)))
      let ub = text.index(text.startIndex, offsetBy: Int(ts_node_end_byte(self)))
      return text[Range(uncheckedBounds: (lb, ub))]
    }

    /// Return the substring of the parsed text which is represented by the receiver.
    public var stringValue : String! {
      substringValue.map {String($0)}
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
