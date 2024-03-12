#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 17
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 0
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_DASH = 1,
  anon_sym_PLUS = 2,
  anon_sym_STAR = 3,
  anon_sym_CARET = 4,
  anon_sym_LPAREN = 5,
  anon_sym_RPAREN = 6,
  sym_Name = 7,
  sym_Int = 8,
  sym_Expr = 9,
  sym_Expr_neg = 10,
  sym_Expr_add = 11,
  sym_Expr_name = 12,
  sym_Expr_numb = 13,
  sym_Expr_mul = 14,
  sym_Expr_pow = 15,
  sym_Expr_paren = 16,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_DASH] = "-",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_CARET] = "^",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_Name] = "Name",
  [sym_Int] = "Int",
  [sym_Expr] = "Expr",
  [sym_Expr_neg] = "Expr_neg",
  [sym_Expr_add] = "Expr_add",
  [sym_Expr_name] = "Expr_name",
  [sym_Expr_numb] = "Expr_numb",
  [sym_Expr_mul] = "Expr_mul",
  [sym_Expr_pow] = "Expr_pow",
  [sym_Expr_paren] = "Expr_paren",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_Name] = sym_Name,
  [sym_Int] = sym_Int,
  [sym_Expr] = sym_Expr,
  [sym_Expr_neg] = sym_Expr_neg,
  [sym_Expr_add] = sym_Expr_add,
  [sym_Expr_name] = sym_Expr_name,
  [sym_Expr_numb] = sym_Expr_numb,
  [sym_Expr_mul] = sym_Expr_mul,
  [sym_Expr_pow] = sym_Expr_pow,
  [sym_Expr_paren] = sym_Expr_paren,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
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
  [sym_Name] = {
    .visible = true,
    .named = true,
  },
  [sym_Int] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_neg] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_add] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_name] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_numb] = {
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
  [sym_Expr_paren] = {
    .visible = true,
    .named = true,
  },
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      if (lookahead == '(') ADVANCE(6);
      if (lookahead == ')') ADVANCE(7);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '+') ADVANCE(3);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == '^') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_Name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_Int);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_Name] = ACTIONS(1),
    [sym_Int] = ACTIONS(1),
  },
  [1] = {
    [sym_Expr] = STATE(15),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_numb] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
    [sym_Int] = ACTIONS(9),
  },
  [2] = {
    [sym_Expr] = STATE(10),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_numb] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
    [sym_Int] = ACTIONS(9),
  },
  [3] = {
    [sym_Expr] = STATE(16),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_numb] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
    [sym_Int] = ACTIONS(9),
  },
  [4] = {
    [sym_Expr] = STATE(12),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_numb] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
    [sym_Int] = ACTIONS(9),
  },
  [5] = {
    [sym_Expr] = STATE(13),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_numb] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
    [sym_Int] = ACTIONS(9),
  },
  [6] = {
    [sym_Expr] = STATE(14),
    [sym_Expr_neg] = STATE(9),
    [sym_Expr_add] = STATE(9),
    [sym_Expr_name] = STATE(9),
    [sym_Expr_numb] = STATE(9),
    [sym_Expr_mul] = STATE(9),
    [sym_Expr_pow] = STATE(9),
    [sym_Expr_paren] = STATE(9),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [sym_Name] = ACTIONS(7),
    [sym_Int] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(11), 5,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_RPAREN,
  [8] = 1,
    ACTIONS(13), 5,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_RPAREN,
  [16] = 1,
    ACTIONS(15), 5,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_RPAREN,
  [24] = 1,
    ACTIONS(17), 5,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_RPAREN,
  [32] = 1,
    ACTIONS(19), 5,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_CARET,
      anon_sym_RPAREN,
  [40] = 3,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_CARET,
    ACTIONS(21), 3,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [52] = 2,
    ACTIONS(25), 1,
      anon_sym_CARET,
    ACTIONS(27), 4,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_RPAREN,
  [62] = 2,
    ACTIONS(25), 1,
      anon_sym_CARET,
    ACTIONS(29), 4,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_RPAREN,
  [72] = 4,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_CARET,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      anon_sym_PLUS,
  [85] = 4,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_CARET,
    ACTIONS(33), 1,
      anon_sym_PLUS,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 8,
  [SMALL_STATE(9)] = 16,
  [SMALL_STATE(10)] = 24,
  [SMALL_STATE(11)] = 32,
  [SMALL_STATE(12)] = 40,
  [SMALL_STATE(13)] = 52,
  [SMALL_STATE(14)] = 62,
  [SMALL_STATE(15)] = 72,
  [SMALL_STATE(16)] = 85,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_name, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_numb, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_neg, 2),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_add, 3),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mul, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_pow, 3),
  [31] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_FunLang(void) {
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
