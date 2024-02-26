/*

  Created by David Spooner

*/


import SwiftTreeSitter


extension STSNode
  {
    /// Return the range represented by the receiver in the given text.
    func range(in text: String) -> Range<String.Index>
      {
        let lb = text.index(text.startIndex, offsetBy: Int(byteRange.lowerBound))
        let ub = text.index(text.startIndex, offsetBy: Int(byteRange.upperBound))
        assert(text.startIndex <= lb && ub <= text.endIndex)
        return Range(uncheckedBounds: (lb, ub))
      }


    /// Return the string represented by the receiver in the given text.
    func stringValue(in text: String) -> String
      { String(text[range(in: text)]) }


    /// Return the child node at the specified index, throwing if its type does not match the given string.
    func child(of expectedType: String?, at index: Int) throws -> STSNode
      {
        let child = child(at: UInt32(index))
        if let expectedType, child.type != expectedType {
          throw Exception("unexpected type for child \(index) of '\(type)': \(child.type) != \(expectedType)")
        }
        return child
      }


    /// Return the receiver's single child node, with optionally constrained type; throw if the receiver does not have a single child or if its type does not match the given constraint.
    func asSingleton(childType: String? = nil) throws -> STSNode
      {
        try assertCount(1)
        return try child(of: childType, at: 0)
      }


    /// Return the receiver's two child nodes, with optionally constrained types; throw if the receiver does not have exactly two child nodes or if their types do not match the given constraints.
    func asPair(firstType: String? = nil, secondType: String? = nil) throws -> (STSNode, STSNode)
      {
        try assertCount(2)
        return (try child(of: firstType, at: 0), try child(of: secondType, at: 1))
      }

    /// Return the receiver's three child nodes, with optionally constrained types; throw if the receiver does not have exactly two child nodes or if their types do not match the given constraints.
    func asTriple(firstType: String? = nil, secondType: String? = nil, thirdType: String? = nil) throws -> (STSNode, STSNode, STSNode)
      {
        try assertCount(3)
        return (try child(of: firstType, at: 0), try child(of: secondType, at: 1), try child(of: thirdType, at: 2))
      }


    /// Throw if the receiver's *childCount* does not match the given value.
    private func assertCount(_ expectedCount: Int) throws
      {
        guard childCount == expectedCount
          else { throw Exception("unexpected child count for '\(type)' node: \(childCount) != \(expectedCount)") }
      }
  }
