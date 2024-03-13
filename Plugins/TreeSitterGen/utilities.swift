/*

  Created by David Spooner

*/

import Foundation
import PackagePlugin


struct Exception : Error {
    let failureReason : String
    init(_ reason: String)
      { failureReason = reason }
  }


extension FileManager {
  func moveItem(at sourcePath: Path, to destinationPath: Path, overwriteExisting: Bool) throws {
    if overwriteExisting && fileExists(atPath: destinationPath.string) {
      try removeItem(atPath: destinationPath.string)
    }
    try moveItem(atPath: sourcePath.string, toPath: destinationPath.string)
  }

  func createDirectory(at path: Path, withIntermediateDirectories createIntermediates: Bool) throws {
    try createDirectory(atPath: path.string, withIntermediateDirectories: createIntermediates)
  }

  func writeData(_ data: Data?, to path: Path, overwriteExisting: Bool = true) throws {
    if overwriteExisting && fileExists(atPath: path.string) {
      try removeItem(atPath: path.string)
    }
    guard createFile(atPath: path.string, contents: data, attributes: [:])
      else { throw Exception("failed to write \(path)") }
  }
}
