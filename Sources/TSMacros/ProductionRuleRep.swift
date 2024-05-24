/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros


/// *ProductionRule* is the 'implementation' of the client-side type of the same name.
struct ProductionRule {
  /// *Form* distinguishes between production rules which have single vs multiple expressions;
  /// note that the latter determines multiple rules in the generated grammar.
  enum Form {
    case single(Choice), multiple([String: Choice])
  }

  /// *Choice* pairs a syntax expression and a constructor with shared type signature.
  struct Choice {
    let expression : Expression
    let signature : Signature
    let constructor : ClosureExprSyntax

    /// Attempt to create an instance from the given expression and closure; throw if
    /// either:
    ///   - the closure does not have explicit parameter
    ///   - the form of expression is not supported
    ///   - the expression capture count does not match the constructor parameter count.
    init(expression e: Expression, constructor c: ClosureExprSyntax) throws {
      guard let parameterCount = c.signature?.parameterCount
        else { throw Exception("trailing closure must have explicit parameter names") }
      expression = e
      signature = try Signature(expression: e)
      constructor = c
      guard signature.captureCount == parameterCount
        else { throw Exception("expression capture count (\(signature.captureCount)) does not match constructor parameter count (\(parameterCount))") }
    }

    /// Return the text for an invocation of the constructor with argument values extracted
    /// from an implicit parse tree 'node' and 'context'...
    var invocationText : String {
      let invocationArgumentsText = switch signature {
        case .symbol(let type) :
          extractionText(for: type)
        case .array(let eltType, .sep(let sep)) :
          "Array<\(eltType)>.extractElements(separatedBy: \"\(sep)\", from: node, in: context, using: {\(extractionText(for: eltType, with: "$0", in: "$1"))})"
        case .array(let eltType, .del(let del)) :
          "Array<\(eltType)>.extractElements(delimitedBy: \"\(del)\", from: node, in: context, using: {\(extractionText(for: eltType, with: "$0", in: "$1"))})"
        case .array(let eltType, .none) :
          "Array<\(eltType)>.extractElements(from: node, in: context, using: {\(extractionText(for: eltType, with: "$0", in: "$1"))})"
        case .tuple(let captures) :
          captures.enumerated()
            .map({ index, capture in
              let nodeText = "node[\"\(index)\"]"
              return capture.optional
                ? "{$0.isNull ? nil : \(extractionText(for: capture.symbol, with: "$0"))}(\(nodeText))"
                : extractionText(for: capture.symbol, with: nodeText)
            })
            .joined(separator: ", ")
      }
      return "\(constructor)(\(invocationArgumentsText))"
    }

    /// Return the text used to create an instance of the given type from the given node.
    func extractionText(for typeName: String, with nodeText: String = "node", in contextText: String = "context") -> String {
      "extract\(typeName)(from: \(nodeText), in: \(contextText))"
    }
  }


  /// The name of the associated language element type.
  let typeName : String
  /// The set of pairs of syntax expressions and constructors.
  let form : Form


  /// Return the text which defines the function to extract an instance of the associated type from a parse tree node and context.
  var extractionDeclText : String {
    """
    private static func extract\(typeName)(from node: TSNode, in context: ParsingContext) -> \(typeName) {
      \(extractionBodyText)
    }
    """
  }

  /// Indicates whether or not the associated symbol is hidden.
  var isSymbolHidden : Bool {
    if case .multiple = form { true } else { false }
  }

  /// Returns the symbol name for the associated type.
  var symbolName : String {
    isSymbolHidden ? "_" + typeName : typeName
  }

  /// Return the body text for the method which extracts an instance of the associated
  /// type from a given parse tree 'node' and 'context'.
  var extractionBodyText : String {
    switch form {
      case .single(let choice) :
        choice.invocationText
      case .multiple(let choicesByName) :
        """
        switch context.language.symbolName(for: node) {
          \(
            choicesByName.map({ key, choice in
              "case \"\(typeName)_\(key)\" : \(choice.invocationText)"
            })
            .joined(separator: "\n")
          )
          case let other:
            fatalError("unexpected symbol: \\(other)")
        }
        """
    }
  }

  /// Return the implied grammar rules as a list of pairs of symbol names and raw syntax expressions.
  func getSymbolNamesAndRawExpressions(_ lookup: (String) throws -> String) throws -> [(symbolName: String, rawExpression: RawExpression)] {
    return switch form {
      case .single(let choice) :
        [(symbolName, try choice.expression.getRawExpression(lookup))]
      case .multiple(let choicesByName) :
        [(symbolName, .choice(choicesByName.map({name, _ in .symbol(typeName + "_" + name)})))]
          + (try choicesByName.map({ name, choice in (typeName + "_" + name, try choice.expression.getRawExpression(lookup)) }))
    }
  }
}


extension ProductionRule {
  /// Attempt to create an instance from a Swift syntax expression.
  init(_ expr: ExprSyntax) throws {
    guard let funcall = expr.as(FunctionCallExprSyntax.self), funcall.arguments.count == 2
      else { throw Exception("expecting function call with two arguments") }

    // Get the produced type from the first argument, which must be of the form `T.self`
    guard let name = try funcall.arguments[0].expression.typeName
      else { throw Exception("expecting type reference") }
    typeName = name

    // Distinguish single and multiple clause initializers
    let arg2 = funcall.arguments[1]
    switch arg2.label?.text {
      case .none : // init<T, each A>(_ type: T.Type, _ expression: Expression, constructor f: (repeat each A) throws -> T)
        guard let closure = funcall.trailingClosure
          else { throw Exception("expecting trailing closure") }
        form = .single(try Choice(expression: try Expression(exprSyntax: arg2.expression), constructor: closure))
      case "choicesByName" : // init<T>(_ type: T.Type, choicesByName: [String: Choice<T>])
        guard let dict = arg2.expression.as(DictionaryExprSyntax.self), case .elements(let elements) = dict.content
          else { throw Exception("'syntaxExpressionsByCaseName' must return a non-empty dictionary") }
        let namesWithClauses = try elements
          .map({ element in
            guard let name = element.key.as(StringLiteralExprSyntax.self)?.stringLiteral
              else { throw Exception("dictionary keys must be string literals") }
            guard let funcall = element.value.as(FunctionCallExprSyntax.self), funcall.arguments.count == 1
              else { throw Exception("expecting a single FunctionCallExpr argument") }
            guard let closure = funcall.trailingClosure
              else { throw Exception("expecting a trailing closure") }
            let expr = try Expression(exprSyntax: funcall.arguments[0].expression)
            return (name, try Choice(expression: expr, constructor: closure))
          })
        form = .multiple(Dictionary(uniqueKeysWithValues: namesWithClauses))
      case .some(let other) :
        throw Exception("invalid argument label: \(other)")
    }
  }
}
