# TreeSitterKit

This project aims to simplify the use of [tree-sitter](https://tree-sitter.github.io/tree-sitter/) for parsing  programming languages and data formats in [Swift](https://swift.org).
Specifically, it enables writing grammar rules as Swift code and automates the translation of parse trees into the Swift data structures which implement an abstract syntax.


## Motivation

Consider an abstract syntax for a simple language of arithmetic expressions.

  ```
  indirect enum Expr {
    case num(Int)
    case add(Expr, Expr)
    case mult(Expr, Expr)
  }
  ```

We'll first show the steps necessary to parse this language using tree sitter directly, and then see how the process is simplified through use of this package.


### Tree-sitter Basics

A tree-sitter grammar is typically written as a javascript object.

  ```
  module.exports = grammar({
    name: 'ExprLang',
    rules: {
      Expr: $ => choice(
        $.Num,
        $.Add,
        $.Mult,
        $.Paren
      ),
      Num: $ => [0-9]+,
      Add: $ => prec(left(1, seq($.Expr, '+', $.Expr))),
      Mult: $ => prec(left(2, seq($.Expr, '*', $.Expr))),
      Paren: $ => seq('(', $.Expr, ')'),
    }
  })
  ```

The tree-sitter program is used to generate a parser configuration as a pair of C source files, *parser.c* and *parser.h*.

  ```
  % tree-sitter generate grammar.js
  ```

The generated files, along with a header file declaring the generated *TSLanguage* structure, must be included in your project.

  ```
  #include <tree_sitter/api.h>
  TSLanguage *tree_sitter_ExprLang();
  ```

An instance of the *TSParser* type, configured with the generated language, enables translating strings into *TSTree* instances which act as containers for a hierarchy of *TSNode* structures.
Each node maintains the identity of its grammar symbol and the byte range of the text which it represents.

Finally we need a method to translate nodes to instances of our abstract syntax; below we use a context parameter to distinguish node symbols and to extract ranges of source text.

  ```
  extension Expr {
    init(node: TSNode, context ctx: Context) {
      assert(ctx.symbol(for: node) == "Expr" && node.count == 1)
      let child = node[0]
      switch ctx.symbol(for: child) {
        case "Num" :
          self = .num(Int(ctx.text(for: child))!)
        case "Add" :
          self = .add(Self(node: child[0], context: ctx), Self(node: child[2], context: ctx))
        case "Mult" :
          self = .mult(Self(node: child[0], context: ctx), Self(node: child[2], context: ctx))
        case "Paren" :
          self = Self(node: child[1], context: ctx)
        default :
          fatalError("unexpected symbol")
      }
    }
  }
  ```

Although the translation code is straight-forward, it is tedious for grammars which have many symbol types or have productions with optional elements.
More importantly, its type safety cannot be guaranteed by the compiler because there is no explict relationship between the grammar and the abstract syntax.

### Streamlined Interface

Using this package, the construction of a parser for the *Expr* type is reduced to the following code:

  ```
  import TSKit

  @Grammar
  struct ExprLang : Grammar {
    typealias Root = Expr
    static var productionRules : [ProductionRule] {
      return [
        ProductionRule(Expr.self, choicesByName: [
          "num": .init(.sym(Int.self)) { value in
            .num(value)
          },
          "add": .init(.prec(.left(1), .seq([.sym(Expr.self), "+", .sym(Expr.self)]))) { lhs, rhs in
            .add(lhs, rhs)
          },
          "mult": .init(.prec(.left(2), .seq([.sym(Expr.self), "*", .sym(Expr.self)]))) { lhs, rhs in
            .mult(lhs, rhs)
          },
          "paren": .init(.seq(["(", .sym(Expr.self), ")"])) { expr in
            expr
          }
        ]),
        ProductionRule(Int.self, .pat("[0-9]+")) { text in
          Int(text)!
        },
      ]
    }
  }
  ```

Here the *Grammar* macro is applied to a structure conforming to the *Grammar* protocol.
The protocol requires specifying the symbol type which appears at the root of each parse tree, together with a list of production rules associating each symbol type with a syntax expression and a constructor for that type.
Swift's parameter packs feature enables each production rule to refer to a distinct sequence of symbol types, and the macro ensures the number and type of syntax expression captures matches the number and type of constructor parameters. 

The macro generates the *TSLanguage* instance which serves as parser configuration and a method for translating parse tree nodes into instances of the root type.

  ```
  static var language : UnsafePointer<TSLanguage>
  static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root
  ```
  
The *Grammar* protocol provides a convenience method for translating text to its *Root* type -- throwing when the parse tree contains errors.

  ```
  static func parse(inputSource src: InputSource) throws -> Root
  ```

Since Swift macros can neither invoke subprocesses nor interact with the file system, the macro relies on a [fork](https://github.com/daspoon/tree-sitter) of tree-sitter extended with a callable interface to generate the Swift equivalent of *parser.c*.


## Installation

Building this project requires an Apple platform (due to the use of binary targets) with both tree-sitter and Rust (in order to build the tree-sitter fork) installed.
After cloning the project you must run the shell script `build_xcframework.rb` from the checkout directory in order to create the binary target TreeSitterCLI.xcframework.
That script must be run again if the tree-sitter working copy is updated via `swift package update`.


## Other Examples

Some example parsers are provided as test cases:

  [ExprLang](https://github.com/daspoon/tree-sitter-kit/blob/main/Tests/ExprLang/ExprLang.swift) shows arithmetic expressions involving function calls and various operators.
  
  [LambdaTests](https://github.com/daspoon/tree-sitter-kit/blob/main/Tests/TSKit/LambdaTests.swift) shows an untyped lambda calculus.
  
  [JSONTests](https://github.com/daspoon/tree-sitter-kit/blob/main/Tests/TSKit/JsonTests.swift) shows a JSON.
  
  [TypedLang](https://github.com/daspoon/tree-sitter-kit/blob/main/Tests/TypedLang/TypedLang.swift) shows a minimal typed functional language with blocks, closures and declarations.


## Related Work

A Swift binding for tree-sitter already exists at https://github.com/ChimeHQ/SwiftTreeSitter.
That work exposes nearly the full tree-sitter runtime API to Swift, but relies on tree-sitter's standard tech for mapping javascript grammar specifications to separately compiled C code.
This work exposes a minimal subset of tree-sitter functionality, but enables defining parsers entirely in Swift -- eliminating the need for javascript and mixed-language targets, and streamlining the build process.


## Future Plans

This is a work in progress, so there are a number of known [issues](https://github.com/daspoon/tree-sitter-kit/issues) and likely many more to be discovered through experimentation.
Among the most obvious:

  - Support for error reporting is very limited. Although tree-sitter performs implicit error recovery, it does not provide support for [generating useful error messages](https://github.com/tree-sitter/tree-sitter/issues/255). I have added the application target TSPlayground in order to explore the space, but haven't made much progress.

  - TreeSitterCLI.xcframework must be built using a separate script. I don't see how to improve the situation without additional features in Swift Packge Manager.

  - All production rules must be defined within the top-level grammar struct, which makes non-trivial grammar definitions lengthy. Ideally each symbol type would specify its own production rules and the set of all rules would be calculated from the grammar's root type. Unfortunately Swift member macros have no apparent means to access components outside the declaration to which they're attached.
