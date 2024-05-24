/*

  Created by David Spooner

*/

import SwiftSyntax


enum Precedence {
  case none(Int)
  case left(Int)
  case right(Int)

  var jsonType : String {
    switch self {
      case .none : "PREC"
      case .left : "PREC_LEFT"
      case .right : "PREC_RIGHT"
    }
  }

  var jsonValue : Int {
    switch self {
      case .none(let v) : v
      case .left(let v) : v
      case .right(let v) : v
    }
  }
}


extension Precedence {
  /// Attempt to create an instance from a Swift syntax expression.
  init(exprSyntax: ExprSyntax) throws {
    switch exprSyntax.kind {
      case .functionCallExpr :
        guard let (name, args) = try exprSyntax.caseComponents
          else { throw Exception("expecting Precedence syntax") }
        switch (name, args.count) {
          case ("left", 1) :
            self = .left(try Int(exprSyntax: args[0].expression))
          case ("right", 1) :
            self = .left(try Int(exprSyntax: args[0].expression))
          default :
            throw Exception("invalid Precedence syntax")
        }
      case .integerLiteralExpr :
        self = .none(try Int(exprSyntax: exprSyntax))
      default :
        throw Exception("invalid Precedence syntax")
    }
  }
}
