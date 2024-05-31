# Tasks


## Streamline the build process. (dave)

Specifically, *GrammarMacro* must generate a property `static var langage : TSLangage {...}` which eliminates the need for `parser.c`. This will have the effect of updating the parser directly in response to changing the Swift expression of the grammar rules, which will in turn eliminate the need for separate parser targets.

Since Swift macros can't launch processes or access the file system, we can't use the 'tree-sitter generate' command directly. Instead, the tree-sitter CLI library must expose a method which takes a json grammar specification and returns the configuration data required to initialize the TSLanguage struct. The exposed method must conform to C calling conventions.


## Write a compelling overview/introduction. (dave)

Contrast the standard usage of tree-sitter with the use of this library.


## Exercise the API by creating example parsers.

Write parsers for JSON, XML or whatever.
Ideally these would be test targets for simple languages, or separate packages for more extensive examples.
Note that adding a language test target currently requires creating a separate parser target for that language (see the build process) .


## Make use of SwiftSyntaxBuilder in GrammarMacro.


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
