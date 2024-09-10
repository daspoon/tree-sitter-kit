/*

*/

import SwiftUI


struct IssuesView : View {
  @StateObject var session : CodeSession

  @Environment(\.font) var font : Font?

  var body : some View {
    List(session.issuesSubject.value, selection: $session.selectedIssueIndex) { issue in
      Text(issue.error.describe(using: session.grammar))
        .font(font)
    }
  }
}
