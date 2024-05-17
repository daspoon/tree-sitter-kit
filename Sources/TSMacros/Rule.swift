/*

  Created by David Spooner

*/

import SwiftSyntax


/// An instance of this class represents a production rule for a struct or enum type declaration which corresponds to a grammar symbol by adopting one of various 'parsable' protocols.
class Rule {
  /// The names of supported protocols.
  static let ruleClasses : [Rule.Type] = [
    RuleForParsable.self,
    RuleForParsableByCases.self,
    RuleForParsableAsSeparatedSequence.self,
    RuleForParsableAsDelimitedSequence.self,
  ]

  static let ruleClassesByProtocolName : [String: Rule.Type]
    = .init(uniqueKeysWithValues: ruleClasses.map {($0.protocolName, $0)})

  // Return the appropriate class of rule, if any, for the given declaration.
  static func ruleClass(for decl: DeclGroupSyntax) -> Rule.Type? {
    return (decl.inheritanceClause?.inheritedTypes ?? [])
      .compactMap({$0.type.as(IdentifierTypeSyntax.self)})
      .map({$0.name.trimmed.text})
      .compactMap({ruleClassesByProtocolName[$0]})
      .only
  }


  let decl : DeclGroupSyntax

  required init(decl d: DeclGroupSyntax) throws {
    decl = d
  }


  /// The name of the declared type.
  var typeName : String {
    decl.typeName!
  }

  /// The name of the corresponding grammar symbol.
  var symbolName : String {
    (Self.symbolIsHidden ? "_" : "") + typeName
  }


  /// The components of a ProductionRule expression.
  typealias Components = (signature: Signature, closure: ClosureExprSyntax)

  /// Given an expression representing a ProductionRule, return the represented signature and constructor.
  static func decomposeProductionRule(name: String, expr: ExprSyntax?) throws -> Components {
    guard
      let funcall = expr?.as(FunctionCallExprSyntax.self),
      let stringLiteralExpr = funcall.arguments.only?.expression.as(StringLiteralExprSyntax.self),
      let closureExpr = funcall.trailingClosure, funcall.additionalTrailingClosures.count == 0
    else {
      throw Exception("ProductionRule values must be implemented as a function call with string literal and trailing closure arguments")
    }
    // Form a signature from the syntax expression
    let signature = try Signature(name: name, syntaxExpression: stringLiteralExpr)
    // Ensure the parameter count of the signature matches that of the closure.
    guard signature.parameters.count == (closureExpr.signature?.parameterCount ?? 0)
      else { throw Exception("a ProductionRule value has a mismatch between the capture count of its descriptor and the parameter count of its closure") }
    return (signature, closureExpr)
  }


  /// Return the text which defines the function to extract an instance of the associated type from a parse tree node and context.
  var extractionDeclText : String {
    """
    static func extract\(typeName)(from node: TSNode, in context: ParsingContext) -> \(typeName) {
      \(extractionBodyText)
    }
    """
  }

  /// Return the text used to create an instance of the given type from the given node.
  static func extractionCallText(for type: TypeSyntax, with nodeText: String) -> String {
    "extract\(type)(from: \(nodeText), in: context)"
  }

  /// Return the text representing the arguments to a type constructor of the same arity.
  static func extractionArgumentsText(for signature: Signature) -> String {
    return signature.parameters.enumerated()
      .map({ index, param in
        let nodeText = "node[\"\(index)\"]"
        switch param.type.as(OptionalTypeSyntax.self) {
          case .some(let optionalType) :
            return "{$0.isNull ? nil : \(extractionCallText(for: optionalType.wrappedType, with: nodeText))}(\(nodeText))"
          case .none :
            return extractionCallText(for: param.type, with: nodeText)
        }
      })
      .joined(separator: ", ")
  }


  // MARK: Subclass opportunities

  /// The name of the associated protocol. The default implementation removes the "RuleFor" prefix from the receiver's class name.
  open class var protocolName : String {
    "\(Self.self)".removing(prefix: "RuleFor")
  }

  /// Indicates whether or not the symbol is hidden; false by default.
  open class var symbolIsHidden : Bool {
    false
  }

  /// The body text of the generated extraction method.
  open var extractionBodyText : String {
    fatalError("subclass responsibility")
  }
}


// MARK: --

class RuleForParsable : Rule {
  let signature : Signature
  let constructor : ClosureExprSyntax

