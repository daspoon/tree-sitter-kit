#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 144
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 80
#define ALIAS_COUNT 0
#define TOKEN_COUNT 30
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 12

enum {
  sym_Word = 1,
  anon_sym_SEMI = 2,
  anon_sym_enum = 3,
  anon_sym_LBRACE = 4,
  anon_sym_RBRACE = 5,
  anon_sym_COMMA = 6,
  anon_sym_PLUS = 7,
  anon_sym_DASH = 8,
  anon_sym_AMP_AMP = 9,
  anon_sym_LPAREN = 10,
  anon_sym_RPAREN = 11,
  anon_sym_EQ_EQ = 12,
  anon_sym_BANG = 13,
  anon_sym_DASH_GT = 14,
  anon_sym_DOT = 15,
  anon_sym_match = 16,
  anon_sym_STAR = 17,
  anon_sym_SLASH = 18,
  anon_sym_PERCENT = 19,
  anon_sym_PIPE_PIPE = 20,
  anon_sym_CARET = 21,
  anon_sym_fun = 22,
  sym_Int = 23,
  anon_sym_let = 24,
  anon_sym_EQ = 25,
  anon_sym_EQ_GT = 26,
  sym_Name = 27,
  anon_sym_COLON = 28,
  anon_sym_typedef = 29,
  sym_start = 30,
  sym_Block = 31,
  sym_DefSequenceDelimitedBySemicolon = 32,
  sym_Def_enum = 33,
  sym_Def_fun = 34,
  sym_Def_let = 35,
  sym_Def_typedef = 36,
  sym_Enum = 37,
  sym_EnumCase = 38,
  sym_EnumCaseSequenceSeparatedByComma = 39,
  sym_ExprSequenceSeparatedByComma = 40,
  sym_Expr_add = 41,
  sym_Expr_and = 42,
  sym_Expr_block = 43,
  sym_Expr_call = 44,
  sym_Expr_eql = 45,
  sym_Expr_lambda = 46,
  sym_Expr_match = 47,
  sym_Expr_mu = 48,
  sym_Expr_mul = 49,
  sym_Expr_name = 50,
  sym_Expr_neg = 51,
  sym_Expr_numb = 52,
  sym_Expr_or = 53,
  sym_Expr_paren = 54,
  sym_Expr_pow = 55,
  sym_Expr_project = 56,
  sym_Fun = 57,
  sym_Let = 58,
  sym_MatchCase = 59,
  sym_MatchCaseSequenceSeparatedByComma = 60,
  sym_NameSequenceSeparatedByCommaBracketedByParentheses = 61,
  sym_Param = 62,
  sym_ParamSequenceSeparatedByCommaBracketedByParentheses = 63,
  sym_TypeSequenceSeparatedByComma = 64,
  sym_Type_const = 65,
  sym_Type_func = 66,
  sym_Type_name = 67,
  sym_Type_tuple = 68,
  sym_Typedef = 69,
  sym__Def = 70,
  sym__Expr = 71,
  sym__Type = 72,
  aux_sym_DefSequenceDelimitedBySemicolon_repeat1 = 73,
  aux_sym_EnumCaseSequenceSeparatedByComma_repeat1 = 74,
  aux_sym_ExprSequenceSeparatedByComma_repeat1 = 75,
  aux_sym_MatchCaseSequenceSeparatedByComma_repeat1 = 76,
  aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1 = 77,
  aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1 = 78,
  aux_sym_TypeSequenceSeparatedByComma_repeat1 = 79,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_Word] = "Word",
  [anon_sym_SEMI] = ";",
  [anon_sym_enum] = "enum",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COMMA] = ",",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG] = "!",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_DOT] = ".",
  [anon_sym_match] = "match",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_CARET] = "^",
  [anon_sym_fun] = "fun",
  [sym_Int] = "Int",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_EQ_GT] = "=>",
  [sym_Name] = "Name",
  [anon_sym_COLON] = ":",
  [anon_sym_typedef] = "typedef",
  [sym_start] = "start",
  [sym_Block] = "Block",
  [sym_DefSequenceDelimitedBySemicolon] = "DefSequenceDelimitedBySemicolon",
  [sym_Def_enum] = "Def_enum",
  [sym_Def_fun] = "Def_fun",
  [sym_Def_let] = "Def_let",
  [sym_Def_typedef] = "Def_typedef",
  [sym_Enum] = "Enum",
  [sym_EnumCase] = "EnumCase",
  [sym_EnumCaseSequenceSeparatedByComma] = "EnumCaseSequenceSeparatedByComma",
  [sym_ExprSequenceSeparatedByComma] = "ExprSequenceSeparatedByComma",
  [sym_Expr_add] = "Expr_add",
  [sym_Expr_and] = "Expr_and",
  [sym_Expr_block] = "Expr_block",
  [sym_Expr_call] = "Expr_call",
  [sym_Expr_eql] = "Expr_eql",
  [sym_Expr_lambda] = "Expr_lambda",
  [sym_Expr_match] = "Expr_match",
  [sym_Expr_mu] = "Expr_mu",
  [sym_Expr_mul] = "Expr_mul",
  [sym_Expr_name] = "Expr_name",
  [sym_Expr_neg] = "Expr_neg",
  [sym_Expr_numb] = "Expr_numb",
  [sym_Expr_or] = "Expr_or",
  [sym_Expr_paren] = "Expr_paren",
  [sym_Expr_pow] = "Expr_pow",
  [sym_Expr_project] = "Expr_project",
  [sym_Fun] = "Fun",
  [sym_Let] = "Let",
  [sym_MatchCase] = "MatchCase",
  [sym_MatchCaseSequenceSeparatedByComma] = "MatchCaseSequenceSeparatedByComma",
  [sym_NameSequenceSeparatedByCommaBracketedByParentheses] = "NameSequenceSeparatedByCommaBracketedByParentheses",
  [sym_Param] = "Param",
  [sym_ParamSequenceSeparatedByCommaBracketedByParentheses] = "ParamSequenceSeparatedByCommaBracketedByParentheses",
  [sym_TypeSequenceSeparatedByComma] = "TypeSequenceSeparatedByComma",
  [sym_Type_const] = "Type_const",
  [sym_Type_func] = "Type_func",
  [sym_Type_name] = "Type_name",
  [sym_Type_tuple] = "Type_tuple",
  [sym_Typedef] = "Typedef",
  [sym__Def] = "_Def",
  [sym__Expr] = "_Expr",
  [sym__Type] = "_Type",
  [aux_sym_DefSequenceDelimitedBySemicolon_repeat1] = "DefSequenceDelimitedBySemicolon_repeat1",
  [aux_sym_EnumCaseSequenceSeparatedByComma_repeat1] = "EnumCaseSequenceSeparatedByComma_repeat1",
  [aux_sym_ExprSequenceSeparatedByComma_repeat1] = "ExprSequenceSeparatedByComma_repeat1",
  [aux_sym_MatchCaseSequenceSeparatedByComma_repeat1] = "MatchCaseSequenceSeparatedByComma_repeat1",
  [aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1] = "NameSequenceSeparatedByCommaBracketedByParentheses_repeat1",
  [aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1] = "ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1",
  [aux_sym_TypeSequenceSeparatedByComma_repeat1] = "TypeSequenceSeparatedByComma_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_Word] = sym_Word,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_fun] = anon_sym_fun,
  [sym_Int] = sym_Int,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [sym_Name] = sym_Name,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_typedef] = anon_sym_typedef,
  [sym_start] = sym_start,
  [sym_Block] = sym_Block,
  [sym_DefSequenceDelimitedBySemicolon] = sym_DefSequenceDelimitedBySemicolon,
  [sym_Def_enum] = sym_Def_enum,
  [sym_Def_fun] = sym_Def_fun,
  [sym_Def_let] = sym_Def_let,
  [sym_Def_typedef] = sym_Def_typedef,
  [sym_Enum] = sym_Enum,
  [sym_EnumCase] = sym_EnumCase,
  [sym_EnumCaseSequenceSeparatedByComma] = sym_EnumCaseSequenceSeparatedByComma,
  [sym_ExprSequenceSeparatedByComma] = sym_ExprSequenceSeparatedByComma,
  [sym_Expr_add] = sym_Expr_add,
  [sym_Expr_and] = sym_Expr_and,
  [sym_Expr_block] = sym_Expr_block,
  [sym_Expr_call] = sym_Expr_call,
  [sym_Expr_eql] = sym_Expr_eql,
  [sym_Expr_lambda] = sym_Expr_lambda,
  [sym_Expr_match] = sym_Expr_match,
  [sym_Expr_mu] = sym_Expr_mu,
  [sym_Expr_mul] = sym_Expr_mul,
  [sym_Expr_name] = sym_Expr_name,
  [sym_Expr_neg] = sym_Expr_neg,
  [sym_Expr_numb] = sym_Expr_numb,
  [sym_Expr_or] = sym_Expr_or,
  [sym_Expr_paren] = sym_Expr_paren,
  [sym_Expr_pow] = sym_Expr_pow,
  [sym_Expr_project] = sym_Expr_project,
  [sym_Fun] = sym_Fun,
  [sym_Let] = sym_Let,
  [sym_MatchCase] = sym_MatchCase,
  [sym_MatchCaseSequenceSeparatedByComma] = sym_MatchCaseSequenceSeparatedByComma,
  [sym_NameSequenceSeparatedByCommaBracketedByParentheses] = sym_NameSequenceSeparatedByCommaBracketedByParentheses,
  [sym_Param] = sym_Param,
  [sym_ParamSequenceSeparatedByCommaBracketedByParentheses] = sym_ParamSequenceSeparatedByCommaBracketedByParentheses,
  [sym_TypeSequenceSeparatedByComma] = sym_TypeSequenceSeparatedByComma,
  [sym_Type_const] = sym_Type_const,
  [sym_Type_func] = sym_Type_func,
  [sym_Type_name] = sym_Type_name,
  [sym_Type_tuple] = sym_Type_tuple,
  [sym_Typedef] = sym_Typedef,
  [sym__Def] = sym__Def,
  [sym__Expr] = sym__Expr,
  [sym__Type] = sym__Type,
  [aux_sym_DefSequenceDelimitedBySemicolon_repeat1] = aux_sym_DefSequenceDelimitedBySemicolon_repeat1,
  [aux_sym_EnumCaseSequenceSeparatedByComma_repeat1] = aux_sym_EnumCaseSequenceSeparatedByComma_repeat1,
  [aux_sym_ExprSequenceSeparatedByComma_repeat1] = aux_sym_ExprSequenceSeparatedByComma_repeat1,
  [aux_sym_MatchCaseSequenceSeparatedByComma_repeat1] = aux_sym_MatchCaseSequenceSeparatedByComma_repeat1,
  [aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1] = aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1] = aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [aux_sym_TypeSequenceSeparatedByComma_repeat1] = aux_sym_TypeSequenceSeparatedByComma_repeat1,
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
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
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
  [anon_sym_AMP_AMP] = {
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
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_match] = {
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
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fun] = {
    .visible = true,
    .named = false,
  },
  [sym_Int] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_Name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_typedef] = {
    .visible = true,
    .named = false,
  },
  [sym_start] = {
    .visible = true,
    .named = true,
  },
  [sym_Block] = {
    .visible = true,
    .named = true,
  },
  [sym_DefSequenceDelimitedBySemicolon] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_fun] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_let] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_typedef] = {
    .visible = true,
    .named = true,
  },
  [sym_Enum] = {
    .visible = true,
    .named = true,
  },
  [sym_EnumCase] = {
    .visible = true,
    .named = true,
  },
  [sym_EnumCaseSequenceSeparatedByComma] = {
    .visible = true,
    .named = true,
  },
  [sym_ExprSequenceSeparatedByComma] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_add] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_and] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_block] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_call] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_eql] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_lambda] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_match] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_mu] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_mul] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_name] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_neg] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_numb] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_or] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_paren] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_pow] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_project] = {
    .visible = true,
    .named = true,
  },
  [sym_Fun] = {
    .visible = true,
    .named = true,
  },
  [sym_Let] = {
    .visible = true,
    .named = true,
  },
  [sym_MatchCase] = {
    .visible = true,
    .named = true,
  },
  [sym_MatchCaseSequenceSeparatedByComma] = {
    .visible = true,
    .named = true,
  },
  [sym_NameSequenceSeparatedByCommaBracketedByParentheses] = {
    .visible = true,
    .named = true,
  },
  [sym_Param] = {
    .visible = true,
    .named = true,
  },
  [sym_ParamSequenceSeparatedByCommaBracketedByParentheses] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeSequenceSeparatedByComma] = {
    .visible = true,
    .named = true,
  },
  [sym_Type_const] = {
    .visible = true,
    .named = true,
  },
  [sym_Type_func] = {
    .visible = true,
    .named = true,
  },
  [sym_Type_name] = {
    .visible = true,
    .named = true,
  },
  [sym_Type_tuple] = {
    .visible = true,
    .named = true,
  },
  [sym_Typedef] = {
    .visible = true,
    .named = true,
  },
  [sym__Def] = {
    .visible = false,
    .named = true,
  },
  [sym__Expr] = {
    .visible = false,
    .named = true,
  },
  [sym__Type] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_DefSequenceDelimitedBySemicolon_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_EnumCaseSequenceSeparatedByComma_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ExprSequenceSeparatedByComma_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_MatchCaseSequenceSeparatedByComma_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_TypeSequenceSeparatedByComma_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_0 = 1,
  field_1 = 2,
  field_2 = 3,
  field_3 = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_0] = "0",
  [field_1] = "1",
  [field_2] = "2",
  [field_3] = "3",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 3},
  [6] = {.index = 8, .length = 2},
  [7] = {.index = 10, .length = 2},
  [8] = {.index = 12, .length = 3},
  [9] = {.index = 15, .length = 2},
  [10] = {.index = 17, .length = 4},
  [11] = {.index = 21, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_0, 0},
  [1] =
    {field_1, 0},
  [2] =
    {field_0, 0},
    {field_1, 1},
  [4] =
    {field_0, 1},
  [5] =
    {field_0, 0},
    {field_1, 1},
    {field_2, 2},
  [8] =
    {field_0, 0},
    {field_1, 2},
  [10] =
    {field_0, 1},
    {field_1, 3},
  [12] =
    {field_0, 1},
    {field_1, 3},
    {field_2, 5},
  [15] =
    {field_0, 0},
    {field_2, 2},
  [17] =
    {field_0, 1},
    {field_1, 2},
    {field_2, 4},
    {field_3, 6},
  [21] =
    {field_0, 0},
    {field_1, 1},
    {field_2, 3},
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
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(29);
      if (lookahead == '%') ADVANCE(41);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == '*') ADVANCE(37);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == ',') ADVANCE(16);
      if (lookahead == '-') ADVANCE(21);
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == '/') ADVANCE(39);
      if (lookahead == ':') ADVANCE(95);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '=') ADVANCE(53);
      if (lookahead == '^') ADVANCE(45);
      if (lookahead == 'e') ADVANCE(67);
      if (lookahead == 'f') ADVANCE(72);
      if (lookahead == 'l') ADVANCE(60);
      if (lookahead == 'm') ADVANCE(57);
      if (lookahead == 't') ADVANCE(73);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(8);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(29);
      if (lookahead == '%') ADVANCE(41);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == '*') ADVANCE(37);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == ',') ADVANCE(16);
      if (lookahead == '-') ADVANCE(21);
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == '/') ADVANCE(39);
      if (lookahead == ':') ADVANCE(95);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '=') ADVANCE(53);
      if (lookahead == '^') ADVANCE(45);
      if (lookahead == 'e') ADVANCE(67);
      if (lookahead == 'f') ADVANCE(72);
      if (lookahead == 'l') ADVANCE(60);
      if (lookahead == 'm') ADVANCE(57);
      if (lookahead == 't') ADVANCE(73);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(8);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(30);
      if (lookahead == '%') ADVANCE(42);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == '*') ADVANCE(38);
      if (lookahead == '+') ADVANCE(19);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '.') ADVANCE(34);
      if (lookahead == '/') ADVANCE(40);
      if (lookahead == ':') ADVANCE(95);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '=') ADVANCE(54);
      if (lookahead == '^') ADVANCE(46);
      if (lookahead == 'e') ADVANCE(67);
      if (lookahead == 'f') ADVANCE(72);
      if (lookahead == 'l') ADVANCE(60);
      if (lookahead == 'm') ADVANCE(57);
      if (lookahead == 't') ADVANCE(73);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(100);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (lookahead == '#' ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '~') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(29);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '=') ADVANCE(52);
      if (lookahead == 'm') ADVANCE(76);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 4:
      if (lookahead == '&') ADVANCE(23);
      END_STATE();
    case 5:
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == ',') ADVANCE(16);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '=') ADVANCE(52);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(27);
      if (lookahead == '>') ADVANCE(55);
      END_STATE();
    case 7:
      if (lookahead == '>') ADVANCE(31);
      END_STATE();
    case 8:
      if (lookahead == '|') ADVANCE(43);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '!') ADVANCE(29);
      if (lookahead == '%') ADVANCE(41);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == '*') ADVANCE(37);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == ',') ADVANCE(16);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == '/') ADVANCE(39);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '^') ADVANCE(45);
      if (lookahead == 'e') ADVANCE(86);
      if (lookahead == 'f') ADVANCE(91);
      if (lookahead == 'l') ADVANCE(79);
      if (lookahead == 'm') ADVANCE(76);
      if (lookahead == 't') ADVANCE(92);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(8);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_enum);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_enum);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(31);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(32);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          lookahead == '<' ||
          lookahead == '=' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_match);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_match);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_fun);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_fun);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_Int);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(27);
      if (lookahead == '>') ADVANCE(55);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(28);
      if (lookahead == '>') ADVANCE(56);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          lookahead == '<' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'a') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'c') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'd') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'e') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'e') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'e') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'f') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'h') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'm') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'n') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'n') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'p') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 't') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 't') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'u') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'u') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (lookahead == 'y') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'a') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'c') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'd') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'e') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'e') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'e') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'f') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'h') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'm') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'n') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'n') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'p') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 't') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 't') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'u') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'u') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_Name);
      if (lookahead == 'y') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_Name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_Name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_typedef);
      if (lookahead == ' ') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_typedef);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_Word);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '&') ADVANCE(24);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '~') ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(101);
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
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 9},
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
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 9},
  [23] = {.lex_state = 9},
  [24] = {.lex_state = 9},
  [25] = {.lex_state = 9},
  [26] = {.lex_state = 9},
  [27] = {.lex_state = 9},
  [28] = {.lex_state = 9},
  [29] = {.lex_state = 9},
  [30] = {.lex_state = 9},
  [31] = {.lex_state = 9},
  [32] = {.lex_state = 9},
  [33] = {.lex_state = 9},
  [34] = {.lex_state = 9},
  [35] = {.lex_state = 9},
  [36] = {.lex_state = 9},
  [37] = {.lex_state = 9},
  [38] = {.lex_state = 9},
  [39] = {.lex_state = 9},
  [40] = {.lex_state = 9},
  [41] = {.lex_state = 9},
  [42] = {.lex_state = 9},
  [43] = {.lex_state = 9},
  [44] = {.lex_state = 9},
  [45] = {.lex_state = 9},
  [46] = {.lex_state = 9},
  [47] = {.lex_state = 9},
  [48] = {.lex_state = 9},
  [49] = {.lex_state = 9},
  [50] = {.lex_state = 9},
  [51] = {.lex_state = 9},
  [52] = {.lex_state = 5},
  [53] = {.lex_state = 5},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 5},
  [56] = {.lex_state = 5},
  [57] = {.lex_state = 5},
  [58] = {.lex_state = 5},
  [59] = {.lex_state = 5},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 5},
  [62] = {.lex_state = 5},
  [63] = {.lex_state = 5},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 5},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 5},
  [68] = {.lex_state = 5},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 9},
  [71] = {.lex_state = 9},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 5},
  [74] = {.lex_state = 9},
  [75] = {.lex_state = 9},
  [76] = {.lex_state = 9},
  [77] = {.lex_state = 5},
  [78] = {.lex_state = 9},
  [79] = {.lex_state = 5},
  [80] = {.lex_state = 5},
  [81] = {.lex_state = 9},
  [82] = {.lex_state = 9},
  [83] = {.lex_state = 9},
  [84] = {.lex_state = 9},
  [85] = {.lex_state = 9},
  [86] = {.lex_state = 9},
  [87] = {.lex_state = 5},
  [88] = {.lex_state = 9},
  [89] = {.lex_state = 9},
  [90] = {.lex_state = 5},
  [91] = {.lex_state = 9},
  [92] = {.lex_state = 5},
  [93] = {.lex_state = 5},
  [94] = {.lex_state = 9},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 5},
  [97] = {.lex_state = 5},
  [98] = {.lex_state = 9},
  [99] = {.lex_state = 9},
  [100] = {.lex_state = 5},
  [101] = {.lex_state = 5},
  [102] = {.lex_state = 5},
  [103] = {.lex_state = 5},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 9},
  [106] = {.lex_state = 9},
  [107] = {.lex_state = 5},
  [108] = {.lex_state = 5},
  [109] = {.lex_state = 9},
  [110] = {.lex_state = 5},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 5},
  [113] = {.lex_state = 3},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 9},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 9},
  [129] = {.lex_state = 5},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 5},
  [132] = {.lex_state = 5},
  [133] = {.lex_state = 5},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 5},
  [136] = {.lex_state = 9},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 3},
  [141] = {.lex_state = 9},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_Word] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_fun] = ACTIONS(1),
    [sym_Int] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [sym_Name] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_typedef] = ACTIONS(1),
  },
  [1] = {
    [sym_start] = STATE(130),
    [sym_Block] = STATE(127),
    [sym_DefSequenceDelimitedBySemicolon] = STATE(15),
    [sym_Def_enum] = STATE(118),
    [sym_Def_fun] = STATE(118),
    [sym_Def_let] = STATE(118),
    [sym_Def_typedef] = STATE(118),
    [sym_Enum] = STATE(126),
    [sym_Expr_add] = STATE(43),
    [sym_Expr_and] = STATE(43),
    [sym_Expr_block] = STATE(43),
    [sym_Expr_call] = STATE(43),
    [sym_Expr_eql] = STATE(43),
    [sym_Expr_lambda] = STATE(43),
    [sym_Expr_match] = STATE(43),
    [sym_Expr_mu] = STATE(43),
    [sym_Expr_mul] = STATE(43),
    [sym_Expr_name] = STATE(43),
    [sym_Expr_neg] = STATE(43),
    [sym_Expr_numb] = STATE(43),
    [sym_Expr_or] = STATE(43),
    [sym_Expr_paren] = STATE(43),
    [sym_Expr_pow] = STATE(43),
    [sym_Expr_project] = STATE(43),
    [sym_Fun] = STATE(123),
    [sym_Let] = STATE(122),
    [sym_Typedef] = STATE(111),
    [sym__Def] = STATE(118),
    [sym__Expr] = STATE(43),
    [anon_sym_enum] = ACTIONS(3),
    [anon_sym_LBRACE] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_BANG] = ACTIONS(11),
    [anon_sym_match] = ACTIONS(13),
    [anon_sym_fun] = ACTIONS(15),
    [sym_Int] = ACTIONS(17),
    [anon_sym_let] = ACTIONS(19),
    [sym_Name] = ACTIONS(21),
    [anon_sym_typedef] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 19,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_Name,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(15), 1,
      sym_DefSequenceDelimitedBySemicolon,
    STATE(111), 1,
      sym_Typedef,
    STATE(116), 1,
      sym_Block,
    STATE(122), 1,
      sym_Let,
    STATE(123), 1,
      sym_Fun,
    STATE(126), 1,
      sym_Enum,
    STATE(118), 5,
      sym_Def_enum,
      sym_Def_fun,
      sym_Def_let,
      sym_Def_typedef,
      sym__Def,
    STATE(43), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [78] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    STATE(114), 1,
      sym_ExprSequenceSeparatedByComma,
    STATE(42), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [125] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    ACTIONS(27), 1,
      anon_sym_RPAREN,
    STATE(120), 1,
      sym_ExprSequenceSeparatedByComma,
    STATE(42), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [172] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(33), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [213] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(44), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [254] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(50), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [295] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(26), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [336] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(49), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [377] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(46), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [418] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(40), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [459] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(48), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [500] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(47), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [541] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(35), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [582] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(45), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [623] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(41), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [664] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(38), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [705] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(32), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [746] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(29), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [787] = 8,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_BANG,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      sym_Int,
    ACTIONS(21), 1,
      sym_Name,
    STATE(37), 17,
      sym_Expr_add,
      sym_Expr_and,
      sym_Expr_block,
      sym_Expr_call,
      sym_Expr_eql,
      sym_Expr_lambda,
      sym_Expr_match,
      sym_Expr_mu,
      sym_Expr_mul,
      sym_Expr_name,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_or,
      sym_Expr_paren,
      sym_Expr_pow,
      sym_Expr_project,
      sym__Expr,
  [828] = 12,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(23), 1,
      aux_sym_DefSequenceDelimitedBySemicolon_repeat1,
    STATE(111), 1,
      sym_Typedef,
    STATE(122), 1,
      sym_Let,
    STATE(123), 1,
      sym_Fun,
    STATE(126), 1,
      sym_Enum,
    ACTIONS(31), 2,
      anon_sym_match,
      sym_Name,
    ACTIONS(29), 5,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_BANG,
      sym_Int,
    STATE(139), 5,
      sym_Def_enum,
      sym_Def_fun,
      sym_Def_let,
      sym_Def_typedef,
      sym__Def,
  [874] = 12,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(21), 1,
      aux_sym_DefSequenceDelimitedBySemicolon_repeat1,
    STATE(111), 1,
      sym_Typedef,
    STATE(122), 1,
      sym_Let,
    STATE(123), 1,
      sym_Fun,
    STATE(126), 1,
      sym_Enum,
    ACTIONS(35), 2,
      anon_sym_match,
      sym_Name,
    ACTIONS(33), 5,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_BANG,
      sym_Int,
    STATE(139), 5,
      sym_Def_enum,
      sym_Def_fun,
      sym_Def_let,
      sym_Def_typedef,
      sym__Def,
  [920] = 12,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(44), 1,
      anon_sym_fun,
    ACTIONS(47), 1,
      anon_sym_let,
    ACTIONS(50), 1,
      anon_sym_typedef,
    STATE(23), 1,
      aux_sym_DefSequenceDelimitedBySemicolon_repeat1,
    STATE(111), 1,
      sym_Typedef,
    STATE(122), 1,
      sym_Let,
    STATE(123), 1,
      sym_Fun,
    STATE(126), 1,
      sym_Enum,
    ACTIONS(42), 2,
      anon_sym_match,
      sym_Name,
    ACTIONS(40), 5,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_BANG,
      sym_Int,
    STATE(139), 5,
      sym_Def_enum,
      sym_Def_fun,
      sym_Def_let,
      sym_Def_typedef,
      sym__Def,
  [966] = 1,
    ACTIONS(53), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [986] = 1,
    ACTIONS(55), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1006] = 3,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(57), 15,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1030] = 1,
    ACTIONS(63), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1050] = 1,
    ACTIONS(65), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1070] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(67), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1106] = 1,
    ACTIONS(81), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1126] = 1,
    ACTIONS(83), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1146] = 6,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(85), 9,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_PIPE_PIPE,
  [1176] = 5,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(87), 11,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_PIPE_PIPE,
  [1204] = 1,
    ACTIONS(89), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1224] = 7,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(91), 8,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_PIPE_PIPE,
  [1256] = 1,
    ACTIONS(93), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1276] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(95), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1312] = 8,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(97), 7,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
  [1346] = 1,
    ACTIONS(99), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_CARET,
  [1366] = 4,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(101), 14,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
  [1392] = 4,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(103), 14,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP_AMP,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
  [1418] = 11,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(105), 1,
      anon_sym_COMMA,
    ACTIONS(107), 1,
      anon_sym_RPAREN,
    STATE(88), 1,
      aux_sym_ExprSequenceSeparatedByComma_repeat1,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1455] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1487] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(111), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1519] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1551] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(115), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1583] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(117), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1615] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(119), 1,
      anon_sym_RBRACE,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1646] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(121), 1,
      anon_sym_SEMI,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1677] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_EQ_EQ,
    ACTIONS(77), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(79), 1,
      anon_sym_CARET,
    ACTIONS(123), 1,
      anon_sym_LBRACE,
    ACTIONS(69), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(75), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1708] = 2,
    ACTIONS(40), 5,
      anon_sym_LBRACE,
      anon_sym_DASH,
      anon_sym_LPAREN,
      anon_sym_BANG,
      sym_Int,
    ACTIONS(42), 6,
      anon_sym_enum,
      anon_sym_match,
      anon_sym_fun,
      anon_sym_let,
      sym_Name,
      anon_sym_typedef,
  [1724] = 5,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(127), 1,
      anon_sym_RPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(121), 1,
      sym_TypeSequenceSeparatedByComma,
    STATE(68), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1744] = 5,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    ACTIONS(131), 1,
      anon_sym_RPAREN,
    STATE(137), 1,
      sym_TypeSequenceSeparatedByComma,
    STATE(68), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1764] = 2,
    ACTIONS(135), 1,
      anon_sym_LPAREN,
    ACTIONS(133), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [1777] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(137), 6,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_EQ,
  [1789] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(67), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1803] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(96), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1817] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(108), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1831] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(103), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1845] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(100), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1859] = 1,
    ACTIONS(141), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [1869] = 1,
    ACTIONS(143), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [1879] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(55), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1893] = 1,
    ACTIONS(145), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [1903] = 3,
    ACTIONS(125), 1,
      anon_sym_LPAREN,
    ACTIONS(129), 1,
      sym_Name,
    STATE(79), 5,
      sym_Type_const,
      sym_Type_func,
      sym_Type_name,
      sym_Type_tuple,
      sym__Type,
  [1917] = 1,
    ACTIONS(147), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [1927] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(149), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
  [1936] = 4,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(151), 1,
      anon_sym_COMMA,
    ACTIONS(153), 1,
      anon_sym_RPAREN,
    STATE(85), 1,
      aux_sym_TypeSequenceSeparatedByComma_repeat1,
  [1949] = 3,
    ACTIONS(157), 1,
      anon_sym_LPAREN,
    STATE(106), 1,
      sym_ParamSequenceSeparatedByCommaBracketedByParentheses,
    ACTIONS(155), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1960] = 3,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    ACTIONS(161), 1,
      anon_sym_COMMA,
    STATE(71), 1,
      aux_sym_EnumCaseSequenceSeparatedByComma_repeat1,
  [1970] = 3,
    ACTIONS(161), 1,
      anon_sym_COMMA,
    ACTIONS(163), 1,
      anon_sym_RBRACE,
    STATE(89), 1,
      aux_sym_EnumCaseSequenceSeparatedByComma_repeat1,
  [1980] = 3,
    ACTIONS(165), 1,
      anon_sym_COMMA,
    ACTIONS(168), 1,
      anon_sym_RPAREN,
    STATE(72), 1,
      aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [1990] = 3,
    ACTIONS(157), 1,
      anon_sym_LPAREN,
    ACTIONS(170), 1,
      sym_Name,
    STATE(129), 1,
      sym_ParamSequenceSeparatedByCommaBracketedByParentheses,
  [2000] = 3,
    ACTIONS(172), 1,
      anon_sym_COMMA,
    ACTIONS(174), 1,
      anon_sym_RPAREN,
    STATE(72), 1,
      aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [2010] = 3,
    ACTIONS(115), 1,
      anon_sym_RPAREN,
    ACTIONS(176), 1,
      anon_sym_COMMA,
    STATE(75), 1,
      aux_sym_ExprSequenceSeparatedByComma_repeat1,
  [2020] = 3,
    ACTIONS(179), 1,
      anon_sym_COMMA,
    ACTIONS(182), 1,
      anon_sym_RPAREN,
    STATE(76), 1,
      aux_sym_TypeSequenceSeparatedByComma_repeat1,
  [2030] = 1,
    ACTIONS(184), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
  [2036] = 3,
    ACTIONS(186), 1,
      anon_sym_COMMA,
    ACTIONS(188), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [2046] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(182), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2054] = 3,
    ACTIONS(190), 1,
      sym_Name,
    STATE(84), 1,
      sym_MatchCase,
    STATE(125), 1,
      sym_MatchCaseSequenceSeparatedByComma,
  [2064] = 3,
    ACTIONS(192), 1,
      anon_sym_RBRACE,
    ACTIONS(194), 1,
      anon_sym_COMMA,
    STATE(81), 1,
      aux_sym_MatchCaseSequenceSeparatedByComma_repeat1,
  [2074] = 3,
    ACTIONS(172), 1,
      anon_sym_COMMA,
    ACTIONS(197), 1,
      anon_sym_RPAREN,
    STATE(74), 1,
      aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [2084] = 3,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_EQ_GT,
    STATE(128), 1,
      sym_NameSequenceSeparatedByCommaBracketedByParentheses,
  [2094] = 3,
    ACTIONS(203), 1,
      anon_sym_RBRACE,
    ACTIONS(205), 1,
      anon_sym_COMMA,
    STATE(91), 1,
      aux_sym_MatchCaseSequenceSeparatedByComma_repeat1,
  [2104] = 3,
    ACTIONS(151), 1,
      anon_sym_COMMA,
    ACTIONS(207), 1,
      anon_sym_RPAREN,
    STATE(76), 1,
      aux_sym_TypeSequenceSeparatedByComma_repeat1,
  [2114] = 3,
    ACTIONS(186), 1,
      anon_sym_COMMA,
    ACTIONS(209), 1,
      anon_sym_RPAREN,
    STATE(78), 1,
      aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [2124] = 1,
    ACTIONS(211), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
  [2130] = 3,
    ACTIONS(105), 1,
      anon_sym_COMMA,
    ACTIONS(213), 1,
      anon_sym_RPAREN,
    STATE(75), 1,
      aux_sym_ExprSequenceSeparatedByComma_repeat1,
  [2140] = 3,
    ACTIONS(215), 1,
      anon_sym_RBRACE,
    ACTIONS(217), 1,
      anon_sym_COMMA,
    STATE(89), 1,
      aux_sym_EnumCaseSequenceSeparatedByComma_repeat1,
  [2150] = 3,
    ACTIONS(220), 1,
      sym_Name,
    STATE(70), 1,
      sym_EnumCase,
    STATE(142), 1,
      sym_EnumCaseSequenceSeparatedByComma,
  [2160] = 3,
    ACTIONS(205), 1,
      anon_sym_COMMA,
    ACTIONS(222), 1,
      anon_sym_RBRACE,
    STATE(81), 1,
      aux_sym_MatchCaseSequenceSeparatedByComma_repeat1,
  [2170] = 3,
    ACTIONS(224), 1,
      anon_sym_RPAREN,
    ACTIONS(226), 1,
      sym_Name,
    STATE(86), 1,
      sym_Param,
  [2180] = 1,
    ACTIONS(228), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
  [2186] = 3,
    ACTIONS(230), 1,
      anon_sym_COMMA,
    ACTIONS(233), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1,
  [2196] = 2,
    ACTIONS(157), 1,
      anon_sym_LPAREN,
    STATE(132), 1,
      sym_ParamSequenceSeparatedByCommaBracketedByParentheses,
  [2203] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(235), 1,
      anon_sym_LBRACE,
  [2210] = 2,
    ACTIONS(220), 1,
      sym_Name,
    STATE(109), 1,
      sym_EnumCase,
  [2217] = 1,
    ACTIONS(168), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2222] = 1,
    ACTIONS(233), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2227] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(237), 1,
      anon_sym_DOT,
  [2234] = 2,
    ACTIONS(226), 1,
      sym_Name,
    STATE(99), 1,
      sym_Param,
  [2241] = 2,
    ACTIONS(226), 1,
      sym_Name,
    STATE(140), 1,
      sym_Param,
  [2248] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(239), 1,
      anon_sym_DOT,
  [2255] = 2,
    ACTIONS(157), 1,
      anon_sym_LPAREN,
    STATE(133), 1,
      sym_ParamSequenceSeparatedByCommaBracketedByParentheses,
  [2262] = 1,
    ACTIONS(192), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2267] = 1,
    ACTIONS(241), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2272] = 2,
    ACTIONS(243), 1,
      anon_sym_RPAREN,
    ACTIONS(245), 1,
      sym_Name,
  [2279] = 2,
    ACTIONS(139), 1,
      anon_sym_DASH_GT,
    ACTIONS(247), 1,
      anon_sym_SEMI,
  [2286] = 1,
    ACTIONS(215), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2291] = 2,
    ACTIONS(190), 1,
      sym_Name,
    STATE(105), 1,
      sym_MatchCase,
  [2298] = 1,
    ACTIONS(249), 1,
      anon_sym_SEMI,
  [2302] = 1,
    ACTIONS(251), 1,
      sym_Name,
  [2306] = 1,
    ACTIONS(253), 1,
      anon_sym_EQ,
  [2310] = 1,
    ACTIONS(255), 1,
      anon_sym_RPAREN,
  [2314] = 1,
    ACTIONS(257), 1,
      sym_Int,
  [2318] = 1,
    ACTIONS(259), 1,
      anon_sym_RBRACE,
  [2322] = 1,
    ACTIONS(261), 1,
      anon_sym_LBRACE,
  [2326] = 1,
    ACTIONS(263), 1,
      anon_sym_SEMI,
  [2330] = 1,
    ACTIONS(265), 1,
      anon_sym_SEMI,
  [2334] = 1,
    ACTIONS(267), 1,
      anon_sym_RPAREN,
  [2338] = 1,
    ACTIONS(269), 1,
      anon_sym_RPAREN,
  [2342] = 1,
    ACTIONS(271), 1,
      anon_sym_SEMI,
  [2346] = 1,
    ACTIONS(273), 1,
      anon_sym_SEMI,
  [2350] = 1,
    ACTIONS(275), 1,
      anon_sym_EQ_GT,
  [2354] = 1,
    ACTIONS(277), 1,
      anon_sym_RBRACE,
  [2358] = 1,
    ACTIONS(279), 1,
      anon_sym_SEMI,
  [2362] = 1,
    ACTIONS(281), 1,
      ts_builtin_sym_end,
  [2366] = 1,
    ACTIONS(283), 1,
      anon_sym_EQ_GT,
  [2370] = 1,
    ACTIONS(285), 1,
      anon_sym_DASH_GT,
  [2374] = 1,
    ACTIONS(287), 1,
      ts_builtin_sym_end,
  [2378] = 1,
    ACTIONS(289), 1,
      sym_Name,
  [2382] = 1,
    ACTIONS(291), 1,
      anon_sym_DASH_GT,
  [2386] = 1,
    ACTIONS(293), 1,
      anon_sym_DASH_GT,
  [2390] = 1,
    ACTIONS(295), 1,
      anon_sym_COLON,
  [2394] = 1,
    ACTIONS(297), 1,
      sym_Name,
  [2398] = 1,
    ACTIONS(299), 1,
      anon_sym_EQ_GT,
  [2402] = 1,
    ACTIONS(301), 1,
      anon_sym_RPAREN,
  [2406] = 1,
    ACTIONS(303), 1,
      sym_Name,
  [2410] = 1,
    ACTIONS(305), 1,
      anon_sym_SEMI,
  [2414] = 1,
    ACTIONS(307), 1,
      anon_sym_EQ,
  [2418] = 1,
    ACTIONS(309), 1,
      anon_sym_EQ_GT,
  [2422] = 1,
    ACTIONS(311), 1,
      anon_sym_RBRACE,
  [2426] = 1,
    ACTIONS(313), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 78,
  [SMALL_STATE(4)] = 125,
  [SMALL_STATE(5)] = 172,
  [SMALL_STATE(6)] = 213,
  [SMALL_STATE(7)] = 254,
  [SMALL_STATE(8)] = 295,
  [SMALL_STATE(9)] = 336,
  [SMALL_STATE(10)] = 377,
  [SMALL_STATE(11)] = 418,
  [SMALL_STATE(12)] = 459,
  [SMALL_STATE(13)] = 500,
  [SMALL_STATE(14)] = 541,
  [SMALL_STATE(15)] = 582,
  [SMALL_STATE(16)] = 623,
  [SMALL_STATE(17)] = 664,
  [SMALL_STATE(18)] = 705,
  [SMALL_STATE(19)] = 746,
  [SMALL_STATE(20)] = 787,
  [SMALL_STATE(21)] = 828,
  [SMALL_STATE(22)] = 874,
  [SMALL_STATE(23)] = 920,
  [SMALL_STATE(24)] = 966,
  [SMALL_STATE(25)] = 986,
  [SMALL_STATE(26)] = 1006,
  [SMALL_STATE(27)] = 1030,
  [SMALL_STATE(28)] = 1050,
  [SMALL_STATE(29)] = 1070,
  [SMALL_STATE(30)] = 1106,
  [SMALL_STATE(31)] = 1126,
  [SMALL_STATE(32)] = 1146,
  [SMALL_STATE(33)] = 1176,
  [SMALL_STATE(34)] = 1204,
  [SMALL_STATE(35)] = 1224,
  [SMALL_STATE(36)] = 1256,
  [SMALL_STATE(37)] = 1276,
  [SMALL_STATE(38)] = 1312,
  [SMALL_STATE(39)] = 1346,
  [SMALL_STATE(40)] = 1366,
  [SMALL_STATE(41)] = 1392,
  [SMALL_STATE(42)] = 1418,
  [SMALL_STATE(43)] = 1455,
  [SMALL_STATE(44)] = 1487,
  [SMALL_STATE(45)] = 1519,
  [SMALL_STATE(46)] = 1551,
  [SMALL_STATE(47)] = 1583,
  [SMALL_STATE(48)] = 1615,
  [SMALL_STATE(49)] = 1646,
  [SMALL_STATE(50)] = 1677,
  [SMALL_STATE(51)] = 1708,
  [SMALL_STATE(52)] = 1724,
  [SMALL_STATE(53)] = 1744,
  [SMALL_STATE(54)] = 1764,
  [SMALL_STATE(55)] = 1777,
  [SMALL_STATE(56)] = 1789,
  [SMALL_STATE(57)] = 1803,
  [SMALL_STATE(58)] = 1817,
  [SMALL_STATE(59)] = 1831,
  [SMALL_STATE(60)] = 1845,
  [SMALL_STATE(61)] = 1859,
  [SMALL_STATE(62)] = 1869,
  [SMALL_STATE(63)] = 1879,
  [SMALL_STATE(64)] = 1893,
  [SMALL_STATE(65)] = 1903,
  [SMALL_STATE(66)] = 1917,
  [SMALL_STATE(67)] = 1927,
  [SMALL_STATE(68)] = 1936,
  [SMALL_STATE(69)] = 1949,
  [SMALL_STATE(70)] = 1960,
  [SMALL_STATE(71)] = 1970,
  [SMALL_STATE(72)] = 1980,
  [SMALL_STATE(73)] = 1990,
  [SMALL_STATE(74)] = 2000,
  [SMALL_STATE(75)] = 2010,
  [SMALL_STATE(76)] = 2020,
  [SMALL_STATE(77)] = 2030,
  [SMALL_STATE(78)] = 2036,
  [SMALL_STATE(79)] = 2046,
  [SMALL_STATE(80)] = 2054,
  [SMALL_STATE(81)] = 2064,
  [SMALL_STATE(82)] = 2074,
  [SMALL_STATE(83)] = 2084,
  [SMALL_STATE(84)] = 2094,
  [SMALL_STATE(85)] = 2104,
  [SMALL_STATE(86)] = 2114,
  [SMALL_STATE(87)] = 2124,
  [SMALL_STATE(88)] = 2130,
  [SMALL_STATE(89)] = 2140,
  [SMALL_STATE(90)] = 2150,
  [SMALL_STATE(91)] = 2160,
  [SMALL_STATE(92)] = 2170,
  [SMALL_STATE(93)] = 2180,
  [SMALL_STATE(94)] = 2186,
  [SMALL_STATE(95)] = 2196,
  [SMALL_STATE(96)] = 2203,
  [SMALL_STATE(97)] = 2210,
  [SMALL_STATE(98)] = 2217,
  [SMALL_STATE(99)] = 2222,
  [SMALL_STATE(100)] = 2227,
  [SMALL_STATE(101)] = 2234,
  [SMALL_STATE(102)] = 2241,
  [SMALL_STATE(103)] = 2248,
  [SMALL_STATE(104)] = 2255,
  [SMALL_STATE(105)] = 2262,
  [SMALL_STATE(106)] = 2267,
  [SMALL_STATE(107)] = 2272,
  [SMALL_STATE(108)] = 2279,
  [SMALL_STATE(109)] = 2286,
  [SMALL_STATE(110)] = 2291,
  [SMALL_STATE(111)] = 2298,
  [SMALL_STATE(112)] = 2302,
  [SMALL_STATE(113)] = 2306,
  [SMALL_STATE(114)] = 2310,
  [SMALL_STATE(115)] = 2314,
  [SMALL_STATE(116)] = 2318,
  [SMALL_STATE(117)] = 2322,
  [SMALL_STATE(118)] = 2326,
  [SMALL_STATE(119)] = 2330,
  [SMALL_STATE(120)] = 2334,
  [SMALL_STATE(121)] = 2338,
  [SMALL_STATE(122)] = 2342,
  [SMALL_STATE(123)] = 2346,
  [SMALL_STATE(124)] = 2350,
  [SMALL_STATE(125)] = 2354,
  [SMALL_STATE(126)] = 2358,
  [SMALL_STATE(127)] = 2362,
  [SMALL_STATE(128)] = 2366,
  [SMALL_STATE(129)] = 2370,
  [SMALL_STATE(130)] = 2374,
  [SMALL_STATE(131)] = 2378,
  [SMALL_STATE(132)] = 2382,
  [SMALL_STATE(133)] = 2386,
  [SMALL_STATE(134)] = 2390,
  [SMALL_STATE(135)] = 2394,
  [SMALL_STATE(136)] = 2398,
  [SMALL_STATE(137)] = 2402,
  [SMALL_STATE(138)] = 2406,
  [SMALL_STATE(139)] = 2410,
  [SMALL_STATE(140)] = 2414,
  [SMALL_STATE(141)] = 2418,
  [SMALL_STATE(142)] = 2422,
  [SMALL_STATE(143)] = 2426,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DefSequenceDelimitedBySemicolon, 3),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DefSequenceDelimitedBySemicolon, 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DefSequenceDelimitedBySemicolon, 2),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DefSequenceDelimitedBySemicolon, 2),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefSequenceDelimitedBySemicolon_repeat1, 2), SHIFT_REPEAT(112),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DefSequenceDelimitedBySemicolon_repeat1, 2),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DefSequenceDelimitedBySemicolon_repeat1, 2),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefSequenceDelimitedBySemicolon_repeat1, 2), SHIFT_REPEAT(138),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefSequenceDelimitedBySemicolon_repeat1, 2), SHIFT_REPEAT(102),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefSequenceDelimitedBySemicolon_repeat1, 2), SHIFT_REPEAT(131),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_block, 3, .production_id = 4),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_project, 3, .production_id = 6),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_neg, 2, .production_id = 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_numb, 1, .production_id = 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mu, 7, .production_id = 10),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_call, 3, .production_id = 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_name, 1, .production_id = 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_and, 3, .production_id = 5),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_add, 3, .production_id = 5),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_call, 4, .production_id = 6),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_or, 3, .production_id = 5),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 3, .production_id = 4),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_lambda, 6, .production_id = 8),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_eql, 3, .production_id = 5),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_match, 5, .production_id = 7),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_pow, 3, .production_id = 5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mul, 3, .production_id = 5),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprSequenceSeparatedByComma, 1),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 1, .production_id = 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCase, 3, .production_id = 9),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 2, .production_id = 3),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprSequenceSeparatedByComma_repeat1, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCase, 4, .production_id = 11),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Let, 4, .production_id = 7),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Type_name, 1, .production_id = 1),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Type_func, 3, .production_id = 6),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Type_const, 4, .production_id = 6),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Type_tuple, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Type_tuple, 3, .production_id = 4),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Type_const, 3, .production_id = 1),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Param, 3, .production_id = 6),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeSequenceSeparatedByComma, 1),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCase, 1, .production_id = 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCaseSequenceSeparatedByComma, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCaseSequenceSeparatedByComma, 2),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1, 2), SHIFT_REPEAT(135),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_NameSequenceSeparatedByCommaBracketedByParentheses_repeat1, 2),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ExprSequenceSeparatedByComma_repeat1, 2), SHIFT_REPEAT(10),
  [179] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_TypeSequenceSeparatedByComma_repeat1, 2), SHIFT_REPEAT(65),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_TypeSequenceSeparatedByComma_repeat1, 2),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamSequenceSeparatedByCommaBracketedByParentheses, 3),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_MatchCaseSequenceSeparatedByComma_repeat1, 2),
  [194] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_MatchCaseSequenceSeparatedByComma_repeat1, 2), SHIFT_REPEAT(110),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCaseSequenceSeparatedByComma, 1),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeSequenceSeparatedByComma, 2),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamSequenceSeparatedByCommaBracketedByParentheses, 2),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprSequenceSeparatedByComma, 2),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_EnumCaseSequenceSeparatedByComma_repeat1, 2),
  [217] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_EnumCaseSequenceSeparatedByComma_repeat1, 2), SHIFT_REPEAT(97),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCaseSequenceSeparatedByComma, 2),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamSequenceSeparatedByCommaBracketedByParentheses, 4),
  [230] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1, 2), SHIFT_REPEAT(101),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ParamSequenceSeparatedByCommaBracketedByParentheses_repeat1, 2),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCase, 2, .production_id = 3),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Typedef, 4, .production_id = 7),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_typedef, 1, .production_id = 1),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Enum, 5, .production_id = 7),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_let, 1, .production_id = 1),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_fun, 1, .production_id = 1),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameSequenceSeparatedByCommaBracketedByParentheses, 2),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_enum, 1, .production_id = 1),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start, 1),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [287] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameSequenceSeparatedByCommaBracketedByParentheses, 3),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameSequenceSeparatedByCommaBracketedByParentheses, 4),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Fun, 8, .production_id = 10),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_TypedLang(void) {
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
