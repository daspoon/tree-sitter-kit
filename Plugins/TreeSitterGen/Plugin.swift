/*

  Created by David Spooner

*/

import PackagePlugin
import Foundation


/// *GenParser* invokes 'tree-sitter generate' to (re)produce the parser source code for a target representing a custom langage,
/// and must be invoked with explicit argument --target <target-name>.  Ideally this would be an in-build tool, but SPM doesn't appear
/// to support in-build tools for c-language targets.

@main
struct TreeSitterGen : CommandPlugin
  {
    /// The location of tree-sitter CLI.
    let treeSitterPath = "/usr/local/bin/tree-sitter"

    /// Names and locations of generated files.
    let grammarFileName = "grammar.js"
    func parserCDir(in directory: Path) -> Path
      { directory.appending(["src"]) }
    func parserCPath(in directory: Path) -> Path
      { parserCDir(in: directory).appending(["parser.c"]) }
    func parserHDir(in directory: Path) -> Path
      { parserCDir(in: directory).appending(["tree_sitter"]) }
    func parserHPath(in directory: Path) -> Path
      { parserHDir(in: directory).appending(["parser.h"]) }


    func performCommand(context: PluginContext, arguments: [String]) throws
      {
        var args = ArgumentExtractor(arguments)

        let fileManager = FileManager.default

        // Iterate over the target names specified as options
        for target in try context.package.targets(named: args.extractOption(named: "target")) {
          guard let target = target as? SourceModuleTarget
            else { print("target \(target.name) is not a source module"); continue }

          // Note paths of the source and working directories.
          let sourceDir = target.directory
          let workingDir = context.pluginWorkDirectory

          // grammar.js must exist in the source directory.
          let grammarPath = sourceDir.appending([grammarFileName]).string
          guard fileManager.fileExists(atPath: grammarPath)
            else { print("target \(target.name) does not contain '\(grammarFileName)'"); continue }

          // Invoke 'tree-sitter generate' with the specified grammar and working directory.
          print("processing \(grammarPath) in \(workingDir)")
          let process = Process()
          process.executableURL = URL(fileURLWithPath: treeSitterPath)
          process.arguments = ["generate", grammarPath]
          process.currentDirectoryURL = URL(fileURLWithPath: workingDir.string)
          try process.run()
          process.waitUntilExit()
          guard process.terminationReason == .exit && process.terminationStatus == 0
            else { throw Exception("tree-sitter generate failed with status: \(process.terminationStatus)") }

          // Move the generated c and h files into the source directory, first creating the required subdirectories if necessary.
          try fileManager.createDirectory(at: parserHDir(in: sourceDir), withIntermediateDirectories: true)
          try fileManager.moveItem(at: parserCPath(in: workingDir), to: parserCPath(in: sourceDir), overwriteExisting: true)
          try fileManager.moveItem(at: parserHPath(in: workingDir), to: parserHPath(in: sourceDir), overwriteExisting: true)
        }
      }


    /// Note that command plugins can't import modules other than Foundation.
    struct Exception : Error
      {
        let failureReason : String
        init(_ reason: String) { failureReason = reason }
      }
  }
