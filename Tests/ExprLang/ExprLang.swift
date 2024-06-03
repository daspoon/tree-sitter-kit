/*

  Created by David Spooner

*/

import TSKit
import TSLanguage


@Grammar
struct ExprLang : Grammar {
  typealias Root = Expr

  static var productionRules : [ProductionRule] {
    return [
      .init(Expr.self, choicesByName: [
        "name": .init(.sym(Name.self)) { name in .name(name) },
        "value": .init(.sym(Value.self)) { value in .value(value) },
        "add": .init(.prec(.left(1), .seq([.sym(Expr.self), .alt(["+", "-"]), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
        "mul": .init(.prec(.left(2), .seq([.sym(Expr.self), .alt(["*", "/"]), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
        "pow": .init(.prec(.right(3), .seq([.sym(Expr.self), .alt(["^"]), .sym(Expr.self)]))) { lhs, op, rhs in .op(op, [lhs, rhs]) },
        "neg": .init(.prec(.left(4), .seq([.alt(["-"]), .sym(Expr.self)]))) { op, arg in .op(op, [arg]) },
        "apply": .init(.prec(5, .seq([.sym(Expr.self), "(", .opt(.sym(ExprList.self)), ")"]))) { fun, args in .apply(fun, args ?? []) },
        "paren": .init(.seq(["(", .sym(Expr.self), ")"])) { expr in expr },
      ]),
      .init(ExprList.self, .rep(.sym(Expr.self), .sep(","))) { exprs in exprs },
      .init(Name.self, .pat("[a-zA-Z_][0-9a-zA-Z_]*")) { string in Name(text: string) },
      .init(Value.self, .sym(Int.self)) { i in .init(int: i) },
      .init(Int.self, .pat("[0-9]+")) { string in Int(string)! },
    ]
  }

  static var word : String? {
    "([a-zA-Z_][0-9a-zA-Z_]* | [!#%&*+-/<=>^|~]+)"
  }

  // MARK: -- BEGIN GENERATED --

  fileprivate static let ts_language_version = 14
  fileprivate static let ts_state_count = 29
  fileprivate static let ts_large_state_count = 9
  fileprivate static let ts_symbol_count = 27
  fileprivate static let ts_alias_count = 0
  fileprivate static let ts_token_count = 12
  fileprivate static let ts_external_token_count = 0
  fileprivate static let ts_field_count = 3
  fileprivate static let ts_max_alias_sequence_length : UInt16 = 4
  fileprivate static let ts_production_id_count : UInt32 = 8

  fileprivate static func ACTIONS(_ i: UInt16) -> UInt16 { i }
  fileprivate static func STATE(_ i: UInt16) -> UInt16 { i }

  fileprivate static let ts_builtin_sym_end : TSSymbol = 0
  fileprivate static let sym_Word : TSSymbol = 1
  fileprivate static let anon_sym_STAR : TSSymbol = 2
  fileprivate static let anon_sym_SLASH : TSSymbol = 3
  fileprivate static let anon_sym_CARET : TSSymbol = 4
  fileprivate static let anon_sym_DASH : TSSymbol = 5
  fileprivate static let anon_sym_LPAREN : TSSymbol = 6
  fileprivate static let anon_sym_RPAREN : TSSymbol = 7
  fileprivate static let anon_sym_PLUS : TSSymbol = 8
  fileprivate static let anon_sym_COMMA : TSSymbol = 9
  fileprivate static let aux_sym_Name_token1 : TSSymbol = 10
  fileprivate static let aux_sym_Int_token1 : TSSymbol = 11
  fileprivate static let sym_start : TSSymbol = 12
  fileprivate static let sym__Expr : TSSymbol = 13
  fileprivate static let sym_Expr_mul : TSSymbol = 14
  fileprivate static let sym_Expr_pow : TSSymbol = 15
  fileprivate static let sym_Expr_name : TSSymbol = 16
  fileprivate static let sym_Expr_neg : TSSymbol = 17
  fileprivate static let sym_Expr_apply : TSSymbol = 18
  fileprivate static let sym_Expr_value : TSSymbol = 19
  fileprivate static let sym_Expr_add : TSSymbol = 20
  fileprivate static let sym_Expr_paren : TSSymbol = 21
  fileprivate static let sym_ExprList : TSSymbol = 22
  fileprivate static let sym_Name : TSSymbol = 23
  fileprivate static let sym_Value : TSSymbol = 24
  fileprivate static let sym_Int : TSSymbol = 25
  fileprivate static let aux_sym_ExprList_repeat1 : TSSymbol = 26

  fileprivate static let field_0 : TSFieldId = 1
  fileprivate static let field_1 : TSFieldId = 2
  fileprivate static let field_2 : TSFieldId = 3

  fileprivate static let symbol_names_buffer : ContiguousArray<CChar> = [
    101, 110, 100, 0, // end
    87, 111, 114, 100, 0, // Word
    42, 0, // *
    47, 0, // /
    94, 0, // ^
    45, 0, // -
    40, 0, // (
    41, 0, // )
    43, 0, // +
    44, 0, // ,
    78, 97, 109, 101, 95, 116, 111, 107, 101, 110, 49, 0, // Name_token1
    73, 110, 116, 95, 116, 111, 107, 101, 110, 49, 0, // Int_token1
    115, 116, 97, 114, 116, 0, // start
    95, 69, 120, 112, 114, 0, // _Expr
    69, 120, 112, 114, 95, 109, 117, 108, 0, // Expr_mul
    69, 120, 112, 114, 95, 112, 111, 119, 0, // Expr_pow
    69, 120, 112, 114, 95, 110, 97, 109, 101, 0, // Expr_name
    69, 120, 112, 114, 95, 110, 101, 103, 0, // Expr_neg
    69, 120, 112, 114, 95, 97, 112, 112, 108, 121, 0, // Expr_apply
    69, 120, 112, 114, 95, 118, 97, 108, 117, 101, 0, // Expr_value
    69, 120, 112, 114, 95, 97, 100, 100, 0, // Expr_add
    69, 120, 112, 114, 95, 112, 97, 114, 101, 110, 0, // Expr_paren
    69, 120, 112, 114, 76, 105, 115, 116, 0, // ExprList
    78, 97, 109, 101, 0, // Name
    86, 97, 108, 117, 101, 0, // Value
    73, 110, 116, 0, // Int
    69, 120, 112, 114, 76, 105, 115, 116, 95, 114, 101, 112, 101, 97, 116, 49, 0, // ExprList_repeat1
  ]

  fileprivate static let symbol_names_buffer_ptr : UnsafePointer<CChar> = symbol_names_buffer.withUnsafeBufferPointer {$0.baseAddress!}

  fileprivate static let ts_symbol_names : ContiguousArray<UnsafePointer<CChar>?> = [
    symbol_names_buffer_ptr + 0,
    symbol_names_buffer_ptr + 4,
    symbol_names_buffer_ptr + 9,
    symbol_names_buffer_ptr + 11,
    symbol_names_buffer_ptr + 13,
    symbol_names_buffer_ptr + 15,
    symbol_names_buffer_ptr + 17,
    symbol_names_buffer_ptr + 19,
    symbol_names_buffer_ptr + 21,
    symbol_names_buffer_ptr + 23,
    symbol_names_buffer_ptr + 25,
    symbol_names_buffer_ptr + 37,
    symbol_names_buffer_ptr + 48,
    symbol_names_buffer_ptr + 54,
    symbol_names_buffer_ptr + 60,
    symbol_names_buffer_ptr + 69,
    symbol_names_buffer_ptr + 78,
    symbol_names_buffer_ptr + 88,
    symbol_names_buffer_ptr + 97,
    symbol_names_buffer_ptr + 108,
    symbol_names_buffer_ptr + 119,
    symbol_names_buffer_ptr + 128,
    symbol_names_buffer_ptr + 139,
    symbol_names_buffer_ptr + 148,
    symbol_names_buffer_ptr + 153,
    symbol_names_buffer_ptr + 159,
    symbol_names_buffer_ptr + 163,
  ]

  fileprivate static let ts_symbol_map : ContiguousArray<TSSymbol> = [
    ts_builtin_sym_end,
    sym_Word,
    anon_sym_STAR,
    anon_sym_SLASH,
    anon_sym_CARET,
    anon_sym_DASH,
    anon_sym_LPAREN,
    anon_sym_RPAREN,
    anon_sym_PLUS,
    anon_sym_COMMA,
    aux_sym_Name_token1,
    aux_sym_Int_token1,
    sym_start,
    sym__Expr,
    sym_Expr_mul,
    sym_Expr_pow,
    sym_Expr_name,
    sym_Expr_neg,
    sym_Expr_apply,
    sym_Expr_value,
    sym_Expr_add,
    sym_Expr_paren,
    sym_ExprList,
    sym_Name,
    sym_Value,
    sym_Int,
    aux_sym_ExprList_repeat1,
  ]

  fileprivate static let ts_symbol_metadata : ContiguousArray<TSSymbolMetadata> = [
    .init(visible: false, named: true), // ts_builtin_sym_end
    .init(visible: true, named: true), // sym_Word
    .init(visible: true, named: false), // anon_sym_STAR
    .init(visible: true, named: false), // anon_sym_SLASH
    .init(visible: true, named: false), // anon_sym_CARET
    .init(visible: true, named: false), // anon_sym_DASH
    .init(visible: true, named: false), // anon_sym_LPAREN
    .init(visible: true, named: false), // anon_sym_RPAREN
    .init(visible: true, named: false), // anon_sym_PLUS
    .init(visible: true, named: false), // anon_sym_COMMA
    .init(visible: false, named: false), // aux_sym_Name_token1
    .init(visible: false, named: false), // aux_sym_Int_token1
    .init(visible: true, named: true), // sym_start
    .init(visible: false, named: true), // sym__Expr
    .init(visible: true, named: true), // sym_Expr_mul
    .init(visible: true, named: true), // sym_Expr_pow
    .init(visible: true, named: true), // sym_Expr_name
    .init(visible: true, named: true), // sym_Expr_neg
    .init(visible: true, named: true), // sym_Expr_apply
    .init(visible: true, named: true), // sym_Expr_value
    .init(visible: true, named: true), // sym_Expr_add
    .init(visible: true, named: true), // sym_Expr_paren
    .init(visible: true, named: true), // sym_ExprList
    .init(visible: true, named: true), // sym_Name
    .init(visible: true, named: true), // sym_Value
    .init(visible: true, named: true), // sym_Int
    .init(visible: false, named: false), // aux_sym_ExprList_repeat1
  ]

  fileprivate static let field_names_buffer : ContiguousArray<CChar> = [
    48, 0, // 0
    49, 0, // 1
    50, 0, // 2
  ]

  fileprivate static let field_names_buffer_ptr : UnsafePointer<CChar> = field_names_buffer.withUnsafeBufferPointer {$0.baseAddress!}

  fileprivate static let ts_field_names : ContiguousArray<UnsafePointer<CChar>?> = [
    nil,
    symbol_names_buffer_ptr + 0,
    symbol_names_buffer_ptr + 2,
    symbol_names_buffer_ptr + 4,
  ]

  fileprivate static let ts_field_map_slices : ContiguousArray<TSFieldMapSlice> = [
    .init(),
    .init(index: 0, length: 1),
    .init(index: 1, length: 2),
    .init(index: 3, length: 1),
    .init(index: 4, length: 3),
    .init(index: 7, length: 2),
    .init(index: 9, length: 2),
    .init(index: 11, length: 2),
  ]

  fileprivate static let ts_field_map_entries : ContiguousArray<TSFieldMapEntry> = [
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_1, child_index: 1),
    .init(field_id: field_0, child_index: 1),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_1, child_index: 1),
    .init(field_id: field_2, child_index: 2),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_0, child_index: 1, inherited: true),
    .init(field_id: field_0, child_index: 0),
    .init(field_id: field_1, child_index: 2),
    .init(field_id: field_0, child_index: 0, inherited: true),
    .init(field_id: field_0, child_index: 1, inherited: true),
  ]

  fileprivate static let ts_alias_sequences : ContiguousArray<TSSymbol>
    = .init(repeating: 0, count: Int(ts_production_id_count) * Int(ts_max_alias_sequence_length))

  fileprivate static let ts_non_terminal_alias_map : ContiguousArray<UInt16> = [
    0
  ]

  fileprivate static let ts_primary_state_ids : ContiguousArray<TSStateId> = [
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
  ]

  fileprivate static func ts_lex(_ lexer: UnsafeMutablePointer<TSLexer>?, _ state: TSStateId) -> Bool {
    let lexer = UnsafeMutableRawPointer(mutating: lexer!).bindMemory(to: TSLexer.self, capacity: 1)
    var state = state
    var result = false
    var skip = false
    var eof = false
    var lookahead : Int32 = 0

    func ADVANCE(_ next_state: TSStateId) { state = next_state }
    func SKIP(_ next_state: TSStateId) { state = next_state; skip = true }
    func ACCEPT_TOKEN(_ symbol: TSSymbol) {
      result = true
      lexer.pointee.result_symbol = symbol
      lexer.pointee.mark_end(lexer)
    }

    while true {
      skip = false
      lookahead = lexer.pointee.lookahead
      eof = lexer.pointee.eof(lexer)
      switch state {
      case 0:
        if eof { ADVANCE(4); break }
        if lookahead == 32 { ADVANCE(2); break }
        if lookahead == 40 { ADVANCE(13); break }
        if lookahead == 41 { ADVANCE(14); break }
        if lookahead == 42 { ADVANCE(5); break }
        if lookahead == 43 { ADVANCE(15); break }
        if lookahead == 44 { ADVANCE(17); break }
        if lookahead == 45 { ADVANCE(11); break }
        if lookahead == 47 { ADVANCE(7); break }
        if lookahead == 94 { ADVANCE(9); break }
        if (lookahead == 9 ||
            lookahead == 10 ||
            lookahead == 13) { SKIP(0); break }
        if (48 <= lookahead && lookahead <= 57) { ADVANCE(21); break }
        if ((65 <= lookahead && lookahead <= 90) ||
            lookahead == 95 ||
            (97 <= lookahead && lookahead <= 122)) { ADVANCE(19); break }
        return result
      case 1:
        if (lookahead == 32) { ADVANCE(2); break }
        if (lookahead == 40) { ADVANCE(13); break }
        if (lookahead == 41) { ADVANCE(14); break }
        if (lookahead == 42) { ADVANCE(5); break }
        if (lookahead == 43) { ADVANCE(15); break }
        if (lookahead == 44) { ADVANCE(17); break }
        if (lookahead == 45) { ADVANCE(11); break }
        if (lookahead == 47) { ADVANCE(7); break }
        if (lookahead == 94) { ADVANCE(9); break }
        if (lookahead == 9 ||
            lookahead == 10 ||
            lookahead == 13) { SKIP(1); break }
        if (48 <= lookahead && lookahead <= 57) { ADVANCE(21); break }
        if ((65 <= lookahead && lookahead <= 90) ||
            lookahead == 95 ||
            (97 <= lookahead && lookahead <= 122)) { ADVANCE(19); break }
        return result
      case 2:
        if (lookahead == 32) { ADVANCE(2); break }
        if (lookahead == 40) { ADVANCE(13); break }
        if (lookahead == 41) { ADVANCE(14); break }
        if (lookahead == 42) { ADVANCE(6); break }
        if (lookahead == 43) { ADVANCE(16); break }
        if (lookahead == 44) { ADVANCE(18); break }
        if (lookahead == 45) { ADVANCE(12); break }
        if (lookahead == 47) { ADVANCE(8); break }
        if (lookahead == 94) { ADVANCE(10); break }
        if (lookahead == 9 ||
            lookahead == 10 ||
            lookahead == 13) { SKIP(1); break }
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            lookahead == 46 ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        if (48 <= lookahead && lookahead <= 57) { ADVANCE(21); break }
        if ((65 <= lookahead && lookahead <= 90) ||
            lookahead == 95 ||
            (97 <= lookahead && lookahead <= 122)) { ADVANCE(19); break }
        return result
      case 3:
        if eof { ADVANCE(4); break }
        if (lookahead == 40) { ADVANCE(13); break }
        if (lookahead == 41) { ADVANCE(14); break }
        if (lookahead == 41) { ADVANCE(5); break }
        if (lookahead == 42) { ADVANCE(15); break }
        if (lookahead == 43) { ADVANCE(17); break }
        if (lookahead == 45) { ADVANCE(11); break }
        if (lookahead == 47) { ADVANCE(7); break }
        if (lookahead == 94) { ADVANCE(9); break }
        if (lookahead == 9 ||
            lookahead == 10 ||
            lookahead == 13 ||
            lookahead == 32) { SKIP(3); break }
        if (48 <= lookahead && lookahead <= 57) { ADVANCE(21); break }
        if ((65 <= lookahead && lookahead <= 90) ||
            lookahead == 95 ||
            (97 <= lookahead && lookahead <= 122)) { ADVANCE(20); break }
        return result
      case 4:
        ACCEPT_TOKEN(ts_builtin_sym_end)
        return result
      case 5:
        ACCEPT_TOKEN(anon_sym_STAR)
        return result
      case 6:
        ACCEPT_TOKEN(anon_sym_STAR)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      case 7:
        ACCEPT_TOKEN(anon_sym_SLASH)
        return result
      case 8:
        ACCEPT_TOKEN(anon_sym_SLASH)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      case 9:
        ACCEPT_TOKEN(anon_sym_CARET)
        return result
      case 10:
        ACCEPT_TOKEN(anon_sym_CARET)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      case 11:
        ACCEPT_TOKEN(anon_sym_DASH)
        return result
      case 12:
        ACCEPT_TOKEN(anon_sym_DASH)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      case 13:
        ACCEPT_TOKEN(anon_sym_LPAREN)
        return result
      case 14:
        ACCEPT_TOKEN(anon_sym_RPAREN)
        return result
      case 15:
        ACCEPT_TOKEN(anon_sym_PLUS)
        return result
      case 16:
        ACCEPT_TOKEN(anon_sym_PLUS)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      case 17:
        ACCEPT_TOKEN(anon_sym_COMMA)
        return result
      case 18:
        ACCEPT_TOKEN(anon_sym_COMMA)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      case 19:
        ACCEPT_TOKEN(aux_sym_Name_token1)
        if (lookahead == 32) { state = 22; break }
        if ((48 <= lookahead && lookahead <= 57) ||
            (65 <= lookahead && lookahead <= 90) ||
            lookahead == 95 ||
            (97 <= lookahead && lookahead <= 122)) { ADVANCE(19); break }
        return result
      case 20:
        ACCEPT_TOKEN(aux_sym_Name_token1)
        if ((48 <= lookahead && lookahead <= 57) ||
            (65 <= lookahead && lookahead <= 90) ||
            lookahead == 95 ||
            (97 <= lookahead && lookahead <= 122)) { ADVANCE(20); break }
        return result
      case 21:
        ACCEPT_TOKEN(aux_sym_Int_token1)
        if ((58 <= lookahead && lookahead <= 57)) { ADVANCE(21); break }
        return result
      case 22:
        ACCEPT_TOKEN(sym_Word)
        return result
      case 23:
        ACCEPT_TOKEN(sym_Word)
        if (lookahead == 33 ||
            lookahead == 35 ||
            lookahead == 37 ||
            lookahead == 38 ||
            (42 <= lookahead && lookahead <= 47) ||
            (60 <= lookahead && lookahead <= 62) ||
            lookahead == 94 ||
            lookahead == 124 ||
            lookahead == 126) { ADVANCE(23); break }
        return result
      default:
        return false
      }
      // next_state:
      lexer.pointee.advance(lexer, skip)
    }
  }

  fileprivate static func ts_lex_keywords(_ lexer: UnsafePointer<TSLexer>?, _ state: TSStateId) -> Bool {
    let lexer = UnsafeMutableRawPointer(mutating: lexer!).bindMemory(to: TSLexer.self, capacity: 1)
    var state = state
    var result = false
    var skip = false
    var eof = false
    var lookahead : Int32 = 0

    func ADVANCE(_ next_state: TSStateId) { state = next_state }
    func SKIP(_ next_state: TSStateId) { state = next_state; skip = true }
    func ACCEPT_TOKEN(_ symbol: TSSymbol) {
      result = true
      lexer.pointee.result_symbol = symbol
      lexer.pointee.mark_end(lexer)
    }

    while true {
      // start"
      skip = false
      lookahead = lexer.pointee.lookahead
      eof = lexer.pointee.eof(lexer)
      switch state {
      case 0:
        ACCEPT_TOKEN(ts_builtin_sym_end)
        return result;
      default:
        return false
      }
      // next_state:
      lexer.pointee.advance(lexer, skip)
    }
  }

  fileprivate static let ts_lex_modes : ContiguousArray<TSLexMode> = [
    .init(lex_state: 0),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 3),
    .init(lex_state: 0),
    .init(lex_state: 0),
  ]

  fileprivate static let ts_parse_table : ContiguousArray<UInt16> = [
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,  27,  24,  24,  24,  24,  24,  24,  24,  24,  24,   0,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,  11,   0,   0,   7,   9,   0,  19,  19,  19,  19,  19,  19,  19,  19,  19,  28,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,   0,  16,  16,  16,  16,  16,  16,  16,  16,  16,   0,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,   0,  12,  12,  12,  12,  12,  12,  12,  12,  12,   0,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,   0,  23,  23,  23,  23,  23,  23,  23,  23,  23,   0,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,   0,  22,  22,  22,  22,  22,  22,  22,  22,  22,   0,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,   0,  18,  18,  18,  18,  18,  18,  18,  18,  18,   0,  14,  10,  11,   0, 
    0,   0,   0,   0,   0,   3,   5,   0,   0,   0,   7,   9,   0,  17,  17,  17,  17,  17,  17,  17,  17,  17,   0,  14,  10,  11,   0, 
  ]

  fileprivate static let ts_small_parse_table : ContiguousArray<UInt16> = [
    1, // 0
    ACTIONS(13), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    1, // 12
    ACTIONS(15), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    1, // 24
    ACTIONS(17), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    2, // 36
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 8,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    1, // 50
    ACTIONS(23), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    1, // 62
    ACTIONS(25), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    1, // 74
    ACTIONS(27), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    3, // 86
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(29), 7,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    2, // 102
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(33), 8,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    4, // 116
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(37), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(35), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    7, // 134
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(41), 1,
      anon_sym_RPAREN,
    ACTIONS(43), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_ExprList_repeat1,
    ACTIONS(37), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    1, // 158
    ACTIONS(45), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    1, // 170
    ACTIONS(47), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_COMMA,
    5, // 182
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(37), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(49), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    5, // 201
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    ACTIONS(37), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    5, // 219
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    ACTIONS(37), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    3, // 237
    ACTIONS(43), 1,
      anon_sym_COMMA,
    ACTIONS(55), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      aux_sym_ExprList_repeat1,
    3, // 247
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    STATE(26), 1,
      aux_sym_ExprList_repeat1,
    1, // 257
    ACTIONS(62), 1,
      ts_builtin_sym_end,
    1, // 261
    ACTIONS(64), 1,
      anon_sym_RPAREN,
  ]

  fileprivate static let ts_small_parse_table_map : ContiguousArray<UInt32> = [
    0,
    12,
    24,
    36,
    50,
    62,
    74,
    86,
    102,
    116,
    134,
    158,
    170,
    182,
    201,
    219,
    237,
    247,
    257,
    261,
  ]

  fileprivate static let ts_parse_actions : ContiguousArray<TSParseActionEntry> = [
    .entry(count: 0, reusable: false),
    .entry(count: 1, reusable: false), .recover,
    .entry(count: 1, reusable: true), .shift(4),
    .entry(count: 1, reusable: true), .shift(5),
    .entry(count: 1, reusable: true), .shift(13),
    .entry(count: 1, reusable: true), .shift(20),
    .entry(count: 1, reusable: true), .shift(9),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_apply, 3, production_id: 1),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_value, 1, production_id: 1),
    .entry(count: 1, reusable: true), .reduce(sym_Value, 1, production_id: 1),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_neg, 2, production_id: 2),
    .entry(count: 1, reusable: true), .shift(2),
    .entry(count: 1, reusable: true), .reduce(sym_Name, 1, production_id: 1),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_name, 1, production_id: 1),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_paren, 3, production_id: 3),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_mul, 3, production_id: 4),
    .entry(count: 1, reusable: true), .shift(8),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_pow, 3, production_id: 4),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_add, 3, production_id: 4),
    .entry(count: 1, reusable: true), .shift(3),
    .entry(count: 1, reusable: true), .shift(7),
    .entry(count: 1, reusable: true), .reduce(sym_ExprList, 1, production_id: 1),
    .entry(count: 1, reusable: true), .shift(6),
    .entry(count: 1, reusable: true), .reduce(sym_Int, 1, production_id: 1),
    .entry(count: 1, reusable: true), .reduce(sym_Expr_apply, 4, production_id: 6),
    .entry(count: 1, reusable: true), .reduce(aux_sym_ExprList_repeat1, 2, production_id: 3),
    .entry(count: 1, reusable: true), .shift(15),
    .entry(count: 1, reusable: true), .reduce(sym_start, 1),
    .entry(count: 1, reusable: true), .reduce(sym_ExprList, 2, production_id: 5),
    .entry(count: 1, reusable: true), .reduce(aux_sym_ExprList_repeat1, 2, production_id: 7),
    .entry(count: 2, reusable: true), .reduce(aux_sym_ExprList_repeat1, 2, production_id: 7), .shift(6, repeat: true),
    .entry(count: 1, reusable: true), .accept,
    .entry(count: 1, reusable: true), .shift(21),
  ]

  static let language : UnsafePointer<TSLanguage> = {
    let rp = UnsafeMutableRawPointer.allocate(byteCount: MemoryLayout<TSLanguage>.size, alignment: MemoryLayout<TSLanguage>.alignment)
    // note: all fields are assigned except 'external_scanner', which has no type annotation...
    _ = rp.initializeMemory(as: UInt8.self, repeating: 0, count: MemoryLayout<TSLanguage>.size)
    let p = rp.bindMemory(to: TSLanguage.self, capacity: 1)
    p.pointee.version = 14
    p.pointee.symbol_count = 27
    p.pointee.alias_count = 0
    p.pointee.token_count = 12
    p.pointee.external_token_count = 0
    p.pointee.state_count = 29
    p.pointee.large_state_count = 9
    p.pointee.production_id_count = 8
    p.pointee.field_count = 3
    p.pointee.max_alias_sequence_length = 4
    p.pointee.parse_table = ts_parse_table.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.small_parse_table = ts_small_parse_table.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.small_parse_table_map = ts_small_parse_table_map.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.parse_actions = ts_parse_actions.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.symbol_names = ts_symbol_names.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.field_names = ts_field_names.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.field_map_slices = ts_field_map_slices.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.field_map_entries = ts_field_map_entries.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.symbol_metadata = ts_symbol_metadata.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.public_symbol_map = ts_symbol_map.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.alias_map = ts_non_terminal_alias_map.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.alias_sequences = ts_alias_sequences.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.lex_modes = ts_lex_modes.withUnsafeBufferPointer {$0.baseAddress}
    p.pointee.lex_fn = {ts_lex($0,$1)}
    p.pointee.keyword_lex_fn = {ts_lex_keywords($0,$1)}
    p.pointee.keyword_capture_token = sym_Word
    p.pointee.primary_state_ids = ts_primary_state_ids.withUnsafeBufferPointer {$0.baseAddress}
    return UnsafeRawPointer(p).bindMemory(to: TSLanguage.self, capacity: 1)
  }()

  // MARK: -- END GENERATED --

}


// MARK: -

indirect enum Expr : Equatable {
  case name(Name)
  case value(Value)
  case apply(Expr, [Expr])
  static func op(_ name: String, _ args: [Expr]) -> Self {
    .apply(.name(Name(text: name)), args)
  }
}

extension Expr : ExpressibleByStringLiteral {
  init(stringLiteral text: String) {
    self = .name(Name(text: text))
  }
}

typealias ExprList = Array<Expr>


// MARK: -

struct Name : Equatable {
  let text : String
}

extension Name : ExpressibleByStringLiteral {
  init(stringLiteral s: String) {
    self.init(text: s)
  }
}

// MARK: -

struct Value : Equatable {
  let int : Int
}

extension Value : ExpressibleByIntegerLiteral {
  init(integerLiteral i: Int) {
    self.init(int: i)
  }
}
