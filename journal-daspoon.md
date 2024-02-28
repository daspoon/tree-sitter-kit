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

