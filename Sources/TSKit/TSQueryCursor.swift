/*

  Created by David Spooner

*/

import TreeSitter


/// A wrapper for tree-sitter's *TSQueryCursor* type.
public class TSQueryCursor {
  let ptr : OpaquePointer
  var state : (query: TSQuery, node: TSNode)?

  public init() {
    ptr = ts_query_cursor_new()
  }

  public convenience init(query: TSQuery, on node: TSNode) {
    self.init()
    exec(query: query, on: node)
  }

  deinit {
    ts_query_cursor_delete(ptr)
  }

  public var matchLimit : UInt32 {
    get { ts_query_cursor_match_limit(ptr) }
    set { ts_query_cursor_set_match_limit(ptr, newValue) }
  }

  public var didExceedMatchLimit : Bool {
    ts_query_cursor_did_exceed_match_limit(ptr)
  }

  public func exec(query: TSQuery, on node: TSNode) {
    ts_query_cursor_exec(ptr, query.ptr, node)
  }

  public var nextMatch : TSQueryMatch? {
    var match = TSQueryMatch()
    return ts_query_cursor_next_match(ptr, &match) ? match : nil
  }

  public var nextCapture : TSQueryCapture? {
    var match = TSQueryMatch()
    var index = UInt32(0)
    guard ts_query_cursor_next_capture(ptr, &match, &index)
      else { return nil }
    assert((0 ..< UInt32(match.capture_count)).contains(index))
    return match.captures![Int(index)]
  }
}
