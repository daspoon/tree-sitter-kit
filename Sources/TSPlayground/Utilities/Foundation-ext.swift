/*

*/

import Foundation


public extension CGFloat {
  func clamped(to range: ClosedRange<CGFloat>) -> CGFloat {
    guard self >= range.lowerBound else { return range.lowerBound }
    guard self <= range.upperBound else { return range.upperBound }
    return self
  }
}
