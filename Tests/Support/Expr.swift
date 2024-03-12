/*

  Created by David Spooner

*/

import FunLang
import TreeSitterKit


public indirect enum Expr : Equatable
  {
    case name(String)
    case numb(Int)
    case add(Expr, Expr)
    case mult(Expr, Expr)
    case pow(Expr, Expr)
    case neg(Expr)
  }


// MARK: - parsing -

extension Expr
  {
    /// Initialize an expression from text.
    public init(_ text: String) throws
      {
        let parser = TSParser(tree_sitter_funlang())
        guard let tree = parser.parse(text)
          else { throw TSException("parser failed to return a syntax tree for '\(text)'") }
        self = try Expr(tree.rootNode[0], in: text)
      }

    /// Initialize an instance from the given 'expr' node of a syntax tree.
    public init(_ node: TSNode, in text: String) throws
      {
        // All expr nodes have a single child.
        guard node.type == "expr", node.count == 1
          else { throw TSException("unexpected node type: '\(node.type)' != 'expr'") }
        let child = node[0]

        // The type of that child dictates its structure and its representation as an Expr.
        switch (child.type, child.count) {
          case ("name", 0) :
            self = .name(child.stringValue)
          case ("numb", 0) :
            guard let value = Int(child.stringValue)
              else { throw TSException("failed to parse int value") }
            self = .numb(value)
          case ("prefix_op", 2) :
            let argExpr = try Self(child[1], in: text)
            switch child[0].stringValue {
              case "-" : self = .neg(argExpr)
              case let opName :
                throw TSException("unexpected prefix operator: '\(String(describing: opName))'")
            }
          case ("binary_op", 3) :
            let lhsExpr = try Self(child[0], in: text)
            let rhsExpr = try Self(child[2], in: text)
            switch child[1].stringValue {
              case "+" : self = .add(lhsExpr, rhsExpr)
              case "*" : self = .mult(lhsExpr, rhsExpr)
              case "^" : self = .pow(lhsExpr, rhsExpr)
              case let opName :
                throw TSException("unexpected binary operator: '\(String(describing: opName))'")
            }
          case ("paren", 3) :
            self = try Self(child[1], in: text)
          default :
            throw TSException("unexpected case (\(child.type), \(child.count)) in \(type(of: self)).\(#function)")
        }
      }
  }


// MARK: - evaluation -

extension Expr
  {
    public func evaluate() throws -> Int {
      switch self {
        case .numb(let v) :
          return v
        case .name(_) :
          throw TSException("not implemented")
        case .add(let lhs, let rhs) :
          return (try lhs.evaluate()) + (try rhs.evaluate())
        case .mult(let lhs, let rhs) :
          return (try lhs.evaluate()) * (try rhs.evaluate())
        case .pow(let lhs, let rhs) :
          return Self.power(try lhs.evaluate(), try rhs.evaluate())
        case .neg(let arg) :
          return -(try arg.evaluate())
      }
    }

  private static func power(_ i: Int, _ j: Int) -> Int
    {
      var result = 1
      for _ in 0 ..< j { result *= i }
      return result
    }
}
