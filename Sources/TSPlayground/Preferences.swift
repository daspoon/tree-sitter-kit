/*

*/

import SwiftUI


class Preferences : ObservableObject {
  static var shared = Preferences()

  var defaults = UserDefaults.standard
  let defaultFontSizeKey = "defaultFontSize"
  let primarySplitRatioKey = "primarySplitRatio"
  let secondarySplitRatioKey = "secondarySplitRatio"

  @Published var defaultFont : NSFont { didSet { defaults.setValue(defaultFont.pointSize, forKey: defaultFontSizeKey)} }
  @Published var primarySplitRatio : CGFloat { didSet { defaults.setValue(primarySplitRatio, forKey: primarySplitRatioKey)} }
  @Published var secondarySplitRatio : CGFloat { didSet { defaults.setValue(secondarySplitRatio, forKey: secondarySplitRatioKey)} }

  private init() {
    UserDefaults.standard.register(defaults: [
      defaultFontSizeKey: NSFont.systemFontSize,
      primarySplitRatioKey: 0.75,
      secondarySplitRatioKey: 0.60,
    ])

    defaultFont = CTFont(.system, size: defaults.double(forKey: defaultFontSizeKey))
    primarySplitRatio = defaults.double(forKey: primarySplitRatioKey)
    secondarySplitRatio = defaults.double(forKey: secondarySplitRatioKey)
  }
}
