# TreeSitterKit

This project aims to simplify use of the [tree-sitter](https://tree-sitter.github.io/tree-sitter/) parser generator for implementing custom programming languages in [Swift](https://swift.org).
Specifically, it enables writing grammar rules as Swift code and automates the translation of parse trees into the Swift data structures which implement the abstract syntax of a custom language.

As a simple example, consider an abstract syntax for a language of arithmetic expressions involving integers, addition and multiplication:

  ```
  indirect enum Expr {
    case num(Int)
    case add(Expr, Expr)
    case mult(Expr, Expr)
  }
  ```

Tree-sitter enables writing a grammar for this language as a javascript object:

  ```
  {
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
  }
  ```

The tree-sitter CLI transforms this notation into a pair of C source files (parser.c and parser.h) which must be added to your project;
if your project is a Swift package, these files must be placed in a separate c-compatibility target.
In short, the generated C code defines an instance of the *TSLanguage* type and the tree-sitter library provides a *TSParser* type which, when configured with a *TSLanguage* instance, translates text into parse trees comprised of *TSNode* structures.
So producing instances of our *Expr* type requires implementing a translation from compatible *TSNode* instances:

  ```
  extension Expr {
    init(node: TSNode, context ctx: Context) {
      assert(ctx.symbol(for: node) == "Expr" && node.count == 1)
      let child = node[0]
      switch ctx.symbol(for: child) {
        case "Num" :
          self = .num(Int(ctx.text(for: child))!)
        case "Add" :
          self = .add(Self(node: child[0], context: ctx), Self(node: child[2]))
        case "Mult" :
          self = .mult(Self(node: child[0], context: ctx), Self(node: child[2]))
        case "Paren" :
          self = Self(node: child[1], context: ctx)
        default :
          fatalError("unexpected symbol")
      }
    }
  }
  ```

The above method assumes the existence of a *Context* type which is used to identify node symbols by name and to extract the range of source text to which a node corresponds.
Although this translation code is straight-forward, it can be complicated for grammars which have many abstract syntax types or have productions with optional elements.
More importantly, the type safety of the translation method cannot be guaranteed by the compiler because there is no explict relationship between the grammar and the abstract syntax.

This package enables grammars to be written in Swift as a collection of production rules, each pairing a syntax expression with a constructor for an associated implementation type.
For example, the grammar shown above is implemented by applying an attached macro (viz. *@Grammar*) to a structure conforming to the *Grammar* protocol:

  ```
  @Grammar
  struct ExprLang : Grammar {
    typealias Root = Expr

    static var productionRules : [ProductionRule] {
      return [
        .init(Expr.self, choicesByName: [
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
        .init(Int.self, .pat("[0-9]+")) { text in
          Int(text)!
        },
      ]
    }
  }
  ```

The parameter packs feature of Swift enables syntax expression of each production rule to be generic in a sequence of symbol types matching the parameters of its constructor.
The macro generates a static *TSLanguage* instance together with a method for translating parse trees into the specified *Root* type.
  ```
  static func translate(parseTree node: TSNode, in context: ParsingContext) -> Root
  ```
The *Grammar* protocol provides a convenience method for translating text to its *Root* type.
  ```
  static func parse(text: String, encoding: String.Encoding = .utf8) throws -> Root
  ```

Note that macros can neither invoke subprocesses nor interact with the file system, so the *Grammar* macro relies on a fork of tree-sitter extended with a callable interface to generate the Swift equivalent of *parser.c*.


## Future

This is a work in progress: there are a number of loose ends (...) and likely many undiscovered issues.

One obvious drawback is that all production rules must be defined within the top-level grammar struct, making that struct definition rather large.
I had wanted each symbol type to specify its own production rules and for the grammar to derive the set of all rules reachable from its root type,
but I don't see how a macro can access components outside the declaration to which it is attached.
