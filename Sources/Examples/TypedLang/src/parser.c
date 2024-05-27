#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 144
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 86
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 10
#define PRODUCTION_ID_COUNT 15

enum {
  sym_Word = 1,
  anon_sym_SEMI = 2,
  anon_sym_enum = 3,
  anon_sym_LBRACE = 4,
  anon_sym_RBRACE = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  anon_sym_COMMA = 8,
  anon_sym_AMP_AMP = 9,
  anon_sym_DOT = 10,
  anon_sym_BANG = 11,
  anon_sym_DASH_GT = 12,
  anon_sym_EQ_EQ = 13,
  anon_sym_LT = 14,
  anon_sym_GT = 15,
  anon_sym_LT_EQ = 16,
  anon_sym_GT_EQ = 17,
  anon_sym_STAR = 18,
  anon_sym_SLASH = 19,
  anon_sym_PERCENT = 20,
  anon_sym_PIPE = 21,
  anon_sym_CARET = 22,
  anon_sym_DASH = 23,
  anon_sym_match = 24,
  anon_sym_PLUS = 25,
  anon_sym_fun = 26,
  aux_sym_Int_token1 = 27,
  anon_sym_let = 28,
  anon_sym_EQ = 29,
  anon_sym_EQ_GT = 30,
  aux_sym_Name_token1 = 31,
  anon_sym_COLON = 32,
  anon_sym_typedef = 33,
  sym_start = 34,
  sym_Block = 35,
  sym__Def = 36,
  sym_Def_let = 37,
  sym_Def_enum = 38,
  sym_Def_typedef = 39,
  sym_Def_fun = 40,
  sym_DefList = 41,
  sym_Enum = 42,
  sym_EnumCase = 43,
  sym_EnumCaseList = 44,
  sym__Expr = 45,
  sym_Expr_and = 46,
  sym_Expr_project = 47,
  sym_Expr_mu = 48,
  sym_Expr_eql = 49,
  sym_Expr_mul = 50,
  sym_Expr_or = 51,
  sym_Expr_name = 52,
  sym_Expr_pow = 53,
  sym_Expr_block = 54,
  sym_Expr_lambda = 55,
  sym_Expr_neg = 56,
  sym_Expr_paren = 57,
  sym_Expr_match = 58,
  sym_Expr_call = 59,
  sym_Expr_numb = 60,
  sym_Expr_add = 61,
  sym_ExprList = 62,
  sym_Fun = 63,
  sym_Int = 64,
  sym_Let = 65,
  sym_MatchCase = 66,
  sym_MatchCaseList = 67,
  sym_Name = 68,
  sym_NameList = 69,
  sym_Param = 70,
  sym_ParamList = 71,
  sym__TypeExpr = 72,
  sym_TypeExpr_name = 73,
  sym_TypeExpr_const = 74,
  sym_TypeExpr_tuple = 75,
  sym_TypeExpr_func = 76,
  sym_TypeExprList = 77,
  sym_Typedef = 78,
  aux_sym_DefList_repeat1 = 79,
  aux_sym_EnumCaseList_repeat1 = 80,
  aux_sym_ExprList_repeat1 = 81,
  aux_sym_MatchCaseList_repeat1 = 82,
  aux_sym_NameList_repeat1 = 83,
  aux_sym_ParamList_repeat1 = 84,
  aux_sym_TypeExprList_repeat1 = 85,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_Word] = "Word",
  [anon_sym_SEMI] = ";",
  [anon_sym_enum] = "enum",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COMMA] = ",",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_DOT] = ".",
  [anon_sym_BANG] = "!",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PIPE] = "|",
  [anon_sym_CARET] = "^",
  [anon_sym_DASH] = "-",
  [anon_sym_match] = "match",
  [anon_sym_PLUS] = "+",
  [anon_sym_fun] = "fun",
  [aux_sym_Int_token1] = "Int_token1",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_EQ_GT] = "=>",
  [aux_sym_Name_token1] = "Name_token1",
  [anon_sym_COLON] = ":",
  [anon_sym_typedef] = "typedef",
  [sym_start] = "start",
  [sym_Block] = "Block",
  [sym__Def] = "_Def",
  [sym_Def_let] = "Def_let",
  [sym_Def_enum] = "Def_enum",
  [sym_Def_typedef] = "Def_typedef",
  [sym_Def_fun] = "Def_fun",
  [sym_DefList] = "DefList",
  [sym_Enum] = "Enum",
  [sym_EnumCase] = "EnumCase",
  [sym_EnumCaseList] = "EnumCaseList",
  [sym__Expr] = "_Expr",
  [sym_Expr_and] = "Expr_and",
  [sym_Expr_project] = "Expr_project",
  [sym_Expr_mu] = "Expr_mu",
  [sym_Expr_eql] = "Expr_eql",
  [sym_Expr_mul] = "Expr_mul",
  [sym_Expr_or] = "Expr_or",
  [sym_Expr_name] = "Expr_name",
  [sym_Expr_pow] = "Expr_pow",
  [sym_Expr_block] = "Expr_block",
  [sym_Expr_lambda] = "Expr_lambda",
  [sym_Expr_neg] = "Expr_neg",
  [sym_Expr_paren] = "Expr_paren",
  [sym_Expr_match] = "Expr_match",
  [sym_Expr_call] = "Expr_call",
  [sym_Expr_numb] = "Expr_numb",
  [sym_Expr_add] = "Expr_add",
  [sym_ExprList] = "ExprList",
  [sym_Fun] = "Fun",
  [sym_Int] = "Int",
  [sym_Let] = "Let",
  [sym_MatchCase] = "MatchCase",
  [sym_MatchCaseList] = "MatchCaseList",
  [sym_Name] = "Name",
  [sym_NameList] = "NameList",
  [sym_Param] = "Param",
  [sym_ParamList] = "ParamList",
  [sym__TypeExpr] = "_TypeExpr",
  [sym_TypeExpr_name] = "TypeExpr_name",
  [sym_TypeExpr_const] = "TypeExpr_const",
  [sym_TypeExpr_tuple] = "TypeExpr_tuple",
  [sym_TypeExpr_func] = "TypeExpr_func",
  [sym_TypeExprList] = "TypeExprList",
  [sym_Typedef] = "Typedef",
  [aux_sym_DefList_repeat1] = "DefList_repeat1",
  [aux_sym_EnumCaseList_repeat1] = "EnumCaseList_repeat1",
  [aux_sym_ExprList_repeat1] = "ExprList_repeat1",
  [aux_sym_MatchCaseList_repeat1] = "MatchCaseList_repeat1",
  [aux_sym_NameList_repeat1] = "NameList_repeat1",
  [aux_sym_ParamList_repeat1] = "ParamList_repeat1",
  [aux_sym_TypeExprList_repeat1] = "TypeExprList_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_Word] = sym_Word,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_fun] = anon_sym_fun,
  [aux_sym_Int_token1] = aux_sym_Int_token1,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [aux_sym_Name_token1] = aux_sym_Name_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_typedef] = anon_sym_typedef,
  [sym_start] = sym_start,
  [sym_Block] = sym_Block,
  [sym__Def] = sym__Def,
  [sym_Def_let] = sym_Def_let,
  [sym_Def_enum] = sym_Def_enum,
  [sym_Def_typedef] = sym_Def_typedef,
  [sym_Def_fun] = sym_Def_fun,
  [sym_DefList] = sym_DefList,
  [sym_Enum] = sym_Enum,
  [sym_EnumCase] = sym_EnumCase,
  [sym_EnumCaseList] = sym_EnumCaseList,
  [sym__Expr] = sym__Expr,
  [sym_Expr_and] = sym_Expr_and,
  [sym_Expr_project] = sym_Expr_project,
  [sym_Expr_mu] = sym_Expr_mu,
  [sym_Expr_eql] = sym_Expr_eql,
  [sym_Expr_mul] = sym_Expr_mul,
  [sym_Expr_or] = sym_Expr_or,
  [sym_Expr_name] = sym_Expr_name,
  [sym_Expr_pow] = sym_Expr_pow,
  [sym_Expr_block] = sym_Expr_block,
  [sym_Expr_lambda] = sym_Expr_lambda,
  [sym_Expr_neg] = sym_Expr_neg,
  [sym_Expr_paren] = sym_Expr_paren,
  [sym_Expr_match] = sym_Expr_match,
  [sym_Expr_call] = sym_Expr_call,
  [sym_Expr_numb] = sym_Expr_numb,
  [sym_Expr_add] = sym_Expr_add,
  [sym_ExprList] = sym_ExprList,
  [sym_Fun] = sym_Fun,
  [sym_Int] = sym_Int,
  [sym_Let] = sym_Let,
  [sym_MatchCase] = sym_MatchCase,
  [sym_MatchCaseList] = sym_MatchCaseList,
  [sym_Name] = sym_Name,
  [sym_NameList] = sym_NameList,
  [sym_Param] = sym_Param,
  [sym_ParamList] = sym_ParamList,
  [sym__TypeExpr] = sym__TypeExpr,
  [sym_TypeExpr_name] = sym_TypeExpr_name,
  [sym_TypeExpr_const] = sym_TypeExpr_const,
  [sym_TypeExpr_tuple] = sym_TypeExpr_tuple,
  [sym_TypeExpr_func] = sym_TypeExpr_func,
  [sym_TypeExprList] = sym_TypeExprList,
  [sym_Typedef] = sym_Typedef,
  [aux_sym_DefList_repeat1] = aux_sym_DefList_repeat1,
  [aux_sym_EnumCaseList_repeat1] = aux_sym_EnumCaseList_repeat1,
  [aux_sym_ExprList_repeat1] = aux_sym_ExprList_repeat1,
  [aux_sym_MatchCaseList_repeat1] = aux_sym_MatchCaseList_repeat1,
  [aux_sym_NameList_repeat1] = aux_sym_NameList_repeat1,
  [aux_sym_ParamList_repeat1] = aux_sym_ParamList_repeat1,
  [aux_sym_TypeExprList_repeat1] = aux_sym_TypeExprList_repeat1,
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
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
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
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
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
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_match] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fun] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_Int_token1] = {
    .visible = false,
    .named = false,
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
  [aux_sym_Name_token1] = {
    .visible = false,
    .named = false,
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
  [sym__Def] = {
    .visible = false,
    .named = true,
  },
  [sym_Def_let] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_typedef] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_fun] = {
    .visible = true,
    .named = true,
  },
  [sym_DefList] = {
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
  [sym_EnumCaseList] = {
    .visible = true,
    .named = true,
  },
  [sym__Expr] = {
    .visible = false,
    .named = true,
  },
  [sym_Expr_and] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_project] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_mu] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_eql] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_mul] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_or] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_name] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_pow] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_block] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_lambda] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_neg] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_paren] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_match] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_call] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_numb] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_add] = {
    .visible = true,
    .named = true,
  },
  [sym_ExprList] = {
    .visible = true,
    .named = true,
  },
  [sym_Fun] = {
    .visible = true,
    .named = true,
  },
  [sym_Int] = {
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
  [sym_MatchCaseList] = {
    .visible = true,
    .named = true,
  },
  [sym_Name] = {
    .visible = true,
    .named = true,
  },
  [sym_NameList] = {
    .visible = true,
    .named = true,
  },
  [sym_Param] = {
    .visible = true,
    .named = true,
  },
  [sym_ParamList] = {
    .visible = true,
    .named = true,
  },
  [sym__TypeExpr] = {
    .visible = false,
    .named = true,
  },
  [sym_TypeExpr_name] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExpr_const] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExpr_tuple] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExpr_func] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExprList] = {
    .visible = true,
    .named = true,
  },
  [sym_Typedef] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_DefList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_EnumCaseList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ExprList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_MatchCaseList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_NameList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ParamList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_TypeExprList_repeat1] = {
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
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 3},
  [8] = {.index = 12, .length = 2},
  [9] = {.index = 14, .length = 2},
  [10] = {.index = 16, .length = 2},
  [11] = {.index = 18, .length = 3},
  [12] = {.index = 21, .length = 2},
  [13] = {.index = 23, .length = 3},
  [14] = {.index = 26, .length = 4},
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
    {field_0, 1, .inherited = true},
  [7] =
    {field_0, 0},
    {field_0, 2, .inherited = true},
  [9] =
    {field_0, 0},
    {field_1, 1},
    {field_2, 2},
  [12] =
    {field_0, 0},
    {field_1, 2},
  [14] =
    {field_0, 0, .inherited = true},
    {field_0, 1, .inherited = true},
  [16] =
    {field_0, 1},
    {field_1, 3},
  [18] =
    {field_0, 1},
    {field_1, 3},
    {field_2, 5},
  [21] =
    {field_0, 0},
    {field_2, 2},
  [23] =
    {field_0, 0},
    {field_1, 1},
    {field_2, 3},
  [26] =
    {field_0, 1},
    {field_1, 3},
    {field_2, 6},
    {field_3, 8},
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
      if (eof) ADVANCE(12);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '%') ADVANCE(44);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(55);
      if (lookahead == ',') ADVANCE(20);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(42);
      if (lookahead == ':') ADVANCE(103);
      if (lookahead == ';') ADVANCE(13);
      if (lookahead == '<') ADVANCE(32);
      if (lookahead == '=') ADVANCE(63);
      if (lookahead == '>') ADVANCE(34);
      if (lookahead == '^') ADVANCE(48);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(82);
      if (lookahead == 'l') ADVANCE(70);
      if (lookahead == 'm') ADVANCE(67);
      if (lookahead == 't') ADVANCE(83);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '|') ADVANCE(46);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '%') ADVANCE(44);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(55);
      if (lookahead == ',') ADVANCE(20);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(42);
      if (lookahead == ':') ADVANCE(103);
      if (lookahead == ';') ADVANCE(13);
      if (lookahead == '<') ADVANCE(32);
      if (lookahead == '=') ADVANCE(63);
      if (lookahead == '>') ADVANCE(34);
      if (lookahead == '^') ADVANCE(48);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(82);
      if (lookahead == 'l') ADVANCE(70);
      if (lookahead == 'm') ADVANCE(67);
      if (lookahead == 't') ADVANCE(83);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '|') ADVANCE(46);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(27);
      if (lookahead == '%') ADVANCE(45);
      if (lookahead == '&') ADVANCE(107);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(41);
      if (lookahead == '+') ADVANCE(56);
      if (lookahead == ',') ADVANCE(21);
      if (lookahead == '-') ADVANCE(52);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '/') ADVANCE(43);
      if (lookahead == ':') ADVANCE(103);
      if (lookahead == ';') ADVANCE(13);
      if (lookahead == '<') ADVANCE(33);
      if (lookahead == '=') ADVANCE(64);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '^') ADVANCE(49);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(82);
      if (lookahead == 'l') ADVANCE(70);
      if (lookahead == 'm') ADVANCE(67);
      if (lookahead == 't') ADVANCE(83);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '|') ADVANCE(47);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '#' ||
          lookahead == '~') ADVANCE(108);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '-') ADVANCE(50);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 4:
      if (lookahead == '&') ADVANCE(22);
      END_STATE();
    case 5:
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == ',') ADVANCE(20);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == ';') ADVANCE(13);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '>') ADVANCE(65);
      END_STATE();
    case 7:
      if (lookahead == '=') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(28);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(65);
      END_STATE();
    case 10:
      if (eof) ADVANCE(12);
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '%') ADVANCE(44);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(55);
      if (lookahead == ',') ADVANCE(20);
      if (lookahead == '-') ADVANCE(50);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(42);
      if (lookahead == ';') ADVANCE(13);
      if (lookahead == '<') ADVANCE(32);
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '>') ADVANCE(34);
      if (lookahead == '^') ADVANCE(48);
      if (lookahead == 'e') ADVANCE(95);
      if (lookahead == 'f') ADVANCE(100);
      if (lookahead == 'l') ADVANCE(88);
      if (lookahead == 'm') ADVANCE(85);
      if (lookahead == 't') ADVANCE(101);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '|') ADVANCE(46);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 11:
      if (eof) ADVANCE(12);
      if (lookahead == '%') ADVANCE(44);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(55);
      if (lookahead == ',') ADVANCE(20);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(42);
      if (lookahead == ':') ADVANCE(103);
      if (lookahead == ';') ADVANCE(13);
      if (lookahead == '<') ADVANCE(32);
      if (lookahead == '=') ADVANCE(63);
      if (lookahead == '>') ADVANCE(34);
      if (lookahead == '^') ADVANCE(48);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '|') ADVANCE(46);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_enum);
      if (lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_enum);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(36);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(37);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(38);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(39);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(28);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(29);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          lookahead == '<' ||
          lookahead == '=' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_match);
      if (lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_match);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_fun);
      if (lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_fun);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_Int_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '>') ADVANCE(65);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(66);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          lookahead == '<' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'a') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'c') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'd') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'e') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'e') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'e') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'f') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'h') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'm') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'n') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'n') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'p') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 't') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 't') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'u') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'u') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (lookahead == 'y') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'a') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'c') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'd') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'e') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'e') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'e') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'f') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'h') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'm') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'n') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'n') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'p') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 't') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 't') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'u') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'u') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'y') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_typedef);
      if (lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(84);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_typedef);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_Word);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '&') ADVANCE(23);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
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
  [1] = {.lex_state = 10},
  [2] = {.lex_state = 10},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 11},
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
  [22] = {.lex_state = 10},
  [23] = {.lex_state = 10},
  [24] = {.lex_state = 10},
  [25] = {.lex_state = 10},
  [26] = {.lex_state = 10},
  [27] = {.lex_state = 10},
  [28] = {.lex_state = 10},
  [29] = {.lex_state = 10},
  [30] = {.lex_state = 10},
  [31] = {.lex_state = 10},
  [32] = {.lex_state = 10},
  [33] = {.lex_state = 10},
  [34] = {.lex_state = 10},
  [35] = {.lex_state = 10},
  [36] = {.lex_state = 10},
  [37] = {.lex_state = 10},
  [38] = {.lex_state = 10},
  [39] = {.lex_state = 10},
  [40] = {.lex_state = 10},
  [41] = {.lex_state = 10},
  [42] = {.lex_state = 10},
  [43] = {.lex_state = 10},
  [44] = {.lex_state = 10},
  [45] = {.lex_state = 10},
  [46] = {.lex_state = 10},
  [47] = {.lex_state = 10},
  [48] = {.lex_state = 10},
  [49] = {.lex_state = 10},
  [50] = {.lex_state = 10},
  [51] = {.lex_state = 10},
  [52] = {.lex_state = 10},
  [53] = {.lex_state = 10},
  [54] = {.lex_state = 11},
  [55] = {.lex_state = 11},
  [56] = {.lex_state = 11},
  [57] = {.lex_state = 11},
  [58] = {.lex_state = 5},
  [59] = {.lex_state = 11},
  [60] = {.lex_state = 11},
  [61] = {.lex_state = 11},
  [62] = {.lex_state = 11},
  [63] = {.lex_state = 11},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 5},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 5},
  [68] = {.lex_state = 5},
  [69] = {.lex_state = 5},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 11},
  [72] = {.lex_state = 11},
  [73] = {.lex_state = 5},
  [74] = {.lex_state = 11},
  [75] = {.lex_state = 11},
  [76] = {.lex_state = 11},
  [77] = {.lex_state = 11},
  [78] = {.lex_state = 7},
  [79] = {.lex_state = 5},
  [80] = {.lex_state = 5},
  [81] = {.lex_state = 5},
  [82] = {.lex_state = 10},
  [83] = {.lex_state = 10},
  [84] = {.lex_state = 10},
  [85] = {.lex_state = 10},
  [86] = {.lex_state = 5},
  [87] = {.lex_state = 10},
  [88] = {.lex_state = 10},
  [89] = {.lex_state = 10},
  [90] = {.lex_state = 10},
  [91] = {.lex_state = 10},
  [92] = {.lex_state = 10},
  [93] = {.lex_state = 10},
  [94] = {.lex_state = 11},
  [95] = {.lex_state = 10},
  [96] = {.lex_state = 10},
  [97] = {.lex_state = 10},
  [98] = {.lex_state = 11},
  [99] = {.lex_state = 11},
  [100] = {.lex_state = 11},
  [101] = {.lex_state = 11},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 11},
  [104] = {.lex_state = 5},
  [105] = {.lex_state = 5},
  [106] = {.lex_state = 10},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 11},
  [109] = {.lex_state = 11},
  [110] = {.lex_state = 5},
  [111] = {.lex_state = 10},
  [112] = {.lex_state = 10},
  [113] = {.lex_state = 5},
  [114] = {.lex_state = 10},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 5},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 3},
  [130] = {.lex_state = 10},
  [131] = {.lex_state = 3},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 5},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
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
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_fun] = ACTIONS(1),
    [aux_sym_Int_token1] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [aux_sym_Name_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_typedef] = ACTIONS(1),
  },
  [1] = {
    [sym_start] = STATE(126),
    [sym_Block] = STATE(124),
    [sym__Def] = STATE(142),
    [sym_Def_let] = STATE(142),
    [sym_Def_enum] = STATE(142),
    [sym_Def_typedef] = STATE(142),
    [sym_Def_fun] = STATE(142),
    [sym_DefList] = STATE(16),
    [sym_Enum] = STATE(141),
    [sym__Expr] = STATE(47),
    [sym_Expr_and] = STATE(47),
    [sym_Expr_project] = STATE(47),
    [sym_Expr_mu] = STATE(47),
    [sym_Expr_eql] = STATE(47),
    [sym_Expr_mul] = STATE(47),
    [sym_Expr_or] = STATE(47),
    [sym_Expr_name] = STATE(47),
    [sym_Expr_pow] = STATE(47),
    [sym_Expr_block] = STATE(47),
    [sym_Expr_lambda] = STATE(47),
    [sym_Expr_neg] = STATE(47),
    [sym_Expr_paren] = STATE(47),
    [sym_Expr_match] = STATE(47),
    [sym_Expr_call] = STATE(47),
    [sym_Expr_numb] = STATE(47),
    [sym_Expr_add] = STATE(47),
    [sym_Fun] = STATE(140),
    [sym_Int] = STATE(29),
    [sym_Let] = STATE(137),
    [sym_Name] = STATE(31),
    [sym_Typedef] = STATE(116),
    [anon_sym_enum] = ACTIONS(3),
    [anon_sym_LBRACE] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(9),
    [anon_sym_DASH] = ACTIONS(11),
    [anon_sym_match] = ACTIONS(13),
    [anon_sym_fun] = ACTIONS(15),
    [aux_sym_Int_token1] = ACTIONS(17),
    [anon_sym_let] = ACTIONS(19),
    [aux_sym_Name_token1] = ACTIONS(21),
    [anon_sym_typedef] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 21,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(16), 1,
      sym_DefList,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(116), 1,
      sym_Typedef,
    STATE(128), 1,
      sym_Block,
    STATE(137), 1,
      sym_Let,
    STATE(140), 1,
      sym_Fun,
    STATE(141), 1,
      sym_Enum,
    STATE(142), 5,
      sym__Def,
      sym_Def_let,
      sym_Def_enum,
      sym_Def_typedef,
      sym_Def_fun,
    STATE(47), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [84] = 12,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(139), 1,
      sym_ExprList,
    STATE(44), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [137] = 12,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    ACTIONS(27), 1,
      anon_sym_RPAREN,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(125), 1,
      sym_ExprList,
    STATE(44), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [190] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(25), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [237] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(41), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [284] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(50), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [331] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(49), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [378] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(45), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [425] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(51), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [472] = 2,
    ACTIONS(31), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_EQ,
    ACTIONS(29), 22,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_EQ_GT,
      aux_sym_Name_token1,
      anon_sym_COLON,
  [503] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(37), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [550] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(36), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [597] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(52), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [644] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(32), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [691] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(48), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [738] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(30), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [785] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(28), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [832] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(27), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [879] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(26), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [926] = 10,
    ACTIONS(5), 1,
      anon_sym_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_match,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    ACTIONS(21), 1,
      aux_sym_Name_token1,
    STATE(29), 1,
      sym_Int,
    STATE(31), 1,
      sym_Name,
    STATE(46), 17,
      sym__Expr,
      sym_Expr_and,
      sym_Expr_project,
      sym_Expr_mu,
      sym_Expr_eql,
      sym_Expr_mul,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_pow,
      sym_Expr_block,
      sym_Expr_lambda,
      sym_Expr_neg,
      sym_Expr_paren,
      sym_Expr_match,
      sym_Expr_call,
      sym_Expr_numb,
      sym_Expr_add,
  [973] = 2,
    ACTIONS(35), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(33), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [999] = 12,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(40), 1,
      aux_sym_DefList_repeat1,
    STATE(116), 1,
      sym_Typedef,
    STATE(137), 1,
      sym_Let,
    STATE(140), 1,
      sym_Fun,
    STATE(141), 1,
      sym_Enum,
    ACTIONS(39), 2,
      anon_sym_match,
      aux_sym_Name_token1,
    ACTIONS(37), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    STATE(136), 5,
      sym__Def,
      sym_Def_let,
      sym_Def_enum,
      sym_Def_typedef,
      sym_Def_fun,
  [1045] = 12,
    ACTIONS(41), 1,
      anon_sym_enum,
    ACTIONS(48), 1,
      anon_sym_fun,
    ACTIONS(51), 1,
      anon_sym_let,
    ACTIONS(54), 1,
      anon_sym_typedef,
    STATE(24), 1,
      aux_sym_DefList_repeat1,
    STATE(116), 1,
      sym_Typedef,
    STATE(137), 1,
      sym_Let,
    STATE(140), 1,
      sym_Fun,
    STATE(141), 1,
      sym_Enum,
    ACTIONS(46), 2,
      anon_sym_match,
      aux_sym_Name_token1,
    ACTIONS(44), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    STATE(136), 5,
      sym__Def,
      sym_Def_let,
      sym_Def_enum,
      sym_Def_typedef,
      sym_Def_fun,
  [1091] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(57), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1133] = 6,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(79), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(77), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PIPE,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1167] = 4,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(83), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(81), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1197] = 8,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(87), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(85), 10,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PIPE,
  [1235] = 2,
    ACTIONS(91), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(89), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1261] = 5,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(95), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(93), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1293] = 2,
    ACTIONS(99), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(97), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1319] = 9,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 9,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1359] = 2,
    ACTIONS(107), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(105), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1385] = 2,
    ACTIONS(111), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(109), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1411] = 2,
    ACTIONS(115), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(113), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1437] = 7,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(119), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(117), 11,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PIPE,
  [1473] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(121), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1515] = 2,
    ACTIONS(125), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(123), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1541] = 2,
    ACTIONS(129), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(127), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1567] = 12,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(24), 1,
      aux_sym_DefList_repeat1,
    STATE(116), 1,
      sym_Typedef,
    STATE(137), 1,
      sym_Let,
    STATE(140), 1,
      sym_Fun,
    STATE(141), 1,
      sym_Enum,
    ACTIONS(133), 2,
      anon_sym_match,
      aux_sym_Name_token1,
    ACTIONS(131), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    STATE(136), 5,
      sym__Def,
      sym_Def_let,
      sym_Def_enum,
      sym_Def_typedef,
      sym_Def_fun,
  [1613] = 4,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(137), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(135), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1643] = 2,
    ACTIONS(141), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(139), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1669] = 2,
    ACTIONS(145), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(143), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_DASH,
      anon_sym_PLUS,
  [1695] = 12,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(147), 1,
      anon_sym_RPAREN,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    STATE(96), 1,
      aux_sym_ExprList_repeat1,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1738] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(151), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1776] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(153), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1814] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(155), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1852] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1890] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(159), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1928] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(161), 1,
      anon_sym_LBRACE,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1965] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(163), 1,
      anon_sym_RBRACE,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2002] = 10,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_AMP_AMP,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(71), 1,
      anon_sym_PIPE,
    ACTIONS(73), 1,
      anon_sym_CARET,
    ACTIONS(165), 1,
      anon_sym_SEMI,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(75), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(69), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2039] = 2,
    ACTIONS(169), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    ACTIONS(167), 6,
      anon_sym_enum,
      anon_sym_match,
      anon_sym_fun,
      anon_sym_let,
      aux_sym_Name_token1,
      anon_sym_typedef,
  [2055] = 6,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      anon_sym_RPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(135), 1,
      sym_TypeExprList,
    STATE(73), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2078] = 6,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    ACTIONS(177), 1,
      anon_sym_RPAREN,
    STATE(58), 1,
      sym_Name,
    STATE(120), 1,
      sym_TypeExprList,
    STATE(73), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2101] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(105), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2118] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(104), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2135] = 2,
    ACTIONS(181), 1,
      anon_sym_LPAREN,
    ACTIONS(179), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [2148] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(65), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2165] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(70), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2182] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(113), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2199] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(110), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2216] = 4,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(58), 1,
      sym_Name,
    STATE(86), 5,
      sym__TypeExpr,
      sym_TypeExpr_name,
      sym_TypeExpr_const,
      sym_TypeExpr_tuple,
      sym_TypeExpr_func,
  [2233] = 1,
    ACTIONS(183), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [2243] = 1,
    ACTIONS(185), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [2253] = 1,
    ACTIONS(187), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [2263] = 1,
    ACTIONS(189), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [2273] = 1,
    ACTIONS(191), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [2283] = 3,
    ACTIONS(195), 1,
      anon_sym_COMMA,
    STATE(80), 1,
      aux_sym_ParamList_repeat1,
    ACTIONS(193), 2,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
  [2294] = 2,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(197), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ,
  [2303] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(69), 1,
      sym_Param,
    STATE(118), 1,
      sym_Name,
    STATE(123), 1,
      sym_ParamList,
  [2316] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(91), 1,
      sym_Name,
    STATE(93), 1,
      sym_EnumCase,
    STATE(117), 1,
      sym_EnumCaseList,
  [2329] = 4,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(201), 1,
      anon_sym_RPAREN,
    ACTIONS(203), 1,
      anon_sym_COMMA,
    STATE(90), 1,
      aux_sym_TypeExprList_repeat1,
  [2342] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(69), 1,
      sym_Param,
    STATE(102), 1,
      sym_Name,
    STATE(121), 1,
      sym_ParamList,
  [2355] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(69), 1,
      sym_Param,
    STATE(118), 1,
      sym_Name,
    STATE(127), 1,
      sym_ParamList,
  [2368] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(69), 1,
      sym_Param,
    STATE(118), 1,
      sym_Name,
    STATE(132), 1,
      sym_ParamList,
  [2381] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(78), 1,
      sym_Name,
    STATE(85), 1,
      sym_MatchCase,
    STATE(133), 1,
      sym_MatchCaseList,
  [2394] = 4,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    ACTIONS(205), 1,
      anon_sym_EQ_GT,
    STATE(97), 1,
      sym_Name,
    STATE(130), 1,
      sym_NameList,
  [2407] = 3,
    ACTIONS(209), 1,
      anon_sym_COMMA,
    STATE(79), 1,
      aux_sym_ParamList_repeat1,
    ACTIONS(207), 2,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
  [2418] = 3,
    ACTIONS(195), 1,
      anon_sym_COMMA,
    STATE(79), 1,
      aux_sym_ParamList_repeat1,
    ACTIONS(212), 2,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
  [2429] = 1,
    ACTIONS(214), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
  [2435] = 3,
    ACTIONS(216), 1,
      anon_sym_RBRACE,
    ACTIONS(218), 1,
      anon_sym_COMMA,
    STATE(88), 1,
      aux_sym_MatchCaseList_repeat1,
  [2445] = 3,
    ACTIONS(220), 1,
      anon_sym_COMMA,
    ACTIONS(223), 1,
      anon_sym_EQ_GT,
    STATE(83), 1,
      aux_sym_NameList_repeat1,
  [2455] = 3,
    ACTIONS(225), 1,
      anon_sym_RPAREN,
    ACTIONS(227), 1,
      anon_sym_COMMA,
    STATE(84), 1,
      aux_sym_TypeExprList_repeat1,
  [2465] = 3,
    ACTIONS(218), 1,
      anon_sym_COMMA,
    ACTIONS(230), 1,
      anon_sym_RBRACE,
    STATE(82), 1,
      aux_sym_MatchCaseList_repeat1,
  [2475] = 2,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(232), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2483] = 3,
    ACTIONS(234), 1,
      anon_sym_COMMA,
    ACTIONS(236), 1,
      anon_sym_EQ_GT,
    STATE(83), 1,
      aux_sym_NameList_repeat1,
  [2493] = 3,
    ACTIONS(238), 1,
      anon_sym_RBRACE,
    ACTIONS(240), 1,
      anon_sym_COMMA,
    STATE(88), 1,
      aux_sym_MatchCaseList_repeat1,
  [2503] = 3,
    ACTIONS(243), 1,
      anon_sym_RPAREN,
    ACTIONS(245), 1,
      anon_sym_COMMA,
    STATE(89), 1,
      aux_sym_ExprList_repeat1,
  [2513] = 3,
    ACTIONS(203), 1,
      anon_sym_COMMA,
    ACTIONS(248), 1,
      anon_sym_RPAREN,
    STATE(84), 1,
      aux_sym_TypeExprList_repeat1,
  [2523] = 2,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
    ACTIONS(250), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2531] = 3,
    ACTIONS(254), 1,
      anon_sym_RBRACE,
    ACTIONS(256), 1,
      anon_sym_COMMA,
    STATE(92), 1,
      aux_sym_EnumCaseList_repeat1,
  [2541] = 3,
    ACTIONS(259), 1,
      anon_sym_RBRACE,
    ACTIONS(261), 1,
      anon_sym_COMMA,
    STATE(95), 1,
      aux_sym_EnumCaseList_repeat1,
  [2551] = 3,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(91), 1,
      sym_Name,
    STATE(112), 1,
      sym_EnumCase,
  [2561] = 3,
    ACTIONS(261), 1,
      anon_sym_COMMA,
    ACTIONS(263), 1,
      anon_sym_RBRACE,
    STATE(92), 1,
      aux_sym_EnumCaseList_repeat1,
  [2571] = 3,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    ACTIONS(265), 1,
      anon_sym_RPAREN,
    STATE(89), 1,
      aux_sym_ExprList_repeat1,
  [2581] = 3,
    ACTIONS(234), 1,
      anon_sym_COMMA,
    ACTIONS(267), 1,
      anon_sym_EQ_GT,
    STATE(87), 1,
      aux_sym_NameList_repeat1,
  [2591] = 3,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(118), 1,
      sym_Name,
    STATE(129), 1,
      sym_Param,
  [2601] = 3,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(78), 1,
      sym_Name,
    STATE(114), 1,
      sym_MatchCase,
  [2611] = 3,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(81), 1,
      sym_Param,
    STATE(118), 1,
      sym_Name,
  [2621] = 2,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(106), 1,
      sym_Name,
  [2628] = 2,
    ACTIONS(269), 1,
      anon_sym_LPAREN,
    ACTIONS(271), 1,
      anon_sym_COLON,
  [2635] = 2,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(119), 1,
      sym_Name,
  [2642] = 2,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(273), 1,
      anon_sym_LBRACE,
  [2649] = 2,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(275), 1,
      anon_sym_DOT,
  [2656] = 1,
    ACTIONS(277), 2,
      anon_sym_COMMA,
      anon_sym_EQ_GT,
  [2661] = 2,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    STATE(34), 1,
      sym_Int,
  [2668] = 2,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(115), 1,
      sym_Name,
  [2675] = 2,
    ACTIONS(175), 1,
      aux_sym_Name_token1,
    STATE(131), 1,
      sym_Name,
  [2682] = 2,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(279), 1,
      anon_sym_DOT,
  [2689] = 1,
    ACTIONS(281), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2694] = 1,
    ACTIONS(283), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2699] = 2,
    ACTIONS(199), 1,
      anon_sym_DASH_GT,
    ACTIONS(285), 1,
      anon_sym_SEMI,
  [2706] = 1,
    ACTIONS(287), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2711] = 1,
    ACTIONS(289), 1,
      anon_sym_LBRACE,
  [2715] = 1,
    ACTIONS(291), 1,
      anon_sym_SEMI,
  [2719] = 1,
    ACTIONS(293), 1,
      anon_sym_RBRACE,
  [2723] = 1,
    ACTIONS(271), 1,
      anon_sym_COLON,
  [2727] = 1,
    ACTIONS(295), 1,
      anon_sym_LPAREN,
  [2731] = 1,
    ACTIONS(297), 1,
      anon_sym_RPAREN,
  [2735] = 1,
    ACTIONS(299), 1,
      anon_sym_DASH_GT,
  [2739] = 1,
    ACTIONS(301), 1,
      anon_sym_SEMI,
  [2743] = 1,
    ACTIONS(303), 1,
      anon_sym_RPAREN,
  [2747] = 1,
    ACTIONS(305), 1,
      ts_builtin_sym_end,
  [2751] = 1,
    ACTIONS(307), 1,
      anon_sym_RPAREN,
  [2755] = 1,
    ACTIONS(309), 1,
      ts_builtin_sym_end,
  [2759] = 1,
    ACTIONS(311), 1,
      anon_sym_RPAREN,
  [2763] = 1,
    ACTIONS(313), 1,
      anon_sym_RBRACE,
  [2767] = 1,
    ACTIONS(315), 1,
      anon_sym_EQ,
  [2771] = 1,
    ACTIONS(317), 1,
      anon_sym_EQ_GT,
  [2775] = 1,
    ACTIONS(319), 1,
      anon_sym_EQ,
  [2779] = 1,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
  [2783] = 1,
    ACTIONS(323), 1,
      anon_sym_RBRACE,
  [2787] = 1,
    ACTIONS(325), 1,
      anon_sym_DASH_GT,
  [2791] = 1,
    ACTIONS(327), 1,
      anon_sym_RPAREN,
  [2795] = 1,
    ACTIONS(329), 1,
      anon_sym_SEMI,
  [2799] = 1,
    ACTIONS(331), 1,
      anon_sym_SEMI,
  [2803] = 1,
    ACTIONS(333), 1,
      anon_sym_DASH_GT,
  [2807] = 1,
    ACTIONS(335), 1,
      anon_sym_RPAREN,
  [2811] = 1,
    ACTIONS(337), 1,
      anon_sym_SEMI,
  [2815] = 1,
    ACTIONS(339), 1,
      anon_sym_SEMI,
  [2819] = 1,
    ACTIONS(341), 1,
      anon_sym_SEMI,
  [2823] = 1,
    ACTIONS(343), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 84,
  [SMALL_STATE(4)] = 137,
  [SMALL_STATE(5)] = 190,
  [SMALL_STATE(6)] = 237,
  [SMALL_STATE(7)] = 284,
  [SMALL_STATE(8)] = 331,
  [SMALL_STATE(9)] = 378,
  [SMALL_STATE(10)] = 425,
  [SMALL_STATE(11)] = 472,
  [SMALL_STATE(12)] = 503,
  [SMALL_STATE(13)] = 550,
  [SMALL_STATE(14)] = 597,
  [SMALL_STATE(15)] = 644,
  [SMALL_STATE(16)] = 691,
  [SMALL_STATE(17)] = 738,
  [SMALL_STATE(18)] = 785,
  [SMALL_STATE(19)] = 832,
  [SMALL_STATE(20)] = 879,
  [SMALL_STATE(21)] = 926,
  [SMALL_STATE(22)] = 973,
  [SMALL_STATE(23)] = 999,
  [SMALL_STATE(24)] = 1045,
  [SMALL_STATE(25)] = 1091,
  [SMALL_STATE(26)] = 1133,
  [SMALL_STATE(27)] = 1167,
  [SMALL_STATE(28)] = 1197,
  [SMALL_STATE(29)] = 1235,
  [SMALL_STATE(30)] = 1261,
  [SMALL_STATE(31)] = 1293,
  [SMALL_STATE(32)] = 1319,
  [SMALL_STATE(33)] = 1359,
  [SMALL_STATE(34)] = 1385,
  [SMALL_STATE(35)] = 1411,
  [SMALL_STATE(36)] = 1437,
  [SMALL_STATE(37)] = 1473,
  [SMALL_STATE(38)] = 1515,
  [SMALL_STATE(39)] = 1541,
  [SMALL_STATE(40)] = 1567,
  [SMALL_STATE(41)] = 1613,
  [SMALL_STATE(42)] = 1643,
  [SMALL_STATE(43)] = 1669,
  [SMALL_STATE(44)] = 1695,
  [SMALL_STATE(45)] = 1738,
  [SMALL_STATE(46)] = 1776,
  [SMALL_STATE(47)] = 1814,
  [SMALL_STATE(48)] = 1852,
  [SMALL_STATE(49)] = 1890,
  [SMALL_STATE(50)] = 1928,
  [SMALL_STATE(51)] = 1965,
  [SMALL_STATE(52)] = 2002,
  [SMALL_STATE(53)] = 2039,
  [SMALL_STATE(54)] = 2055,
  [SMALL_STATE(55)] = 2078,
  [SMALL_STATE(56)] = 2101,
  [SMALL_STATE(57)] = 2118,
  [SMALL_STATE(58)] = 2135,
  [SMALL_STATE(59)] = 2148,
  [SMALL_STATE(60)] = 2165,
  [SMALL_STATE(61)] = 2182,
  [SMALL_STATE(62)] = 2199,
  [SMALL_STATE(63)] = 2216,
  [SMALL_STATE(64)] = 2233,
  [SMALL_STATE(65)] = 2243,
  [SMALL_STATE(66)] = 2253,
  [SMALL_STATE(67)] = 2263,
  [SMALL_STATE(68)] = 2273,
  [SMALL_STATE(69)] = 2283,
  [SMALL_STATE(70)] = 2294,
  [SMALL_STATE(71)] = 2303,
  [SMALL_STATE(72)] = 2316,
  [SMALL_STATE(73)] = 2329,
  [SMALL_STATE(74)] = 2342,
  [SMALL_STATE(75)] = 2355,
  [SMALL_STATE(76)] = 2368,
  [SMALL_STATE(77)] = 2381,
  [SMALL_STATE(78)] = 2394,
  [SMALL_STATE(79)] = 2407,
  [SMALL_STATE(80)] = 2418,
  [SMALL_STATE(81)] = 2429,
  [SMALL_STATE(82)] = 2435,
  [SMALL_STATE(83)] = 2445,
  [SMALL_STATE(84)] = 2455,
  [SMALL_STATE(85)] = 2465,
  [SMALL_STATE(86)] = 2475,
  [SMALL_STATE(87)] = 2483,
  [SMALL_STATE(88)] = 2493,
  [SMALL_STATE(89)] = 2503,
  [SMALL_STATE(90)] = 2513,
  [SMALL_STATE(91)] = 2523,
  [SMALL_STATE(92)] = 2531,
  [SMALL_STATE(93)] = 2541,
  [SMALL_STATE(94)] = 2551,
  [SMALL_STATE(95)] = 2561,
  [SMALL_STATE(96)] = 2571,
  [SMALL_STATE(97)] = 2581,
  [SMALL_STATE(98)] = 2591,
  [SMALL_STATE(99)] = 2601,
  [SMALL_STATE(100)] = 2611,
  [SMALL_STATE(101)] = 2621,
  [SMALL_STATE(102)] = 2628,
  [SMALL_STATE(103)] = 2635,
  [SMALL_STATE(104)] = 2642,
  [SMALL_STATE(105)] = 2649,
  [SMALL_STATE(106)] = 2656,
  [SMALL_STATE(107)] = 2661,
  [SMALL_STATE(108)] = 2668,
  [SMALL_STATE(109)] = 2675,
  [SMALL_STATE(110)] = 2682,
  [SMALL_STATE(111)] = 2689,
  [SMALL_STATE(112)] = 2694,
  [SMALL_STATE(113)] = 2699,
  [SMALL_STATE(114)] = 2706,
  [SMALL_STATE(115)] = 2711,
  [SMALL_STATE(116)] = 2715,
  [SMALL_STATE(117)] = 2719,
  [SMALL_STATE(118)] = 2723,
  [SMALL_STATE(119)] = 2727,
  [SMALL_STATE(120)] = 2731,
  [SMALL_STATE(121)] = 2735,
  [SMALL_STATE(122)] = 2739,
  [SMALL_STATE(123)] = 2743,
  [SMALL_STATE(124)] = 2747,
  [SMALL_STATE(125)] = 2751,
  [SMALL_STATE(126)] = 2755,
  [SMALL_STATE(127)] = 2759,
  [SMALL_STATE(128)] = 2763,
  [SMALL_STATE(129)] = 2767,
  [SMALL_STATE(130)] = 2771,
  [SMALL_STATE(131)] = 2775,
  [SMALL_STATE(132)] = 2779,
  [SMALL_STATE(133)] = 2783,
  [SMALL_STATE(134)] = 2787,
  [SMALL_STATE(135)] = 2791,
  [SMALL_STATE(136)] = 2795,
  [SMALL_STATE(137)] = 2799,
  [SMALL_STATE(138)] = 2803,
  [SMALL_STATE(139)] = 2807,
  [SMALL_STATE(140)] = 2811,
  [SMALL_STATE(141)] = 2815,
  [SMALL_STATE(142)] = 2819,
  [SMALL_STATE(143)] = 2823,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Name, 1, .production_id = 1),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Name, 1, .production_id = 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_match, 5, .production_id = 10),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_match, 5, .production_id = 10),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DefList, 2, .production_id = 1),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DefList, 2, .production_id = 1),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(108),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(103),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(98),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(109),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mu, 9, .production_id = 14),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_add, 3, .production_id = 7),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_add, 3, .production_id = 7),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_pow, 3, .production_id = 7),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_pow, 3, .production_id = 7),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_or, 3, .production_id = 7),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_or, 3, .production_id = 7),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_numb, 1, .production_id = 1),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_numb, 1, .production_id = 1),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mul, 3, .production_id = 7),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_mul, 3, .production_id = 7),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_name, 1, .production_id = 1),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_name, 1, .production_id = 1),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_eql, 3, .production_id = 7),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_eql, 3, .production_id = 7),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Int, 1, .production_id = 1),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Int, 1, .production_id = 1),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_project, 3, .production_id = 8),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_project, 3, .production_id = 8),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 2),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_paren, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_and, 3, .production_id = 7),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_and, 3, .production_id = 7),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_lambda, 6, .production_id = 11),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_call, 4, .production_id = 8),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_call, 4, .production_id = 8),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_call, 3, .production_id = 1),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_call, 3, .production_id = 1),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DefList, 3, .production_id = 6),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DefList, 3, .production_id = 6),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_neg, 2, .production_id = 3),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_neg, 2, .production_id = 3),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 3, .production_id = 4),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_paren, 3, .production_id = 4),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_block, 3, .production_id = 4),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_block, 3, .production_id = 4),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 1, .production_id = 1),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCase, 3, .production_id = 12),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 4),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 1, .production_id = 2),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 2, .production_id = 3),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCase, 4, .production_id = 13),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Let, 4, .production_id = 10),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 1),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 1),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_name, 1, .production_id = 1),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_const, 3, .production_id = 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_func, 3, .production_id = 8),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_tuple, 2),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_const, 4, .production_id = 8),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_tuple, 3, .production_id = 4),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamList, 1, .production_id = 1),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Param, 3, .production_id = 8),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExprList, 1, .production_id = 1),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ParamList_repeat1, 2, .production_id = 9),
  [209] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ParamList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(100),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamList, 2, .production_id = 5),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ParamList_repeat1, 2, .production_id = 4),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCaseList, 2, .production_id = 5),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_NameList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(101),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_NameList_repeat1, 2, .production_id = 9),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_TypeExprList_repeat1, 2, .production_id = 9),
  [227] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_TypeExprList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(63),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCaseList, 1, .production_id = 1),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_TypeExprList_repeat1, 2, .production_id = 4),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameList, 2, .production_id = 5),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_MatchCaseList_repeat1, 2, .production_id = 9),
  [240] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_MatchCaseList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(99),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 9),
  [245] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(21),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExprList, 2, .production_id = 5),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCase, 1, .production_id = 1),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_EnumCaseList_repeat1, 2, .production_id = 9),
  [256] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_EnumCaseList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(94),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCaseList, 1, .production_id = 1),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCaseList, 2, .production_id = 5),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 2, .production_id = 5),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameList, 1, .production_id = 1),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_NameList_repeat1, 2, .production_id = 4),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCase, 4, .production_id = 8),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_EnumCaseList_repeat1, 2, .production_id = 4),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Typedef, 4, .production_id = 10),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_MatchCaseList_repeat1, 2, .production_id = 4),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_typedef, 1, .production_id = 1),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Enum, 5, .production_id = 10),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start, 1),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [309] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_let, 1, .production_id = 1),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_fun, 1, .production_id = 1),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_enum, 1, .production_id = 1),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Fun, 10, .production_id = 14),
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
