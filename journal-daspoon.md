### Mon Feb 26, 2024

Create minimal Swift bindings for required tree-sitter APIs
  - create swift classes which wrap the underlying structs TSParser and TSTree
  - the swift classes can use the same names as the TS types are not exported
  - extend the exported TSNode struct with various utility methods; e.g. to retrieve type and children

Merge the FunLang target with the test target

Create a separate target for FunLang's parser.c
  - this is necessary because SPM doesn't support mixed language targets
  - the target must live under Sources in a folder with the same name
  - the target folder must have an 'include' subfolder containing the headers for the exposed api
      - in this case just tree_sitter_funlang(), which creates the TSLanguage struct
  - the generated parser.c includes <tree-sitter/parser.h>, but that isn't exported by the tree-sitter package
      - so place parser.h in a subfolder named tree-sitter and add cSettings: [.headerSearchPath(".")] to the parser target

Consider using SPM plugin to generate parser.c/h from grammar.js...
  - it would be an 'in-build' plugin since it has known inputs and outputs


### Tue Feb 27, 2024

Notes on SPM command plugins:
  - invoked on user request; in Xcode via context menu on the package root; in SPM, via associated verb
  - command plugins can link against Foundation
      - use the Process api to synchronously execute tasks and parse their stdout
      - can't link against custom libraries, so utility code must be replicated...
  - Xcode UI provides arguments of the form "--target <target-name>" for each target, except non-swift targets -- which is what we want
      - can provide explicit arguments (e.g. --target FunLangParser), but Xcode doesn't save those

Notes on SPM in-build plugins:
  - generate commands which can reference tools made available through their dependencies; such tools are either
      - executableTarget or binaryTarget targets in the same package
      - executable products in other packages
  - it appears that in-build tools are not invoked for non-swift targets
      - this prevents generating parser.c from grammar.js implicitly through dependencies

Draft of command plugin GenParserCmd...
  - locate grammar.js in source dir of given target
  - invoke 'tree-sitter generate' in working directory specified by plugin context
  - move generated parser c and h files to the source directory
  - invoke via 'swift package generate-parser --target FunLangParser'


### Wed Feb 28, 2024

Refinement of GenParser command plugin
  - mirror the hierarchy of generated files in source directory for simplicity:
      grammar.js
      src/parser.c
      src/tree_sitter/parser.c
  - create directory structure if necessary
  - add FileManager extension for brevity 

Rename project to TreeSitterKit

Update README.md


### Tue Mar 12, 2024

Add Parsable protocol marking Swift types as being parsable by tree-sitter
  - each such type specifies a grammar symbol name, a syntax expression, and an initializer taking a TSNode
  - use a derived protocol ParsableAsChoice for types which require multiple production rules (e.g. enums)

Extend test language to include lambda terms with tuples and projections

Note: the relative precedence of application and operators needs refinement...


### Wed Mar 13, 2024

Extend the parser generation plugin to create include/exports.h
  - take the language name from grammar.js using a regex


### Thu Mar 14, 2024

Various changes to example language syntax:
  - abstractions bind (possibly empty) lists of arguments
  - change application syntax from juxtaposition to parenthesized argument list
  - add recursive abstractions
  - add match expression
  - add more operators

Add specialized protocol ParsableAsArray by which Element can specify bracket and separator symbols for parsing Arrays
  - tree-sitter rules can't match the empty string, so Array's syntax expression must either require brackets or be limited to non-empty arrays
  - we want different brackets according to specific syntax -- e.g. '()' for records and function arguments and parameters, but '<>' for generic type parameters


### Fri Mar 15, 2024

Rework Grammar to infer all required Parsable types from a Root type
  - i.e. rather than specifying all required types
  - introduce ParsableTypeProxy as a means of working with (existential) Parsable type instances


### Mon Mar 18, 2024

We need to parse lists of Decl without enclosing braces (e.g. Block ::= [Decl] ';' Expr)
  - so separators and brackets must be specified explicitly in syntax expressions rather than implicitly by Parsable types
  - also Array cannot be Parsable because syntaxExpression and symbolName depend on the separator and brackets
  - also list production rules must be generated implicitly for each combination of type, separator and brackets

Changes to support list productions...
  - eliminate the ParsableInSequence protocol
  - rework ProductionRule a non-generic enum with cases value and list, corresponding to a single parsable value and a list of parsable values (together with punctuation symbols) respectively
  - a ProductionRule has a symbol name and an expanded syntax expression, and produces javascript of the form <sym>: $ => <expr>
  - note that the syntax expression for lists requires 'optional' and 'repeat' cases of TSExpression
  - combine the rule and list cases of TSExpression into a single case prod(ProductionRule)
  - recast Parsable's supportingTypeProxies as ProductionRule's supportingRules (i.e. to calculate the set of rules reachable from the start type)

