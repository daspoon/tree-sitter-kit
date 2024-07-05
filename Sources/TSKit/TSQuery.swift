/*

*/

import TreeSitter
import TSCommon
import TSLanguage


/// A wrapper for tree-sitter's *TSQuery* type.
public class TSQuery {
  public let language : UnsafePointer<TSLanguage>
  public let text : String
  let ptr : OpaquePointer

  /// Initialize a query for the given language and text, throwing on failure.
  public init(language l: UnsafePointer<TSLanguage>, text t: String) throws {
    var errorOffset : UInt32 = 0
    var errorType = TSQueryErrorNone
    guard let p = t.withCString({ cstr in
      ts_query_new(l, cstr, UInt32(strlen(cstr)), &errorOffset, &errorType)
    }) else {
      throw Exception("failed to parse query: error_offset=\(errorOffset); error_type=\(errorType)")
    }
    language = l
    text = t
    ptr = p
  }

  deinit {
    ts_query_delete(ptr)
  }
}
