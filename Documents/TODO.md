# Tasks


## Write a compelling overview/introduction. (dave)

Contrast the standard usage of tree-sitter with the use of this library.


## Submit a pull request for our tree-sitter fork


## Exercise the API by creating example parsers.

Write parsers for JSON, XML or whatever.
Ideally these would be test targets for simple languages, or separate packages for more extensive examples.
Note that adding a language test target currently requires creating a separate parser target for that language (see the build process) .


## Make use of SwiftSyntaxBuilder in GrammarMacro.


## Eliminate the addition of crate-type staticlib in tree-sitter/cli/Cargo.toml

i.e. don't burden that project with an additional build target
instead, specify staticlib as an override to cargo in the script to build the xcframework


## Eliminate the use of clone in tree-sitter/cli/generate/render_buffer.rs

i.e. RenderBuffer.get_text


## Eliminate the TSLanguage target

This target merely exports the symbols of parser.h and would be unnecessary if those symbols were exported by TreeSitterCLI.xcframework.
I attempted this by having making parser.h a sibling of tree_sitter_cli.h and #including it in the latter,
but the result was to hang the swift frontend...


## Improve the treatment of precedence.

GrammarMacro requires the precedence elements of syntax expressions to be integer literals, so we can't use symbols to better manage precedence assignments. 

For example, client-side code might define precedence groups as static constructors,
  ```
  extension Precedence {
    static var addition : Self { .left(1) }
    static var exponent : Self { .right(2) }
    ...
  }
  ```
but to the macro-side can't use these definitions to produce the tree-sitter syntax.

An alternative is to enable precedence values to be specified as strings and to provide the macro-side with a mapping of strings to precedence expressions as an optional property of the Grammar protocol:
  ```
  static var precedenceGroupNames : [String: Precedence] { get }
  ```
This would require the client-side declares that Precedence conforms to ExpressibleByStringLiteral; the implementation could either return an arbitrary value such as .none(0) since it should never be invoked.


## Develop support for error reporting.


## Develop support for interactive editing features, such as syntax highlighting.


## Can we support dynamically defined operators?

More specifically, can the parsed language introduce operators of specified name, fixity and precedence without regenerating the parser?


## Create language-independent tests for TSKit APIs?
