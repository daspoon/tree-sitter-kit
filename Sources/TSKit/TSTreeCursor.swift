/*

  Created by David Spooner

  Notes:
    - ts_tree_cursor_current_field_name is not exposed (say as currentFieldName); instead use currentFieldId and TSLanguage.fieldName(for:).
    - an earlier implementation existed as TSCursor

*/

import TreeSitter


/// A wrapper for tree-sitter's *TSTreeCursor* type.
public class TSTreeCursor {
  private var _cursor : TreeSitter.TSTreeCursor

  /// Initialize a new instance pointing to the given node.
  public init(node: TSNode) {
    _cursor = ts_tree_cursor_new(node)
  }

  public init(_ other: TSTreeCursor) {
    _cursor = ts_tree_cursor_copy(&other._cursor)
  }

  deinit {
    ts_tree_cursor_delete(&_cursor)
  }

  /// The current node, or *nil* if there is none.
  public var currentNode : TSNode {
     ts_tree_cursor_current_node(&_cursor)
  }

  public var currentFieldId : TSFieldId {
    ts_tree_cursor_current_field_id(&_cursor)
  }

  public func reset(_ node: TSNode) {
    ts_tree_cursor_reset(&_cursor, node)
  }

  public func reset(to other: TSTreeCursor) {
    ts_tree_cursor_reset_to(&_cursor, &other._cursor)
  }

  public func gotoParent() -> Bool {
    ts_tree_cursor_goto_parent(&_cursor)
  }

  public func gotoNextSibling() -> Bool {
    ts_tree_cursor_goto_next_sibling(&_cursor)
  }

  public func gotoPreviousSibling() -> Bool {
    ts_tree_cursor_goto_previous_sibling(&_cursor)
  }

  public func gotoFirstChild() -> Bool {
    ts_tree_cursor_goto_first_child(&_cursor)
  }

  public func gotoLastChild() -> Bool {
    ts_tree_cursor_goto_last_child(&_cursor)
  }

  public func gotoFirstChild(for byte: UInt32) -> Int64 {
    ts_tree_cursor_goto_first_child_for_byte(&_cursor, byte)
  }

  public func gotoDescendant(at index: UInt32) {
    ts_tree_cursor_goto_descendant(&_cursor, index)
  }

  public var currentDescendantIndex : UInt32 {
    ts_tree_cursor_current_descendant_index(&_cursor)
  }

  public var currentDepth : UInt32 {
    ts_tree_cursor_current_depth(&_cursor)
  }

  /// Move the cursor to the first leaf descendant of the current node. Return `true` if the cursor moved, or `false` if there was no descendant node.
  public func gotoFirstLeafDescendant() -> Bool {
    var moved = false
    while gotoFirstChild() {
      moved = true
    }
    return moved
  }
}
