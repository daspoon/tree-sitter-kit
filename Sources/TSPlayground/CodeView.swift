/*

*/

import Combine
import SwiftUI
import TSKit


public class CodeViewController : NSViewController, NSTextViewDelegate {
  typealias Issue = CodeSession.Issue

  let session : CodeSession
  var issues : [Issue] = []
  var editing : Bool = false
  var subscriptions : [AnyCancellable] = []

  init(session s: CodeSession) {
    session = s
    super.init(nibName: nil, bundle: nil)
  }

  var textView : NSTextView {
    view as! NSTextView
  }

  var textAttributes : [NSAttributedString.Key: Any] {
    return [
      .font: font,
      .foregroundColor: NSColor.textColor,
    ]
  }

  func attributes(for issue: Issue) -> [NSAttributedString.Key: Any] {
    let keyValuePairs : [(NSAttributedString.Key, Any)] = [
      (.underlineColor, NSColor.red),
      (.underlineStyle, NSNumber(value: NSUnderlineStyle.thick.rawValue)),
      (.toolTip, issue.error.describe(using: session.grammar)),
    ]
    return textAttributes.merging(keyValuePairs) { _, _ in fatalError() }
  }

  var font : CTFont = .init(.system, size: NSFont.systemFontSize) {
    didSet { updateContent() }
  }

  func updateContent() {
    // Note: we reconstruct attributed ranges with an explicit font to avoid the problem where the
    // value of textView.font is ignored both on application launch and after each editing change...
    let storage = textView.textStorage!
    storage.setAttributes(textAttributes, range: NSMakeRange(0, storage.string.count))
    for issue in issues {
      storage.setAttributes(attributes(for: issue), range: NSRange(issue.error.range))
    }
    textView.setNeedsDisplay(textView.bounds)
  }


  // MARK: NSViewController

  public override func loadView() {
    let textView = NSTextView()
    textView.translatesAutoresizingMaskIntoConstraints = false
    textView.linkTextAttributes = [:]
    textView.delegate = self
    view = textView
  }

  public override func viewWillAppear() {
    super.viewWillAppear()

    textView.string = session.text
    subscriptions = [
      session.selectedRangePublisher.sink { [weak self] range in
        guard let self else { return }
        // Note: our textView loses focus on selection changes in the Issues view; workaround by requesting focus
        if let nsrange = range.map({NSRange($0)}) {
          textView.setSelectedRange(nsrange)
          textView.scrollRangeToVisible(nsrange)
        }
        textView.window?.makeFirstResponder(textView)
      },
      session.issuesPublisher.sink { [weak self] issues in
        guard let self else { return }
        self.issues = issues
        self.updateContent()
      },
    ]
  }

  public override func viewDidDisappear() {
    super.viewDidDisappear()

    subscriptions = []
  }


  // MARK: NSTextViewDelegate

  public func textDidChange(_ notification: Notification) {
    assert(editing && notification.object as? NSTextView == .some(textView))
    session.text = textView.string
  }

  public func textDidBeginEditing(_ notification: Notification) {
    editing = true
  }

  public func textDidEndEditing(_ notification: Notification) {
    editing = false
  }

  public func textView(_: NSTextView, clickedOnLink link: Any, at index: Int) -> Bool {
    guard let string = link as? String, let index = Int(string)
      else { return false }
    guard (0 ..< issues.count).contains(index)
      else { print("\(#function) -- invalid issue index: \(index)"); return false }

    session.selectedIssueIndex = index
    return true
  }


  // MARK: NSCoding

  required init?(coder: NSCoder) {
    nil
  }
}


public struct CodeViewRepresentable : NSViewRepresentable {
  public let session : CodeSession

  @Environment(\.ctFont) private var ctFont : CTFont

  public init(session s: CodeSession) {
    session = s
  }

  public func makeCoordinator() -> CodeViewController {
    CodeViewController(session: session)
  }

  public func makeNSView(context: Context) -> NSTextView {
    return context.coordinator.textView
  }

  public func updateNSView(_ textView: NSTextView, context: Context) {
    context.coordinator.font = ctFont
  }
}


extension EnvironmentValues {
  struct CTFontEnvironmentKey : EnvironmentKey {
    static let defaultValue = CTFont(.system, size: 18)
  }

  public var ctFont : CTFont {
    get { self[CTFontEnvironmentKey.self] }
    set { self[CTFontEnvironmentKey.self] = newValue }
  }
}
