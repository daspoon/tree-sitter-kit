/*

*/

import SwiftUI


public struct SplitView<FirstView: View, SecondView: View> : View {
  public enum Orientation { case horizontal, vertical }

  let orientation : Orientation
  let firstView : FirstView
  let secondView : SecondView
  let splitRatio : Binding<CGFloat>

  var dividerThickness = CGFloat(2)
  var dividerColor = Color.gray
  var minimumFirstLength = CGFloat(120)
  var minimumSecondLength = CGFloat(120)

  public init(orientation o: Orientation, splitRatio r: Binding<CGFloat>, firstView v1: FirstView, secondView v2: SecondView) {
    orientation = o
    splitRatio = r
    firstView = v1
    secondView = v2
  }

  public var body: some View {
    GeometryReader { geometry in
      let frame = geometry.frame(in: .local)
      let length = (orientation == .horizontal ? frame.width : frame.height) - dividerThickness
      switch orientation {
        case .horizontal :
          HStack {
            firstView
              .frame(width: splitRatio.wrappedValue * length)
            AdjustableDivider(orientation: .vertical,
              color: dividerColor,
              thickness: dividerThickness,
              onDrag: { x in
                // Note: x is reltive to the minX of the divider rect (i.e. splitRatio * length)
                let x = (splitRatio.wrappedValue * length + x).clamped(to: frame.minX + minimumFirstLength ... frame.maxX - minimumSecondLength)
                splitRatio.wrappedValue = x / length
              }
            )
            secondView
              .frame(width: (1 - splitRatio.wrappedValue) * length)
          }
        case .vertical :
          VStack {
            firstView
              .frame(height: splitRatio.wrappedValue * length)
            AdjustableDivider(orientation: .horizontal,
              color: dividerColor,
              thickness: dividerThickness,
              onDrag: { y in
                let y = (splitRatio.wrappedValue * length + y).clamped(to: frame.minY + minimumFirstLength ... frame.maxY - minimumSecondLength)
                splitRatio.wrappedValue = y / length
              }
            )
            secondView
              .frame(height: (1 - splitRatio.wrappedValue) * length)
          }
      }
    }
    .frame(minWidth: minimumFirstLength + dividerThickness + minimumSecondLength)
  }
}
