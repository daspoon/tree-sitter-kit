#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 25
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 20
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  anon_sym_PLUS = 1,
  anon_sym_DASH = 2,
  anon_sym_STAR = 3,
  anon_sym_SLASH = 4,
  anon_sym_CARET = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  anon_sym_COMMA = 8,
  sym_Name = 9,
  sym_Expr = 10,
  sym_Expr_name = 11,
  sym_Expr_add = 12,
  sym_Expr_mul = 13,
  sym_Expr_pow = 14,
  sym_Expr_neg = 15,
  sym_Expr_apply = 16,
  sym_Expr_paren = 17,
  sym_ExprList = 18,
  aux_sym_ExprList_repeat1 = 19,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_CARET] = "^",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COMMA] = ",",
  [sym_Name] = "Name",
  [sym_Expr] = "Expr",
  [sym_Expr_name] = "Expr_name",
  [sym_Expr_add] = "Expr_add",
  [sym_Expr_mul] = "Expr_mul",
  [sym_Expr_pow] = "Expr_pow",
  [sym_Expr_neg] = "Expr_neg",
  [sym_Expr_apply] = "Expr_apply",
  [sym_Expr_paren] = "Expr_paren",
  [sym_ExprList] = "ExprList",
  [aux_sym_ExprList_repeat1] = "ExprList_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_Name] = sym_Name,
  [sym_Expr] = sym_Expr,
  [sym_Expr_name] = sym_Expr_name,
  [sym_Expr_add] = sym_Expr_add,
  [sym_Expr_mul] = sym_Expr_mul,
  [sym_Expr_pow] = sym_Expr_pow,
  [sym_Expr_neg] = sym_Expr_neg,
  [sym_Expr_apply] = sym_Expr_apply,
  [sym_Expr_paren] = sym_Expr_paren,
  [sym_ExprList] = sym_ExprList,
  [aux_sym_ExprList_repeat1] = aux_sym_ExprList_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_Name] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_name] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_add] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_mul] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_pow] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_neg] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_apply] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_paren] = {
    .visible = true,
    .named = true,
  },
  [sym_ExprList] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_ExprList_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_args = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_args] = "args",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_args, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      if (lookahead == '(') ADVANCE(7);
      if (lookahead == ')') ADVANCE(8);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '+') ADVANCE(2);
      if (lookahead == ',') ADVANCE(9);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '^') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_Name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_Name] = ACTIONS(1),
  },
  [1] = {
    [sym_Expr] = STATE(21),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
  [2] = {
    [sym_Expr] = STATE(17),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [sym_ExprList] = STATE(24),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_RPAREN] = ACTIONS(9),
    [sym_Name] = ACTIONS(7),
  },
  [3] = {
    [sym_Expr] = STATE(13),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
  [4] = {
    [sym_Expr] = STATE(10),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
  [5] = {
    [sym_Expr] = STATE(20),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
  [6] = {
    [sym_Expr] = STATE(19),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
  [7] = {
    [sym_Expr] = STATE(14),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
  [8] = {
    [sym_Expr] = STATE(15),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_apply] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(11), 9,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [12] = 1,
    ACTIONS(13), 9,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [24] = 1,
    ACTIONS(15), 9,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [36] = 1,
    ACTIONS(17), 9,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [48] = 3,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(21), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(19), 6,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [64] = 2,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(25), 8,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [78] = 2,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(27), 8,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [92] = 1,
    ACTIONS(29), 9,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [104] = 7,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    ACTIONS(37), 1,
      anon_sym_COMMA,
    STATE(22), 1,
      aux_sym_ExprList_repeat1,
    ACTIONS(21), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(31), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [128] = 1,
    ACTIONS(39), 9,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [140] = 5,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(31), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(41), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [159] = 5,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    ACTIONS(21), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(31), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [177] = 5,
    ACTIONS(23), 1,
      anon_sym_CARET,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(31), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [195] = 3,
    ACTIONS(37), 1,
      anon_sym_COMMA,
    ACTIONS(47), 1,
      anon_sym_RPAREN,
    STATE(23), 1,
      aux_sym_ExprList_repeat1,
  [205] = 3,
    ACTIONS(41), 1,
      anon_sym_RPAREN,
    ACTIONS(49), 1,
      anon_sym_COMMA,
    STATE(23), 1,
      aux_sym_ExprList_repeat1,
  [215] = 1,
    ACTIONS(52), 1,
      anon_sym_RPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 12,
  [SMALL_STATE(11)] = 24,
  [SMALL_STATE(12)] = 36,
  [SMALL_STATE(13)] = 48,
  [SMALL_STATE(14)] = 64,
  [SMALL_STATE(15)] = 78,
  [SMALL_STATE(16)] = 92,
  [SMALL_STATE(17)] = 104,
  [SMALL_STATE(18)] = 128,
  [SMALL_STATE(19)] = 140,
  [SMALL_STATE(20)] = 159,
  [SMALL_STATE(21)] = 177,
  [SMALL_STATE(22)] = 195,
  [SMALL_STATE(23)] = 205,
  [SMALL_STATE(24)] = 215,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_neg, 2),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_name, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 3),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_add, 3),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mul, 3),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_pow, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_apply, 3),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_apply, 4, .production_id = 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [45] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2), SHIFT_REPEAT(6),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ExprLang(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
