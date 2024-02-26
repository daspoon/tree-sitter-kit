# New Project

This project aims to explore the use of tree-sitter for parsing of custom languages.


## Overview of tree-sitter

Tree-sitter is a parser generator, so it takes a language grammar and produces a program to convert source code to syntax trees,
but also provides a library for navigating and querying syntax trees.
It was developed at github to support a wide range of languages in their products.

### Features:
  - grammars are written in javascript
  - generated parsers are C files with no external dependencies
  - tree-sitter-cli enables generation and testing
  - tree-sitter is distributed with parsers for many popular languages
  - tree-sitter has bindings for many popular languages

### Advantages of tree-sitter parsers (vs yacc):
  - they are incremental, meaning that when the source changes they can update an existing syntax tree rather than creating a new one
  - they have built-in error resolution and produce the 'best' syntax tree when faced with ambiguity
  - together these advantages make tree-sitter parsers ideal for interactive coding environments
  - also support a larger class of languages (GLR vs LR)

### Learning resources:
  Github project: https://github.com/tree-sitter/tree-sitter
  Intro video: https://news.ycombinator.com/item?id=18213022
  Getting started: https://tree-sitter.github.io/tree-sitter


## Project Overview:

The immediate goal of the project is to integrate a tree-sitter parser into a Swift package which implements a custom programming language.
A more general goal is to simplify implementation of custom languages in Swift and/or Rust.

### Status
  - created an initial grammar via tree-sitter-cli
  - created a skeletal command-line tool to interact with swift-tree-sitter

### Hurdles
  1) How to load a custom parser into the command-line tool
      - neither of the swift bindings for tree-sitter on github (viktorstrate/swift-tree-sitter and ChimeHQ/SwiftTreeSitter) can be built when cloned; why?
      - doing so would provide a path forward as my custom language could be added by the same means as the default languages

  2) How to correlate grammar.js with the syntax-related data structures defined in swift
      A swift implementation naturally defines types for various syntactic elements,
          enum Expr {
            case name(String)
            case application(Expr, Expr)
            case abstraction(Var, Expr)
          }
      allowing the compiler to ensure that functions over those elements are total:
          func eval(_ expr: Expr) -> Value {
            switch expr {
              ...
            }
      But tree-sitter parsers produce generic syntax trees which must be translated into swift types by a process not unlike parsing.
          func ingest(_ tree: TSTree) throws -> Expr
            { ... }
      This translation process should be automated and type-driven, perhaps using macros...
      Note that the rust binding provides various macros as an alternate means to define grammars; we need to understand how that works.

