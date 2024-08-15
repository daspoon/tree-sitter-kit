/*

*/

import XCTest
import TSKit
import TSCommon
import TreeSitterCLI


/// Test the callable interface to tree-sitter CLI.
class ParserGenTests : XCTestCase {
  let validJsonText = """
    {
      "name": "TestSuccess",
      "rules": {
        "start": { "type": "SYMBOL", "name": "Word" },
        "Word": { "type": "PATTERN", "value": "[a-z]+" }
      },
      "extras": [],
      "conflicts": [],
      "precedences": [],
      "externals": [],
      "inline": [],
      "supertypes": []
    }
    """

  /// Ensure that non-empty text is returned for a trivial valid grammar.
  func testSuccess() throws {
    let swiftText = try generateParserSource(for: validJsonText)
    XCTAssert(swiftText.isEmpty == false)
  }

  func testAccessModifier() throws {
    for modifier in ["public", "package"] {
      let swiftText = try generateParserSource(for: validJsonText, accessModifier: modifier)
      XCTAssert(swiftText.contains(try Regex("\(modifier) static let symbolNames")))
      XCTAssert(swiftText.contains(try Regex("\(modifier) static let language")))
    }
  }

  /// Ensure that specifying an invalid ABI version if rejected.
  func testInvalidVersion() throws {
    do {
      _ = try generateParserSource(for: validJsonText, abi_version: UInt32.max)
      XCTFail("failed to throw")
    }
    catch let error as Exception {
      XCTAssertEqual(error.code, SWIFTGEN_ERROR_INVALID_VERSION)
    }
  }

  /// Ensure that specifying a non-UTF8 encoded by sequence is rejected.
  func testInvalidInput() throws {
    let nonUTF8Bytes = UnsafeBufferPointer<UInt8>.initialized(with: [0xff])
    let accessBytes = UnsafeBufferPointer<UInt8>.initialized(with: [])
    do {
      _ = try generateParserSource(for: nonUTF8Bytes, accessModifier: accessBytes)
      XCTFail("failed to throw")
    }
    catch let error as Exception {
      XCTAssertEqual(error.code, SWIFTGEN_ERROR_INVALID_INPUT)
    }
  }

  /// Ensure that an error is produced for an incomplete grammar (missing required entries).
  func testIncompleteGrammar() throws {
    do {
      _ = try generateParserSource(for: "{}")
      XCTFail("failed to throw")
    }
    catch let error as Exception {
      XCTAssertEqual(error.code, SWIFTGEN_ERROR_OTHER)
    }
  }
}
