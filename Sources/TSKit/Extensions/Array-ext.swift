/*

*/


extension Array {
  public static func extractElements(from node: TSNode, in context: ParsingContext, using f: (TSNode, ParsingContext) -> Element) -> Self {
    return (0 ..< node.count).map { i in
      f(node[i], context)
    }
  }

  public static func extractElements(separatedBy sep: String, from node: TSNode, in context: ParsingContext, using f: (TSNode, ParsingContext) -> Element) -> Self {
    let n = node.count; assert(n > 0 && n % 2 == 1)
    return stride(from: 0, to: n, by: 2).map { i in
      assert(i == 0 || context.inputSource.text(for: node[i-1]) == sep)
      return f(node[i], context)
    }
  }

  public static func extractElements(delimitedBy del: String, from node: TSNode, in context: ParsingContext, using f: (TSNode, ParsingContext) -> Element) -> Self {
    let n = node.count; assert(n > 0 && n % 2 == 0)
    return stride(from: 0, to: n, by: 2).map { i in
      assert(context.inputSource.text(for: node[i+1]) == del)
      return f(node[i], context)
    }
  }
}
