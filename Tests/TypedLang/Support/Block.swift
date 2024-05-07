/*

  Created by David Spooner

*/

@testable import TSKit
import TypedLang


/// A type representing a block -- i.e. a sequence of definitions followed by an expression.

struct Block : Equatable {
  let decls : [Def]
  let expr : Expr
}


extension Block : Parsable {
  typealias DefList = DelimitedSequence<Def, Semicolon>
  static var productionRule : ProductionRule<Self> {
    .init(descriptor: "\(Optional<DefList>.self) \(Expr.self)") { (deflist: DefList?, expr) in
      Self(decls: deflist?.elements ?? [], expr: expr)
    }
  }
}


fileprivate let language = TSLanguage(tree_sitter_TypedLang())

extension Block {
  /// A convenience method for initializing an instance by parsing text.
  init(_ text: String) throws {
    self = try Self.from(text: text, language: language)
  }
}
