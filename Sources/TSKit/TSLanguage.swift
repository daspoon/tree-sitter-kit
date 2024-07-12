/*

*/

import TreeSitter
@_exported import TreeSitterCLI


extension TSLanguage {
  /// The built-in symbol for `ERROR`.
  public static var errorSymbol : TSSymbol
    { .max } // ts_builtin_sym_error

  /// The built-in symbol for `_ERROR`.
  public static var errorRepeatSymbol : TSSymbol
    { .max - 1 } // ts_builtin_sym_error_repeat
}
