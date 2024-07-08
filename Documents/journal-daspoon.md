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


### Wed Mar 20, 2024

Aesthetic improvements to syntax expression...
  - make TSExpression conform to ExpressibleByStringInterpolation to enable concise expressions such as "! \(Name.self) . \(Expr.self)"
  - eliminate the list-related cases of ProductionRule since specifying punctuation in interpolation methods is overly verbose
  - instead, rely on .prod(T) and:
      1. make Array conform to Parsable with round brackets and comma separator
      2. add protocols SeparatedSequence and DelimitedSequence to produce arrays with alternate punctuation


### Thu Mar 21, 2024

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


### Fri Mar 22, 2024

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


### Sat Mar 23, 2024

Note: syntax types which contain 'special' arrays (e.g. SeparatedSequence) must declare their array members as that the production type, not as Array
  - e.g. Enum.cases : EnumCaseList

Refine ParsableByCases protocol
  - replace productionsByChoiceName with syntaxExpressionsByCaseName, since constructors will be implicit...

Should our macro macro declare conformance to Parsable?
  - is this possible?
  - we can declare conformance and have the macro generate the init method


### Sun Mar 24, 2024

Note: up to this point we use an auxiliary method to interpret single-element expression sequences as parenthesized rather a tuple
  - this requires a constructor which produce one of two cases
  - but we plan to produce the result from the init method of the production type (e.g. ExprList)
  - some possible solutions:
      1. use separate productions for tuples and parentheszed terms (requires 3 rules)
      2. replace Parsable's init method with a static constructor which produces an associated type defaulting to Self...
            protocol Parsable<T> { associatedtype T; static func from(_: TSNode) -> T; ... }
            extension Parsable { typealias T = Self }
      3. introduce an auxiliary protocol (which Parsable adopts) which can be used in productions; it would have requirements similar to above


### Mon Mar 25, 2024

Continue implementation of the ParsableEnum macro
  - add a method to retrieve a variable binding declaration by name; ideally also by type, but TypeSyntax.== does not implement structural equality
  - require target type implement 'syntaxExpressionsByCaseName' as a dictionary literal with string literal keys, where the keys are considered to be constructor names
  - build a dictionary of 'constructors' corresponding to case and static function name, where the parameters of each are expected to be of parsable type and serve to translate the node arguments provided to each constructor


### Tue Mar 26, 2024

We need to apply field names to captures within the syntax expressions for production rules...
  - clearly we must add a 'field' case to TSExpression
  - then when producing javascript for a ProductionRule, we can transform its syntax expression into a copy in which production nodes are wrapped in field annotations with increasing indices...

Continue implementation of the ParsableEnum macro
  - override == on TypeSyntax to test structural equality...
      - for now, limit implementation to syntax subset required for retrieving property implementations for the current purpose
      - enables a utility method to retrieve a property by name and type
  - strip backquotes from the names of enum cases and static functions to enable matching specified case names
  - disambiguate subrule names by prepending the symbol name of the target type (e.g. "num" => "Expr_num")
      - allow for overrides of symbolName which return string literals


### Wed Mar 27, 2024

Debug the changes made to support macros...

bug fix: "(x)" is parsed as a tuple
  - the production expression is "\(ExprList.self)", but ExprList.from(_:) is not invoked because the 'tuple' constructor specifies its argument as [Expr]
  - change the rule to 'paren' and adding `static func paren(_: [Expr]) -> Expr`

bug fix: parsing applications "f()", "f(x)", etc fails when Expr.from(_:) is called with an ExprList node
  - the problem is the production method is chosen by the second argument of case apply(Expr, Expr), but the node type is determined by the production expression "\(Expr.self) \(ExprList.self)"
  - change the rule to 'call' and add `static func call(_: Expr, _: ExprList) -> Expr`

Note: can we ensure these kinds of bugs shown above can't occur?
  - i.e. can we formalize the correlation between the types of constructor arguments and syntax expression captures?
  - two possibilities:
      1. have the macro parse syntax expressions and choose a constructor which is appropriate for the capture types
      2. devise a means of specifying production rules from which the macros generate:
          - case and static function constructors for enum types
          - instance variables for struct types
          - production methods (viz. static func from(_ node: TSNode) -> T) for both types

bug fix: parsing of infix/prefix operators fails; e.g. "\(Expr) \("+", "-") \(Expr)"
  - text captures must be wrapped as fields

bug fix: production method generated by ParsableEnum doesn't work:
  - must switch on (type of) sole child of input node
  - symbol names for cases must prepend defined type name; e.g. Expr_name

Extend TSExpression's string interpolation to treat all interpolation components as captures and to implicitly apply numeric field annotations.
  - this enables capturing the text of variable operator symbols; e.g. "\(Expr) \("+", "-") \(Expr)"
  - limit 'optional' components to productions, which is sufficient for our use cases and avoids the complication of nested fields within arbitrary expression components
  - making field annotation a function of string interpolation (rather than javascript translation) allows opt-out for types with explicit production methods


### Thu Mar 28, 2024

Can we extend ParsableEnum to select a constructor based on the sequence of capture types in the production expression?
  - we can extend constructor names to include argument names and types when we build our mapping
  - we must then parse the syntax expressions specified in syntaxExpressionsByCaseName, which we require to be string interpolations
  - we can make syntax expressions easier to parse by extending string interpolation to cover precedence
  - create a function which takes a StringLiteralExprSyntax and returns a signature

bug: parsing fails for match expressions...
  - the second argument of case match(_,_) is produced by [MatchCase] rather than MatchCaseList
  - because the type specified in the case declaration differs from that of production rule
  - we should be able to solve the problem by introducing `static func match(_ e: Expr, _ cs: MatchCaseList) -> Expr { cs.elements }`
  - oddly, naming the production anything other than 'match' (to avoid ambiguity) causes macro expansion to crash
  - so time to address ambiguity resolution in the macro...

todo: generated production methods must handle optionals (e.g. Block, EnumCase); how?
  - clearly production methods must decide when optional nodes exist by attempting to retrieve named nodes
  - knowing which constructor arguments are optional could come from the constructor argument type or by analyzing the production expression


### Fri Mar 29, 2024

