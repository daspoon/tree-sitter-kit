/*

*/

import TSLanguage


extension TSFieldMapEntry {
  public init(_ field_id: TSFieldId, _ child_index: UInt8, inherited: Bool = false) {
    self.init(field_id: field_id, child_index: child_index, inherited: inherited)
  }
}