Knock-on changes to Parsable enums...
  - implicitly generated rules for ParsableByMultipleChoice types must now correspond to explicit ProductionRule instances
  - first rename ParsableByMultipleChoice to ParsableByCases
  - add ProductionRule case 'value_case' which pairs a ParsableByCases type with a case name
  - ParsableByCases implements syntaxExpression as a choice of value_case productions

note: the separator and bracket symbols must contribute to the name of the production rule for each list...
  - add a required name property to each
  - if arbitrary literals are desired, we can add an initializer which generates names as unicode expressions


### Tue Mar 19, 2024

Add Block and Decl types to test language...
  - move parser property from Expr to new struct FunLang, which should be generated by the plugin but requires SPM mixed language support...
  - Expr's convenience initializer for creating expressions from text must now parse a Block and return its expr

Split the production rule for lists in twain:
  - a bracketed, possibly empty sequence with an element separator; e.g. "(a, b, c)"
  - a non-bracketed, non-empty sequence with an element delimiter; e.g. "a; b; c;"


### Wed Mar 19, 2024

Aesthetic improvements to syntax expression...
  - make TSExpression conform to ExpressibleByStringInterpolation to enable concise expressions such as "! \(Name.self) . \(Expr.self)"
  - eliminate the list-related cases of ProductionRule since specifying punctuation in interpolation methods is overly verbose
  - instead, rely on .prod(T) and:
      1. make Array conform to Parsable with round brackets and comma separator
      2. add protocols SeparatedSequence and DelimitedSequence to produce arrays with alternate punctuation


### Thu Mar 20, 2024

Explore use of macros to generate the init method for Parsable struct types...
  - consider struct Let { let name : Name; let expr: Expr }
  - we want to generate the following for appropriate node child indices i and j
      init(_ node: TSNode) { name = Name(node[i]); expr = Expr(node[j]) }
  - but, even assuming the number and order of ivars and captures match, we can't calculate a mapping of ivars to node indices without access to the defining syntax expression; it is unclear how to make that available for use in a macro...
  - instead we could each capture's index within an interpolation as its field name
      "let \(Name.self) = \(Expr.self)"
  - a generated init could then retrieve nodes for each ivar by increasing numeric label...
      name = Name(node["0"]); expr = Expr(node["1"])
  - the interpolation method could allow explicit indices if the order of captures and ivars doesn't match
      "let \(Name.self, 1) = \(Expr.self, 0)"
  - we might instead use ivar names as field names, although this is rather verbose
      "let \(Name.self, "name") = \(Expr.self, "expr")"
    we might add type Capture<T: Parsable> = (type: T.Type, name: String) and a method on Parsable
      static subscript (_ name: String) -> Capture<Self>
    which could make this less verbose...
      "let \(Name["name"]) = \(Expr["expr"])
  - create proof-of-concept using indices

Notes on SwiftSyntax:
  - all declarations conform to DeclSyntaxProtocol; e.g. EnumDeclSyntax, StructDeclSyntax, ClassDeclSyntax, and ExtensionDeclSyntax


### Fri Mar 21, 2024

Macro Resources:
  https://swift-ast-explorer.com
  https://github.com/krzysztofzablocki/Swift-Macros

Explore use of macros to generate the init method for Parsable enum types...
  - consider enum Expr { case num(Int), fun(Fun), tuple([Expr]), apply(Expr, Expr), ... }
  - we can't assume 1:1 correspondence of production rules and enum cases, but we want to eliminate closures in the production rule format
      "infix" : ("\(Expr) \(Infix) \(Expr)", { node in .apply(.fun(Infix(node[1])), .tuple(Expr(node[0]), Expr(node[1]))) }),
  - if we require that each production rule corresponds to either an enum case or a static constructor,
      static func infix(_ lhs: Expr, _ op: Infix, _ rhs: Expr) { ... }
    then the production rule format could be simplified to
      "num": "\(Int)",
      "infix": "\(Expr) \(Infix) \(Expr)",
      "prefix": "\(Prefix) \(Expr)",
  - some possibilities to provide our macro with non-case production names:
      - a macro argument (note: AttributeSyntax has a property argumentList)
      - custom attributes on static constructors

Note: an ExtensionMacro can generate an extension when attached to a declaration, but can't be attached to an extension,
  so it doesn't enable the desired use case of making an existing type Parsable...
    ```
    static func expansion(of node: AttributeSyntax, attachedTo decl: some DeclGroupSyntax, providingExtensionsOf type: some TypeSyntaxProtocol, conformingTo protocols: [TypeSyntax], in context: some MacroExpansionContext ) throws -> [ExtensionDeclSyntax] {
    ```

