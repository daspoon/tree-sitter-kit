/*

*/

import SwiftUI


public struct AdjustableDivider : View {
  public enum Orientation { case horizontal, vertical }

  struct Thickness : ViewModifier {
    let thickness : CGFloat
    let orientation : Orientation

    public func body(content: Content) -> some View
      { orientation == .vertical ? content.frame(width: thickness) : content.frame(height: thickness) }
  }

  let orientation : Orientation
  let color : Color
  let thickness : CGFloat
  let onDrag : (CGFloat) -> Void

  public init(orientation o: Orientation, color c: Color = .init(white: 0.75), thickness t: CGFloat = 1, onDrag f: @escaping (CGFloat) -> Void) {
    orientation = o
    color = c
    thickness = t
    onDrag = f
  }

  var resizeCursor : NSCursor
    { orientation == .vertical ? .resizeLeftRight : .resizeUpDown }

  public var body: some View {
    Rectangle()
      .fill(color)
      .modifier(Thickness(thickness: thickness, orientation: orientation))
      .edgesIgnoringSafeArea(orientation == .horizontal ? .vertical : .horizontal)
      .onHover { if $0 { resizeCursor.push() } else { NSCursor.pop() } }
      .gesture(DragGesture(minimumDistance: 1, coordinateSpace: .local)
        .onChanged {
          onDrag(orientation == .vertical ? $0.location.x : $0.location.y)
        }
      )
  }
}
