/*

*/

import SwiftUI


// An alternative to OutlineGroup ...

public struct OutlineView<Node, ID, Subview> : View where ID : Hashable, Subview : View {

  struct Context {
    let id : KeyPath<Node, ID>
    let children : KeyPath<Node, [Node]?>
    let selection : Binding<Node?>?
    let content : (Node, Bool) -> Subview
    let indent : CGFloat
    let autoexpand : Bool
  }

  struct Item : View {
    let context : Context
    let node : Node
    let isRoot : Bool

    @State var isExpanded : Bool = true

    init(context: Context, node: Node, isRoot: Bool) {
      self.context = context
      self.node = node
      self.isRoot = isRoot
      self.isExpanded = context.autoexpand
    }

    var isSelected : Bool
      { context.selection.map { $0.wrappedValue?[keyPath: context.id] == .some(node[keyPath: context.id]) } ?? false }

    func toggleSelection()
      { context.selection?.wrappedValue = isSelected ? nil : node }

    public var body : some View {
      HStack {
        Spacer()
          .frame(width: isRoot ? 0 : context.indent)
        switch node[keyPath: context.children] {
          case .some(let subnodes) :
            DisclosureGroup(
              isExpanded: $isExpanded,
              content: {
                if isExpanded {
                  ForEach(subnodes, id: context.id) { subnode in
                    Self(context: context, node: subnode, isRoot: false)
                  }
                }
              },
              label: {
                context.content(node, isSelected)
                  .onTapGesture { toggleSelection() }
              }
            )
          case .none :
            context.content(node, isSelected)
              .onTapGesture { toggleSelection() }
        }
        Spacer()
      }
    }
  }

  private let root : Node
  private let context : Context

  public init(_ root: Node, id: KeyPath<Node, ID>, children: KeyPath<Node, [Node]?>, selection: Binding<Node?>? = nil, autoexpand: Bool = false, @ViewBuilder content: @escaping (Node, Bool) -> Subview) {
    self.root = root
    self.context = .init(id: id, children: children, selection: selection, content: content, indent: 12, autoexpand: autoexpand)
  }

  public var body : some View {
    VStack {
      Item(context: context, node: root, isRoot: true)
      Spacer()
    }
  }
}
