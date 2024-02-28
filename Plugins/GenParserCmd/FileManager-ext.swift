/*

  Created by David Spooner

*/

import Foundation
import PackagePlugin


extension FileManager
  {
    func moveItem(at sourcePath: Path, to destinationPath: Path, overwriteExisting: Bool) throws
      {
        if overwriteExisting && fileExists(atPath: destinationPath.string) {
          try removeItem(atPath: destinationPath.string)
        }
        try moveItem(atPath: sourcePath.string, toPath: destinationPath.string)
      }


    func createDirectory(at path: Path, withIntermediateDirectories createIntermediates: Bool) throws
      {
        try createDirectory(atPath: path.string, withIntermediateDirectories: createIntermediates)
      }
  }
