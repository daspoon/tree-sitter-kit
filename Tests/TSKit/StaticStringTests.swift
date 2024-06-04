/*

  Created by David Spooner

*/

import XCTest
import TSKit


class StaticStringTests : XCTestCase {
  func testEqual() throws {
    let examples : [(lhs: StaticString, rhs: StaticString)] = [
      ("", ""),
      ("a", "a"),
      ("heynow", "heynow"),
    ]
    for eg in examples {
      XCTAssertEqual(eg.lhs, eg.rhs)
    }
  }

  func testNotEqual() throws {
    let examples : [(lhs: StaticString, rhs: StaticString)] = [
      ("", "a"),
      ("b", ""),
      ("this", "that"),
      ("heynow", "hey"),
      ("hey", "heynow"),
      ("x", "y"),
    ]
    for eg in examples {
      XCTAssertNotEqual(eg.lhs, eg.rhs)
    }
  }

  func testLessThan() throws {
    let examples : [(lhs: StaticString, rhs: StaticString)] = [
      ("", "a"),
      ("a", "b"),
      ("A", "a"),
      ("a", "ab"),
      ("heyno", "heynow"),
      ("heynow", "heynoz"),
    ]
    for eg in examples {
      XCTAssertLessThan(eg.lhs, eg.rhs)
    }
  }

  func testGreaterThan() throws {
    let examples : [(lhs: StaticString, rhs: StaticString)] = [
      ("a", ""),
      ("b", "a"),
      ("a", "B"),
      ("ab", "a"),
      ("heynow", "heyno"),
      ("heynoz", "heynow"),
    ]
    for eg in examples {
      XCTAssertGreaterThan(eg.lhs, eg.rhs)
    }
  }

  func testLessThanOrEqual() throws {
    let examples : [(lhs: StaticString, rhs: StaticString)] = [
      ("", ""),
      ("a", "a"),
      ("a", "b"),
      ("a", "aaa"),
      ("A", "a"),
    ]
    for eg in examples {
      XCTAssertLessThanOrEqual(eg.lhs, eg.rhs)
    }
  }

  func testGreaterThanOrEqual() throws {
    let examples : [(lhs: StaticString, rhs: StaticString)] = [
      ("", ""),
      ("a", "a"),
      ("b", "a"),
      ("aaa", "a"),
      ("a", "A"),
    ]
    for eg in examples {
      XCTAssertGreaterThanOrEqual(eg.lhs, eg.rhs)
    }
  }
}
