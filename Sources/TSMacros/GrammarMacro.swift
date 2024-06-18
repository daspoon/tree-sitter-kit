/*

  Created by David Spooner

*/

import SwiftSyntax
import SwiftSyntaxMacros
import TreeSitterCLI
import Foundation


public struct GrammarMacro : MemberMacro {
  public static func expansion(of node: AttributeSyntax, providingMembersOf decl: some DeclGroupSyntax, in ctx: some MacroExpansionContext) throws -> [DeclSyntax] {
    guard let decl = decl.as(StructDeclSyntax.self)
      else { throw Exception("unsupported declaration kind") }

    // Create a representative of the declaration.
    let grammar = try GrammarRep(structDecl: decl)

    // Get a JSON (string) representation of the grammar.
    let grammarText = grammar.jsonText

    // Create the Swift source which defines the corresponding TSLanguage instance.
    let languageDefinitionText = try parserSource(for: grammarText)

    // Get the visibility of the affected declaration.
    let visibility = decl.visibility

    // Return the declarations for the generated methods...
    return [
      DeclSyntax(stringLiteral:
        languageDefinitionText
      ),

      DeclSyntax(stringLiteral: """
        \(visibility) static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root {
          extract\(grammar.rootType)(from: node, in: context)
        }
        """),
      DeclSyntax(stringLiteral: """
        \(visibility) static func isRuleHidden(for type: Any.Type) -> Bool {
          let hiddenTypes : Set<ObjectIdentifier> = [
            \(grammar.definedRules.compactMap({$0.isSymbolHidden ? ".init(\($0.typeName).self)" : nil})
              .joined(separator: ", "))
          ]
          return hiddenTypes.contains(ObjectIdentifier(type))
        }
        """),
      DeclSyntax(stringLiteral: """
        \(visibility) static func symbolName(for symbol: TSSymbol) -> StaticString {
          symbolNames[Int(symbol)]
        }
        """),
    ] + grammar.definedRules.map { rule in
      DeclSyntax(stringLiteral: rule.extractionDeclText)
    }
  }


  static func parserSource(for jsonText: String, abi_version: UInt32 = 14) throws -> String {
    // Invoke the parser generator with the bytes of the JSON grammar and a callback which
    // returns (as an opaque pointer) a manually retained NSString containing the Swift text.
    let optionalOptionalUnsafeRawPointer = try jsonText.utf8.withContiguousStorageIfAvailable { jsonBuf in
      guard jsonBuf.count <= Int(UInt32.max)
        else { throw Exception("grammar text is too long") }
      return swift_parser_source_from_json_utf8(jsonBuf.baseAddress, UInt32(jsonBuf.count), abi_version) { srcBuf, srcLen in
        guard let srcBuf = srcBuf
          else { print("parser genertion returned null?"); return nil }
        guard let swiftCode = NSString(bytes: srcBuf, length: Int(srcLen), encoding: NSUTF8StringEncoding)
          else { print("failed to interpret result of parser generation"); return nil }
        return UnsafeRawPointer(Unmanaged.passRetained(swiftCode).toOpaque())
      }
    }

    guard let optionalUnsafeRawPointer = optionalOptionalUnsafeRawPointer
      else { throw Exception("grammar text has no contiguous utf8 representation") }
    guard let unsafeRawPointer = optionalUnsafeRawPointer
      else { throw Exception("parser generation failed") }

    return Unmanaged<NSString>.fromOpaque(unsafeRawPointer).takeRetainedValue() as String
  }
}
