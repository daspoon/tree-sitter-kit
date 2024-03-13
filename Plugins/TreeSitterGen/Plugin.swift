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
    func includeDir(in directory: Path) -> Path
      { directory.appending(["include"]) }
    func includeFile(in directory: Path) -> Path
      { includeDir(in: directory).appending("exports.h") }

    /// The content of the generated include file.
    func includeText(with languageName: any StringProtocol) -> String {
      """
      #include <tree_sitter/api.h>
      TSLanguage *tree_sitter_\(languageName)();
      """
    }

    func performCommand(context: PluginContext, arguments: [String]) throws
      {
        var args = ArgumentExtractor(arguments)

        let fileManager = FileManager.default

        // Regex to extract the grammar name from the content of each grammar.js
        let grammarNameRegex = try Regex("module\\.exports\\s*=\\s*grammar\\s*\\(\\s*{\\s*name\\s*:\\s*'([a-zA-Z_]+)'")

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

          // Read grammar.js and extract the specified name
          let grammarText = try String(contentsOfFile: grammarPath)
          guard let match = grammarText.firstMatch(of: grammarNameRegex), let nameRange = match[1].range
            else { throw Exception("failed to extract name from grammar file") }
          // WTF: Regex behaves differently here than in a playground, returning the whole match rather than the capture text...
          let grammarName = grammarText[nameRange]

          // Invoke 'tree-sitter generate' with the specified grammar and working directory.
          print("processing '\(grammarName)' in \(workingDir)")
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

          // Write the target include file defining the language.
          guard let includeData = includeText(with: grammarName).data(using: .utf8)
            else { throw Exception("failed to encode include file text as UTF8") }
          try fileManager.createDirectory(at: includeDir(in: sourceDir), withIntermediateDirectories: true)
          try fileManager.writeData(includeData, to: includeFile(in: sourceDir))
        }
      }
  }
