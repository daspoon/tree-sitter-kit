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

