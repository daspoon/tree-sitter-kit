/*

  Created by David Spooner

*/

import SwiftSyntax


/// *Signature* is intended to distinguish constructor of an implicit return type according to their names and parameter types.
/// It is used in the implementation of *ParsableEnum* to ensure that each production rule corresponds to a constructor with
/// parameter types matching the types of its captured values, which serve as constructor arguments. The parameter names
/// maintained by each instance are used in constructing 'invocations', but do not contribute to 'identity' since production rules
/// have no means of specifying argument names.

struct Signature {
  typealias Parameter = (name: String?, type: TypeSyntax)

  let name : String
  let parameters : [Parameter]

  init(name n: String, parameters ps: [Parameter]) {
    name = n.removing(prefix: "`", suffix: "`")
    parameters = ps
  }

  /// Return the string representation identifying constructors with the same name and argument types.
  var identifier : String {
    let paramsText = parameters
      .map({ param in
        "\(param.type.description)"
      })
      .joined(separator: ",")
    return "\(name)(\(paramsText))"
  }

  /// Return the text of the constructor application to the children of a *TSNode* instance of the given named;
  /// the children are expected to have field names which are numeric indices starting from 0.
  func invocationText(for node: String) -> String {
    let argsText : String = parameters
      .enumerated()
      .map({ index, param in
        "\(param.name.map{"\($0): "} ?? "")\(param.type.description).from(\(node)[\"\(index)\"])"
      })
      .joined(separator: ", ")
    return ".\(name)(\(argsText))"
  }
}


extension Signature {
  /// Create an instance from an enum case element.
  init(case enumCaseElement: EnumCaseElementSyntax, of enumDecl: EnumDeclSyntax) {
    self.init(
      name: enumCaseElement.name.text,
      parameters: (enumCaseElement.parameterClause?.parameters ?? []).map { ($0.firstName?.text, $0.type.trimmed) }
    )
  }

  /// Create an instance from a function declaration, which is assumed to return constructor's type.
  init(functionDecl: FunctionDeclSyntax) {
    self.init(
      name: functionDecl.name.text,
      parameters: functionDecl.signature.parameterClause.parameters.map { ($0.firstName.text, $0.type.trimmed) }
    )
  }

  /// Create an instance from an element of a dictionary literal which representing a production rule, with the key providing a constructor
  /// name and the value its syntax expression -- both of which must be string literals.
  init(dictionaryElement: DictionaryElementSyntax) throws {
    // Ensure both key and value components are string literals.
    guard let nameLiteral = dictionaryElement.key.as(StringLiteralExprSyntax.self)
      else { throw Exception("dictionary keys must be string literals") }
    guard let exprLiteral = dictionaryElement.value.as(StringLiteralExprSyntax.self)
      else { throw Exception("dictionary values must be string literals") }

    // Ensure the key component consists of a single string segment
    guard nameLiteral.segments.count == 1, let nameSegment = nameLiteral.segments.first?.as(StringSegmentSyntax.self)
      else { throw Exception("dictionary key literals must have a single string segment") }

    // Extract the rule/constructor name.
    let ruleName = nameSegment.trimmedDescription

    // Parse the syntax component to extract the list of capture types.
    var capturedTypeNames : [String] = []
    for segment in exprLiteral.segments {
      // Ignore any segments which are not embedded expressions
      guard let exprSegment = segment.as(ExpressionSegmentSyntax.self)
        else { continue }
      // exprSegment has a property 'expressions: [LabeledExprSyntax]'
      for arg in exprSegment.expressions {
        switch arg.label?.text {
          case .none :
            // No label indicates a Parsable type expressed as T.self; extract the type T.
            guard let memberAccess = arg.expression.as(MemberAccessExprSyntax.self)
              else { throw Exception("production argument must be a member access expression") }
            guard let baseRef = memberAccess.base
              else { throw Exception("production argument must have a base for member access") }
            guard memberAccess.declName.baseName.text == "self"
              else { throw Exception("production argument must access member 'self'") }
            switch baseRef.kind {
              case .declReferenceExpr :
                let declRef = baseRef.cast(DeclReferenceExprSyntax.self)
                capturedTypeNames.append(declRef.baseName.text)
              case .arrayExpr :
                let arrayExpr = baseRef.cast(ArrayExprSyntax.self)
                guard arrayExpr.elements.count == 1, let elementExpr = arrayExpr.elements.first
                  else { throw Exception("array expression has \(arrayExpr.elements.count) elements") }
                guard let elementRef = elementExpr.expression.as(DeclReferenceExprSyntax.self)
                  else { throw Exception("unexpected kind for array element: \(elementExpr.kind)") }
                capturedTypeNames.append("[\(elementRef.baseName.text)]")
              default :
                throw Exception("unsupported base for member access: \(baseRef.kind)")
            }

          case "lit" :
            // The 'lit' label indicates a string from an explicit set.
            capturedTypeNames.append("String")

          default :
            continue
        }
      }
    }

    self.init(name: ruleName, parameters: capturedTypeNames.map {(nil, TypeSyntax(stringLiteral: $0))})
  }
}
