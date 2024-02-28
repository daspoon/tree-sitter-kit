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
    public static func createParser() -> TSParser {
      TSParser(tree_sitter_funlang())
    }

    /// Initialize an expression from text.
    public init(_ text: String) throws
      {
        let parser = Self.createParser()
        guard let tree = parser.parse(text)
          else { throw Exception("parser failed to return a syntax tree for '\(text)'") }
        self = try Expr(tree.rootNode.child(at: 0), in: text)
      }

    /// Initialize an instance from the given 'expr' node of a syntax tree.
    public init(_ node: TSNode, in text: String) throws
      {
        // All expr nodes have a single child.
        guard node.type == "expr", node.count == 1
          else { throw Exception("unexpected node type: '\(node.type)' != 'expr'") }
        let child = node.child(at: 0)

        // The type of that child dictates its structure and its representation as an Expr.
        switch child.type {
          case "name" :
            self = .name(child.stringValue(in: text))
          case "numb" :
            guard let value = Int(text[child.range(in: text)])
              else { throw Exception("failed to parse int value") }
            self = .numb(value)
          case "prefix_op" :
            let (opNode, argNode) = try child.childrenAsPair()
            let argExpr = try Self(argNode, in: text)
            switch text[opNode.range(in: text)] {
              case "-" : self = .neg(argExpr)
              case let opName :
                throw Exception("unexpected prefix operator: '\(opName)'")
            }
          case "binary_op" :
            let (lhsNode, opNode, rhsNode) = try child.childrenAsTriple()
            let lhsExpr = try Self(lhsNode, in: text)
            let rhsExpr = try Self(rhsNode, in: text)
            switch text[opNode.range(in: text)] {
              case "+" : self = .add(lhsExpr, rhsExpr)
              case "*" : self = .mult(lhsExpr, rhsExpr)
              case "^" : self = .pow(lhsExpr, rhsExpr)
              case let opName :
                throw Exception("unexpected binary operator: '\(opName)'")
            }
          case "paren" :
            let (_, exprNode, _) = try child.childrenAsTriple(firstType: "(", thirdType: ")")
            self = try Self(exprNode, in: text)
          default :
            throw Exception("unhandled node type '\(child.type)' for text '\(text[child.range(in: text)])'")
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
          throw Exception("not implemented")
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
