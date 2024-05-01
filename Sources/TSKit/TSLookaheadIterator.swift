/*

  Created by David Spooner

*/

import TreeSitter


/// A wrapper for tree-sitter's *TSLookaheadIterator* type.
public class TSLookaheadIterator {
  let ptr : OpaquePointer

  public init(language: TSLanguage, state: TSStateId) {
    guard let iterator = ts_lookahead_iterator_new(language.ptr, state)
      else { fatalError("failed to create iterator") }
    assert(ts_lookahead_iterator_current_symbol(iterator) == TSLanguage.errorSymbol)
    ptr = iterator
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
