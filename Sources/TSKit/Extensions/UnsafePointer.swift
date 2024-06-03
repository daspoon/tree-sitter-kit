/*

  Created by David Spooner

*/


extension UnsafePointer {
  /// Return an allocated instance intialized with the given procedure. If 'zero' is true (the default) then the allocated memory is first initialized to zero.
  public static func initialized(zero: Bool = true, using initializer: (inout Pointee) -> Void) -> Self {
    let rp = UnsafeMutableRawPointer.allocate(byteCount: MemoryLayout<Pointee>.size, alignment: MemoryLayout<Pointee>.alignment)
    if zero {
      _ = rp.initializeMemory(as: UInt8.self, repeating: 0, count: MemoryLayout<Pointee>.size)
    }
    let mp = rp.bindMemory(to: Pointee.self, capacity: 1)
    initializer(&mp.pointee)
    return UnsafeRawPointer(rp).bindMemory(to: Pointee.self, capacity: 1)
  }

  /// Return an allocated instance initialized with the resule of the given function.
  public static func initialized(with constructor: () -> Pointee) -> Self {
    let p = UnsafeMutableRawPointer.allocate(byteCount: MemoryLayout<Pointee>.size, alignment: MemoryLayout<Pointee>.alignment)
      .bindMemory(to: Pointee.self, capacity: 1)
    p.pointee = constructor()
    return UnsafeRawPointer(p).bindMemory(to: Pointee.self, capacity: 1)
  }
}
