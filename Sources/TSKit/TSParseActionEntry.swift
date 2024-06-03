/*

  Created by David Spooner

*/

import TSLanguage


extension TSParseActionEntry {
  public static func shift(_ state: TSStateId, extra: Bool = false, repeat: Bool = false) -> Self {
    .init(action: .init(shift: .init(type: UInt8(TSParseActionTypeShift.rawValue), state: state, extra: extra, repetition: `repeat`)))
  }

  public static func reduce(_ symbol: TSSymbol, _ child_count: UInt8, dynamic_precedence: Int16 = 0, production_id: UInt16 = 0) -> Self {
    .init(action: .init(reduce: .init(type: UInt8(TSParseActionTypeReduce.rawValue), child_count: child_count, symbol: symbol, dynamic_precedence: dynamic_precedence, production_id: production_id)))
  }

  public static var recover : Self {
    .init(action: .init(type: UInt8(TSParseActionTypeRecover.rawValue)))
  }

  public static var accept : Self {
    .init(action: .init(type: UInt8(TSParseActionTypeAccept.rawValue)))
  }

  public static func entry(count: UInt8, reusable: Bool) -> Self {
    .init(entry: .init(count: count, reusable: reusable))
  }
}
