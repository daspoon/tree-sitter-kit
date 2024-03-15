/*

  Created by David Spooner

*/


/// *Parsable* identifies a language element which has a tree-sitter production rule and can be initialized with a parse tree.
public protocol Parsable {
  /// The name of the grammar symbol representing this language element. The default implementation returns the receiver's type name.
  static var symbolName : String { get }

  /// The production rule for this language element.
  static var productionRule : ProductionRule<Self> { get }

  /// The means to initialize an instance from a compatible parse tree node.
  init(_ node: TSNode)
}

extension Parsable {
  /// Default implementation.
  public static var symbolName : String
    { "\(Self.self)" }

  /// Return the associated syntax expression.
  public static var syntaxExpression : TSExpression {
    switch productionRule {
      case .single(let expr) : return expr
      case .multiple(let cases) :
        return .choice(cases.map { _, pair in pair.0 })
    }
  }

  /// Return the set of representatives of *Parsable* types (excluding the receiver) which are reachable from the receiver's syntax expression.
  public static var supportingTypeProxies : Set<ParsableTypeProxy> {
    let root = ParsableTypeProxy(Self.self)
    var visited : Set<ParsableTypeProxy> = []
    var remaining : Set<ParsableTypeProxy> = [root]

    while remaining.isEmpty == false {
      let proxy = remaining.removeFirst()
      visited.insert(proxy)
      func walk(_ expr: TSExpression) {
        switch expr {
          case .rule(let proxy), .list(let proxy, _, _) :
            guard visited.contains(proxy) == false else { break }
            remaining.insert(proxy)
          case .seq(let exprs), .choice(let exprs) :
            exprs.forEach { walk($0) }
          case .prec(_, let expr) :
            walk(expr)
          case .literal, .pattern :
            break
        }
      }
      walk(proxy.syntaxExpression)
    }
    visited.remove(root)

    return visited
  }
}


/// A specialization of *Parsable* which allows parsing arrays of the conforming type.
public protocol ParsableAsArray : Parsable {
  /// The pair of literal strings which encloses array elements. The default implementation returns *("(", ")")*.
  static var bracketLiterals : (lhs: String, rhs: String) { get }
  /// The literal string which separates array elements. The default implementation returns *","*.
  static var separatorLiteral : String { get }
}

extension ParsableAsArray {
  public static var bracketLiterals : (lhs: String, rhs: String)
    { ("(", ")") }
  public static var separatorLiteral : String
    { "," }
}


/// *ParsableAsChoice* simplifies conformance to *Parsable* for types which require multiple production rules, such as enums.
public protocol ParsableAsChoice : Parsable {
  /// A mapping of sub-rule names to pairs of syntax expressions and instance constructors.
  static var productionRuleChoices : [String: (expression: TSExpression, constructor: (TSNode) -> Self)] { get }
}

extension ParsableAsChoice
  {
    public static var productionRule : ProductionRule<Self>
      { .multiple(productionRuleChoices) }

    public init(_ node: TSNode)
      {
        precondition(node.type == Self.symbolName && node.count == 1)
        let child = node[0]
        guard let choice = Self.productionRuleChoices[child.type]
          else { fatalError() }
        self = choice.constructor(child)
      }
  }
