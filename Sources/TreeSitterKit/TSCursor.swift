/*

  Created by David Spooner

*/

import TreeSitter


/// A variation on *TSTreeCursor* which provides scanner-like functionality.
public struct TSCursor
  {
    // Note: An initial implementation via TSTreeCursor did not behave as expected, so an explict stack was used instead...

    private var stack : [State]
    struct State {
      let parent : TSNode
      let count : Int
      var index : Int
      init(parent p: TSNode, count n: Int, index i: Int) { parent = p; count = n; index = i }
      init(parent p: TSNode, index i: Int = 0) { self.init(parent: p, count: p.count, index: i) }
      var node : TSNode? { index < count ? parent[index] : nil }
    }

    /// Initialize a new instance pointing to the *i*-th subnode of the given node; fails if either the given node has no subnodes or the given index is out of range.
    public init(subnodesOf parent: TSNode, from i: Int = 0) throws {
      let n = parent.count
      guard (0 ..< n).contains(i) else { throw TSException("invalid arguments") }
      stack = [.init(parent: parent, count: n, index: i)]
    }

    /// Initialize a new instance pointing to the given node.
    public init(node: TSNode) throws {
      guard let parent = node.parent, let index = parent.index(of: node)
        else { throw TSException("invalid argument") }
      try self.init(subnodesOf: parent, from: index)
    }

    /// The current node, or *nil* if there is none.
    public var node : TSNode! {
      stack.last?.node
    }

    /// Advance and return the current node if it is non-*nil* and has the given type, otherwise throw.
    @discardableResult
    public mutating func scanNode(of type: String? = nil) throws -> TSNode {
      guard let node, type == nil || type == .some(node.type)
        else { throw TSException("expecting a node of type '\(type ?? "<any>")'") }
      stack[stack.count-1].index += 1
      return node
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The method (which takes the receiver and the index of the element to scan) must either advance the receiver's state and return *true* if an element is recognized, or leave the state intact and return *false* otherwise. Returns the number of scanned elements.
    @discardableResult
    public mutating func scanElements(bracketedBy brackets: (leading: String, trailing: String)? = nil, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> Bool) throws -> Int {
      var count : Int = 0
      if let brackets {
        try scanNode(of: brackets.leading)
      }
      while let node, brackets?.trailing != .some(node.type) {
        if count > 0 {
          try scanNode(of: separator)
        }
        if try process(&self, count) == false {
          break
        }
        count += 1
      }
      if let brackets {
        try scanNode(of: brackets.trailing)
      }
      return count
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The method (which takes the receiver and the index of the element to scan) must either advance the receiver's state and return an element value, or leave the state intact and return *nil*. Returns the array of scanned elements.
    public mutating func scanArray<T>(bracketedBy brackets: (leading: String, trailing: String)? = nil, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> T?) throws -> [T] {
      var elements : [T] = []
      _ = try scanElements(bracketedBy: brackets, separatedBy: separator) { cursor, index in
        guard let element = try process(&cursor, index)
          else { return false }
        elements.append(element)
        return true
      }
      return elements
    }

    /// Returns the result of invoking the preceding method if the current node represents a leading bracket, or *[]* otherwise.
    public mutating func scanOptionalArray<T>(bracketedBy brackets: (leading: String, trailing: String), separatedBy separator: String, using process: (inout TSCursor, Int) throws -> T?) throws -> [T] {
      guard node?.type == brackets.leading
        else { return [] }
      return try scanArray(bracketedBy: brackets, separatedBy: separator, using: process)
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The method (which takes the receiver and the index of the element to scan) must either advance the receiver's state and return a key/value pair, or leave the state intact and return *nil*. Returns the dictionary of scanned key/value pairs.
    public mutating func scanDictionary<K, V>(bracketedBy brackets: (leading: String, trailing: String)?, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> (K, V)?) throws -> [K: V] {
      try Dictionary(try scanArray(bracketedBy: brackets, separatedBy: separator, using: process)) { _, _ in
        throw TSException("duplicate keys")
      }
    }
    /// Returns the result of invoking the preceding method if the current node represents a leading bracket, or *[:]* otherwise.
    public mutating func scanOptionalDictionary<K, V>(bracketedBy brackets: (leading: String, trailing: String), separatedBy separator: String, using process: (inout TSCursor, Int) throws -> (K, V)?) throws -> [K: V] {
      guard node?.type == brackets.leading
        else { return [:] }
      return try scanDictionary(bracketedBy: brackets, separatedBy: separator, using: process)
    }

    /// Descend into the current node. Throw if the current node is *nil* or has no subnodes.
    public mutating func enter() throws {
      guard let node, node.count > 0
        else { throw TSException("invalid argument") }
      stack.append(.init(parent: node))
    }

    /// Ascend out of the current node, implicitly advancing to the next sibling of the current node's parent. Throw if the traversal has not met the current node's parent.
    public mutating func exit() throws {
      guard stack.count > 1
        else { throw TSException("invalid argument") }
      stack.removeLast()
      stack[stack.count-1].index += 1
    }
  }
