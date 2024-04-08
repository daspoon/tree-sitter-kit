/*

  Created by David Spooner

*/

import TreeSitter


/// A minimal variation on *TSTreeCursor* which provides scanner-like functionality. This interface will be extended with hierarchy navigation as necessary.
public class TSCursor
  {
    private var _cursor : TSTreeCursor
    private var _node : TSNode!

    /// Initialize a new instance pointing to the given node.
    public init(node: TSNode) {
      _cursor = ts_tree_cursor_new(node)
      _node = node
    }

    /// Initialize a new instance pointing to the first subnode of the given node; fails if the given node has no subnodes.
    public convenience init(subnodesOf parent: TSNode) throws {
      guard parent.count > 0
        else { throw Exception("invalid argument") }
      self.init(node: parent[0])
    }

    deinit {
      ts_tree_cursor_delete(&_cursor)
    }

    /// The current node, or *nil* if there is none.
    public var node : TSNode!
      { _node }

    /// Advance and return *true* iff the current node is non-*nil* and has the given type.
    @discardableResult
    public func scanNode(of type: String? = nil) -> Bool {
      guard let node, type == nil || type == .some(node.type)
        else { return false }
      let didAdvance = ts_tree_cursor_goto_next_sibling(&_cursor)
      _node = didAdvance ? ts_tree_cursor_current_node(&_cursor) : nil
      return true
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The given method (which is given the receiver and the index of the element to be scanned) must either advance the receiver's state and return *true* if an element is recognized, or leave the state intact and return *false* otherwise. Returns the number of scanned elements.
    @discardableResult
    public func scanElements(bracketedBy brackets: (leading: String, trailing: String)?, separatedBy separator: String, using process: (TSCursor, Int) throws -> Void) throws -> Int {
      var count : Int = 0
      guard brackets.map({scanNode(of: $0.leading)}) ?? true
        else { throw Exception("expecting leading '\(brackets!.leading)'") }
      while let node, brackets?.trailing != .some(node.type) {
        guard count == 0 || scanNode(of: separator)
          else { throw Exception("expecting '\(separator)' separator") }
        try process(self, count)
        count += 1
      }
      guard brackets.map({scanNode(of: $0.trailing)}) ?? true
        else { throw Exception("expecting trailing '\(brackets!.trailing)'") }
      return count
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The given method (which is given the receiver and the index of the element to be scanned) must either advance the receiver's state and return the scanned element, or leave the state intact and return *nil*. Returns the array of scanned elements.
    public func scanElements<T>(of type: T.Type = T.self, bracketedBy brackets: (leading: String, trailing: String)?, separatedBy separator: String, using process: (TSCursor, Int) throws -> T) throws -> [T] {
      var elements : [T] = []
      _ = try scanElements(bracketedBy: brackets, separatedBy: separator) { scanner, index in
        elements.append(try process(self, index))
      }
      return elements
    }

    /// Descend into the current node. Throw if the current node is nil or has no subnodes.
    public func enter() throws -> TSNode {
      guard let node
        else { throw Exception("node is nil") }
      guard node.count > 0
        else { throw Exception("node is a leaf") }
      ts_tree_cursor_goto_first_child(&_cursor)
      _node = ts_tree_cursor_current_node(&_cursor)
      return _node
    }

    /// Ascend out of the current node. Throw if the current node is nil or has no parent.
    public func exit() throws -> TSNode {
      guard let node
        else { throw Exception("node is nil") }
      guard ts_tree_cursor_goto_parent(&_cursor)
        else { throw Exception("node has no parent") }
      _node = ts_tree_cursor_current_node(&_cursor)
      return _node
    }
  }
