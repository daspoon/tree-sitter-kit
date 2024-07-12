/*

*/

import XCTest
import TSKit


enum JSONValue : Equatable {
  case object(JSONObject)
  case array(JSONArray)
  case string(JSONString)
  case number(JSONNumber)
  case bool(JSONBool)
  case null
}

typealias JSONObject = Dictionary<JSONString, JSONValue>
typealias JSONMember = JSONObject.Element
typealias JSONArray = Array<JSONValue>
typealias JSONString = String
typealias JSONNumber = Double
typealias JSONBool = Bool


@Grammar
struct JSONGrammar : Grammar {
  typealias Root = JSONValue

  static var productionRules : [ProductionRule] {
    return [
      .init(JSONValue.self, choicesByName: [
        "object": .init(.seq(["{", .opt(.sym(JSONObject.self)), "}"])) { mems in .object(mems ?? [:]) },
        "array": .init(.seq(["[", .opt(.sym(JSONArray.self)), "]"])) { elts in .array(elts ?? []) },
        "string": .init(.sym(JSONString.self)) { str in .string(str) },
        "number": .init(.sym(JSONNumber.self)) { num in .number(num) },
        "true": .init(.lit("true")) { () in .bool(true) },
        "false": .init(.lit("false")) { () in .bool(false) },
        "null": .init(.lit("null")) { () in .null },
      ]),
      .init(JSONObject.self, .rep(.sym(JSONMember.self), .sep(","))) { (mems: Array<JSONMember>) in Dictionary(uniqueKeysWithValues: mems) },
      .init(JSONMember.self, .seq([.sym(JSONString.self), ":", .sym(JSONValue.self)])) { k, v in (k, v) },
      .init(JSONArray.self, .rep(.sym(JSONValue.self), .sep(","))) { elts in elts },
      .init(JSONNumber.self, .pat("(-?)(0|[1-9][0-9]*)([.][0-9]+)?([eE][+-]?[0-9]+)?")) { str in .init(Double(str)!) },
      .init(JSONString.self, .pat("\"([^\"\\\\\\n]|[\\\\]([\\\\/bfnrt]|u[0-9a-fA-F]{4,4}))*\"")) { str in removingFirstAndLastCharacter(of: str) },
    ]
  }
}


class JSONTests : XCTestCase {
  func testBuild() throws { }

  func testSuccess() throws {
    let examples : [(text: String, value: JSONValue)] = [
      ("null", nil),

      ("true", true),
      ("false", false),

      ("0", 0),
      ("-1", -1),
      ("1.5", 1.5),
      ("1.5e3", 1.5e3),
      ("1.5e+3", 1.5e+3),
      //("1.5e-3", .number(1.5e-3)), // need approximate comparison

      ("\"\"", ""),
      ("\"heynow\"", "heynow"),
      ("\"\\n\"", "\\n"),
      ("\"\\u03bb\"", "\\u03bb"),

      ("[]", []),
      ("[1, \"two\", [null, true, false]]", [1, "two", [nil, true, false]]),

      ("{}", [:]),
      ("{\"a\": 1}", ["a": 1]),
      ("{\"a\": 1, \"b\": 2, \"c\": 3}", ["a": 1, "b": 2, "c": 3]),
      ("{\"\": {\"x\": null}}", ["": ["x": nil]]),
    ]
    for eg in examples {
      XCTAssertEqual(try JSONGrammar.parse(text: eg.text), eg.value, eg.text)
    }
  }

  func testFailure() throws {
    let examples : [String] = [
      "",           // no text
      //"\"\n\"",   // no newlines (NOTE: this fails, perhaps due to the default treatment of whitespace)
      "leading\"",  // no leading quote
      "\"trailing", // no trailing quote
      "\"\\ux\"",   // invalid utf8 character
      "01",         // unnecessary leading zero
      "1.",
      ".2",
    ]
    for text in examples {
      do {
        _ = try JSONGrammar.parse(text: text)
        XCTFail("failed to reject invalid text: `\(text)`")
      }
      catch { }
    }
  }
}

// convenience

extension JSONValue : ExpressibleByNilLiteral {
  init(nilLiteral: ()) {
    self = .null
  }
}

extension JSONValue : ExpressibleByBooleanLiteral {
  init(booleanLiteral: Bool) {
    self = .bool(booleanLiteral)
  }
}

extension JSONValue : ExpressibleByIntegerLiteral {
  init(integerLiteral: Int) {
    self = .number(Double(integerLiteral))
  }
}

extension JSONValue : ExpressibleByFloatLiteral {
  init(floatLiteral: Float) {
    self = .number(Double(floatLiteral))
  }
}

extension JSONValue : ExpressibleByStringLiteral {
  init(stringLiteral: String) {
    self = .string(stringLiteral)
  }
}

extension JSONValue : ExpressibleByArrayLiteral {
  init(arrayLiteral: JSONValue...) {
    self = .array(arrayLiteral)
  }
}

extension JSONValue : ExpressibleByDictionaryLiteral {
  init(dictionaryLiteral: (JSONString, JSONValue)...) {
    self = .object(Dictionary(uniqueKeysWithValues: dictionaryLiteral))
  }
}

func removingFirstAndLastCharacter(of string: String) -> String {
  var copy = string
  copy.removeFirst()
  copy.removeLast()
  return copy
}
