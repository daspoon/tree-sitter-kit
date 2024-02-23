/*

*/

import SwiftTreeSitter


@main
struct TreeSitting
  {
    static func main() throws
      {
        let javascript = try STSLanguage(fromPreBundle: .javascript)
        let parser = STSParser(language: javascript)

        let sourceCode = "let x = 1; console.log(x);";
        let tree : STSTree = parser.parse(string: sourceCode, oldTree: nil)!
        print(tree.rootNode.sExpressionString!)

        let callExpression = tree.rootNode.child(at: 1).firstChild(forOffset: 0)
        print("type:\t\(callExpression.type)")
        print("start point:\t\(callExpression.startPoint)")
        print("end point:\t\(callExpression.endPoint)")
        print("start byte:\t\(callExpression.startByte)")
        print("end byte:\t\(callExpression.endByte)")
        print("")

//        sourceCode = "const x = 1; console.log(x);";
//        tree.edit(
//          STSInputEdit(
//            startByte: 0,
//            oldEndByte: 3,
//            newEndByte: 5,
//            startPoint: STSPoint(row: 0, column: 0),
//            oldEndPoint: STSPoint(row: 0, column: 3),
//            newEndPoint: STSPoint(row: 0, column: 5)
//        ))
//        tree = parser.parse(string: newSourceCode, oldTree: tree)!
//        print(newTree.rootNode.sExpressionString!)
      }
  }
