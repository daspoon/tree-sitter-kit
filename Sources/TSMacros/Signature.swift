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
  struct Parameter {
    let name : String?
    let type : TypeSyntax
  }

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
  func invocationText(for names: (node: String, context: String)) -> String {
    let argTexts : [String] = parameters
      .enumerated()
      .map({ index, param in
        let label = param.name.map {$0 + ": "} ?? ""
        let nodeText = "\(names.node)[\"\(index)\"]"
        switch param.type.as(OptionalTypeSyntax.self) {
          case .some(let optionalType) :
            return label + "{$0.isNull ? nil : \(optionalType.wrappedType.text)(parseTree: $0, context: \(names.context))}(\(nodeText))"
          case .none :
            return label + "\(param.type.text)(parseTree: \(nodeText), context: \(names.context))"
        }
      })
    return """
      .\(name)(
        \(argTexts.joined(separator: ",\n"))
      )
    """
  }
}


extension Signature : Equatable {
  static func == (lhs: Self, rhs: Self) -> Bool {
    lhs.identifier == rhs.identifier
  }
}


extension Signature.Parameter {
  init(_ e: EnumCaseParameterSyntax) {
    self.init(name: e.firstName?.text, type: e.type.trimmed)
  }
  init(_ p: FunctionParameterSyntax) {
    self.init(name: p.firstName.text, type: p.type.trimmed)
  }
}


extension Signature {
  /// Create an instance from an enum case element.
  init(case enumCaseElement: EnumCaseElementSyntax, of enumDecl: EnumDeclSyntax) {
    self.init(
      name: enumCaseElement.name.text,
      parameters: (enumCaseElement.parameterClause?.parameters ?? []).map { .init($0) }
    )
  }

  /// Create an instance from a function declaration, which is assumed to return constructor's type.
  init(functionDecl: FunctionDeclSyntax) {
    self.init(
      name: functionDecl.name.text,
      parameters: functionDecl.signature.parameterClause.parameters.map { .init($0) }
    )
  }

  init(initializerDecl: InitializerDeclSyntax) {
    self.init(
      name: "init",
      parameters: initializerDecl.signature.parameterClause.parameters.map { .init($0) }
    )
  }

  /// Create an instance for the (synthesized) init method of a struct declaration.
  init(structDecl: StructDeclSyntax) {
    self.init(
      name: "init",
      parameters: structDecl.storedProperties.map { .init(name: $0.name, type: $0.type) }
    )
  }

  /// Create an instance from an element of a dictionary literal which representing a production rule, with the key providing a constructor
  /// name and the value its syntax expression -- both of which must be string literals.
  init(dictionaryElement: DictionaryElementSyntax) throws {
    // Ensure the key is a string literal.
    guard let name = dictionaryElement.key.as(StringLiteralExprSyntax.self)?.stringLiteral
      else { throw Exception("dictionary keys must be string literals") }
    // Ensure the value is a string literal expression.
    guard let exprLiteral = dictionaryElement.value.as(StringLiteralExprSyntax.self)
      else { throw Exception("dictionary values must be string literal expressions") }

    try self.init(name: name, syntaxExpression: exprLiteral)
  }

  /// Create an instance from a production rule with a given name and syntax expression.
  init(name: String, syntaxExpression: StringLiteralExprSyntax) throws {
    // Parse the syntax component to extract the list of capture types.
    var capturedTypes : [String] = []
    for segment in syntaxExpression.segments {
      // Ignore any segments which are not embedded expressions
      guard let exprSegment = segment.as(ExpressionSegmentSyntax.self)
        else { continue }
      // exprSegment has a property 'expressions: [LabeledExprSyntax]'
      for arg in exprSegment.expressions {
        switch arg.label?.text {
         case .none :
            // No label indicates a Parsable type expressed as T.self.
            capturedTypes.append(try Self.typeName(from: arg))
          case "opt" :
            // The 'opt' label also indicates a Parsable type expressed as T.self, but its capture is optional.
            capturedTypes.append("\(try Self.typeName(from: arg))?")
          case "lit", "pat" :
            // The 'lit' label indicates a string from an explicit set.
            capturedTypes.append("String")
          case "prec" :
            // The 'prec' label indicates precedence, which has no associated capture.
            continue
          case .some(let other) :
            throw Exception("unhandled case: \(other)")
        }
      }
    }
    self.init(name: name, parameters: capturedTypes.map { .init(name: nil, type: TypeSyntax(stringLiteral: $0)) })
  }

  private static func typeName(from arg: LabeledExprSyntax) throws -> String {
    guard let memberAccess = arg.expression.as(MemberAccessExprSyntax.self)
      else { throw Exception("production argument must be a member access expression") }
    guard let baseRef = memberAccess.base
      else { throw Exception("production argument must have a base for member access") }
    guard memberAccess.declName.baseName.text == "self"
      else { throw Exception("production argument must access member 'self'") }
    switch baseRef.kind {
      case .declReferenceExpr :
        let declRef = baseRef.cast(DeclReferenceExprSyntax.self)
        return declRef.baseName.text
      case .arrayExpr :
        let arrayExpr = baseRef.cast(ArrayExprSyntax.self)
        guard arrayExpr.elements.count == 1, let elementExpr = arrayExpr.elements.first
          else { throw Exception("array expression has \(arrayExpr.elements.count) elements") }
        guard let elementRef = elementExpr.expression.as(DeclReferenceExprSyntax.self)
          else { throw Exception("unexpected kind for array element: \(elementExpr.kind)") }
        return "[" + elementRef.baseName.text + "]"
      default :
        throw Exception("unsupported base for member access: \(baseRef.kind)")
    }
  }
}
