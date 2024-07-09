/*

*/

import XCTest
import TSKit


/// Test the utility methods defined on *UnsafePointer* and *UnsafeBufferPointer* which are used to implement various static properties in the expansion of the *Grammar* macro.
class UnsafePointerTests : XCTestCase {
  // Auxiliary type
  struct Position : Hashable { let row, column : Int }

  /// Test UnsafePointer.initialized(implicitlyZeroing:using:), which is used to implement the *language* property.
  func testValue() throws {
    struct Thing : Equatable {
      var a, b, c : Int
      var d: Double
    }
    let examples : [(value: Thing, initializer: (inout Thing) -> Void)] = [
      (.init(a: 0, b: 0, c: 0, d: 0), { _ in }),
      (.init(a: 1, b: 0, c: 3, d: 0), { $0.a = 1; $0.c = 3 }),
      (.init(a: 1, b: 2, c: 3, d: 4), { $0.a = 1; $0.b = 2; $0.c = 3; $0.d = 4 }),
    ]
    for eg in examples {
      let ptr = UnsafePointer<Thing>.initialized(implicitlyZeroing: true, using: eg.initializer)
      XCTAssert(eg.value == ptr.pointee)
      ptr.deallocate()
    }
  }

  /// Test UnsafeBufferPointer.initialized(with:), which is used to create various static arrays.
  func testArrayOfValues() throws {
    let examples : [Array<Int>] = [
      .init(1 ... 10),
      [42],
      [],
    ]
    for array in examples {
      let buffer = UnsafeBufferPointer<Int>.initialized(with: array)
      XCTAssert(array.count == buffer.count)
      for i in 0 ..< array.count {
        XCTAssertEqual(array[i], buffer[i])
      }
      buffer.deallocate()
    }
  }

  /// Test UnsafeBufferPointer.initialized(count:zero:indexValuePairs:), which is used to implement the *ts_primary_state_ids*, *ts_lex_modes*, and *ts_external_scanner_symbol_map* properties.
  func testArrayOfIndexValuePairs() throws {
    let examples : [(count: Int, pairs: [(index: Int, value: Int)])] = [
      (10, [(1, 111), (5, 555), (9, 999)]),
      (10, (0 ..< 10).map {i in (i, i * 10)}),
      (0, []),
    ]
    for eg in examples {
      let buffer = UnsafeBufferPointer<Int>.initialized(count: eg.count, indexValuePairs: eg.pairs)
      XCTAssert(buffer.count == eg.count)
      let mapping = Dictionary(uniqueKeysWithValues: eg.pairs)
      for i in 0 ..< eg.count {
        XCTAssertEqual(buffer[i], mapping[i] ?? 0)
      }
      buffer.deallocate()
    }
  }

  /// Test UnsafeBufferPointer.initialized(rowCount:columnCount:zero:rowColumnValueTriples:), which is used to implement the *ts_alias_sequences* and *ts_external_scanner_states* properties.
  func testMatrixOfRowColumnValueTriples() throws {
    let examples : [(rowCount: Int, columnCount: Int, triples: [(row: Int, column: Int, value: Int)])] = [
      (5, 5, [(0, 0, 1), (1, 1, 2), (2, 2, 3), (3, 3, 4), (4, 4, 5), (0, 4, 6), (4, 0, 7)]),
      (2, 3, []),
      (0, 1, []),
      (1, 0, []),
    ]
    for eg in examples {
      let buffer = UnsafeBufferPointer<Int>.initialized(rowCount: eg.rowCount, columnCount: eg.columnCount, rowColumnValueTriples: eg.triples)
      XCTAssertEqual(buffer.count, eg.rowCount * eg.columnCount)
      let mapping = Dictionary(uniqueKeysWithValues: eg.triples.map {t in (key: Position(row: t.row, column: t.column), value: t.value)})
      for i in 0 ..< eg.rowCount {
        for j in 0 ..< eg.columnCount {
          XCTAssertEqual(buffer[i * eg.columnCount + j], mapping[Position(row: i, column: j)] ?? 0)
        }
      }
      buffer.deallocate()
    }
  }

  /// Test UnsafeBufferPointer.initialized(rowCount:columnCount:zero:columnValuesByRow:), which is used to implement the *ts_parse_table* property.
  func testMatrixOfColumnValuesByRow() throws {
    let examples : [(rowCount: Int, columnCount: Int, columnValuesByRow: Array<(row: Int, pairs: Array<(column: Int, value: Int)>)>)] = [
      (10, 10, (0 ..< 10).map {i in (i, (0 ..< 10).map {j in (j, i * j + 1)})}),
      (10, 10, []),
      (0, 10, []),
      (10, 0, []),
      (0, 0, []),
    ]
    for eg in examples {
      let buffer = UnsafeBufferPointer<Int>.initialized(rowCount: eg.rowCount, columnCount: eg.columnCount, columnValuesByRow: eg.columnValuesByRow)
      XCTAssertEqual(buffer.count, eg.rowCount * eg.columnCount)
      let mapping = Dictionary(uniqueKeysWithValues: eg.columnValuesByRow.flatMap { row, columnValues in
        columnValues.map { column, value in
          (key: Position(row: row, column: column), value: value)
        }
      })
      for i in 0 ..< eg.rowCount {
        for j in 0 ..< eg.columnCount {
          XCTAssertEqual(buffer[i * eg.columnCount + j], mapping[Position(row: i, column: j)] ?? 0)
        }
      }
      buffer.deallocate()
    }
  }

  /// Test UnsafeBufferPointer.arrayOfCSrings(_:), which is used to implement *symbolNames* and *fieldNames*.
  func testArrayOfCStrings() throws {
    let examples : [[StaticString?]] = [
      ["hey", "μ", "getoffa", "icloud", nil],
      [],
    ]
    for sstrings in examples {
      let cstrings = UnsafeBufferPointer.arrayOfCSrings(sstrings)
      XCTAssert(cstrings.count == sstrings.count)
      for i in 0 ..< cstrings.count {
        XCTAssert(sstrings[i].map {$0.hasPointerRepresentation} ?? true)
        switch (sstrings[i], cstrings[i]) {
          case (.some(let sstring), .some(let cstring)) :
            let length = sstring.utf8CodeUnitCount + 1 // +1 to include null terminator
            let sstring_cast = UnsafeRawPointer(sstring.utf8Start).bindMemory(to: Int8.self, capacity: length)
            XCTAssertEqual(strncmp(sstring_cast, cstring, sstring.utf8CodeUnitCount + 1), 0);
          case (.none, .none) :
            break
          default :
            XCTFail()
        }
      }
      cstrings.deallocate()
    }
  }
}
