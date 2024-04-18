/*

  Created by David Spooner

*/

@testable import TSKit
import TypedLang


/// A type representing a block -- i.e. a sequence of definitions followed by an expression.

@Parsable
struct Block : Equatable, Parsable {
  let decls : [Def]
  let expr : Expr

  init(decls ds: [Def], expr e: Expr) {
    decls = ds
    expr = e
  }

  init(decls ds: DefList?, expr e: Expr) {
    self.init(decls: ds?.elements ?? [], expr: e)
  }

  typealias DefList = DelimitedSequence<Def, Semicolon>

  static var syntaxExpression : TSExpression {
    "\(opt: DefList.self) \(Expr.self)"
  }

}


fileprivate let language = TSLanguage(tree_sitter_TypedLang())

extension Block {
  /// A convenience method for initializing an instance by parsing text.
  init(_ text: String) throws {
    try self.init(text: text, language: language)
  }
}