How to implement proper treatment of optionals...
  - generated parsing methods must: a) know which production arguments are optional; and b) decide whether or the corresponding nodes exist
  - the first requires tagging each argument within of signature generated for the production, and might be accomplished by either:
      - using an distinct interpolation format (in place, but not considered by the macro0
      - using the argument type's optionality...
  - the second requires testing either:
      - the existence of a label
      - the node count (assuming we revert the insertion of field names)
  - if we are generating an production method for a rule which has an optional capture, then the parameter of the corresponding constructor ('init' in the case of structures) must be optional -- which suggests type optionality is the natural approach...
  - we can't make Optional conform to Parsable because its production rule would have to match the empty string
      - i.e. optionals must be coded into larger syntax expressions through string intepolation
  - our Signature struct must both:
      - maintain knowledge of which parameters are optional
      - generated production invocation text which accounts for optional arguments...
  - first incorporate Signature into ParsableStruct...

bug: parsing of enum definitions fails on cases without parameters
  - this requires proper treatment of optionals...

Recognize static functions returning the type name explicitly (rather than Self) as constructors.
  - e.g. func tuple(_ exprs: [Expr]) -> Expr

commit: Improve ParsableEnum by matching the target type's production rules its known constructors, respecting argument types.
  - require that syntaxExpressionsByCaseName be implemented as a dictionary literal and that its production rules have string literal syntax expressions
  - this requires TSExpression's string interpolation syntax include a means to specify precedence

bug fix: productions involving operators don't work...
  - the production reads "... \(lit: ...) ...", which translates to type String, but the constructor expects a Name
  - we might specify Name in the production rule, but then we would need to extend the syntax of productions to allow additional
    arguments for choice of literals and/or patterns which would also complicate the macro interpretation of production rules
  - instead, change the constructors to take String arguments for the operator symbol and build a Name implicitly

Note: ExprList and TypeExprList are now redundant
  - static constructors provide that functionality


### Sat Mar 30, 2024

Complete support for optional productions
  - the init(parseTree:) generated for structs now invokes an init or static constructor with param types matching the production rule, rather than directly assigning ivars
      - todo: assign ivars if no such constructor exists?
  - Signature generates conditional argument expressions (based on node.isNull) for optional captures
      - todo: ensure the generated expression works generally, w.r.t. parsing trailing '?'


### Tue Apr 2, 2024

Restructure package to provide better separation between exported targets and example language/test targets.

Add simpler language as a motivating example...
  - single Expr type
  - define grammar.js and Expr.init(parseTree:) manually

Note: although Expr's init(parseTree:) is fairly simple, there is no single 'source of truth'
  - grammar.js and init(parseTree:) must be manually synchronized


### Wed Apr 3, 2024

Restructure example languages...
  - rename FunLang to TypedLang
  - extend ArithLang to include functions and application; call it FuncLang

Extend SeparatedSequence to include optional enclosing brackets


### Thu Apr 4, 2024

Consider generalizing Parsable with an associated Return type...
  - the constructor would change from `init(parseTree:TSNode)` to `static func from(_:TSNode) -> Result`,
    with `Result` defaulting to `Self`
  - the macro would assume/require `Result` to be `Self` for the affected type, so the constructor search wouldn't change
  - but it would have to use the `Result` of each captured type to choose a matching constructor, which (I believe) is not currently possible (i.e. to retrieve members of a type outside the affected declaration)

Can our macro be made to apply to an extension?
  - yes, but it would remain MemberMacro
  - the ExtensionMacro protocol provides the attached declaration, which would be a struct or enum
  - the search for constructors would have to be limited to the attached declaration
  - the macro could likely add protocol conformance to the generated extension
  - would the attached declaration contain synthesized default initializers?


### Mon Apr 8, 2024

Iterate on write-up 


### Tue Apr 9, 2024

Write SwiftUI program to present TSNode hierarchy for a parsed expression via OutlineGroup
  - how to maintain expansion state?

Further refinement of example expression language

How best to avoid duplication of unit tests for the two versions of ExprLang?
  - create a single base class with two subclasses, each defining an Expr type and a parsing function
  - have a single class with a list of Expr type/parse function pairs (less appealing)


### Wed Apr 10, 2024

Review tree-sitter's interface to the source text...
  The 'designated' method for parsing is `ts_parser_parse(TSParser *self, const TSTree *old_tree, TSInput input)`, which takes an instance of the the following struct:
    ```
    struct TSInput {
      void *payload;
      const char *(*read)(void *payload, uint32_t byte_index, TSPoint position, uint32_t *bytes_read);
      TSInputEncoding encoding
    }
    ```
  When parsing a string, the following struct serves as payload
    ```
    struct TSStringInput {
      const char *string;
      uint32_t length;
    }
    ```
  and the read function returns a pointer to the substring from the given index (ignoring `position`).
  TSParser invokes `read` only to ensure the source is non-null, otherwise it is simply passed to `ts_lexer_set_input(TSLexer *self, TSInput input)`.
  TSLexer maintains a portion of the source text in its `chunk`, `chunk_start`, and `chunk_size` members by calling TSInput's read when necessary.

Begin implementing a means to retrieve source text from a byte range regardless of whether provided as a string or a file
  - essentially we want an object with a method of the form `func text(in: Range<UInt32>) -> String`
  - tree-sitter uses struct TSInput to retrieve portions of the source text on demand, and defines multiple parsing methods which create appropriate instances of this struct
  - intuitively we should extend TSInput to implement the desired method, but TSInput's read method requires a TSPoint argument which I don't know how to synthesize...
  - instead create protocol InputSource with the desired method and a means to create a TSInput
      ```
      protocol InputSource {
        func text(in: Range<UInt32>) -> String
        var tsinput : TSInput { get }
      }
      ```
  - create StringInputSource which is backed by a String
  - add a 'source' parameter to init(parseTree:)


### Thu Apr 11, 2024

Finish implementing source text retrieval by node.

Eliminate unused TSCursor implementation.

Remove Parsable conformance from Array; use instantiations of SeparatedSequence instead.

Note: I would like to for TSExpression's string interpolation to support regex parameters, but...
  - there is no obvious means to obtain the string representation of a Regex, which is required to create grammar source


### Mon Apr 15, 2024

Create OutlineView as alternative to OutlineGroup which supports automated expansion
  - based on DisclosureGroup

bug: OutlineView crashes on macOS when expression text is empty or contains a single identifier
  - it appears to be triggering table view layout while layout is in progress
  - the problem does not appear on iOS (although autolayout errors are reported in other scenarios)


### Tue Apr 16, 2024

Allow production rules to be hidden to eliminate unnecessary parse tree nodes for enum types
  - add property productionRuleIsHidden defaulting to false; ParsableByCases override returns true
  - add property productionRuleName to prefix symbolName with underscore when productionRuleIsHidden returns true
  - rework Grammar to include an implicit 'start' rule; requires making Grammar non-generic
  - various references to symbolName replaced with productionRuleName
  - update top-level parsing methods to accommodate start node

Note: I want to visually distinguish symbol names and matched text in the parse tree view, but...
  - the foregroundColor attribute of AttributeString has no effect
  - the code from AttributedString's documentation doesn't even compile...


### Wed Apr 17, 2024

Replace TSNode's type method (which allocates a String) with TSLanguage.symbolName(for: TSNode), and generalize the context argument provided to Parsable's ingestion method to include the language.
  - TSNode's type method allocates a String which copies the cstring result of `ts_node_type`
  - extend TSLanguage to maintain a table mapping numeric symbol ids to strings
  - use `t_node_symbol` and `ts_language_symbol_name`


### Thu Apr 18, 2024

bug fix: after adopting yesterday's changes, TreeSitterView doesn't update properly..
  - the initial tree is presented correctly, but either changing the expression or switching grammars causes the view to show errors and apparent gibberish
  - I don't know what the problem was, but backing-out and re-introducing the changes incrementally has solved the problem

Note: `tree-sitter generate` should reject grammars which define productions named `ERROR` or `_ERROR`
  - constants `ts_builtin_sym_error` and `ts_builtin_sym_error_repeat` are defined to be UInt16.max and UInt16.max-1 respectively and are given special treatment by  `ts_language_symbol_name` and `ts_language_symbol_for_name`
  - those constants should also be exported


### Mon Apr 22, 2024

Work on write-up...


### Tue Apr 23, 2024

Continue work on write-up...

Note: I want to move the Expr example (both stages) to the TreeSitterView project...
  - I can add a unit testing bundle and move Expr et.al. into there
  - but the generated language must also be accessible
  - this means the languages must also be bundled
  - which might best be achieved by moving the existing subpackages from TreeSitterKit
      - actually, only the 'economy' grammar is required...


### Wed Apr 24, 2024

Continue work on write-up...

More build system woes...

add a drop-down menu of recent expressions to avoid SwiftUI pant-shitting while editing the text field
  - show an example for each case of the Expr translation method


### Mon Apr 29, 2024

Tree-sitter API aimed to improve error reporting added in https://github.com/tree-sitter/tree-sitter/pull/2324 :
  ```
  bool ts_node_is_error(TSNode)
  
  TSStateId ts_node_parse_state(TSNode)
  
  void ts_tree_cursor_reset_to(TSTreeCursor *, const TSStreeCursor *)
  bool ts_tree_cursor_goto_previous_sibling(TSTreeCursor *)
  bool ts_tree_cursor_goto_last_child(TSTreeCursor *)
  
  uint32_t ts_language_state_count(const TSLanguage *)
  TSStateId ts_language_next_state(const TSLanguage *, TSStateId, TSSymbol);

  TSLookaheadIterator *ts_lookahead_iterator_new(const TSLanguage *, TSStateId);
  TSSymbol ts_lookahead_iterator_current_symbol(const TSLookaheadIterator *);
  bool ts_lookahead_iterator_advance(TSLookaheadIterator *);
  void ts_lookahead_iterator_delete(TSLookaheadIterator *);
  ```

Explore use of TSQuery et.al. for finding errors
  - implement Swift wrappers for TSQuery and TSQueryCursor
  - create a TSQuery which captures error nodes "(ERROR @node)"
  - create a TSQueryCursor and execute the query on the root node
  - use the cursor's nextCapture method to step through all ERROR nodes


### Tue Apr 30, 2024

Extend Grammar to allow specifying 'word' attribute of grammar.js
  - tree-sitter requires it be a named rule whose expression is a pattern, so we can't use choices or productions
  - add Grammar.init overload with parsable type parameter
  - note: the effect on parser.c is to set the 'keyword_lex_fn' and 'keyword_capture_token' elements of the language struct

Replace TSQueryCursor nextMatch and nextCapture with matches and captures respectively


### Thu May 2, 2024

Can we specify a production rule as a pairing of syntax expression and closure?

    struct LetDecl : Parsable {
      let name : Name
      let type : Type
      let expr : Expr

      static var productionRule : ProductionRule<Self> {
        .init("let \(Name.self) : \(Type.self) = \(Expr.self)", {
          Self(name: $0, type: $1, expr: $2)
        })
      }
    }
  
This would require (string-interpolated) syntax expressions be variadic

    enum SyntaxExpr<each T: Parsable> : ExpressibleByStringInterpolation {
      let captureTypes : (repeat each T)
      var captureCount : Int = 0
      init(literalCapacity: Int, interpolationCount: Int) {
      }
      mutating func appendInterpolation<T: Parsable>(_: T.Type) {
        assert(T.self == captureTypes[captureCount])
      }
    }

If possible, it would eliminate the macro-generated init methods...


### Fri May 3, 2024

Continue work on new production rule format...


### Mon May 6, 2024

Continue work on new production rule format...
  - extend and symplify Symbol, eliminating proxy types ParsableProxy and ParsableByCasesProxy
  - minimize AnyProductionRule, moving calculation of support symbols to Grammar

bug: grammar generation runs, but 'case' rules appear with symbol of hidden parent type
  - attempted to add extend ProductionRule with either a Symbol or a symbol name, but Swift shits itself 


### Tue May 7, 2024

submit bug report for parameter pack issue (viz. ProductionRule can't be extended to maintain symbol/name)

bug fix: adapt grammar generation to avoid parameter pack issue 

bug fix: sort production rule choices in syntax expression for ParsableByCases

tweak sorting of symbols to ignore leading underscore

reinstate use of field names in ProductionRule constructors...

bug fix: optional productions use TSNode.isNull to determine whether or not node exists

update TypedLangTests to use new productoin rule format


### Thu May 9, 2024

note: string interpolation for syntax expression must distinguish between optional and non-optional symbol references because tree-sitter rules cannot match the empty string; the question of whether or not hidden symbols are exempt is irrelevant because, obviously, they can't be captured as nodes

note: string interpolation for syntax expressions is unsatisfying because mismatch of capture types and counts can only be detected at runtime
  - we can make appendInterpolation throw, but this requires the methods which specify production to throw
  - note that the syntax for declaring a throwing property is var p : T { get throws }


### Mon May 13, 2024

I want to streamline the build process by:
  - defining production rules as static methods on language/syntax types
  - generating grammar.js/json from the production rules of (a set of) syntax types
  - generating and compiling parser.c within the build process
  - having both the syntax types and the generated parser live in the same build target

This is not currently possible because...
  - SPM does not allow mixed language targets, so grammar.js and the generated parser.c must live a separate target
  - the language target must either depend on the parser target (i.e. a circular dependency), or split in two so that we have a chain of three dependent targets: the language type definitions, the grammar/parser generation, and finally the parametrized/language-specific parser
  - were SPM to allow mixed-language targets, we would have to run code based on the language type definitions in order to generate the grammar, which (in a compiled language) requires separating the language and parser targets

It appears the only way forward is to use a macro to generate both the grammar and the parser...
  - but macros can't create or alter files, so we must run tree-sitter generate within the macro and incorporate its output into the attached declaration;
  - and macros can't invoke subprocesses, so we must: 
      - link the tree-sitter cli as a library
      - expose a method which takes grammar source and returns the parse tables (viz. the result of the build_tables method in mod.rs)
      - generate a static instance of the TSLanguage struct using those parse tables
  - this will eliminate the need for parser.c

We would need to change Grammar from a struct to a protocol...
    ```
    protocol Grammar<Root> {
      associatedtype Root : Parsable
      /// The language name. Required.
      static var name : String { get }
      /// The shared instance of the language structure. Implementation provided (by the *Grammar* macro).
      static var language : TSLanguage { get }
    }
    ```
    
The top-level parsing method can then be provided by Grammar, replacing Parsable.init(inputSource: InputSource, language: TSLanguage):
    ```
    extension Grammar {
      static func parse(inputSource: InputSource) throws -> Root { ... }
    }
    ```
    
We will need to rework sequence types as protocols (rather than typealiases) in order to make their production rules available within macro expansion:
    ```
    protocol ParsableAsSeparatedSequence<Element> {
      associatedtype Element : Parsable
      static var separator : String { get }
    }
    ```

As there is no API to to access declarations outside of the one to which a macro is attached, all supporting types must be defined within that 'top-level' declaration:
    ```
    @Grammar
    struct ExprLang : Grammar<Expr> {
      @Parsable
      enum Expr : ParsableByCases {
        case name(Name) :
        case apply(Expr, [Expr])
        static var syntaxExpressionsByCaseName : [String: SyntaxExpression] {
          "name": "\(Name.self)",
          "call": "\(Expr.self) ( \(Optional<ExprList>.self) )",
          "add": "\(Expr.self) \("+", "-") \(Expr.self)",
        }
      }
      @Parsable
      struct Name : Parsable {
        let text : String
        static var syntaxExpression : SyntaxExpression {
          .pattern("[a-z]+")
        }
      }
      @Parsable
      struct ExprList : ParsableAsSeparatedSequence {
        typealias Element = Expr
        static let separator = ","
      }
    }
    ```

Unfortunately Swift doesn't support nested macro applications (citing a 'circular reference' error)...


### Wed-Fri May 15-17, 2024

Note: we can't avoid the parameter pack bug by leaving the interpolation/descriptor untyped

Attempt to work around the parameter pack bug by merging @Parsable's functionality into @Grammar...
  - i.e. @Grammar generates methods `static func parseT(node: TSNode, context: ParsingContext) -> T` for each type T reachable from the production rule of the root type
  - this might be achieved by either:
      1. requiring T has a constructor with argument types matching the captures of its syntax expression (viz. the current method)
      2. specifying constructors in each ProductionRule instance

Note: creating a constructor for a ProductionRule from a string interpolation requires constructors for the capture types
  - currently that is taken from the type's productionRule
  - this is a problem conceptually for String because it can't specify a syntax expression, so shouldn't conform to Parsable; however, the problem will occur in practice only if 'String' appears as an explicit capture in another productino rule
  - we might weaken the requirement for interpolation capture types to require only a constructor `(TSNode, ParsingContext) -> T`, say ExpressibleByParseTree...

Note: language types whose syntax expression is specified as a string interpolation are non-terminals; we may need a means of identifying terminal symbols 

Note: perhaps we can eliminate the need for nesting syntax types within the grammar by accumulating all production rules in a single property on the Grammar protocol; e.g.
  ```
  static var productionRules : [ProductionRule] {
    .init(syntaxExpression: "...") { (capture1, ...) in ... },
  }
  ```

### Sun-Tue May 19-21, 2024

Given a syntax expression, can we derive the argument type of the corresponding production method?
  - a symbol represents the corresponding type
  - a pattern represents a String
  - an optional represents an optional of the argument type
  - a repeat1 corresponds to a list of the argument type
  - a sequence represents a tuple of the argument types (ignoring arguments with no type)
  - a choice represents an anonymous sum of the argument types
  - a field or prec expression represents the type of its argument

Some considerations...
  - string literals should have no effect on the derived type as they have no use in the production method; their type is null/void
  - the types of composite expressions must account for null-typed components, and may themselves be null
      - repeat and option expression propagate null-typed arguments
      - a sequence expression excludes null-typed elements from its tuple type
  - constructors can't have arguments of anonymous sum type, so we can't support general choice expressions; choices must instead be specified as production rules with multiple cases, which typically correspond to enum types
  - field and prec elements needn't appear in our syntax expressions: field names are obviated by automated parse tree translation, and precedence can be specified (without loss of expressivity) at the level of production rules

Create a refined type of syntax expression...
  ```
  enum SyntaxExpression {
    case lit(String)
    case pat(String)
    case sym(Symbol)
    case opt(SyntaxExpression)
    case rep(SyntaxExpression, Punctuation?)
    case seq([SyntaxExpression])
    case prec(Precedence, SyntaxExpression)
  }
  ```
Create a type of signature 
  ```
  enum Signature {
    case symbol(String) 
    case array(String)  
    case tuple([(symbol: String, optional: Bool)])
  }
  ```
and a partial function mapping expressions to signatures which limits the forms of supported expression...


### Wed May 22, 2024

ExprLang test cases work for translation methods generated by GrammarMarco!!!

Adapt TypedLang to use new grammar format...

Extend macro-side production rule to allow string literals to serve as .lit syntax expressions 

Note: It is no longer necessary to define custom sequence types
  - instead we can typealias an Array type (i.e. so the symbol name doesn't have angle brackets)

Note: we can no longer use static properties to define precedence values because our macro has no means of interpeting that syntax; instead we should either:
  - provide a tie-in with tree-sitter's named precedence groups
  - allow Grammar to implement a property mapping names to precedence

Note: $i syntax for closure parameters is not supported in production rules

Note: regex literals have syntax class RegexLiteralExprSyntax and kind regexLiteralExpr

Note: grammar.json has the following keys:
  - 'name', a string
  - 'word', a string 
  - 'rules', a dictionary mapping symbol names (string) to syntax expressions (object); a syntax expression has a 'type' (string) which determines its additional elements:
      - SYMBOL types have a 'name', which is a string
      - STRING types have a 'value', which is a string
      - PATTERN types have a 'value', which is a string
      - SEQ and CHOICE types have 'members', which are lists of expression
      - REPEAT types have a 'content', which is an expression
      - PREC, PREC_LEFT and PREC_RIGHT types have a 'value' (int) and a 'content' (expression)
      - FIELD types have a 'name' (string) and a 'content' (expression)
      - BLANK types have no extra elements
  - 'extra' is (presumably) a list of ignored expressions tokens, defined by default as {type: PATTERN, value: "\\s"}
  - other keys (which don't serve the immediate purpose) are 'conflicts', 'precedences', 'externals', 'inline' and 'supertypes'
  * note that optional(e) translates into choice(e, BLANK)


### Thu May 23, 2024

Implement generation of grammar.json...
  - add type RawExpression to reflect the structure of grammar.json
  - add a translation from Expression to RawExpression
  - add a translation from RawExpression to JSON
  - create grammar json by combining the symbol name and expression pairs of each rule

bug fix: references to multiple-choice symbol names are not prefixed with underscore
  - when creating expr instances from syntax, we can't know when referenced symbols/types are hidden because their rules are not generally available
  - so, when translating from Expr to RawExpr, we should provide a method to identify hidden type/symbol names
  - if that method detects undefined symbols then we needn't explicitly calculate sets of defined and referenced symbols

bug fix: need to add implicit start rule...
  - we can't use JSONSerialization because we must ensure the start rule appears first; so generate json text

bug fix: use of patterns for operator choices doesn't work; e.g. "(+|-)"
  - need to escape special characters...


### Fri May 24, 2024

bug fix: field names must be applied to captures in raw expressions...
  - wrap symbols and patterns in fields in Expression.getRawExpression
  - add a counter parameter...

bug fix: can't capture operators using pattern expressions
  - patterns don't generate syntax nodes
  - we need to expose an explicit choice node, but choices generally require all branches have the same capture types
  - for now, implement a restricted form 'alt' taking a list of string literals...

todo: implement word...
  - `static var word : String?` returns a regex as a string literal
  - output grammar must include top-level `"word": "Word"` and rule `"Word": .pattern(regex),`

todo: cleanup...
  - split GrammarImp out of GrammarMacro
  - rename macro-side types with Imp suffix
  - remove unnecessary/obsolete code from TSKit and TSMacro

question: has anyone successfully linked a rust library into a swift package?
  - assuming the exported rust methods have a C-compatible interface

todo:
  - extend Grammar word spec to `static var word: (symbol: String, pattern: String)`
  - change pat case client-side Expression to take a Regex?


### Mon-Tue May 27-28, 2024

Update TSGen plugin to expect grammar.json rather than grammar.js

bug fix: TypedLang tests fail
  - the task of updating the grammar rules to the new format was incomplete

On adding Rust library dependencies to Swift packages...
  - see https://chinedufn.github.io/swift-bridge/building/swift-packages/index.html
  - see https://github.com/tmarkovski/rust-to-swift
  - Package.swift must specify a `binaryTarget` for the compiled rust lib
      ```
      products: [
        .library(name: "SwiftWrapper", targets: "SwiftWrapper"),
      ],
      targets: [
        .target(name: "SwiftWrapper", dependencies: ["RustLib"]),
        .binaryTarget(name: "RustLib", url: "https://.../bundle.zip",
        checksum: "..."),"
      ]
      ```
      
On extending tree-sitter CLI for use as a library...
  - `tree-sitter generate` can take grammar.json rather than grammar.js
  - following is the essesnce of the generate command:
    ```
    pub fn generate_parser_text_from_json(json: &str) -> String {
        let input_grammar = parse_grammar(&json)?;
        let (syntax_grammar, lexical_grammar, inlines, simple_aliases) = prepare_grammar(&input_grammar)?;
        let variable_info = node_types::get_variable_info(&syntax_grammar, &lexical_grammar, &simple_aliases)?;
        let tables = build_tables(
            &syntax_grammar,
            &lexical_grammar,
            &simple_aliases,
            &variable_info,
            &inlines,
            None,
        )?;
        render_c_code(grammar_name, tables, syntax_grammar, simple_aliases, inlines)
    }
    ```
  - rendering is implemented by `struct Generator`, which serves both to extract the parameters of a TSLanguage instance and to support the incremental construction of the source (via text buffer and indentation state)
  - note that supporting multiple rendering formats will require decoupling the parameter extraction and rendering functionality of Generator, which is complicated by the fact that parameter extraction is spread across init and the various rendering methods...
      - `add_stats` calculates token_count, which would better be assigned to an ivar on init
      - `add_symbol_enum` populates `symbol_order: HashMap<Symbol,usize>`, which would better be done by init
      - `add_non_terminal_alias_map` calculates local var `alias_ids_by_symbol` from `alias_ids` (note the shadowing of the latter); ...
      - `add_primary_state_id_list` calculates local var `first_state_for_each_core_id` ...
      - `add_field_sequences` calculates local var `field_map_ids`
      - `add_lex_function` calls `add_lex_state`; 


### Thu May 30, 2024

Factor the data used in code generation out of struct Generator (as GeneratorData), leaving only the code generation specifics.

Factor construction of alias_ids_by_symbol out of add_non_terminal_alias_map as method get_symbol_and_alias_list_pairs.


### Fri May 31, 2024

The current plan is to 
  - first enable a tree-sitter cli option to generate swift code 
  - then expose a callable function to  
  - need to fork tree-sitter; for now link to a local copy

As a proof of concept, manually translate a parser.c into a swift equivalent
  - the swift code will reside in each Grammar struct; in this trial case, ExprLang
  - this code requires knowledge of the API declared by parser.h...
      - 'ideally' that could be included in tree-sitter/api.h, but the naive approach doesn't work
      - instead create a new package TSLanguage which simply contains parser.h; this file appears to be invariant across parsers


### Mon Jun 3, 2024

Complete first translation of parser.c into Swift...

Summary of changes to TSKit to support generation of TSLanguage...
  - added TSLanguage target to provide access to the API defined by parser.h; an empty TSLanguage.c is required to enable running tests...
      ** in an Xcode project, this could be achieved with a bridging header **
  - remove the TSLanguage wrapper class
  - Grammar's language now has type UnsafePointer<TSLanguage>
  - Grammar maintains symbol names as an array of StaticString
      - extend StaticString to implement Comparable
  - Grammar adopts method to translate symbols to strings
  - ParsingContext no longer requires language member
  - provide convenience initializers for various TreeSitter structs (such as TSFieldMapEntry)
  - manually implement ExprLang.language (effectively parser.swift)


### Tue Jun 4, 2024

Debug manual implementation of ExprLang.language

Plan for refactoring plan tree-sitter generate...
  - complete separation of Generator and GeneratorData
      - todo: add_lex_state needs unwinding
      - todo: add_parse_table needs unwinding
  - create a trait to specify Generator functionality
  - add an cli argument to choose generated code format/language
  - implement swift code gen

Extract calculation of field_map_ids and flat_field_maps from add_field_sequences to function get_field_info on GeneratorData.

Notes on the generation of lexing methods...
  - `struct LexTable { states: Vec<LexState> }`
  - `struct LexState { accept_action: Option<Symbol>, eof_action: Option<AdvanceAction>, advance_actions: Vec<(CharacterSet, AdvanceAction)> }`
  - why does Generator.generate replace each of main_lex_table and keyword_lex_table with LexTable::default(); why initialize as tables.main_lex_table???
  - add_lex_function affects data.large_character_sets, so is called prior to add_character_set; since C requires forward declarations, the text of the lex functions is then shifted ...
  - data.large_character_set_info has an is_used property which gates the generation of `static TSCharacterRange xxx[] = {`


### Wed Jun 5, 2024

Notes on add_parse_table :
  - this method generates both ts_parse_table and, conditionally, ts_small_parse_table and ts_small_parse_table_map
  - regarding ts_parse_table
      - the code iterates over the first `large_state_count` elements of the `states` array of `parse_table`
      - each state has `terminal_entries` and `nonterminal_entries`, which have type IndexMap (a HashMap with predictable ordering)
      - the entries are combined and ordered starting with non-terminals by symbol, followed by terminals by symbol_order
  - ts_small_parse_table and ts_small_parse_table_map are generated if `large_state_count < parse_table.states.len()`

Define `trait RenderTarget` with methods to build code for the configuration hierarchy
  ```
  fn begin_language(&mut self);

  fn begin_symbol_types(&mut self);
  fn add_symbol_types_item(&mut self, name: &str, text: &str);
  fn end_symbol_types(&mut self);

  ...

  fn end_language(&mut self);
  ```

Create `struct RenderTargetC`, and implement `RenderTarget` by translating the existing `add_` methods of Generator

  
### Thu Jun 6, 2024

Continue tweaking tree-sitter's Generator to enable alternate source code


### Fri Jun 7, 2024

Notes on add_lex_state :
    ```struct LexState {
           accept_action: Option<Symbol>,
           eof_action: Option<AdvanceAction>,
           advance_actions: Vec<(CharacterSet, AdvanceAction)>,
       }```
  - each such struct corresponds to a case of a lex function, rendered as a sequence of statements terminated by END_STATE
  - accept_action and eof_action are rendered first
  - the pairs (chars, action) of advance_actions are then rendered iteratively...
  - these are sorted with singleton sets first, which will be grouped together as a single ADVANCE_MAP if there are sufficiently many (stated to reduce compile time)
  - for each subsequent pair, the chars set is 'simplified' by removing characters which have already appeared in preceding elements (viz. ruled-out)
  - if the simplified chars has sufficiently many ranges then it is approximated by a 'large' character set, which determines sets of additions and removals...
  - ultimately a pair of sets 'asserted_chars' and 'negated_chars' is computed, which is additions and removals if a large set is chosen or simplified_chars and {} otherwise
  - the condition on each action consists of positive and negative components, both optional; the positive condition is derived from large_set and asserted_chars, and the negative condition from negated_chars


### Mon Jun 10, 2024

Complete transition of add_lex_state method...
  - except, the ordering of lex function and character set definitions...


### Tue Jun 11, 2024

Begin to implement rendering of swift code...
  - create RenderBuffer as a means to text accumulation code between RenderTarget impls
  - add extensions to Swift.UnsafeBufferPointer to simplify creating sparse 1 and 2-d arrays
      `static func initialized(count: Int, zero: Element, indexValuePairs: [(index: Int, value: Element)]) -> Self`
      `static func initialized(rowCount: Int, columnCount: Int, zero: Element, indexValuePairs: [(row: Int, column: Int, value: Element)]) -> Self`
  - various changes to RenderTarget trait...
      - add context parameter to leverage various features of Generator; particularly conversion of symbol and field indices to enum names
      - drop the begin/end section methods w.r.t. external scanner states; instead, the add_item method must iterate over the given token set; a similar simplificatino should be applied to parse_table methods
  
todo: allow specifying an optional enclosing struct or extension name


### Wed Jun 12, 2024

Continue with rendering swift code
  - implement ADVANCE_MAP as inline fn
  - implement extension methods on UnsafeBufferPointer to support defining 'sparse' arrays (to mirror C syntax)
  - generated swift code compiles, but is incomplete:
    - todo: implement rendering of ADVANCE actions via RenderTarget trait default

note: we might reuse C code generation through various changes to RenderTarget
  - add default implementations for various methods
  - add a property indicating whether if/else branches require braces


### Thu Jun 13, 2024

Note: For now I'm going to ignore the problem of generating a swift-code parser from the command-line...
  - instead focus on the library interface

Move method implementations from RenderTargetC to RenderTarget as defaults where appropriate...
  - this requires rendering macros be applicable to RenderTarget, which requires it has a method to retrieve a mutable reference to a RenderBuffer...
  - for RenderTargetSwift, references to named character sets must be suffixed with .baseAddress
  - set_contains must be defined in parser.h, and must use const for range pointers...

todo: link tree-sitter cli into TSLanguage target and call from TSMacro
todo: clean-up interface by which RenderTarget obtains symbol names from Generator
todo: rename GeneratorData to Generator
todo: eliminate trailing whitespace in generated code by replacing add_line!(self, "\n") with add_newline!(self), which doesn't implicitly add_whitespace


### Fri Jun 14, 2024

Note: when running tree-sitter generate...
  - if grammar.js does not exist in the working directory it is created to contain a simple 'hello' grammar; this is the case regardless of whether or not an existing file is specified as argument
  - if no argument is given then the 'hello' grammar is used even if grammar.json exists, so grammar.json must be specified as an argument
  - arguably grammar.js should not be created if an argument is provided

Towards calling the grammar generation library function from our Swift macro...
  - first enable calling from a c program ...
  - requirements documented at https://docs.rust-embedded.org/book/interoperability/rust-with-c.html
  - first configure Cargo.toml to produce a static library in addition the rlib format which is required by the binary target
      [lib]
      crate-type = ["rlib", ""staticlib"]
  - this produces libtree_sitter_cli.a

On adding Rust library dependencies to Swift packages...
  - references...
      - https://chinedufn.github.io/swift-bridge/building/swift-packages/index.html
      - https://developer.apple.com/documentation/xcode/creating-a-multi-platform-binary-framework-bundle
      - https://developer.apple.com/documentation/xcode/distributing-binary-frameworks-as-swift-packages
  - ensure rust toolchains are installed for the desired platforms: aarch64-apple-darwin, x86_64-apple-darwin
      $ rustup target add aarch64-apple-darwin
  - build for the desired platforms, creating target/<platform>/libtree_sitter_cli.a for each
      $ cargo build --target aarch64-apple-darwin
  - within the target directory, create a universal library combining the binaries for each platform
      $ mkdir -p macos-universal
      $ lipo target/aarch64-apple-darwin/debug/libtree_sitter_cli.a ... \
          -create \
          -output universal-macos/libtree_sitter_cli.a
  - create an XCFramework bundle combining the universal library and headers...
      $ xcodebuild -create-xcframework \
          -library macos-universal/libtree_sitter_cli.a \
          -headers ../cli/include \
          -output universal-macos/TreeSitterCLI.xcframework
  - sign the bundle
      $ codesign --timestamp -s "Apple Development: ..." universal-macos/TreeSitterCLI.xcframework
  - Package.swift must specify a binary target for the xcframework, either directly within the package
      .binaryTarget(name: "TreeSitterCLI", path: "XCFrameworks/TreeSitterCLI.xcframework"),
    or as a remote bundle...
      - todo
  * note: the lipo step appears to be necessary; instead specifying all platform-specific libraries to xcodebuild fails with the following
      - `Both 'macos-x86_64' and 'macos-arm64' represent two equivalent library definitions`


TODO: add a constant TS_ABI_VERSION_CURRENT to TreeSitterCLI.h

TODO: build xcframework as part of cargo build (opt-in)


### Sat Jun 15, 2024

After minor tweaks, the parser generation function is successfully invoked from Swift!
    ```
    import TreeSitterCLI
    extension Grammar {
      public static func parserSource(for jsonText: String, abi_version: UInt32 = 14) throws -> String {
        // Invoke the parser generator with the bytes of the JSON grammar and a callback which
        // returns (as an opaque pointer) a manually retained NSString containing the Swift text.
        let optionalOptionalUnsafeRawPointer = try jsonText.utf8.withContiguousStorageIfAvailable { jsonBuf in
          guard jsonBuf.count <= Int(UInt32.max)
            else { throw TSError("grammar text is too long") }
          return swift_parser_source_from_json_utf8(jsonBuf.baseAddress, UInt32(jsonBuf.count), abi_version) { srcBuf, srcLen in
            guard let srcBuf = srcBuf
              else { fatalError("parser genertion returned null?") }
            guard let swiftCode = NSString(bytes: srcBuf, length: Int(srcLen), encoding: NSUTF8StringEncoding)
              else { fatalError("failed to interpret result of parser generation") }
            return UnsafeRawPointer(Unmanaged.passRetained(swiftCode).toOpaque())
          }
        }
        guard let optionalUnsafeRawPointer = optionalOptionalUnsafeRawPointer
          else { throw TSError("grammar text has no contiguous utf8 representation") }
        guard let unsafeRawPointer = optionalUnsafeRawPointer
          else { throw TSError("parser generation failed") }
        return Unmanaged<NSString>.fromOpaque(unsafeRawPointer).takeRetainedValue() as String;
      }
    }
    ```
Unfortunately, invoking this function within the macro causes the macro to fail 
  - perhaps due to a sandbox violation?
  - after failure subsequent build fails linking with undefined symbol `_swift_parser_from_json_utf8`
  - note that libtree_sitter_cli.a must be manually removed from the build products dir in order to be update!!!


### Mon Jun 17, 2024

Debug the macro...
  - the link failure appears if TSKit does not have TreeSitterCLI as a dependency; I don't understand why, since TSMacro does not depend on TSKit (and has an explicit dependency on TreeSitterCLI)
  - ultimately the macro crashed because the json text passed was invalid due to enclosing triple quotes...


### Tue Jun 18, 2024

TreeSitterCLI.xcframework should be generated rather than being either in the repo or hosted remotely
  - however, being a binary target, we can't run any product of our package until it exists
  - we could require a script be run to produce the xcframework to make the package functional
  - ideally that script would build the framework from our tree-sitter fork, but that would require a clone independent of tht made by SPM to build our package
  - instead, add a script which creates a skeletal xcframework to enable building the package;
    and then add a command plugin to update the xcframework from the tree-sitter dependency...


### Wed Jun 19, 2024

Notes on cargo build
  - specify the location of Cargo.toml via --manifest-path
  - specify --lib to build the package's library
  - the directory for generated artifacts and intermediate files can be specified via the --target-dir option or the CARGO_TARGET_DIR environment variable
  - the --config option should allow override of crate-type; e.g. --config 'lib.crate-type=["staticlib"]'

Notes on Swift command plugins...
  - the plugin has a parameter of type PluginContext, which gives access to the package
  - a package has a list of dependencies, each with an associated package
  - a package has a directory, which in the case of a remote dependency is the location of the working copy
  
Adapt the script for building the cli xcframework to run from TreeSitterKit
  - there is no benefit to having a SPM command plugin 


### Thu Jun 20, 2024

How to implement error handling for the parser generation function...
  - the complication is that a swift function/closure passed to C can't capture context, so the means to interpret success or failure must be encapsulated in the return value of the completion callback, which in turn must be returned by the generation function
  - the simplest approach is for the completion callback to take a status code (zero for success) along with the existing parameters of text bytes and length, which can serve to describe the problem in the case of failure 
  - there are various sources of failure:
      - the given byte sequence might not be utf8
      - the abi_version might lie outside ABI_VERSION_MIN .. ABI_VERSION_MAX
      - internal methods parse_grammar, prepare_grammar and build_tables might return a Result::Err
  - without refactoring internal methods, we can only provide codes to distinguish these three sources

Add TSCommon sub-package for code shared by TSKit and macros
  - contains Swift interface to parser generation to enable testing
  - contains Exception type, extended with status code
  
Add tests for the parser generation interface

Removed obsolete command plugin for generating parser.c/h

Note: We can likely eliminate the TSLanguage package by including the content of parser.h in tree_sitter_cli.h...


### Fri Jun 21, 2024

Towards tree-sitter pull-request..
  - clean-up interface by which RenderTarget uses functionality of Generator
  - tweak RenderTarget method naming to better match existing code
  - rearrange contents of render.cs to minimize differences
  - fork tree-sitter and create a feature branch
  - tweak RenderTargetC to place character sets definitions prior to lex functions


### Mon Jun 24, 2024

Upload changes to tree-sitter fork (tag 0.1.0)

Update Package.swift to reference github

Note: the script for building TreeSitterCLI.xcframework needs to know the path to the working copy of tree-sitter
  - swift package build uses ./build/checkouts/tree-sitter
  - but Xcode uses ~/Library/Developer/Xcode/DerivedData/<MyProject>-<uid>/SourcePackages/checkouts/tree-sitter, where <uid> is a 'random' sequence of chars
  - apparently this can be overridden by adding an .xcconfig file to your project (https://stackoverflow.com/a/33192207),
    but Xcode provides no interface for specifying such a file in a swift package
  - rely on the copy made by SPM, which can be created or updated via `swift package update`,
    which must be performed immediately after cloning the project ...

Add unit tests for buffer pointer utilities


### Tue Jun 25, 2024

Delete Source/Examples, which are now obsolete 

Draft project overview


### Wed Jun 26, 2024

TSKit Issues ...
  - why does Expression not have an explicit choice?
  - constructor closures must have explicit param names
  - 0-ary constructors must declare params as `()`
  - macro-generated errors do not appear in written source; investigate use of 'diagnostics'
  - can't refer to nested types; must add type aliases
  - can be difficult to debug production rules since errors appear in the macro expansion which is unwieldy; helpful to generate a stub language to minimize macro expansion size
  - macro expansion is not well formatted; may help to adopt syntax builder


### Fri Jun 28, 2024

Recreate tree-sitter changes incrementally to ensure proper function:
  - Introduce RenderBuffer
  - Restrict mutation of Generator to its init method and move its rendering methods to new struct RenderTargetC.


### Tue Jul 2, 2024

bug fix: ADVANCE_MAP must accommodate two-character ranges

bug fix: avoid clone of render buffer text 


### Wed Jul 3, 2024

debugging tree-sitter tests
  - fix missing indentation
  - fix translation error in use of `ADVANCE_MAP`


### Thu Jul 4, 2024

Revert the addition of crate-type staticlib to cli/Cargo.toml
  - instead, specify staticlib as an override to cargo in the script to build the xcframework
  - cargo rustc --crate-type=staticlib ...

Upload changes to tree-sitter fork

Update build_xcframework script to remove .build/cargo prior to running cargo rustc
  - to avoid permission violation during build


### Fri Jul 5, 2024

Finish replaying tree-sitter fork commits to improve presentation...
  - push feature branch `swiftgen` and tag 0.1.4

Move todo items to github issues.

Added license file and removed per-file attribution.


### Sat Jul 6, 2024

Verified that the authentic tree-sitter periodically log panic backtaces to stderr for java and python corpus tests
  - these don't appear as test failures, so presumably they're expected behavior

Sync tree-sitter-fork with original repo (https://dev.to/untilyou58/keep-your-fork-in-sync-understanding-git-remote-upstream-366l)
  - create upstream remote
    ```
    $ git remote add upstream https://github.com/tree-sitter/tree-sitter
    $ git remote set-url --push upstream DISABLE
    ```
  - merge upstream changes 
    ```
    $ git fetch upstream
    $ git checkout master
    $ git merge upstream/master
    ```

Submit a pull request for tree-sitter fork
  - #3453 Extend CLI with a method to generate the Swift equivalent of parser.c
