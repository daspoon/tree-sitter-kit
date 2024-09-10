/*

*/

import AppKit
import SwiftUI


@main
struct TSPlayground : App {
  @NSApplicationDelegateAdaptor(AppDelegate.self) var delegate

  struct ContentView : View {
    @StateObject var preferences = Preferences.shared
    @StateObject var session = CodeSession(grammar: MyGrammar())

    var body : some View {
      SplitView(orientation: .horizontal, splitRatio: $preferences.primarySplitRatio,
        firstView:
          CodeViewRepresentable(session: session)
            .environment(\.ctFont, preferences.defaultFont),
        secondView:
          SplitView(orientation: .vertical, splitRatio: $preferences.secondarySplitRatio,
            firstView: ParseTreeView(session: session)
              .tabItem { Label("Parse Tree", systemImage: "folder") },
            secondView: IssuesView(session: session)
              .tabItem { Label("Issues", systemImage: "questionmark.diamond") }
          )
      )
      .environment(\.font, Font(preferences.defaultFont))
    }
  }

  var body : some Scene {
    WindowGroup {
      ContentView()
    }
  }
}


class AppDelegate : NSObject, NSApplicationDelegate {
  @objc func selectedFontDidChange(_ sender: NSFontManager) {
    Preferences.shared.defaultFont = sender.convert(Preferences.shared.defaultFont)
  }

  func applicationDidFinishLaunching(_ notification: Notification) {
    // Register to observe changes to the selected font
    let fontManager = NSFontManager.shared
    fontManager.target = self
    fontManager.action = #selector(selectedFontDidChange(_:))

    // Install the font menu
    guard let fontMenu = fontManager.fontMenu(true)
      else { print("failed to create font menu"); return }
    guard let mainMenu = NSApp.mainMenu
      else { print("failed to get main menu"); return }
    let fontItem = NSMenuItem(title: "Font", action: nil, keyEquivalent: "")
    fontItem.submenu = fontMenu
    let editIndex = mainMenu.indexOfItem(withTitle: "Edit")
    mainMenu.insertItem(fontItem, at: editIndex >= 0 ? editIndex + 1 : mainMenu.numberOfItems)

    // Activate the app...
    NSApp.setActivationPolicy(.regular)
    NSApp.activate(ignoringOtherApps: true)
  }
}
