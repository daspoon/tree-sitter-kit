/*

  Created by David Spooner

  Methods added to types defined in SwiftSyntax.

*/

import SwiftSyntax


extension ClosureSignatureSyntax {
  public var parameterCount : Int {
    switch parameterClause {
      case .none :
        return 0
      case .simpleInput(let shorthandParameterList) :
        return shorthandParameterList.count
      case .parameterClause(let parameterClause) :
        return parameterClause.parameters.count
    }
  }
}


extension DeclSyntax {
  public var typeName : String? {
    switch kind {
      case .classDecl :
        return self.cast(ClassDeclSyntax.self).name.text
      case .enumDecl :
        return self.cast(EnumDeclSyntax.self).name.text
      case .structDecl :
        return self.cast(StructDeclSyntax.self).name.text
      default :
        return nil
    }
  }

  public var inheritanceClause : InheritanceClauseSyntax? {
    switch kind {
      case .classDecl :
        return self.as(ClassDeclSyntax.self)?.inheritanceClause
      case .enumDecl :
        return self.as(EnumDeclSyntax.self)?.inheritanceClause
      case .structDecl :
        return self.as(StructDeclSyntax.self)?.inheritanceClause
      default :
        return nil
    }
  }
}

// MARK: -

extension DeclGroupSyntax {
  public var visibility : String {
    let options : Set<String> = ["public", "internal", "private", "fileprivate"]
    return modifiers.map({$0.name.text})
      .filter({options.contains($0)})
      .joined(separator: " ")
  }

  public var typeName : String? {
    self.as(DeclSyntax.self)?.typeName
  }

  public func aliasType(for name: String) -> TypeSyntax? {
    memberBlock.members
      .compactMap({$0.decl.as(TypeAliasDeclSyntax.self)})
      .filter({$0.name.text == name})
      .only?.initializer.value
  }

  public func variableBindingWith(name: String, type: TypeSyntax, isStatic: Bool = false) -> PatternBindingSyntax? {
    memberBlock.members
      .compactMap({$0.decl.as(VariableDeclSyntax.self)})
      .filter({$0.isStatic == isStatic})
      .compactMap({$0.bindings.only})
      .filter({
        guard let identifier = $0.pattern.as(IdentifierPatternSyntax.self)?.identifier else { return false }
        return identifier.text == name
      })
      .filter({
        guard let annotation = $0.typeAnnotation else { return false }
        return annotation.type == type
      })
      .first
  }

  public var initMethods : [InitializerDeclSyntax] {
    return memberBlock.members
      .compactMap({$0.decl.as(InitializerDeclSyntax.self)})
  }

  public var staticFunctionsReturningSelf : [FunctionDeclSyntax] {
    return memberBlock.members
      .compactMap({$0.decl.as(FunctionDeclSyntax.self)})
      .filter({$0.isStatic})
      .filter({
        guard let rtype = $0.signature.returnClause?.type else { return false }
        return rtype == "Self" || (typeName.map {rtype == $0} ?? false)
      })
  }

  public var storedProperties : [StoredPropertyInfo] {
    memberBlock.members.compactMap({StoredPropertyInfo($0.decl)})
  }
}

// MARK: -

extension EnumDeclSyntax {
  var enumCaseElements : [EnumCaseElementSyntax] {
    return memberBlock.members
      .compactMap({$0.decl.as(EnumCaseDeclSyntax.self)})
      .reduce([]) { $0 + $1.elements }
  }
}


// MARK: -

extension FunctionDeclSyntax {
  /// Return *true* if the receiver's modifiers contain 'static'.
  public var isStatic : Bool {
    modifiers.contains {$0.name.text == "static"}
  }
}

// MARK: -

extension PatternBindingSyntax {
  /// Return the expression returned by the defined getter. Return nil if the receiver does not have a single getter or if its code block is empty.
  public var resultExpr : ExprSyntax? {
    guard case .getter(let codeBlockItemList) = accessorBlock?.accessors
      else { return nil }
    guard let returnItem = codeBlockItemList.last?.item
      else { return nil }
    return returnItem.kind == .returnStmt
      ? returnItem.cast(ReturnStmtSyntax.self).expression
      : returnItem.as(ExprSyntax.self)
  }
}

// MARK: -

extension StringLiteralExprSyntax {
  var stringLiteral : String? {
    guard let stringSegment = segments.first?.as(StringSegmentSyntax.self), segments.count == 1
      else { return nil }
    return stringSegment.trimmedDescription
  }

  var text : String {
    "\(segments)"
  }
}

// MARK: -

extension TypeSyntax {
  var text : String {
    trimmed.description
  }

  /// Structual equality for type syntax expressions. Partial.
  static func == (lhs: Self, rhs: Self) -> Bool {
    guard lhs.kind == rhs.kind else { return false }
    switch lhs.kind {
      case .arrayType :
        return lhs.cast(ArrayTypeSyntax.self).element == rhs.cast(ArrayTypeSyntax.self).element
      case .dictionaryType :
        return lhs.cast(DictionaryTypeSyntax.self).key == rhs.cast(DictionaryTypeSyntax.self).key
          && lhs.cast(DictionaryTypeSyntax.self).value == rhs.cast(DictionaryTypeSyntax.self).value
      case .identifierType :
        return lhs.cast(IdentifierTypeSyntax.self).name.text == rhs.cast(IdentifierTypeSyntax.self).name.text
      case .optionalType :
        return lhs.cast(OptionalTypeSyntax.self).wrappedType == rhs.cast(OptionalTypeSyntax.self).wrappedType
      case .attributedType, .classRestrictionType, .compositionType, .functionType, .implicitlyUnwrappedOptionalType, .memberType, .metatypeType, .missingType, .namedOpaqueReturnType, .packElementType, .packExpansionType, .someOrAnyType, .suppressedType, .tupleType:
        fallthrough
      default :
        return false
    }
  }

  static func == (lhs: Self, rhs: String) -> Bool {
    lhs.trimmed.description == rhs
  }
}

// MARK: -

extension VariableDeclSyntax {
  /// Return *true* if the receiver's modifiers contain 'static'.
  public var isStatic : Bool {
    modifiers.contains {$0.name.text == "static"}
  }
}
