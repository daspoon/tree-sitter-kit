## Intro
  - I've recently been implementing a programming language in Swift and decided to used tree-sitter for the parser
  - tree-sitter is a parser generator, meaning that you provide it with a grammar which describes the language and it produces a function whch converts text into  parse trees (aka syntax trees)
  - this is nice, because writing parsers is difficult, but it requires maintaining three separate components:
      - the grammar, which is written in javascript;
      - the data types which implement the language, such as variables, expressions and statements;
      - and glue code which translates parse trees into language implementation types
  - this is fine for one-off situations, but if you're implementing multiple languages or experimenting with language features it's a source of technical debt
  - so I wrote a library to brings these pieces together by generating both the grammar and the parse tree translation code from the language implementation types
  - I think it's cool and useful, so I've released it as open source and i'm delighted for the opportunity to share it with you today

## Outline
  - We'll begin with a basic overview of tree-sitter
  - next we'll look at a swift application to display parse trees
  - then we'll look at the main task of translating parse trees
  - and finally we'll see how to automate the process using swift protocols and macros
  - summary

## Caveats
  - I chose swift because it supports a functional style and is what I use most often now; swift's syntax is based on C, so it should be familiar to most of you; I'll say introduce features which may not be obvious as we encounter them, but please feel free to ask questions
  - here's the repo link; I'm using separate branches to present incremental changes; I'll start on the branch named 'talk-step-1' and will let you know when I switch, so you can follow along on github if you like
  - TODO: publish the outline with embedded branch links...

