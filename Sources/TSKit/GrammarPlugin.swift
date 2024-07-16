/*

*/


/// A convenience type for creating loadable grammar bundles.
open class GrammarPlugin {
  public init() {
  }

  /// The associated grammar type. Override required.
  open var grammarType : any Grammar.Type {
    fatalError("subclass responsibility")
  }

  /// A pairing of names and example strings to be presented in a drop-down. The default implementation returns `[]`.
  open var exampleNamesAndStrings : [(name: String, string: String)] {
    []
  }
}
