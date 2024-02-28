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
    public func child(at index: Int) -> TSNode {
      ts_node_child(self, UInt32(index))
    }
  }


// MARK: - convenience -

extension TSNode
  {
    /// Return the child node at the specified index; throw if its type does not match the given type.
    public func child(of expectedType: String?, at index: Int) throws -> TSNode
      {
        let child = child(at: index)
        if let expectedType, child.type != expectedType {
          throw TSException("unexpected type for child \(index) of '\(type)': \(child.type) != \(expectedType)")
        }
        return child
      }

    /// Return the receiver's single child node, with optionally constrained type; throw if the receiver does not have a single child or if its type does not match the given constraint.
    public func childrenAsSingleton(of childType: String? = nil) throws -> TSNode
      {
        guard count == 1
          else { throw TSException("unexpected child count for '\(type)' node: \(count) != 1") }
        return try child(of: childType, at: 0)
      }

    /// Return the receiver's two child nodes, with optionally constrained types; throw if the receiver does not have exactly two child nodes or if their types do not match the given constraints.
    public func childrenAsPair(firstType: String? = nil, secondType: String? = nil) throws -> (TSNode, TSNode)
      {
        guard count == 2
          else { throw TSException("unexpected child count for '\(type)' node: \(count) != 2") }
        return (try child(of: firstType, at: 0), try child(of: secondType, at: 1))
      }

    /// Return the receiver's three child nodes, with optionally constrained types; throw if the receiver does not have exactly two child nodes or if their types do not match the given constraints.
    public func childrenAsTriple(firstType: String? = nil, secondType: String? = nil, thirdType: String? = nil) throws -> (TSNode, TSNode, TSNode)
      {
        guard count == 3
          else { throw TSException("unexpected child count for '\(type)' node: \(count) != 3") }
        return (try child(of: firstType, at: 0), try child(of: secondType, at: 1), try child(of: thirdType, at: 2))
      }
  }