## Tree-sitter
  - tree-sitter is what's called a parser generator; you give it a grammar which describes a language and it creates a program which converts strings into what are called syntax trees or parse trees
  - (bring up the simple arithmetic expression grammar)
  - a tree-sitter grammar is written in javascript in a style called BNF; it consists of a set of production rules which map symbol names to syntax expressions;
  - (in this case there's only one production rule)
  - symbol names represent language elements, and syntax expressions describe matching strings;
  - syntax expressions are formed from the basic elements of string literals (enclosed in single quotes), regular expressions (enclosed in forward slashes), and symbol references (which are symbol names prefixed by $.); complex syntax expressions are build using choice, sequencing, optionality and repetition; 
  - symbol references give rise to the tree structure of a language and make these grammars more powerful than regular expressions
  - they also enable rules which could be interpreted in more than one way; such ambiguity must be avoided using precedence and associativity annotations
  - this says addition and subtraction are left associative and have precedence one; this states that exponentiation is right associative and has precedence 3; higher precedence values bind more tightly
  - this is a grammar for arithmetic expressions containing variables, operators and function calls; it's single rule states that an arithmetic expression has several possible forms:
      - the first is a variable name matching a regular expression
      - the second is an expression enclosed in parentheses; here we require a sequence of substrings, with the first and last being open and close parentheses, and with the string in-between matching the Expr rule;
      - the next four forms correspond to operators grouped by precedence and associativity, with higher values binding more tightly; the first three are infix operators, with addition '+' and exponentiation '^' being left and right associative respectively; the last is a prefix negation operator;
      - the final form is a function applied to a possibly empty sequence of arguments enclosed in parentheses and separated by commas.

  - let's look at how tree-sitter generates a parser...
      - you need the tree-sitter command-line tool installed
          $ which tree-sitter
      - you run it from a directory containing your grammar file
          $ cd ~/Desktop/tree-sitter
          $ ls
          $ more grammar.js
          $ tree-sitter generate
      - it generates a bunch of files, but only two are necessary for our purpose
          $ ls
          $ open -a xcode src/parser.c src/tree-sitter/parser.h
      - parser.c is the generated source code; it configures data structures required for parsing the grammar and defines a TSLanguage struct aggregating this data; parser.h is the subset ofthe tree-sitter API required to compile parser.c

  - in addition to creating a parser, tree-sitter also provides a library to support working with parse trees
      - let's take a quick look at the API <tree-sitter/api.h>
      - its an object-oriented API, in the sense that it exports a number of types and each of those types has a set of functions which take an instance as its first argument
      - there are only 4 data types relevant to our purpose 
      - and the first three (scroll to reveal), TSLanguage, TSParser and TSTree, are mostly incidental
      - but the fourth, TSNode, represents the nodes of the parse trees which we must translate into our language implementation types

## Using tree-sitter from Swift
  - as a visual aid, I've written an app to display the parse tree for the text of an expression
  - let's run it
      - the text "a + f(b, c)" produces a tree of depth 2; the root node has three children, the first two being leaves and the third a subtree with six children (all of which are leaves)
      - each node is labelled with the source text that it represents and the name of its production rule, if any; the string literals (such as open paren) and regular expressions in the grammar do not have symbols; so nodes representing identifiers do not have children
      - as the text changes the parser is invoked to produce a new tree and the view is updated
      - you'll notice that the parser synthesizes missing structure whe possible
      - and that syntax errors appear as nodes in the tree; parsing never fails, it just produces a tree with embedded error nodes
  - let's look at the implementation
      - this is an xcode project
      - it contains the grammar and the generated parser files
      - we need a bridging header to make the the defined language and tree-sitter APIs available to Swift
      - the entry point for the application presents a window containing a custom view
      - the view has a state object named content which maintains the expression text and the corresponding parse tree
      - the StateObject annotation enables the view to be re-rendered whenever content changes
      - rendering is performed by the body property, which in this case presents a TextField to edit the expression and an OutlineView to show the  node hierarchy as a sequence of collapsable rows
      - the final argument to OutlineView, which is called a trailing closure, is a function to produce a view for each visible node of the hiearchy; in this case we ask content for a bit of styled text
  - let's look at the Content object
      - conforming to the ObservableObject protocol enables its use as a state object by client views
      - first we create a parser for the defined language (looking at TSLanguage is a distraction)
      - the text property is marked Published to enable change notification 
      - the root node method recreates the parse tree because it's called in response to the changing text
      - next we have an initialize and finally a method to produce a styled description of a given node; that description includes the matched range of the underling source and the grammar symbol, if any.
      - note that TSNode maintains the range of source bytes which it matches, so an auxiliary type InputSource is to retrieve the text for a range of bytes
      - the rest of the code is incidental
  
## Translating syntax trees
  - now that we understand tree-sitter basics, let's turn to the task of translating parse trees into data structures of our language
  - we define an Expr type as a union, or enum, of either a string naming a possibly functional value or an application of a function to a list of argument expressions
  - we need to write a method to create an instance of this type from a parse tree node
  - this requires knowing which of the production rule choices the given node represents
  - unfortunately this requires analyzing the number and content of the node's children, which is complicated and doesn't scale well

  - let's step back and modify our grammar to make translation simpler
  - I'm now switching to the 'talk-tests' branch
  - on this branch the application offers a choice of grammars; the original grammar is named 'simple', and i've added variations named 'verbose' and 'economy'
  - the 'verbose' grammar has three essential changes:
      1. the Expr rule has been split into subrules, one for each of the original choices; now each Expr node has a single child whose symbol is the name of the subrule; this can be used by the ingestion method;
      2. I've also added rules for variable names and argument lists; this is for clarity and reuse, but I'm also taking the stance that each language element should have its own production rule
      3. finally, i'm tagging the function call's optional parameter list with a field name; this enables use to decide whether or not it exists; (note that ExprList node doesn't appear when there are no arguments)
  - note that the Expr node has become redundant since it always has a single child which provides all necessary information,
  - the 'economy' grammar hides the Expr nodes by adding an underscore prefix; doint this requires a adding a start rule because the root node of a parse tree corresponds to the first listed rule and must be visible

  - let's return to the translation method
  - I've modified Expr to represent variables as a Name type rather than String
  - also, our initializer must take an extra parameter which provides access to the source text and the language symbol table; this is necessary because nodes only maintain text ranges and symbols identifiers;
  - now we configure a new instance using a switch statement on the symbol of the given node
  - the first case corresponds to a variable; I've changed the representation of variables from strings to instances of a Name type, so this case delegates translation of the child node to that type
  - the second case is a parenthesized expression, so we simply recurse on the node's middle child
  - the third case is an infix operator, so we form an application of the operator name to the left and right arguments
  - the fourth case is a prefix operator, which is handled similary
  - the last case is function call; we attempt to get the child node with the 'args' label; this will return a special 'null' node if there is no such child; so we delegate to ExprList if that node exists and create an empty argument list otherwise;
  - finally, switch statements must be exhaustive so we exit for any unexpected symbol names
  - how do Name and ExprList work...

  - in order to test the translation method we must first convert a string into a parse tree and provide the necessary context information
  - this is best written as a method as it is a somewhat verbose
  - as before we need a our language and parser
  - we also need to throw if the parse tree has errors because our translation method expects there is none
  - the root node of the parse tree is always a 'start' production, so we take its child,
  - and finally we bundle the language and input source as context for the translation method
  
  - the tests are written against the XCTest package, which is typical for Apple platforms
  - we define a class inheriting from XCTestCase and implement various functions whose names begin with 'test' and which take no arguments;
  - these functions throw an exception to indicate failure, and there's a bunch of macros beginning with XCTAsert which enforce expectations;
  - the main purpose of these tests is to ensure that parsing of various strings produce the expected results, which requires writing instances manually
  - to improve readability I've added a method enabling Expr instance to be written more concisely;
  - essentially, a string literal appearing in a context which requires an Expr is implicitly converted to an Expr;
  - this is because I've made Expr conform to the ExpressibleByStringLiteral protocol which implements the conversion;
  - the next test takes advantage of this feature to check the results of parsing the essential language features
  - the final test checks that parsing fails for various ill-formatted strings
  
  - we've now seen the three separate components of parsing a custom language: the implementation types, the grammar, and the translation of parse trees into implementation types
  - the translation code is a source of error which can't be checked by the compiler
  - can we do better?

## Automating the process
  - we can do better by having a single specification which is checked by the compiler; adding structure to the implementation types allows us to generate both the grammar and translation methods

### Grammar generation

  - we start by adding a protocol to specify the extra structure of implementation types, which amounts to a production rule and a translation method
      - the production rule is implied by the symbolName and syntaxExpression properties
      - the symbolName is the type name with an underscore prefix if the production rule is hidden,
        which is determined by the *symbolIsHidden* property which defaults to *false*
      - so only the syntax expression and translation methods are required
      - note that default implementations are provided by extensions, and that methods without defaults must be implemented by the conforming type
      - note also that Swift support both static and dynamic binding for protocol methods -- those listed in the protocol itself are dynamically bound (and can be overridden by conforming types), while those listed only in an extension are statically bound (and cannot be overridden).
  - a nice consequence of the protocol is that we get a top-level parsing method for 'free'

  - for enum types such as Expr we add the refined protocol ParsableByCases which specifies the subrules as a mapping of names to syntax expressions; the production rule for the enum type itself is derived from the subrules and is implicitly hidden
  - the TSExpression type corresponds of tree-sitter's grammar syntax which is not part of the tree-sitter library; it has the same constructs (string literals, regular expressions, sequencing, etc.); the the prod case represents to a production, which equates to   tree-sitter's dollars-dot syntax
  - a ProductionRule represents a production rule for either a struct type or an enum case

  - i'm switching now to the 'talk-step-3' branch to look at the changes made in using this protocol
      - we'll start with Name because its the simplest; 
      - we declare conformance to the protocol and implement the only missing requirement, syntaxExpression, as a regular expression
      - similarly for ExprList, where the syntax expression involves repetition of the Expr production
      - finally for Expr we have adopted ParsableByCases and have defined the syntax expressions for subrules using custom string interpolation
      - this works because TSExpression conforms to the ExpressibleByStringInterpolation protocol
      - which enables an interpolated string to be used in any context requiring that type, must like we saw previously with ExpressibleByStringLiteral
      - an interpolated string is effectively a sequence of alternating string literals and escaped method calls
      - the protocol requires defining an interpolator which builds an instance of the type by accumulating the string literals and method call results
      - the supported method calls are determined by the interpolator's implementations of addInterpolation
      - essentially it's building a sequence of expressions
  - this gives us enough to generate a grammar
      - I've added a Grammar type for this purpose; it takes the root type of the language, forms the transitive closure of the types reachable through production rules, and formats the production rules of those types in javascript
      - this is run as a test case, and I'll say more about that in the conclusion
      - but for let's look at the result...
      - aside from formatting changes, the only difference is that production reference is tagged with an increasing numeric field names
  
### Automated parse tree translation
  - our parse tree translation code looks like boiler-plate, and we might eliminate it by using the syntax tree to either traverse the input node hierarchy (like an interpreter) or to generate the code which we would naturally write; i chose the latter approach because it made the most sense to me at the time
  - code generation in swift is performed by macros
  - swift macros differ from C macros in that...
      - macro expressions are checked for both syntactic and semantic validity; they have specific numbers and types of arguments and can appear in specific contexts; in that sense they're similar to function calls
      - a macro implementation is essentially a function which takes and returns swift syntax
      - macro expansion is performed by the compiler invoking the macro implementation in a separate/sandboxed process -- so implementations must (currently) live in a library separate from the code in which they're used
  - there are several kinds of macro tailored to specific use cases; we're using a 'member' macro which can add variables, methods or types to a declaration to which it is 'attached'
  - let's look briefly the elements required to define our macro
      - the implementation is in the TSMacros target of the TreeSitterKit package
      - we won't look at the code in detail; it is enough to understand that there are two key files;
      - the first is Parsable.swift; it requires the SwiftSyntax module which is the API for interacting with Swift parse trees; it defines a struct named Parsable conforming to the MemberMacro protocol; it defines a method which given a struct or enum declaration returns an initializer declaration; it throws an exception to indicate that it can't be applied for some reason; 
      - the second important file is Plugin.swift which the compiler uses to locate available macros within a library
      - the final requirement is a declaration of the macro interface; that lives in the macros.swift file of the TSKit package, and enables use of the macro by the clients of that package; this declaration also states the names of the added members
  - finally, let's look at applying the macro to our language types
      - I'm now switching to the 'main' branch
      - applying @Parsable to Expr has allowed us to remove the translation method
      - and we can see the code generated by the macro expansion
      - you'll see it relies on adding static constructors for each rule which does not correspond to an enum case; that's a tradeoff, but not unreasonable
      - I haven't changed either Name or ExprList, because it wasn't clear how to support repetition and also it didn't seem worth the effort
      - what I did do was create a couple of generic sequence types, so ExprList can be rewritten a
      - in exchange i've added a static constructor for each rule which does not correspond to an enum case name
      - I have replaced ExprList with an instantiation of a generic sequence type


## Summary
  - what have we done...
  - issues
  - future directions
