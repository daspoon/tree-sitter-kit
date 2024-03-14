/*

  Created by David Spooner

*/


/// *ProductionRule* represents a rule of a tree-sitter grammar together with a method which constructs instances of the associated type from matching parse tree nodes.
public enum ProductionRule<T: Parsable>
  {
    case single(TSExpression)
    case multiple([String: (TSExpression, (TSNode) -> T)])

    /// Return the receiver's javascript representation, which has a prefix of the from '*T.symbolName*: $ => ', and a suffix which is either
    /// a single expression or a choice of implicitly generated production rules...
    public func javascript(indent i: Int) -> String
      {
        func seq(label: String, expression: TSExpression) -> String
          { "\(label): $ => \(expression.javascript)" }

        func choice(label: String, indent i: Int, sublabels: [String]) -> String
          { label + ": $ => choice(\n" + .space(i) + sublabels.map({"$.\($0)"}).joined(separator: ",\n" + .space(i)) + "\n)" }

        switch self {
          case .single(let expr) :
            return seq(label: T.symbolName, expression: expr)
          case .multiple(let choices) :
            let choices = choices.sorted(by: {$0.key < $1.key})
            let lines = [choice(label: T.symbolName, indent: i, sublabels: choices.map {$0.key})]
              + choices.map({seq(label: $0.key, expression: $0.value.0)})
            return lines.joined(separator: ",\n")
        }
      }
  }
