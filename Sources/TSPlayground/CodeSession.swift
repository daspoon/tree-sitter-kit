/*

*/

import Combine
import Foundation
import SwiftUI
import TSKit


public class CodeSession : ObservableObject {
  public struct Issue : Identifiable {
    public let id : Int
    public let error : SyntaxError
  }

  public let grammar : any Grammar
  public let encoding : String.Encoding

  private let parser : TSParser
  private var tree : TSTree!

  let issuesSubject = CurrentValueSubject<[Issue], Never>([])
  let selectedRangeSubject = CurrentValueSubject<Range<Int>?, Never>(nil)

  public init(grammar g: any Grammar, encoding e: String.Encoding = .utf8) {
    grammar = g
    encoding = e
    parser = g.createParser()
    textDidChange()
  }

  @Published public var text : String = "" {
    didSet { textDidChange() }
  }

  @Published public var selectedNode : TSNode? {
    didSet {
      let range = selectedNode.map {text.characterRange(forByteRange: $0.sourceByteRange, encoding: encoding)!} ?? nil
      selectedRangeSubject.value = range
    }
  }

  @Published public var selectedIssueIndex : Int? {
    didSet {
      let issue = selectedIssueIndex.map { issuesSubject.value[$0] }
      let range = issue.map {$0.error.range}
      selectedRangeSubject.value = range
    }
  }

  public var selectedRangePublisher : AnyPublisher<Range<Int>?, Never> {
    selectedRangeSubject.eraseToAnyPublisher()
  }

  public var issuesPublisher : AnyPublisher<[Issue], Never> {
    issuesSubject.eraseToAnyPublisher()
  }

  private func textDidChange() {
    #if true
    tree = parser.parse(text, existingTree: tree)
    #else
    tree = parser.parse(text)!
    #endif

    issuesSubject.value = grammar.syntaxErrors(in: tree, for: text)
      .enumerated()
      .map {.init(id: $0, error: $1)}
  }

  public var rootNode : TSNode {
    tree.rootNode
  }

  // Return an attributed string indicating the node symbol name, or the corresponding source text if unnamed.
  public func attributedText(for node: TSNode, color: Color = .primary) -> AttributedString {
    //assert(node.tree == tree.opaqueTree)
    let string = node.isNamed ? grammar.symbolName(for: node).description : text.string(forByteRange: node.sourceByteRange, encoding: encoding)!
    var attstr = AttributedString(string + " " + (node.hasError ? "⚠︎" : "") + (node.state == .max ? "⁕" : ""))
    attstr.foregroundColor = color
    return attstr
  }
}
