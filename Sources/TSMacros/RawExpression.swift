/*

*/


/// Corresponds to the structure of rules in tree-sitter's grammar.json.
indirect enum RawExpression {
  case blank
  case string(String)
  case pattern(String)
  case symbol(String)
  case seq([RawExpression])
  case choice([RawExpression])
  case field(String, RawExpression)
  case prec(Precedence, RawExpression)
  case `repeat`(RawExpression)

  static var whitespace : Self {
    .pattern("\\\\s")
  }

  var json : String {
    switch self {
      case .blank : """
        {"type": "BLANK"}
        """
      case .string(let value) : """
        {"type": "STRING", "value": "\(value)"}
        """
      case .pattern(let value) : """
        {"type": "PATTERN", "value": "\(value)"}
        """
      case .symbol(let name) : """
        {"type": "SYMBOL", "name": "\(name)"}
        """
      case .choice(let members) : """
        {"type": "CHOICE", "members": [\(members.map(\.json).joined(separator: ", "))]}
        """
      case .seq(let members) : """
        {"type": "SEQ", "members": [\(members.map(\.json).joined(separator: ", "))]}
        """
      case .prec(let prec, let content) : """
        {"type": "\(prec.jsonType)", "value": \(prec.jsonValue), "content": \(content.json)}
        """
      case .field(let name, let content) : """
        {"type": "FIELD", "name": "\(name)", "content": \(content.json)}
        """
      case .repeat(let content) : """
        {"type": "REPEAT", "content": \(content.json)}
        """
    }
  }
}
