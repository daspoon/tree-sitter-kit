/*

  Created by David Spooner

*/

import TSLanguage


extension TSFieldMapEntry {
  public init(field_id id: TSFieldId, child_index j: UInt8) {
    self.init(field_id: id, child_index: j, inherited: false)
  }
}
