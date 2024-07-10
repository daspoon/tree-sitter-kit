/*

*/

import TreeSitter


/// This protocol serves as an extension on *TSInput* which enables retrieval of source text corresponding to *TSNode* instances.

public protocol InputSource {
  /// Return the portion of the source text for the given byte range, or the empty string if that range is invalid.
  func text(in range: Range<UInt32>) -> String

  /// Return the structure required by tree-sitter's parse method.
  var tsinput : TSInput { get }
}
