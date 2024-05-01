Take-aways
  - there can be many grammars for a particular language, and the grammar determines the shape of the syntax tree
  - grammars only specify syntax, so some valid strings may fail to meet semantic restrictions such as type checking


Refine article outline...
  1. What is tree-sitter?
      - syntactically, a programming language is an infinite set of strings which are deemed to be valid, a grammar is a set of rules for producing the strings of a language, and a parser attempts to validate a string by translating it into the tree structure which demonstrates its construction by the rules of the grammar; parsing is typically the first step performed by a compiler
      - tree-sitter is a parser generator -- you give it a grammar written in javascript and it creates a parser written in C; it also provides a library which enables navigation of the tree structures produced by the parser
      - let's look at an example
          - this is a grammar for a language of arithmetic expressions with variables, operators and function calls
          - a grammar has a name and a set of production rules, typically one for each language construct such as type, declaration and statement
          - as our language has only expressions, this grammar has a single rule which states that an Expr has several possible forms
          - the first is a regular expression for variable names
          - the second is a sequence involving string literals for parentheses and a production; read $.Term as 'match an instance of the Term rule'
          - the next group corresponds to various operators grouped by precedence and associativity, with higher values binding more tightly; the first three are infix operators, with addition '+' and exponentiation '^' being left and right associative respectively; the last is a prefix negation operator.
          - the final expression describes a function applied to a possibly empty sequence of arguments separated by commas
      - let's look at how tree-sitter generates a parser...
          - you need tree-sitter installed
              $ which tree-sitter
          - you run it from a directory containing your grammar file
              $ cd ~/Desktop/tree-sitter
              $ ls
              $ more grammar.js
              $ tree-sitter generate
          - it generates a bunch of files, but only two are strictly necessary
              $ ls
              $ open -a xcode src/parser.c src/tree-sitter/parser.h
          - parser.c is the generated source code; it defines a TSLanguage struct which initializes the grammar-specific data structures required for parsing, and parser.h is the minimal subset of tree-sitter API required to compile parser.c

  2. How do we use tree-sitter from Swift?
      - i've written a SwiftUI app to show the parse trees for expressions of our language...
          - look at the default expression and note that every node corresponds to a range of text
          - edit the expression and note the error handling/resolution
      - the point is to give you a sense of what tree-sitter gives us:
            - language is a distillation of a grammar
            - parsing produces a hierarchy of nodes, each of which has a label (...), a range of source text, and zero or more child nodes
      - let's look at the code for this app...
          - it includes grammar.js and the corresponding parser.c/h
          - another header is required to export the defined language(s)
          - we need to link in the TreeSitter library, which implements the tree-sitter APIs
          - we need a language binding which enables the application language to interact with tree-sitter's C code; mention TSKit
          - walk through App, ContentView, and Content; note the roles of TSLanguage et.al. w.r.t. memory management; note that TSNode is 'toll-free bridged' and allows extension

  3. How to use tree-sitter to implement a custom language?
      - need language data types
      - need to translate parse trees into these types
      - need a means to distinguish choices
      - generally we want a correspondence between symbols and language structures
      - walk through the implementation of Expr.init(parseTree:)
      - show and run tests
      - state the problem: loose correlation between three artifacts
      - we can eliminate the separation of artifacts by doing two things: 
          - generate grammar.js by having each type define its own production rule
          - generate init method for each types

  4. Generating grammar.js
      - add Parsable protocol to identify the implementation types for our language elements:
          - symbolName, syntaxExpression, init(parseTree:context:)
      - create TSExpression to represent tree-sitter syntax expressions in Swift
      - ParsableByCases is a specialization for types with multiple production rules
      - ProductionRule represents a grammar rule for either a type or an enum case
      - ParsableProxy allows interaction with an existential type
      - Grammar infers all parsable types reachable through the syntax expression of a root type
      - show the test method for generation
      - this enables grammar generation, but what about construction?

  5. 

