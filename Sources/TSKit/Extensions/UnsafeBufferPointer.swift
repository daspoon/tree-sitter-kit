/*

*/

import Foundation


extension UnsafeBufferPointer {
  /// Return a buffer containing the given elements.
  public static func initialized(with elements: [Element]) -> Self {
    let umrbp = UnsafeMutableRawBufferPointer.allocate(byteCount: elements.count * MemoryLayout<Element>.stride, alignment: MemoryLayout<Element>.alignment)
    let umbp = umrbp.bindMemory(to: Element.self)
    for i in 0 ..< elements.count {
      umbp[i] = elements[i]
    }
    return Self(umbp)
  }

  /// Return a buffer representing an array of *count* values, containing the given index/value pairs and *zero* elsewhere.
  public static func initialized(count: Int, zero: Element, indexValuePairs: [(index: Int, value: Element)]) -> Self {
    let umrbp = UnsafeMutableRawBufferPointer.allocate(byteCount: count * MemoryLayout<Element>.stride, alignment: MemoryLayout<Element>.alignment)
    let umbp = umrbp.bindMemory(to: Element.self)
    var indices = IndexSet(integersIn: 0 ..< count)
    for (index, value) in indexValuePairs {
      assert((0 ..< count).contains(index))
      umbp[index] = value
      indices.remove(index)
    }
    for index in indices {
      umbp[index] = zero
    }
    return Self(umbp)
  }

  // Return a buffer representing a 2d matrix of *rowCount* times *columnCount* values, containing the given row/column/value triples and *zero* elsewhere.
  public static func initialized(rowCount: Int, columnCount: Int, zero: Element, rowColumnValueTriples: [(row: Int, column: Int, value: Element)]) -> Self {
    let umrbp = UnsafeMutableRawBufferPointer.allocate(byteCount: rowCount * columnCount * MemoryLayout<Element>.stride, alignment: MemoryLayout<Element>.alignment)
    let umbp = umrbp.bindMemory(to: Element.self)
    var indices = IndexSet(integersIn: 0 ..< rowCount * columnCount)
    for (row, column, value) in rowColumnValueTriples {
      assert((0 ..< rowCount).contains(row) && (0 ..< columnCount).contains(column))
      let index = row * columnCount + column
      umbp[index] = value
      indices.remove(index)
    }
    for index in indices {
      umbp[index] = zero
    }
    return Self(umbp)
  }

  // Return a buffer representing a 2d matrix of *rowCount* times *columnCount* values, with each specified row containing the given column values and *zero* elsewhere.
  public static func initialized<R: BinaryInteger, C: BinaryInteger>(rowCount: Int, columnCount: Int, zero: Element, columnValuesByRow: [(row: R, [(column: C, value: Element)])]) -> Self {
    let umrbp = UnsafeMutableRawBufferPointer.allocate(byteCount: rowCount * columnCount * MemoryLayout<Element>.stride, alignment: MemoryLayout<Element>.alignment)
    let umbp = umrbp.bindMemory(to: Element.self)
    var indices = IndexSet(integersIn: 0 ..< rowCount * columnCount)
    for (row, columnValues) in columnValuesByRow {
      for (column, value) in columnValues {
        assert((0 ..< rowCount).contains(Int(row)) && (0 ..< columnCount).contains(Int(column)))
        let index = Int(row) * columnCount + Int(column)
        umbp[index] = value
        indices.remove(index)
      }
    }
    for index in indices {
      umbp[index] = zero
    }
    return Self(umbp)
  }
}


extension UnsafeBufferPointer where Element : ExpressibleByIntegerLiteral {
  public static func initialized(count k: Int, indexValuePairs v: [(index: Int, value: Element)]) -> Self {
    .initialized(count: k, zero: 0, indexValuePairs: v)
  }

  public static func initialized(rowCount n: Int, columnCount m: Int, rowColumnValueTriples v: [(row: Int, column: Int, value: Element)]) -> Self {
    .initialized(rowCount: n, columnCount: m, zero: 0, rowColumnValueTriples: v)
  }

  public static func initialized<R: BinaryInteger, C: BinaryInteger>(rowCount n: Int, columnCount m: Int, columnValuesByRow v: [(row: R, [(column: C, value: Element)])]) -> Self {
    .initialized(rowCount: n, columnCount: m, zero: 0, columnValuesByRow: v)
  }
}


extension UnsafeBufferPointer where Element == UnsafePointer<CChar>? {
  typealias CString = UnsafePointer<CChar>?

  /// Allocate and initialize a buffer containing the C string pointers for the given array of static strings.
  /// A runtime error will occur unless all given strings satisfy `hasPointerRepresentation`.
  public static func arrayOfCSrings(_ strings: [StaticString?]) -> Self {
    let ptrbuf = UnsafeMutableRawBufferPointer.allocate(byteCount: strings.count * MemoryLayout<CString>.stride, alignment: MemoryLayout<CString>.alignment)
      .bindMemory(to: CString.self)
    for (i, string) in strings.enumerated() {
      ptrbuf[i] = string?.cStringStart
    }
    return Self(ptrbuf)
  }

  public static func arrayOfCSrings(_ strings: [StaticString]) -> Self {
    arrayOfCSrings(strings.map {$0 as StaticString?})
  }
}
