/*

  Created by David Spooner

*/

import SwiftSyntax


extension DeclGroupSyntax {
  public var storedProperties : [StoredPropertyInfo] {
    memberBlock.members.compactMap({StoredPropertyInfo($0.decl)})
  }
}


extension EnumDeclSyntax {
  public var enumCaseElements : [EnumCaseElementSyntax] {
    memberBlock.members
      .compactMap({$0.decl.as(EnumCaseDeclSyntax.self)})
      .reduce([]) { $0 + $1.elements }
  }
}


/// A convenience type aggregating the name, type and optional initial value of a variable declaration.
public struct StoredPropertyInfo {
  public let name : String
  public let type : TypeSyntax
  public let value : ExprSyntax?


  /// Attempt to initialize an instance with a declaration, which must be a *VariableDeclSyntax* with a single bound name and type.
  public init?(_ decl: DeclSyntax) {
    guard let vbl = decl.as(VariableDeclSyntax.self)
      else { return nil }

    // Get the single binding, ensuring it has represents an identifier and type.
    guard
      let binding = vbl.bindings.first, vbl.bindings.count == 1,
      let name = binding.pattern.as(IdentifierPatternSyntax.self)?.identifier.text,
      let type = binding.typeAnnotation?.type.trimmed
    else {
      return nil
    }

    // Ensure the declaration's binding corresponds to a stored property
    switch binding.accessorBlock?.accessors {
      case .none :
        break
      case .accessors(let accessors) :
        for accessor in accessors {
          switch accessor.accessorSpecifier.tokenKind {
            case .keyword(.willSet), .keyword(.didSet) :
              break
            default :
              return nil
          }
        }
      case .getter :
        return nil
    }

    self.name = name
    self.type = type
    self.value = binding.initializer?.value
  }
}
