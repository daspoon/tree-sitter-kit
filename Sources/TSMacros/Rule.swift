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
  struct Components {
    enum Format {
      case pattern(String)
      case signature(Signature)
      var parameterCount : Int {
        switch self {
          case .pattern : return 1
          case .signature(let signature) : return signature.parameters.count
        }
      }
    }
    let name : String
    let format : Format
    let constructor : ClosureExprSyntax

    init(name n: String = "", expr: ExprSyntax?) throws {
      // Extract the argument and trailing closure.
      guard
        let funcall = expr?.as(FunctionCallExprSyntax.self),
        let argument = funcall.arguments.only,
        let argname = argument.label?.text,
        let argexpr = argument.expression.as(StringLiteralExprSyntax.self),
        let closure = funcall.trailingClosure, funcall.additionalTrailingClosures.count == 0,
        let closure_sig = closure.signature
      else {
        throw Exception("ProductionRule values must be implemented as a function call with a labeled string literal argument and a trailing closure with explicit parameter names")
      }
      name = n
      constructor = closure
      // The argument label distinguishes determines our format...
      switch argname {
        case "pattern" :
          guard let pattern = argexpr.stringLiteral
            else { throw Exception("pattern argument must be a string literal") }
          format = .pattern(pattern)
        case "descriptor" :
          format = .signature(try Signature(name: name, syntaxExpression: argexpr))
        default :
          throw Exception("invalid argument label: \(argname)")
      }
      // Ensure the parameter count of the format matches that of the closure.
      guard format.parameterCount == closure_sig.parameterCount
        else { throw Exception("mismatch between capture count (\(format.parameterCount)) and constructor parameter count (\(closure_sig.parameterCount))") }
    }

    /// Return the text for an invocation of the constructor to instances of the capture types.
    var invocationText : String {
      let argstext : String
      switch format {
        case .pattern :
          argstext = "context.inputSource.text(for: node)"
        case .signature(let signature) :
          argstext = signature.parameters.enumerated()
            .map({ index, param in
              let nodeText = "node[\"\(index)\"]"
              switch param.type.as(OptionalTypeSyntax.self) {
                case .some(let optionalType) :
                  return "{$0.isNull ? nil : \(Rule.extractionCallText(for: optionalType.wrappedType, with: nodeText))}(\(nodeText))"
                case .none :
                  return Rule.extractionCallText(for: param.type, with: nodeText)
              }
            })
            .joined(separator: ", ")
      }
      return "\(constructor)(\(argstext))"
    }
  }


  /// Return the text which defines the function to extract an instance of the associated type from a parse tree node and context.
  var extractionDeclText : String {
    """
    private static func extract\(typeName)(from node: TSNode, in context: ParsingContext) -> \(typeName) {
      \(extractionBodyText)
    }
    """
  }

  /// Return the text used to create an instance of the given type from the given node.
  static func extractionCallText(for type: TypeSyntax, with nodeText: String) -> String {
    "extract\(type)(from: \(nodeText), in: context)"
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
  let components : Components

  required init(decl: DeclGroupSyntax) throws {
    // Get the implementation of `static var productionRule : ProductionRule<Self>`
    guard let binding : PatternBindingSyntax = decl.variableBindingWith(name: "productionRule", type: "ProductionRule<Self>", isStatic: true)
      else { throw Exception("requires an implementation of 'static var productionRule : ProductionRule<Self>'") }

    // Extract the signature and constructor elements of the production rule
    components = try Components(name: "", expr: binding.resultExpr)

    try super.init(decl: decl)
  }

  override var extractionBodyText : String {
    components.invocationText
  }
}

// MARK: --

class RuleForParsableByCases : Rule {
  let components : [Components]

  required init(decl: DeclGroupSyntax) throws {
    // Get the implementation of `static var productionRulesBySymbolName : [String: ProductionRule<Self>]`
    guard let binding : PatternBindingSyntax = decl.variableBindingWith(name: "productionRulesByCaseName", type: "[String: ProductionRule<Self>]", isStatic: true)
      else { throw Exception("requires an implementation of 'static var productionRulesByCaseName : [String: ProductionRule<Self>]'") }
    guard let dictionaryExpr = binding.resultExpr?.as(DictionaryExprSyntax.self)
      else { throw Exception("productionRulesByCaseName must be implemented as a single getter returning a dictionary literal.") }
    guard case .elements(let dictionaryElementList) = dictionaryExpr.content
      else { throw Exception("productionRulesByCaseName must return a non-empty dictionary.") }

    // Translate the dictionary literal return value into a list of signature/constructor pairs...
    components = try dictionaryElementList.map { pair in
      guard let name = pair.key.as(StringLiteralExprSyntax.self)?.stringLiteral
        else { throw Exception("productionRulesByCaseName requires string literal keys") }
      return try Components(name: name, expr: pair.value)
    }

    try super.init(decl: decl)
  }

  override var extractionBodyText : String {
    """
    switch context.language.symbolName(for: node) {
      \(
        components.map({ component in
          return "case \"\(typeName)_\(component.name)\" : return \(component.invocationText)"
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
