
## abstract
  - i've been using tree-sitter to implement a custom programming language in Swift 
  - tree-sitter is a parser generator: you provide it with a grammar for a language and it produces a function to parse that language - i.e. to convert text into syntax trees
  - that's great, because writing parsers by hand can be difficult
  - but it requires maintaining three separate pieces of code:
      - the data types which implement the language (i.e. the abstract syntax)
      - the grammar specification (in javascript)
      - and a translation of syntax trees (output by tree-sitter) into your implementation types
  - maintaining these artifacts is tedious and error-prone, so I made a library which avoids this source of error using various features of Swift which include protocols, custom string interpolation, and macros.
  - I think it's cool and useful, so I've released it as open source 
  - and i'm delighted for the opportunity to share it with you today

## outline
  - what is tree-sitter
  - how to use tree-sitter from Swift
  - how do parse trees relate to a language implementation
  - 

## what is tree-sitter
  - let's look at a very simple language of arithmetic expressions over variables and function calls; while simple, it illustrates the essential issues in parsing of a full-featured language such as Rust
  - a grammar consist of a set of production rules which map symbols to syntax expressions;
  - symbols correspond to the data structures of your language, and syntax expressions describe tree structures (called parse trees) whose leaves represent matched strings and whose internal nodes represent matched production symbols
  - this grammar has a single production rule defining the form of the Term type; its syntax expression indicates a choice of several different forms:
      - the first is a regular expression for variable names
      - the second is a sequence involving string literals for parentheses and a production; read $.Term as 'match an instance of the Term rule'
      - the next group corresponds to various operators grouped by precedence and associativity, with higher values binding more tightly; the first three are infix operators, with addition '+' and exponentiation '^' being left and right associative respectively; the last is a prefix negation operator.
      - the final rule describes a function applied to a possibly empty sequence of arguments separated by commas
  - let's take a quick look at how tree-sitter turns this grammar into a parser written in C
      - show grammar.js in an otherwise empty directory
      - run tree-sitter generate in that directory
      - show the generated files, noting that src/parser.c and src/tree-sitter/parser.h 
      - parser.h and parser.c must be included in your project

## swift integration
  - how do we use tree-sitter from Swift?
  - I created a simple app to display the parse tree for an input expression...
      - launch app
      - tweak expression
      - note every node corresponds to a range of text (); internal nodes represent productions, leaves represent captured patterns
      - TODO: visually distinguish (via color) matched text vs production symbols; show text for every node
  - show tree-sitter as a dependency import
      - note that the TSLanguage, TSParser and TSTree are an opaque types; show tree-sitter/api.h
  - show the extension of TSNode and the underlying C struct...
      - part of this is a 'language binding' for the tree-sitter API
      - oop design, with methods of the form `ts_node_whatever(TSNode self, ...)`
      - Swift can interact directly with this type, and we can add methods to make it a 'better citizen'
      - briefly review its methods
  - note the essential features:
      - nodes have 'types'
      - nodes maintain source ranges
      - an auxiliary type is required to retrieve the text for a node's range
      
## swift Expr
  - how do parse trees relate to a custom language implementation
  - let's look at the Swift implementation of this language ...
      - Expr is an enum or disjoint union type with two cases: a variable name, and an application of an expression to a list of other expressions
      - this is more abstract than the grammar in that operators are represented as functions of two arguments
  - our first task is to translate parse trees into instances of this type
      - we'll use an initializer which takes a node and the underlying source 
      - we must decide which case to construct based on the structure of the node
      - but our current parse tree doesn't provide enough information; 
  - we need to tweak our grammar to better enable translation...
      - start by splitting Expr's single rule into a set of subrules, one for each alternate form...
      - also add production rules for Name and ExprList; partly for clarity and reuse, but also because each datatype should have its own production rule
      - show how this affects the parse tree
  - walk through the cases of Expr.init
      - note the delegation to Name and show its initializer
      - note the optional production of ExprList and the need for field name 'args'
      - show ExprList.init for parsing sequences
  - we're going to look at some tests, but first we'll add some code to make tests more readable
      - show Expr.init(text:)
      - show Name.init(stringLiteral:), Expr.init(stringLiteral:) and Expr.init(arrayLiteral:)
      - show and run the tests
  - in summary...
      - the relationship between parse trees and implementation types is manually written code
      - essentially we have three artifacts with no formal correlation between:
          - production symbols and abstract syntax types
          - captured symbols and constructor argument types
          - node indices/fields and constructor argument types
      - we can do better


## a parsable protocol
  - we want to eliminate the separation of artifacts by doing two things: 
      - generate grammar.js by having each type define its own production rule
      - generate init method for each types

  - Parsable is used to identify the types of our abstract syntax
      - it defines a symbol name, syntax expression, and an initializer
      - its functionality is defined on types rather than instances
  - TSExpression mirrors tree-sitter expressions and enables writing syntax expressions in Swift
  - ParsableByCases is a specialization for types with multiple production rules
  - ProductionRule represents a grammar rule for either a type or an enum case; its role is in generating grammar.js
  - ParsableProxy allows interaction with a type which is either Parsable type
  - Grammar create grammar.js by inferring all parsable types reachable through the syntax expression of a root type
  - show the test method for generation
  - this enables grammar generation, but what about construction?

## custom string interpolation
  - we look at string interpolation as a more economical means of specifying syntax expressions,
    but also that it simplifies the task of extracting captures (relevant for our macro)

## a parsable macro
  - macros are defined in special library targets, and expansion is performed a separate process
      - Parsable.swift defines the macro type
      - Plugin.swift makes the macro available to the Swift toolchain
      - macros.swift defines the client interface to the macro

  - look at the files Parsable.swift (defining the macro) and Plugin.swift (exporting the macro) in the TSMacros target
  - macro implementations receive syntactic/semantic correct code, and produce additional code (they can't change existing code) which is fed back into the compiler
  - macros operate on Swift (concrete) syntax
  
  - there are several kinds of macros, but we'll use 'member' macros which add additional members to a declaration
  - look at our parsable macro; we implement the method required by MemberMacro; it gives us a declaration; we distinguish between enum and struct declarations and invoke a method to generate initializer text, then return the translation of that text to syntax
  - generating an init method requires traversing the syntax expression and pulling-out the captures...
      - a struct might assign ivars in declaration order
      - an enum might use the production name as case constructor and pull the arguments 
      - generally we can view both as invoking a constructor with the appropriate arguments
  - the first problem is how to pull the captures from syntax expression
  - solve this by providing a higher-level interface to TSExpression; string interpolation to highlight captures
  - the second problem is matching a syntax expression to a constructor
  - solve this with the Signature type
  - putting it together as a single @Parsable...
  - show the code with string interpolated syntax expressions 
  - run the tests

6. Summary
  - the task of ingesting a parse tree informs the specifics of our grammar rules
  - optional must be encoded into calling productions
  - workflow needs polish; mixed language targets; invoking grammar generation
  - critique of swift macros

* Various notes
  - examples of why you might write a parser?