  required init(decl: DeclGroupSyntax) throws {
    // Get the implementation of `static var productionRule : ProductionRule<Self>`
    guard let binding : PatternBindingSyntax = decl.variableBindingWith(name: "productionRule", type: "ProductionRule<Self>", isStatic: true)
      else { throw Exception("requires an implementation of 'static var productionRule : ProductionRule<Self>'") }

    // Extract the signature and constructor elements of the production rule
    (signature, constructor) = try Self.decomposeProductionRule(name: "", expr: binding.resultExpr)

    try super.init(decl: decl)
  }

  override var extractionBodyText : String {
    "\(constructor)(\(Self.extractionArgumentsText(for: signature)))"
  }
}

// MARK: --

class RuleForParsableByCases : Rule {
  let signaturesAndConstructors : [Components]

  required init(decl: DeclGroupSyntax) throws {
    // Get the implementation of `static var productionRulesBySymbolName : [String: ProductionRule<Self>]`
    guard let binding : PatternBindingSyntax = decl.variableBindingWith(name: "productionRulesByCaseName", type: "[String: ProductionRule<Self>]", isStatic: true)
      else { throw Exception("requires an implementation of 'static var productionRulesByCaseName : [String: ProductionRule<Self>]'") }
    guard let dictionaryExpr = binding.resultExpr?.as(DictionaryExprSyntax.self)
      else { throw Exception("productionRulesByCaseName must be implemented as a single getter returning a dictionary literal.") }
    guard case .elements(let dictionaryElementList) = dictionaryExpr.content
      else { throw Exception("productionRulesByCaseName must return a non-empty dictionary.") }

    // Translate the dictionary literal return value into a list of signature/constructor pairs...
    signaturesAndConstructors = try dictionaryElementList.map { pair in
      guard let name = pair.key.as(StringLiteralExprSyntax.self)?.stringLiteral
        else { throw Exception("productionRulesByCaseName requires string literal keys") }
      return try Self.decomposeProductionRule(name: name, expr: pair.value)
    }

    try super.init(decl: decl)
  }

  override var extractionBodyText : String {
    """
    switch context.language.symbolName(for: node) {
      \(
        signaturesAndConstructors.map({ (signature, constructor) in
          return "case \"\(typeName)_\(signature.name)\" : return \(constructor)(\(Self.extractionArgumentsText(for: signature)))"
        })
        .joined(separator: "\n")
      )
    default:
        fatalError()
    }
    """
  }
}

// MARK: --

class RuleForParsableAsSeparatedSequence : Rule {
  let elementType : TypeSyntax
  let separator : String

  required init(decl: DeclGroupSyntax) throws {
    guard let elt = decl.aliasType(for: "Element")
      else { throw Exception("requires a typealias for Element") }

    // Get the implementation of `static var separator : String`
    guard let binding : PatternBindingSyntax = decl.variableBindingWith(name: "separator", type: "String", isStatic: true)
      else { throw Exception("requires an implementation of 'static var separator : String'") }
    // Get the separator string (needed for grammar generation only)
    guard let sep = binding.resultExpr?.as(StringLiteralExprSyntax.self)?.stringLiteral
      else { throw Exception("separator must be implemented as a string literal.") }

    elementType = elt
    separator = sep

    try super.init(decl: decl)
  }

  override var extractionBodyText : String {
    """
    let n = node.count; assert(n > 0 && n % 2 == 1)
    return .init(elements: stride(from: 0, to: n, by: 2).map { i in
      \(Self.extractionCallText(for: elementType, with: "node[i]"))
    })
    """
  }
}

// MARK: --

class RuleForParsableAsDelimitedSequence : Rule {
  // syntaxExpression: .repeat1(.prod(Element.self), delimiter: Delimiter.symbol),

  let elementType : TypeSyntax
  let delimiter : String

  required init(decl: DeclGroupSyntax) throws {
    guard let elt = decl.aliasType(for: "Element")
      else { throw Exception("requires a typealias for Element") }

    // Get the implementation of `static var separator : String`
    guard let binding : PatternBindingSyntax = decl.variableBindingWith(name: "delimiter", type: "String", isStatic: true)
      else { throw Exception("requires an implementation of 'static var delimiter : String'") }
    // Get the separator string (needed for grammar generation only)
    guard let delim = binding.resultExpr?.as(StringLiteralExprSyntax.self)?.stringLiteral
      else { throw Exception("separator must be implemented as a string literal.") }

    elementType = elt
    delimiter = delim

    try super.init(decl: decl)
  }

  override var extractionBodyText : String {
    """
    let n = node.count; assert(n > 0 && n % 2 == 0)
    return .init(elements: stride(from: 0, to: n, by: 2).map { i in
      \(Self.extractionCallText(for: elementType, with: "node[i]"))
    })
    """
  }
}
