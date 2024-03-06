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
      guard let node
        else { throw TSException("missing node\(type.map {" of type '\($0)'"} ?? "")") }
      guard type == nil || type! == node.type
        else { throw TSException("expecting '\(type!)' node; found \(node.type)") }
      guard node.isError == false
        else { throw TSException("encounered error node\(type.map {" of type '\($0)'"} ?? "")") }
      stack[stack.count-1].index += 1
      return node
    }

    /// Scan and transform the current node.
    public mutating func scanNode<T>(of type: String? = nil, transform: (TSNode) throws -> T) throws -> T {
      try transform(try scanNode(of: type))
    }

    /// A convenience type for specifying a bracket symbol pairs.
    public struct BracketPair {
      public let leading : String
      public let trailing : String
      public init(leading l: String, trailing t: String) { leading = l; trailing = t }
      public static var angle : Self { .init(leading: "<", trailing: ">") }
      public static var curly : Self { .init(leading: "{", trailing: "}") }
      public static var round : Self { .init(leading: "(", trailing: ")") }
      public static var square : Self { .init(leading: "[", trailing: "]") }
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The method (which takes the receiver and the index of the element to scan) must either advance the receiver's state and return *true* if an element is recognized, or leave the state intact and return *false* otherwise. Returns the number of scanned elements.
    @discardableResult
    public mutating func scanElements(bracketedBy brackets: BracketPair? = nil, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> Bool) throws -> Int {
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
    public mutating func scanArray<T>(bracketedBy brackets: BracketPair? = nil, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> T?) throws -> [T] {
      var elements : [T] = []
      _ = try scanElements(bracketedBy: brackets, separatedBy: separator) { cursor, index in
        guard let element = try process(&cursor, index)
          else { return false }
        elements.append(element)
        return true
      }
      return elements
    }

    public mutating func scanKeyValuePairs<K, V>(bracketedBy brackets: BracketPair, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> (K, V)?) throws -> ([K], [V]) where K: Hashable {
      var pairs : ([K], [V]) = ([], [])
      var keys : Set<K> = []
      _ = try scanElements(bracketedBy: brackets, separatedBy: separator) { cursor, index in
        guard let pair = try process(&cursor, index)
          else { return false }
        guard keys.contains(pair.0) == false
          else { throw TSException("duplicate key: '\(pair.0)'") }
        keys.insert(pair.0)
        pairs.0.append(pair.0)
        pairs.1.append(pair.1)
        return true
      }
      return pairs
    }

    /// Returns the result of invoking the preceding method if the current node represents a leading bracket, or *[]* otherwise.
    public mutating func scanOptionalArray<T>(bracketedBy brackets: BracketPair, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> T?) throws -> [T] {
      guard node?.type == brackets.leading
        else { return [] }
      return try scanArray(bracketedBy: brackets, separatedBy: separator, using: process)
    }

    /// Scan a sequence of elements delimited by the given separator type and optionally enclosed by the given bracket types. The method (which takes the receiver and the index of the element to scan) must either advance the receiver's state and return a key/value pair, or leave the state intact and return *nil*. Returns the dictionary of scanned key/value pairs.
    public mutating func scanDictionary<K, V>(bracketedBy brackets: BracketPair?, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> (K, V)?) throws -> [K: V] {
      try Dictionary(try scanArray(bracketedBy: brackets, separatedBy: separator, using: process)) { _, _ in
        throw TSException("duplicate keys")
      }
    }
    /// Returns the result of invoking the preceding method if the current node represents a leading bracket, or *[:]* otherwise.
    public mutating func scanOptionalDictionary<K, V>(bracketedBy brackets: BracketPair, separatedBy separator: String, using process: (inout TSCursor, Int) throws -> (K, V)?) throws -> [K: V] {
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

    /// Ascend out of the current node, advancing to the next sibling of the current node's parent by default. Throw if the traversal has not met the current node's parent.
    public mutating func exit(advance: Bool = true) throws {
      guard stack.count > 1
        else { throw TSException("invalid argument") }
      stack.removeLast()
      if advance {
        stack[stack.count-1].index += 1
      }
    }
  }
