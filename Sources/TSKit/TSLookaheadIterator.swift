/*

*/

import TreeSitter
import TreeSitterCLI


/// A wrapper for tree-sitter's *TSLookaheadIterator* type.
public class TSLookaheadIterator {
  let ptr : OpaquePointer

  /// Initialize an instance for the given language.
  public init(language: UnsafePointer<TSLanguage>) {
    // Note: state 0 indicates end-of-input and is always valid.
    ptr = ts_lookahead_iterator_new(language, 0)
  }

  /// Initialize an instance for the given language and state. This will fail for invalid states, such as 65535 which is assigned to various nodes in the vicinity of ERROR nodes.
  public init?(language: UnsafePointer<TSLanguage>, state: TSStateId) {
    guard let ptr = ts_lookahead_iterator_new(language, state)
      else { return nil }
    self.ptr = ptr
  }

  deinit {
    ts_lookahead_iterator_delete(ptr)
  }

  public var currentSymbol : TSSymbol {
    ts_lookahead_iterator_current_symbol(ptr)
  }

  public func next() -> Bool {
    ts_lookahead_iterator_next(ptr)
  }

  /// Attempt to reset iteration to the given state. Return `true` iff successful.
  public func reset(state: TSStateId) -> Bool {
    ts_lookahead_iterator_reset_state(ptr, state)
  }

  /// Return the list of valid symbols for the parse state given on initialization.
  public var validSymbols : AnySequence<TSSymbol> {
    return AnySequence(AnyIterator {
      self.next() ? self.currentSymbol : nil
    })
  }
}
