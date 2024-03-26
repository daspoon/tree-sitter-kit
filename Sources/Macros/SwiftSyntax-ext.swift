/*

  Created by David Spooner

*/

import SwiftSyntax


// MARK: -

extension DeclGroupSyntax {
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

  public var storedProperties : [StoredPropertyInfo] {
    memberBlock.members.compactMap({StoredPropertyInfo($0.decl)})
  }
}

// MARK: -

//extension DeclModifierSyntax {
//  public static func == (lhs: DeclModifierSyntax, rhs: String) -> Bool {
//    lhs.name.text == rhs
//  }
//}

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
  var text : String {
    "\(segments)"
  }
}

// MARK: -

extension TypeSyntax {
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
