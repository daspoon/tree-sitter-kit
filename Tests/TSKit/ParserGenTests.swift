/*

*/

import XCTest
import TSKit
import TSCommon
import TreeSitterCLI


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
    do {
      _ = try generateParserSource(for: nonUTF8Bytes)
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
