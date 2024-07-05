/*

*/


/// The *ProductionRule* type serves as a syntax for specifying production rules for language elements,
/// pairing syntax expressions with instance constructors.
public struct ProductionRule {
  /// Specify a production rule for language element `T` as a single syntax expression along
  /// a constructor for `T` (i.e. a function taking the captures of the syntax expression and
  /// returning an instance of `T`).
  public init<T, each A>(_ type: T.Type, _ expression: Expression, constructor f: (repeat each A) throws -> T) { }

  /// Specify a production rule for language element `T` as a choice of syntax expressions
  /// along with the corresponding constructors.
  public init<T>(_ type: T.Type, choicesByName: [String: Choice<T>]) { }

  /// A pairing of syntax expression and constructor.
  public struct Choice<T> {
    public init<each A>(_ expression: Expression, _ constructor: (repeat each A) throws -> T) { }
  }
}
