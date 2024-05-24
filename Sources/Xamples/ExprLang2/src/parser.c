#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 29
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 27
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 8

enum {
  sym_Word = 1,
  anon_sym_STAR = 2,
  anon_sym_SLASH = 3,
  anon_sym_PLUS = 4,
  anon_sym_DASH = 5,
  anon_sym_CARET = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  anon_sym_COMMA = 9,
  aux_sym_Name_token1 = 10,
  aux_sym_Int_token1 = 11,
  sym_start = 12,
  sym__Expr = 13,
  sym_Expr_mul = 14,
  sym_Expr_value = 15,
  sym_Expr_add = 16,
  sym_Expr_pow = 17,
  sym_Expr_paren = 18,
  sym_Expr_neg = 19,
  sym_Expr_name = 20,
  sym_Expr_apply = 21,
  sym_ExprList = 22,
  sym_Name = 23,
  sym_Value = 24,
  sym_Int = 25,
  aux_sym_ExprList_repeat1 = 26,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_Word] = "Word",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_CARET] = "^",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COMMA] = ",",
  [aux_sym_Name_token1] = "Name_token1",
  [aux_sym_Int_token1] = "Int_token1",
  [sym_start] = "start",
  [sym__Expr] = "_Expr",
  [sym_Expr_mul] = "Expr_mul",
  [sym_Expr_value] = "Expr_value",
  [sym_Expr_add] = "Expr_add",
  [sym_Expr_pow] = "Expr_pow",
  [sym_Expr_paren] = "Expr_paren",
  [sym_Expr_neg] = "Expr_neg",
  [sym_Expr_name] = "Expr_name",
  [sym_Expr_apply] = "Expr_apply",
  [sym_ExprList] = "ExprList",
  [sym_Name] = "Name",
  [sym_Value] = "Value",
  [sym_Int] = "Int",
  [aux_sym_ExprList_repeat1] = "ExprList_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_Word] = sym_Word,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [aux_sym_Name_token1] = aux_sym_Name_token1,
  [aux_sym_Int_token1] = aux_sym_Int_token1,
  [sym_start] = sym_start,
  [sym__Expr] = sym__Expr,
  [sym_Expr_mul] = sym_Expr_mul,
  [sym_Expr_value] = sym_Expr_value,
  [sym_Expr_add] = sym_Expr_add,
  [sym_Expr_pow] = sym_Expr_pow,
  [sym_Expr_paren] = sym_Expr_paren,
  [sym_Expr_neg] = sym_Expr_neg,
  [sym_Expr_name] = sym_Expr_name,
  [sym_Expr_apply] = sym_Expr_apply,
  [sym_ExprList] = sym_ExprList,
  [sym_Name] = sym_Name,
  [sym_Value] = sym_Value,
  [sym_Int] = sym_Int,
  [aux_sym_ExprList_repeat1] = aux_sym_ExprList_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_Word] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
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
  [aux_sym_Name_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_Int_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_start] = {
    .visible = true,
    .named = true,
  },
  [sym__Expr] = {
    .visible = false,
    .named = true,
  },
  [sym_Expr_mul] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_value] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_add] = {
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
  [sym_Expr_neg] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_name] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_apply] = {
    .visible = true,
    .named = true,
  },
  [sym_ExprList] = {
    .visible = true,
    .named = true,
  },
  [sym_Name] = {
    .visible = true,
    .named = true,
  },
  [sym_Value] = {
    .visible = true,
    .named = true,
  },
  [sym_Int] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_ExprList_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_0 = 1,
  field_1 = 2,
  field_2 = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_0] = "0",
  [field_1] = "1",
  [field_2] = "2",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 3},
  [5] = {.index = 7, .length = 2},
  [6] = {.index = 9, .length = 2},
  [7] = {.index = 11, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_0, 0},
  [1] =
    {field_0, 0},
    {field_1, 1},
  [3] =
    {field_0, 1},
  [4] =
    {field_0, 0},
    {field_1, 1},
    {field_2, 2},
  [7] =
    {field_0, 0},
    {field_0, 1, .inherited = true},
  [9] =
    {field_0, 0},
    {field_1, 2},
  [11] =
    {field_0, 0, .inherited = true},
    {field_0, 1, .inherited = true},
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
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '+') ADVANCE(9);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(11);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '^') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '+') ADVANCE(9);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(11);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '^') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '+') ADVANCE(10);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(12);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '^') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          lookahead == '.' ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 3:
      if (eof) ADVANCE(4);
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '+') ADVANCE(9);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(11);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '^') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_Int_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_Word);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(23);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 3},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 3},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_Word] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [aux_sym_Name_token1] = ACTIONS(1),
    [aux_sym_Int_token1] = ACTIONS(1),
  },
  [1] = {
    [sym_start] = STATE(27),
    [sym__Expr] = STATE(24),
    [sym_Expr_mul] = STATE(24),
    [sym_Expr_value] = STATE(24),
    [sym_Expr_add] = STATE(24),
    [sym_Expr_pow] = STATE(24),
    [sym_Expr_paren] = STATE(24),
    [sym_Expr_neg] = STATE(24),
    [sym_Expr_name] = STATE(24),
    [sym_Expr_apply] = STATE(24),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [2] = {
    [sym__Expr] = STATE(19),
    [sym_Expr_mul] = STATE(19),
    [sym_Expr_value] = STATE(19),
    [sym_Expr_add] = STATE(19),
    [sym_Expr_pow] = STATE(19),
    [sym_Expr_paren] = STATE(19),
    [sym_Expr_neg] = STATE(19),
    [sym_Expr_name] = STATE(19),
    [sym_Expr_apply] = STATE(19),
    [sym_ExprList] = STATE(28),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_RPAREN] = ACTIONS(11),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [3] = {
    [sym__Expr] = STATE(16),
    [sym_Expr_mul] = STATE(16),
    [sym_Expr_value] = STATE(16),
    [sym_Expr_add] = STATE(16),
    [sym_Expr_pow] = STATE(16),
    [sym_Expr_paren] = STATE(16),
    [sym_Expr_neg] = STATE(16),
    [sym_Expr_name] = STATE(16),
    [sym_Expr_apply] = STATE(16),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [4] = {
    [sym__Expr] = STATE(12),
    [sym_Expr_mul] = STATE(12),
    [sym_Expr_value] = STATE(12),
    [sym_Expr_add] = STATE(12),
    [sym_Expr_pow] = STATE(12),
    [sym_Expr_paren] = STATE(12),
    [sym_Expr_neg] = STATE(12),
    [sym_Expr_name] = STATE(12),
    [sym_Expr_apply] = STATE(12),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [5] = {
    [sym__Expr] = STATE(23),
    [sym_Expr_mul] = STATE(23),
    [sym_Expr_value] = STATE(23),
    [sym_Expr_add] = STATE(23),
    [sym_Expr_pow] = STATE(23),
    [sym_Expr_paren] = STATE(23),
    [sym_Expr_neg] = STATE(23),
    [sym_Expr_name] = STATE(23),
    [sym_Expr_apply] = STATE(23),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [6] = {
    [sym__Expr] = STATE(22),
    [sym_Expr_mul] = STATE(22),
    [sym_Expr_value] = STATE(22),
    [sym_Expr_add] = STATE(22),
    [sym_Expr_pow] = STATE(22),
    [sym_Expr_paren] = STATE(22),
    [sym_Expr_neg] = STATE(22),
    [sym_Expr_name] = STATE(22),
    [sym_Expr_apply] = STATE(22),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [7] = {
    [sym__Expr] = STATE(18),
    [sym_Expr_mul] = STATE(18),
    [sym_Expr_value] = STATE(18),
    [sym_Expr_add] = STATE(18),
    [sym_Expr_pow] = STATE(18),
    [sym_Expr_paren] = STATE(18),
    [sym_Expr_neg] = STATE(18),
    [sym_Expr_name] = STATE(18),
    [sym_Expr_apply] = STATE(18),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
  [8] = {
    [sym__Expr] = STATE(17),
    [sym_Expr_mul] = STATE(17),
    [sym_Expr_value] = STATE(17),
    [sym_Expr_add] = STATE(17),
    [sym_Expr_pow] = STATE(17),
    [sym_Expr_paren] = STATE(17),
    [sym_Expr_neg] = STATE(17),
    [sym_Expr_name] = STATE(17),
    [sym_Expr_apply] = STATE(17),
    [sym_Name] = STATE(14),
    [sym_Value] = STATE(10),
    [sym_Int] = STATE(11),
    [anon_sym_DASH] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [aux_sym_Name_token1] = ACTIONS(7),
    [aux_sym_Int_token1] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(13), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [12] = 1,
    ACTIONS(15), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [24] = 1,
    ACTIONS(17), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [36] = 2,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 8,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [50] = 1,
    ACTIONS(23), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [62] = 1,
    ACTIONS(25), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [74] = 1,
    ACTIONS(27), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [86] = 3,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(29), 7,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [102] = 4,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(35), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(33), 5,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [120] = 2,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(37), 8,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [134] = 7,
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
    ACTIONS(35), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [158] = 1,
    ACTIONS(45), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [170] = 1,
    ACTIONS(47), 9,
      ts_builtin_sym_end,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [182] = 5,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(35), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(49), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [201] = 5,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    ACTIONS(35), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [219] = 5,
    ACTIONS(21), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_CARET,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(39), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [237] = 3,
    ACTIONS(43), 1,
      anon_sym_COMMA,
    ACTIONS(55), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      aux_sym_ExprList_repeat1,
  [247] = 3,
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    ACTIONS(59), 1,
      anon_sym_COMMA,
    STATE(26), 1,
      aux_sym_ExprList_repeat1,
  [257] = 1,
    ACTIONS(62), 1,
      ts_builtin_sym_end,
  [261] = 1,
    ACTIONS(64), 1,
      anon_sym_RPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 12,
  [SMALL_STATE(11)] = 24,
  [SMALL_STATE(12)] = 36,
  [SMALL_STATE(13)] = 50,
  [SMALL_STATE(14)] = 62,
  [SMALL_STATE(15)] = 74,
  [SMALL_STATE(16)] = 86,
  [SMALL_STATE(17)] = 102,
  [SMALL_STATE(18)] = 120,
  [SMALL_STATE(19)] = 134,
  [SMALL_STATE(20)] = 158,
  [SMALL_STATE(21)] = 170,
  [SMALL_STATE(22)] = 182,
  [SMALL_STATE(23)] = 201,
  [SMALL_STATE(24)] = 219,
  [SMALL_STATE(25)] = 237,
  [SMALL_STATE(26)] = 247,
  [SMALL_STATE(27)] = 257,
  [SMALL_STATE(28)] = 261,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_apply, 3, .production_id = 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_value, 1, .production_id = 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Value, 1, .production_id = 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_neg, 2, .production_id = 2),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Name, 1, .production_id = 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_name, 1, .production_id = 1),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 3, .production_id = 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mul, 3, .production_id = 4),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_add, 3, .production_id = 4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_pow, 3, .production_id = 4),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 1, .production_id = 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Int, 1, .production_id = 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_apply, 4, .production_id = 6),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 3),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 2, .production_id = 5),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 7),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 7), SHIFT_REPEAT(6),
  [62] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
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
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_Word,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
