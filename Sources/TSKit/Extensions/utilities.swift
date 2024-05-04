/*

  Created by David Spooner

*/



func throwingCast<Value>(_ any: Any, as _: Value.Type = Value.self) throws -> Value {
  guard let value = any as? Value
    else { throw TSError("failed to cast \(type(of: any)) to \(Value.self)") }
  return value
}
