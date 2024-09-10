/*

*/

import SwiftUI


struct ParseTreeView : View {
  @StateObject var session : CodeSession

  var body : some View {
    ScrollView {
      OutlineView(session.rootNode, id: \.identifier, children: \.children, selection: $session.selectedNode) { node, isSelected in
        Text(session.attributedText(for: node, color: isSelected ? .blue : .primary))
      }
    }
  }
}
