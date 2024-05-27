#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 165
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 86
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 10
#define PRODUCTION_ID_COUNT 17

enum {
  sym_Word = 1,
  anon_sym_SEMI = 2,
  anon_sym_enum = 3,
  anon_sym_LBRACE = 4,
  anon_sym_RBRACE = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  anon_sym_COMMA = 8,
  anon_sym_BANG = 9,
  anon_sym_DASH_GT = 10,
  anon_sym_DOT = 11,
  anon_sym_EQ_EQ = 12,
  anon_sym_LT = 13,
  anon_sym_GT = 14,
  anon_sym_LT_EQ = 15,
  anon_sym_GT_EQ = 16,
  anon_sym_PLUS = 17,
  anon_sym_DASH = 18,
  anon_sym_CARET = 19,
  anon_sym_STAR = 20,
  anon_sym_SLASH = 21,
  anon_sym_PERCENT = 22,
  anon_sym_match = 23,
  anon_sym_PIPE = 24,
  anon_sym_AMP_AMP = 25,
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
  sym_Def_typedef = 37,
  sym_Def_let = 38,
  sym_Def_fun = 39,
  sym_Def_enum = 40,
  sym_DefList = 41,
  sym_Enum = 42,
  sym_EnumCase = 43,
  sym_EnumCaseList = 44,
  sym__Expr = 45,
  sym_Expr_lambda = 46,
  sym_Expr_eql = 47,
  sym_Expr_block = 48,
  sym_Expr_paren = 49,
  sym_Expr_mu = 50,
  sym_Expr_add = 51,
  sym_Expr_pow = 52,
  sym_Expr_mul = 53,
  sym_Expr_neg = 54,
  sym_Expr_numb = 55,
  sym_Expr_match = 56,
  sym_Expr_or = 57,
  sym_Expr_name = 58,
  sym_Expr_and = 59,
  sym_Expr_call = 60,
  sym_Expr_project = 61,
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
  sym_TypeExpr_const = 73,
  sym_TypeExpr_func = 74,
  sym_TypeExpr_tuple = 75,
  sym_TypeExpr_name = 76,
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
  [anon_sym_BANG] = "!",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_DOT] = ".",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_CARET] = "^",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_match] = "match",
  [anon_sym_PIPE] = "|",
  [anon_sym_AMP_AMP] = "&&",
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
  [sym_Def_typedef] = "Def_typedef",
  [sym_Def_let] = "Def_let",
  [sym_Def_fun] = "Def_fun",
  [sym_Def_enum] = "Def_enum",
  [sym_DefList] = "DefList",
  [sym_Enum] = "Enum",
  [sym_EnumCase] = "EnumCase",
  [sym_EnumCaseList] = "EnumCaseList",
  [sym__Expr] = "_Expr",
  [sym_Expr_lambda] = "Expr_lambda",
  [sym_Expr_eql] = "Expr_eql",
  [sym_Expr_block] = "Expr_block",
  [sym_Expr_paren] = "Expr_paren",
  [sym_Expr_mu] = "Expr_mu",
  [sym_Expr_add] = "Expr_add",
  [sym_Expr_pow] = "Expr_pow",
  [sym_Expr_mul] = "Expr_mul",
  [sym_Expr_neg] = "Expr_neg",
  [sym_Expr_numb] = "Expr_numb",
  [sym_Expr_match] = "Expr_match",
  [sym_Expr_or] = "Expr_or",
  [sym_Expr_name] = "Expr_name",
  [sym_Expr_and] = "Expr_and",
  [sym_Expr_call] = "Expr_call",
  [sym_Expr_project] = "Expr_project",
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
  [sym_TypeExpr_const] = "TypeExpr_const",
  [sym_TypeExpr_func] = "TypeExpr_func",
  [sym_TypeExpr_tuple] = "TypeExpr_tuple",
  [sym_TypeExpr_name] = "TypeExpr_name",
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
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
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
  [sym_Def_typedef] = sym_Def_typedef,
  [sym_Def_let] = sym_Def_let,
  [sym_Def_fun] = sym_Def_fun,
  [sym_Def_enum] = sym_Def_enum,
  [sym_DefList] = sym_DefList,
  [sym_Enum] = sym_Enum,
  [sym_EnumCase] = sym_EnumCase,
  [sym_EnumCaseList] = sym_EnumCaseList,
  [sym__Expr] = sym__Expr,
  [sym_Expr_lambda] = sym_Expr_lambda,
  [sym_Expr_eql] = sym_Expr_eql,
  [sym_Expr_block] = sym_Expr_block,
  [sym_Expr_paren] = sym_Expr_paren,
  [sym_Expr_mu] = sym_Expr_mu,
  [sym_Expr_add] = sym_Expr_add,
  [sym_Expr_pow] = sym_Expr_pow,
  [sym_Expr_mul] = sym_Expr_mul,
  [sym_Expr_neg] = sym_Expr_neg,
  [sym_Expr_numb] = sym_Expr_numb,
  [sym_Expr_match] = sym_Expr_match,
  [sym_Expr_or] = sym_Expr_or,
  [sym_Expr_name] = sym_Expr_name,
  [sym_Expr_and] = sym_Expr_and,
  [sym_Expr_call] = sym_Expr_call,
  [sym_Expr_project] = sym_Expr_project,
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
  [sym_TypeExpr_const] = sym_TypeExpr_const,
  [sym_TypeExpr_func] = sym_TypeExpr_func,
  [sym_TypeExpr_tuple] = sym_TypeExpr_tuple,
  [sym_TypeExpr_name] = sym_TypeExpr_name,
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
  [anon_sym_match] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
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
  [sym_Def_typedef] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_let] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_fun] = {
    .visible = true,
    .named = true,
  },
  [sym_Def_enum] = {
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
  [sym_Expr_lambda] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_eql] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_block] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_paren] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_mu] = {
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
  [sym_Expr_mul] = {
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
  [sym_Expr_match] = {
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
  [sym_Expr_and] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_call] = {
    .visible = true,
    .named = true,
  },
  [sym_Expr_project] = {
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
  [sym_TypeExpr_const] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExpr_func] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExpr_tuple] = {
    .visible = true,
    .named = true,
  },
  [sym_TypeExpr_name] = {
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
  [7] = {.index = 9, .length = 2},
  [8] = {.index = 11, .length = 3},
  [9] = {.index = 14, .length = 2},
  [10] = {.index = 16, .length = 2},
  [11] = {.index = 18, .length = 2},
  [12] = {.index = 20, .length = 3},
  [13] = {.index = 23, .length = 3},
  [14] = {.index = 26, .length = 2},
  [15] = {.index = 28, .length = 4},
  [16] = {.index = 32, .length = 3},
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
    {field_1, 2},
  [11] =
    {field_0, 0},
    {field_1, 1},
    {field_2, 2},
  [14] =
    {field_0, 0, .inherited = true},
    {field_0, 1, .inherited = true},
  [16] =
    {field_0, 1},
    {field_1, 3},
  [18] =
    {field_1, 4},
    {field_2, 6},
  [20] =
    {field_0, 2},
    {field_1, 5},
    {field_2, 7},
  [23] =
    {field_0, 1},
    {field_2, 5},
    {field_3, 7},
  [26] =
    {field_0, 0},
    {field_2, 4},
  [28] =
    {field_0, 1},
    {field_1, 3},
    {field_2, 6},
    {field_3, 8},
  [32] =
    {field_0, 0},
    {field_1, 2},
    {field_2, 5},
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
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '*') ADVANCE(43);
      if (lookahead == '+') ADVANCE(36);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(45);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '<') ADVANCE(28);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '>') ADVANCE(30);
      if (lookahead == '^') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(81);
      if (lookahead == 'l') ADVANCE(69);
      if (lookahead == 'm') ADVANCE(66);
      if (lookahead == 't') ADVANCE(82);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(51);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '*') ADVANCE(43);
      if (lookahead == '+') ADVANCE(36);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(45);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '<') ADVANCE(28);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '>') ADVANCE(30);
      if (lookahead == '^') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(81);
      if (lookahead == 'l') ADVANCE(69);
      if (lookahead == 'm') ADVANCE(66);
      if (lookahead == 't') ADVANCE(82);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(51);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(2);
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '%') ADVANCE(48);
      if (lookahead == '&') ADVANCE(106);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '*') ADVANCE(44);
      if (lookahead == '+') ADVANCE(37);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == '-') ADVANCE(40);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '/') ADVANCE(46);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '<') ADVANCE(29);
      if (lookahead == '=') ADVANCE(63);
      if (lookahead == '>') ADVANCE(31);
      if (lookahead == '^') ADVANCE(42);
      if (lookahead == 'e') ADVANCE(76);
      if (lookahead == 'f') ADVANCE(81);
      if (lookahead == 'l') ADVANCE(69);
      if (lookahead == 'm') ADVANCE(66);
      if (lookahead == 't') ADVANCE(82);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(52);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '#' ||
          lookahead == '~') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == '=') ADVANCE(60);
      if (lookahead == 'm') ADVANCE(84);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 4:
      if (lookahead == '&') ADVANCE(53);
      END_STATE();
    case 5:
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '=') ADVANCE(60);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(26);
      if (lookahead == '>') ADVANCE(64);
      END_STATE();
    case 7:
      if (lookahead == '>') ADVANCE(22);
      END_STATE();
    case 8:
      if (eof) ADVANCE(10);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '*') ADVANCE(43);
      if (lookahead == '+') ADVANCE(36);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(45);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '<') ADVANCE(28);
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '>') ADVANCE(30);
      if (lookahead == '^') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(94);
      if (lookahead == 'f') ADVANCE(99);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'm') ADVANCE(84);
      if (lookahead == 't') ADVANCE(100);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(51);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '(') ADVANCE(16);
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == '*') ADVANCE(43);
      if (lookahead == '+') ADVANCE(36);
      if (lookahead == ',') ADVANCE(18);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(45);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == ';') ADVANCE(11);
      if (lookahead == '<') ADVANCE(28);
      if (lookahead == '=') ADVANCE(61);
      if (lookahead == '>') ADVANCE(30);
      if (lookahead == '^') ADVANCE(41);
      if (lookahead == '{') ADVANCE(14);
      if (lookahead == '|') ADVANCE(51);
      if (lookahead == '}') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_enum);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_enum);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
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
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(32);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(34);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(35);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(22);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(23);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          lookahead == '<' ||
          lookahead == '=' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_match);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_match);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_fun);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_fun);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_Int_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(26);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(26);
      if (lookahead == '>') ADVANCE(64);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(27);
      if (lookahead == '>') ADVANCE(65);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          lookahead == '<' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'a') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'c') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'd') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'e') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'e') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'e') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'f') ADVANCE(103);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'h') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'm') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'n') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'n') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'p') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 't') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 't') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'u') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'u') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (lookahead == 'y') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'a') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'c') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'd') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'e') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'e') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'e') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'f') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'h') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'm') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'n') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'n') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'p') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 't') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 't') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'u') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'u') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (lookahead == 'y') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_Name_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_typedef);
      if (lookahead == ' ') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_typedef);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_Word);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '&') ADVANCE(54);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_Word);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '%' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '/') ||
          ('<' <= lookahead && lookahead <= '>') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(107);
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
  [1] = {.lex_state = 8},
  [2] = {.lex_state = 8},
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
  [24] = {.lex_state = 9},
  [25] = {.lex_state = 8},
  [26] = {.lex_state = 8},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 8},
  [32] = {.lex_state = 8},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 8},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 8},
  [38] = {.lex_state = 8},
  [39] = {.lex_state = 8},
  [40] = {.lex_state = 8},
  [41] = {.lex_state = 8},
  [42] = {.lex_state = 8},
  [43] = {.lex_state = 8},
  [44] = {.lex_state = 8},
  [45] = {.lex_state = 8},
  [46] = {.lex_state = 8},
  [47] = {.lex_state = 8},
  [48] = {.lex_state = 8},
  [49] = {.lex_state = 8},
  [50] = {.lex_state = 8},
  [51] = {.lex_state = 8},
  [52] = {.lex_state = 8},
  [53] = {.lex_state = 8},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 8},
  [56] = {.lex_state = 8},
  [57] = {.lex_state = 8},
  [58] = {.lex_state = 8},
  [59] = {.lex_state = 8},
  [60] = {.lex_state = 9},
  [61] = {.lex_state = 9},
  [62] = {.lex_state = 9},
  [63] = {.lex_state = 9},
  [64] = {.lex_state = 9},
  [65] = {.lex_state = 9},
  [66] = {.lex_state = 9},
  [67] = {.lex_state = 9},
  [68] = {.lex_state = 9},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 9},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 5},
  [74] = {.lex_state = 5},
  [75] = {.lex_state = 5},
  [76] = {.lex_state = 5},
  [77] = {.lex_state = 5},
  [78] = {.lex_state = 9},
  [79] = {.lex_state = 9},
  [80] = {.lex_state = 9},
  [81] = {.lex_state = 9},
  [82] = {.lex_state = 5},
  [83] = {.lex_state = 9},
  [84] = {.lex_state = 9},
  [85] = {.lex_state = 9},
  [86] = {.lex_state = 5},
  [87] = {.lex_state = 8},
  [88] = {.lex_state = 8},
  [89] = {.lex_state = 8},
  [90] = {.lex_state = 5},
  [91] = {.lex_state = 9},
  [92] = {.lex_state = 8},
  [93] = {.lex_state = 8},
  [94] = {.lex_state = 8},
  [95] = {.lex_state = 8},
  [96] = {.lex_state = 8},
  [97] = {.lex_state = 9},
  [98] = {.lex_state = 8},
  [99] = {.lex_state = 8},
  [100] = {.lex_state = 8},
  [101] = {.lex_state = 9},
  [102] = {.lex_state = 8},
  [103] = {.lex_state = 9},
  [104] = {.lex_state = 8},
  [105] = {.lex_state = 8},
  [106] = {.lex_state = 8},
  [107] = {.lex_state = 8},
  [108] = {.lex_state = 9},
  [109] = {.lex_state = 8},
  [110] = {.lex_state = 5},
  [111] = {.lex_state = 9},
  [112] = {.lex_state = 9},
  [113] = {.lex_state = 9},
  [114] = {.lex_state = 8},
  [115] = {.lex_state = 5},
  [116] = {.lex_state = 9},
  [117] = {.lex_state = 8},
  [118] = {.lex_state = 5},
  [119] = {.lex_state = 5},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 5},
  [122] = {.lex_state = 8},
  [123] = {.lex_state = 5},
  [124] = {.lex_state = 8},
  [125] = {.lex_state = 8},
  [126] = {.lex_state = 5},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 8},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 5},
  [133] = {.lex_state = 5},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 5},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 5},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 3},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 3},
  [145] = {.lex_state = 8},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 5},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 5},
  [164] = {.lex_state = 0},
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
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
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
    [sym_start] = STATE(160),
    [sym_Block] = STATE(159),
    [sym__Def] = STATE(158),
    [sym_Def_typedef] = STATE(158),
    [sym_Def_let] = STATE(158),
    [sym_Def_fun] = STATE(158),
    [sym_Def_enum] = STATE(158),
    [sym_DefList] = STATE(15),
    [sym_Enum] = STATE(157),
    [sym__Expr] = STATE(51),
    [sym_Expr_lambda] = STATE(51),
    [sym_Expr_eql] = STATE(51),
    [sym_Expr_block] = STATE(51),
    [sym_Expr_paren] = STATE(51),
    [sym_Expr_mu] = STATE(51),
    [sym_Expr_add] = STATE(51),
    [sym_Expr_pow] = STATE(51),
    [sym_Expr_mul] = STATE(51),
    [sym_Expr_neg] = STATE(51),
    [sym_Expr_numb] = STATE(51),
    [sym_Expr_match] = STATE(51),
    [sym_Expr_or] = STATE(51),
    [sym_Expr_name] = STATE(51),
    [sym_Expr_and] = STATE(51),
    [sym_Expr_call] = STATE(51),
    [sym_Expr_project] = STATE(51),
    [sym_Fun] = STATE(156),
    [sym_Int] = STATE(25),
    [sym_Let] = STATE(154),
    [sym_Name] = STATE(40),
    [sym_Typedef] = STATE(153),
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
    STATE(15), 1,
      sym_DefList,
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(151), 1,
      sym_Block,
    STATE(153), 1,
      sym_Typedef,
    STATE(154), 1,
      sym_Let,
    STATE(156), 1,
      sym_Fun,
    STATE(157), 1,
      sym_Enum,
    STATE(158), 5,
      sym__Def,
      sym_Def_typedef,
      sym_Def_let,
      sym_Def_fun,
      sym_Def_enum,
    STATE(51), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(135), 1,
      sym_ExprList,
    STATE(49), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(150), 1,
      sym_ExprList,
    STATE(49), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(42), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(31), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(58), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(56), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(50), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(44), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [472] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(26), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [519] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(57), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [566] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(41), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [613] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(54), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [660] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(53), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [707] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(39), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [754] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(27), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [801] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(35), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [848] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(52), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [895] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(47), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [942] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(36), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [989] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(55), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [1036] = 10,
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
    STATE(25), 1,
      sym_Int,
    STATE(40), 1,
      sym_Name,
    STATE(45), 17,
      sym__Expr,
      sym_Expr_lambda,
      sym_Expr_eql,
      sym_Expr_block,
      sym_Expr_paren,
      sym_Expr_mu,
      sym_Expr_add,
      sym_Expr_pow,
      sym_Expr_mul,
      sym_Expr_neg,
      sym_Expr_numb,
      sym_Expr_match,
      sym_Expr_or,
      sym_Expr_name,
      sym_Expr_and,
      sym_Expr_call,
      sym_Expr_project,
  [1083] = 2,
    ACTIONS(31), 4,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_EQ,
    ACTIONS(29), 20,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_COLON,
  [1112] = 2,
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
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1138] = 7,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(43), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(37), 11,
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
      anon_sym_AMP_AMP,
  [1174] = 9,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(53), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(51), 9,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1214] = 2,
    ACTIONS(61), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(59), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1240] = 12,
    ACTIONS(63), 1,
      anon_sym_enum,
    ACTIONS(70), 1,
      anon_sym_fun,
    ACTIONS(73), 1,
      anon_sym_let,
    ACTIONS(76), 1,
      anon_sym_typedef,
    STATE(29), 1,
      aux_sym_DefList_repeat1,
    STATE(153), 1,
      sym_Typedef,
    STATE(154), 1,
      sym_Let,
    STATE(156), 1,
      sym_Fun,
    STATE(157), 1,
      sym_Enum,
    ACTIONS(68), 2,
      anon_sym_match,
      aux_sym_Name_token1,
    ACTIONS(66), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    STATE(127), 5,
      sym__Def,
      sym_Def_typedef,
      sym_Def_let,
      sym_Def_fun,
      sym_Def_enum,
  [1286] = 2,
    ACTIONS(81), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(79), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1312] = 4,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(83), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1342] = 2,
    ACTIONS(89), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1368] = 12,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(29), 1,
      aux_sym_DefList_repeat1,
    STATE(153), 1,
      sym_Typedef,
    STATE(154), 1,
      sym_Let,
    STATE(156), 1,
      sym_Fun,
    STATE(157), 1,
      sym_Enum,
    ACTIONS(93), 2,
      anon_sym_match,
      aux_sym_Name_token1,
    ACTIONS(91), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    STATE(127), 5,
      sym__Def,
      sym_Def_typedef,
      sym_Def_let,
      sym_Def_fun,
      sym_Def_enum,
  [1414] = 2,
    ACTIONS(97), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(95), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1440] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(99), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1482] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(105), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1524] = 12,
    ACTIONS(3), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_typedef,
    STATE(33), 1,
      aux_sym_DefList_repeat1,
    STATE(153), 1,
      sym_Typedef,
    STATE(154), 1,
      sym_Let,
    STATE(156), 1,
      sym_Fun,
    STATE(157), 1,
      sym_Enum,
    ACTIONS(109), 2,
      anon_sym_match,
      aux_sym_Name_token1,
    ACTIONS(107), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    STATE(127), 5,
      sym__Def,
      sym_Def_typedef,
      sym_Def_let,
      sym_Def_fun,
      sym_Def_enum,
  [1570] = 2,
    ACTIONS(113), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(111), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1596] = 4,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(117), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(115), 17,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1626] = 2,
    ACTIONS(121), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(119), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1652] = 5,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(125), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(123), 16,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1684] = 8,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(129), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(127), 10,
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
  [1722] = 2,
    ACTIONS(133), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(131), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1748] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(135), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1790] = 6,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(139), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(137), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1824] = 2,
    ACTIONS(143), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(141), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1850] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(145), 6,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1892] = 2,
    ACTIONS(149), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(147), 19,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_AMP_AMP,
  [1918] = 12,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(151), 1,
      anon_sym_RPAREN,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      aux_sym_ExprList_repeat1,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1961] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(155), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1999] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2037] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(159), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2075] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(161), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2113] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(163), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2151] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(165), 1,
      anon_sym_RBRACE,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2188] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(167), 1,
      anon_sym_SEMI,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2225] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2262] = 10,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_DOT,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(55), 1,
      anon_sym_PIPE,
    ACTIONS(57), 1,
      anon_sym_AMP_AMP,
    ACTIONS(171), 1,
      anon_sym_LBRACE,
    ACTIONS(45), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(101), 3,
      anon_sym_EQ_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [2299] = 2,
    ACTIONS(175), 5,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_BANG,
      anon_sym_DASH,
      aux_sym_Int_token1,
    ACTIONS(173), 6,
      anon_sym_enum,
      anon_sym_match,
      anon_sym_fun,
      anon_sym_let,
      aux_sym_Name_token1,
      anon_sym_typedef,
  [2315] = 6,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(161), 1,
      sym_TypeExprList,
    STATE(82), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2338] = 6,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    ACTIONS(183), 1,
      anon_sym_RPAREN,
    STATE(70), 1,
      sym_Name,
    STATE(136), 1,
      sym_TypeExprList,
    STATE(82), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2361] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(115), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2378] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(110), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2395] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(119), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2412] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(118), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2429] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(77), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2446] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(86), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2463] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(126), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2480] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(121), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2497] = 2,
    ACTIONS(187), 1,
      anon_sym_LPAREN,
    ACTIONS(185), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [2510] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(90), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2527] = 4,
    ACTIONS(177), 1,
      anon_sym_LPAREN,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(70), 1,
      sym_Name,
    STATE(123), 5,
      sym__TypeExpr,
      sym_TypeExpr_const,
      sym_TypeExpr_func,
      sym_TypeExpr_tuple,
      sym_TypeExpr_name,
  [2544] = 1,
    ACTIONS(189), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [2554] = 1,
    ACTIONS(191), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [2564] = 1,
    ACTIONS(193), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [2574] = 1,
    ACTIONS(195), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [2584] = 1,
    ACTIONS(197), 7,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_DOT,
      anon_sym_EQ,
  [2594] = 5,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    ACTIONS(199), 1,
      anon_sym_RPAREN,
    STATE(109), 1,
      sym_Param,
    STATE(128), 1,
      sym_Name,
    STATE(155), 1,
      sym_ParamList,
  [2610] = 5,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    ACTIONS(201), 1,
      anon_sym_RPAREN,
    STATE(109), 1,
      sym_Param,
    STATE(128), 1,
      sym_Name,
    STATE(138), 1,
      sym_ParamList,
  [2626] = 5,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    ACTIONS(203), 1,
      anon_sym_RPAREN,
    STATE(109), 1,
      sym_Param,
    STATE(128), 1,
      sym_Name,
    STATE(131), 1,
      sym_ParamList,
  [2642] = 4,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(93), 1,
      sym_Name,
    STATE(104), 1,
      sym_EnumCase,
    STATE(134), 1,
      sym_EnumCaseList,
  [2655] = 4,
    ACTIONS(205), 1,
      anon_sym_RPAREN,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    STATE(96), 1,
      aux_sym_TypeExprList_repeat1,
  [2668] = 4,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    ACTIONS(211), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      sym_Name,
    STATE(130), 1,
      sym_NameList,
  [2681] = 4,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(95), 1,
      sym_MatchCase,
    STATE(140), 1,
      sym_Name,
    STATE(146), 1,
      sym_MatchCaseList,
  [2694] = 4,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(109), 1,
      sym_Param,
    STATE(128), 1,
      sym_Name,
    STATE(143), 1,
      sym_ParamList,
  [2707] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(213), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ,
  [2716] = 3,
    ACTIONS(215), 1,
      anon_sym_RPAREN,
    ACTIONS(217), 1,
      anon_sym_COMMA,
    STATE(89), 1,
      aux_sym_NameList_repeat1,
  [2726] = 3,
    ACTIONS(219), 1,
      anon_sym_RBRACE,
    ACTIONS(221), 1,
      anon_sym_COMMA,
    STATE(100), 1,
      aux_sym_MatchCaseList_repeat1,
  [2736] = 3,
    ACTIONS(217), 1,
      anon_sym_COMMA,
    ACTIONS(223), 1,
      anon_sym_RPAREN,
    STATE(107), 1,
      aux_sym_NameList_repeat1,
  [2746] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(225), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2754] = 3,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(93), 1,
      sym_Name,
    STATE(117), 1,
      sym_EnumCase,
  [2764] = 3,
    ACTIONS(227), 1,
      anon_sym_RBRACE,
    ACTIONS(229), 1,
      anon_sym_COMMA,
    STATE(106), 1,
      aux_sym_EnumCaseList_repeat1,
  [2774] = 2,
    ACTIONS(233), 1,
      anon_sym_LPAREN,
    ACTIONS(231), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2782] = 3,
    ACTIONS(235), 1,
      anon_sym_RPAREN,
    ACTIONS(237), 1,
      anon_sym_COMMA,
    STATE(94), 1,
      aux_sym_ParamList_repeat1,
  [2792] = 3,
    ACTIONS(221), 1,
      anon_sym_COMMA,
    ACTIONS(240), 1,
      anon_sym_RBRACE,
    STATE(88), 1,
      aux_sym_MatchCaseList_repeat1,
  [2802] = 3,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(242), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      aux_sym_TypeExprList_repeat1,
  [2812] = 3,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(124), 1,
      sym_MatchCase,
    STATE(140), 1,
      sym_Name,
  [2822] = 3,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(244), 1,
      anon_sym_RPAREN,
    STATE(105), 1,
      aux_sym_ExprList_repeat1,
  [2832] = 3,
    ACTIONS(246), 1,
      anon_sym_RPAREN,
    ACTIONS(248), 1,
      anon_sym_COMMA,
    STATE(99), 1,
      aux_sym_TypeExprList_repeat1,
  [2842] = 3,
    ACTIONS(251), 1,
      anon_sym_RBRACE,
    ACTIONS(253), 1,
      anon_sym_COMMA,
    STATE(100), 1,
      aux_sym_MatchCaseList_repeat1,
  [2852] = 3,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    STATE(149), 1,
      sym_Name,
  [2862] = 3,
    ACTIONS(258), 1,
      anon_sym_RPAREN,
    ACTIONS(260), 1,
      anon_sym_COMMA,
    STATE(94), 1,
      aux_sym_ParamList_repeat1,
  [2872] = 3,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(125), 1,
      sym_Param,
    STATE(128), 1,
      sym_Name,
  [2882] = 3,
    ACTIONS(229), 1,
      anon_sym_COMMA,
    ACTIONS(262), 1,
      anon_sym_RBRACE,
    STATE(92), 1,
      aux_sym_EnumCaseList_repeat1,
  [2892] = 3,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    ACTIONS(266), 1,
      anon_sym_COMMA,
    STATE(105), 1,
      aux_sym_ExprList_repeat1,
  [2902] = 3,
    ACTIONS(269), 1,
      anon_sym_RBRACE,
    ACTIONS(271), 1,
      anon_sym_COMMA,
    STATE(106), 1,
      aux_sym_EnumCaseList_repeat1,
  [2912] = 3,
    ACTIONS(274), 1,
      anon_sym_RPAREN,
    ACTIONS(276), 1,
      anon_sym_COMMA,
    STATE(107), 1,
      aux_sym_NameList_repeat1,
  [2922] = 3,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(128), 1,
      sym_Name,
    STATE(144), 1,
      sym_Param,
  [2932] = 3,
    ACTIONS(260), 1,
      anon_sym_COMMA,
    ACTIONS(279), 1,
      anon_sym_RPAREN,
    STATE(102), 1,
      aux_sym_ParamList_repeat1,
  [2942] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(281), 1,
      anon_sym_DOT,
  [2949] = 2,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(152), 1,
      sym_Name,
  [2956] = 2,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(148), 1,
      sym_Name,
  [2963] = 2,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(142), 1,
      sym_Name,
  [2970] = 1,
    ACTIONS(283), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2975] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(285), 1,
      anon_sym_LBRACE,
  [2982] = 2,
    ACTIONS(181), 1,
      aux_sym_Name_token1,
    STATE(114), 1,
      sym_Name,
  [2989] = 1,
    ACTIONS(287), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2994] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(289), 1,
      anon_sym_SEMI,
  [3001] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(291), 1,
      anon_sym_DOT,
  [3008] = 2,
    ACTIONS(17), 1,
      aux_sym_Int_token1,
    STATE(30), 1,
      sym_Int,
  [3015] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(293), 1,
      anon_sym_DOT,
  [3022] = 1,
    ACTIONS(295), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [3027] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(297), 1,
      anon_sym_DOT,
  [3034] = 1,
    ACTIONS(299), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [3039] = 1,
    ACTIONS(301), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [3044] = 2,
    ACTIONS(209), 1,
      anon_sym_DASH_GT,
    ACTIONS(303), 1,
      anon_sym_LBRACE,
  [3051] = 1,
    ACTIONS(305), 1,
      anon_sym_SEMI,
  [3055] = 1,
    ACTIONS(307), 1,
      anon_sym_COLON,
  [3059] = 1,
    ACTIONS(309), 1,
      anon_sym_EQ_GT,
  [3063] = 1,
    ACTIONS(311), 1,
      anon_sym_RPAREN,
  [3067] = 1,
    ACTIONS(313), 1,
      anon_sym_RPAREN,
  [3071] = 1,
    ACTIONS(315), 1,
      anon_sym_DASH_GT,
  [3075] = 1,
    ACTIONS(317), 1,
      anon_sym_DASH_GT,
  [3079] = 1,
    ACTIONS(319), 1,
      anon_sym_RBRACE,
  [3083] = 1,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
  [3087] = 1,
    ACTIONS(323), 1,
      anon_sym_RPAREN,
  [3091] = 1,
    ACTIONS(325), 1,
      anon_sym_DASH_GT,
  [3095] = 1,
    ACTIONS(327), 1,
      anon_sym_RPAREN,
  [3099] = 1,
    ACTIONS(329), 1,
      anon_sym_DASH_GT,
  [3103] = 1,
    ACTIONS(331), 1,
      anon_sym_LPAREN,
  [3107] = 1,
    ACTIONS(333), 1,
      anon_sym_SEMI,
  [3111] = 1,
    ACTIONS(335), 1,
      anon_sym_EQ,
  [3115] = 1,
    ACTIONS(337), 1,
      anon_sym_RPAREN,
  [3119] = 1,
    ACTIONS(339), 1,
      anon_sym_EQ,
  [3123] = 1,
    ACTIONS(341), 1,
      anon_sym_EQ_GT,
  [3127] = 1,
    ACTIONS(343), 1,
      anon_sym_RBRACE,
  [3131] = 1,
    ACTIONS(345), 1,
      anon_sym_DASH_GT,
  [3135] = 1,
    ACTIONS(347), 1,
      anon_sym_LPAREN,
  [3139] = 1,
    ACTIONS(349), 1,
      anon_sym_LPAREN,
  [3143] = 1,
    ACTIONS(351), 1,
      anon_sym_RPAREN,
  [3147] = 1,
    ACTIONS(353), 1,
      anon_sym_RBRACE,
  [3151] = 1,
    ACTIONS(355), 1,
      anon_sym_LBRACE,
  [3155] = 1,
    ACTIONS(357), 1,
      anon_sym_SEMI,
  [3159] = 1,
    ACTIONS(359), 1,
      anon_sym_SEMI,
  [3163] = 1,
    ACTIONS(361), 1,
      anon_sym_RPAREN,
  [3167] = 1,
    ACTIONS(363), 1,
      anon_sym_SEMI,
  [3171] = 1,
    ACTIONS(365), 1,
      anon_sym_SEMI,
  [3175] = 1,
    ACTIONS(367), 1,
      anon_sym_SEMI,
  [3179] = 1,
    ACTIONS(369), 1,
      ts_builtin_sym_end,
  [3183] = 1,
    ACTIONS(371), 1,
      ts_builtin_sym_end,
  [3187] = 1,
    ACTIONS(373), 1,
      anon_sym_RPAREN,
  [3191] = 1,
    ACTIONS(375), 1,
      anon_sym_SEMI,
  [3195] = 1,
    ACTIONS(377), 1,
      anon_sym_DASH_GT,
  [3199] = 1,
    ACTIONS(379), 1,
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
  [SMALL_STATE(12)] = 519,
  [SMALL_STATE(13)] = 566,
  [SMALL_STATE(14)] = 613,
  [SMALL_STATE(15)] = 660,
  [SMALL_STATE(16)] = 707,
  [SMALL_STATE(17)] = 754,
  [SMALL_STATE(18)] = 801,
  [SMALL_STATE(19)] = 848,
  [SMALL_STATE(20)] = 895,
  [SMALL_STATE(21)] = 942,
  [SMALL_STATE(22)] = 989,
  [SMALL_STATE(23)] = 1036,
  [SMALL_STATE(24)] = 1083,
  [SMALL_STATE(25)] = 1112,
  [SMALL_STATE(26)] = 1138,
  [SMALL_STATE(27)] = 1174,
  [SMALL_STATE(28)] = 1214,
  [SMALL_STATE(29)] = 1240,
  [SMALL_STATE(30)] = 1286,
  [SMALL_STATE(31)] = 1312,
  [SMALL_STATE(32)] = 1342,
  [SMALL_STATE(33)] = 1368,
  [SMALL_STATE(34)] = 1414,
  [SMALL_STATE(35)] = 1440,
  [SMALL_STATE(36)] = 1482,
  [SMALL_STATE(37)] = 1524,
  [SMALL_STATE(38)] = 1570,
  [SMALL_STATE(39)] = 1596,
  [SMALL_STATE(40)] = 1626,
  [SMALL_STATE(41)] = 1652,
  [SMALL_STATE(42)] = 1684,
  [SMALL_STATE(43)] = 1722,
  [SMALL_STATE(44)] = 1748,
  [SMALL_STATE(45)] = 1790,
  [SMALL_STATE(46)] = 1824,
  [SMALL_STATE(47)] = 1850,
  [SMALL_STATE(48)] = 1892,
  [SMALL_STATE(49)] = 1918,
  [SMALL_STATE(50)] = 1961,
  [SMALL_STATE(51)] = 1999,
  [SMALL_STATE(52)] = 2037,
  [SMALL_STATE(53)] = 2075,
  [SMALL_STATE(54)] = 2113,
  [SMALL_STATE(55)] = 2151,
  [SMALL_STATE(56)] = 2188,
  [SMALL_STATE(57)] = 2225,
  [SMALL_STATE(58)] = 2262,
  [SMALL_STATE(59)] = 2299,
  [SMALL_STATE(60)] = 2315,
  [SMALL_STATE(61)] = 2338,
  [SMALL_STATE(62)] = 2361,
  [SMALL_STATE(63)] = 2378,
  [SMALL_STATE(64)] = 2395,
  [SMALL_STATE(65)] = 2412,
  [SMALL_STATE(66)] = 2429,
  [SMALL_STATE(67)] = 2446,
  [SMALL_STATE(68)] = 2463,
  [SMALL_STATE(69)] = 2480,
  [SMALL_STATE(70)] = 2497,
  [SMALL_STATE(71)] = 2510,
  [SMALL_STATE(72)] = 2527,
  [SMALL_STATE(73)] = 2544,
  [SMALL_STATE(74)] = 2554,
  [SMALL_STATE(75)] = 2564,
  [SMALL_STATE(76)] = 2574,
  [SMALL_STATE(77)] = 2584,
  [SMALL_STATE(78)] = 2594,
  [SMALL_STATE(79)] = 2610,
  [SMALL_STATE(80)] = 2626,
  [SMALL_STATE(81)] = 2642,
  [SMALL_STATE(82)] = 2655,
  [SMALL_STATE(83)] = 2668,
  [SMALL_STATE(84)] = 2681,
  [SMALL_STATE(85)] = 2694,
  [SMALL_STATE(86)] = 2707,
  [SMALL_STATE(87)] = 2716,
  [SMALL_STATE(88)] = 2726,
  [SMALL_STATE(89)] = 2736,
  [SMALL_STATE(90)] = 2746,
  [SMALL_STATE(91)] = 2754,
  [SMALL_STATE(92)] = 2764,
  [SMALL_STATE(93)] = 2774,
  [SMALL_STATE(94)] = 2782,
  [SMALL_STATE(95)] = 2792,
  [SMALL_STATE(96)] = 2802,
  [SMALL_STATE(97)] = 2812,
  [SMALL_STATE(98)] = 2822,
  [SMALL_STATE(99)] = 2832,
  [SMALL_STATE(100)] = 2842,
  [SMALL_STATE(101)] = 2852,
  [SMALL_STATE(102)] = 2862,
  [SMALL_STATE(103)] = 2872,
  [SMALL_STATE(104)] = 2882,
  [SMALL_STATE(105)] = 2892,
  [SMALL_STATE(106)] = 2902,
  [SMALL_STATE(107)] = 2912,
  [SMALL_STATE(108)] = 2922,
  [SMALL_STATE(109)] = 2932,
  [SMALL_STATE(110)] = 2942,
  [SMALL_STATE(111)] = 2949,
  [SMALL_STATE(112)] = 2956,
  [SMALL_STATE(113)] = 2963,
  [SMALL_STATE(114)] = 2970,
  [SMALL_STATE(115)] = 2975,
  [SMALL_STATE(116)] = 2982,
  [SMALL_STATE(117)] = 2989,
  [SMALL_STATE(118)] = 2994,
  [SMALL_STATE(119)] = 3001,
  [SMALL_STATE(120)] = 3008,
  [SMALL_STATE(121)] = 3015,
  [SMALL_STATE(122)] = 3022,
  [SMALL_STATE(123)] = 3027,
  [SMALL_STATE(124)] = 3034,
  [SMALL_STATE(125)] = 3039,
  [SMALL_STATE(126)] = 3044,
  [SMALL_STATE(127)] = 3051,
  [SMALL_STATE(128)] = 3055,
  [SMALL_STATE(129)] = 3059,
  [SMALL_STATE(130)] = 3063,
  [SMALL_STATE(131)] = 3067,
  [SMALL_STATE(132)] = 3071,
  [SMALL_STATE(133)] = 3075,
  [SMALL_STATE(134)] = 3079,
  [SMALL_STATE(135)] = 3083,
  [SMALL_STATE(136)] = 3087,
  [SMALL_STATE(137)] = 3091,
  [SMALL_STATE(138)] = 3095,
  [SMALL_STATE(139)] = 3099,
  [SMALL_STATE(140)] = 3103,
  [SMALL_STATE(141)] = 3107,
  [SMALL_STATE(142)] = 3111,
  [SMALL_STATE(143)] = 3115,
  [SMALL_STATE(144)] = 3119,
  [SMALL_STATE(145)] = 3123,
  [SMALL_STATE(146)] = 3127,
  [SMALL_STATE(147)] = 3131,
  [SMALL_STATE(148)] = 3135,
  [SMALL_STATE(149)] = 3139,
  [SMALL_STATE(150)] = 3143,
  [SMALL_STATE(151)] = 3147,
  [SMALL_STATE(152)] = 3151,
  [SMALL_STATE(153)] = 3155,
  [SMALL_STATE(154)] = 3159,
  [SMALL_STATE(155)] = 3163,
  [SMALL_STATE(156)] = 3167,
  [SMALL_STATE(157)] = 3171,
  [SMALL_STATE(158)] = 3175,
  [SMALL_STATE(159)] = 3179,
  [SMALL_STATE(160)] = 3183,
  [SMALL_STATE(161)] = 3187,
  [SMALL_STATE(162)] = 3191,
  [SMALL_STATE(163)] = 3195,
  [SMALL_STATE(164)] = 3199,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Name, 1, .production_id = 1),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Name, 1, .production_id = 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_numb, 1, .production_id = 1),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_numb, 1, .production_id = 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_and, 3, .production_id = 8),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_and, 3, .production_id = 8),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_eql, 3, .production_id = 8),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_eql, 3, .production_id = 8),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_call, 4, .production_id = 7),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_call, 4, .production_id = 7),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(111),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(112),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(108),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(113),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_project, 3, .production_id = 7),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_project, 3, .production_id = 7),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_neg, 2, .production_id = 3),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_neg, 2, .production_id = 3),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_call, 3, .production_id = 1),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_call, 3, .production_id = 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DefList, 3, .production_id = 6),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DefList, 3, .production_id = 6),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_match, 5, .production_id = 10),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_match, 5, .production_id = 10),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_lambda, 8, .production_id = 12),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mu, 8, .production_id = 13),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DefList, 2, .production_id = 1),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DefList, 2, .production_id = 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Int, 1, .production_id = 1),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Int, 1, .production_id = 1),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_pow, 3, .production_id = 8),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_pow, 3, .production_id = 8),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_name, 1, .production_id = 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_name, 1, .production_id = 1),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mul, 3, .production_id = 8),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_mul, 3, .production_id = 8),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_or, 3, .production_id = 8),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_or, 3, .production_id = 8),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 2),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_paren, 2),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_lambda, 7, .production_id = 11),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_add, 3, .production_id = 8),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_add, 3, .production_id = 8),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_paren, 3, .production_id = 4),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_paren, 3, .production_id = 4),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_mu, 9, .production_id = 15),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Expr_block, 3, .production_id = 4),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Expr_block, 3, .production_id = 4),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 1, .production_id = 1),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 4),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 1, .production_id = 2),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCase, 5, .production_id = 14),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 2, .production_id = 3),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCase, 6, .production_id = 16),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Let, 4, .production_id = 10),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 1),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_DefList_repeat1, 2, .production_id = 1),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_name, 1, .production_id = 1),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_tuple, 3, .production_id = 4),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_const, 3, .production_id = 1),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_const, 4, .production_id = 7),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_tuple, 2),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExpr_func, 3, .production_id = 7),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExprList, 1, .production_id = 1),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Param, 3, .production_id = 7),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameList, 1, .production_id = 1),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCaseList, 2, .production_id = 5),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_NameList, 2, .production_id = 5),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_TypeExprList_repeat1, 2, .production_id = 4),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCaseList, 2, .production_id = 5),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCase, 1, .production_id = 1),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ParamList_repeat1, 2, .production_id = 9),
  [237] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ParamList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(103),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_MatchCaseList, 1, .production_id = 1),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_TypeExprList, 2, .production_id = 5),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ExprList, 2, .production_id = 5),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_TypeExprList_repeat1, 2, .production_id = 9),
  [248] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_TypeExprList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(71),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_MatchCaseList_repeat1, 2, .production_id = 9),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_MatchCaseList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(97),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamList, 2, .production_id = 5),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCaseList, 1, .production_id = 1),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 9),
  [266] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ExprList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(9),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_EnumCaseList_repeat1, 2, .production_id = 9),
  [271] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_EnumCaseList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(91),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_NameList_repeat1, 2, .production_id = 9),
  [276] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_NameList_repeat1, 2, .production_id = 9), SHIFT_REPEAT(116),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ParamList, 1, .production_id = 1),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_NameList_repeat1, 2, .production_id = 4),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_EnumCaseList_repeat1, 2, .production_id = 4),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Typedef, 4, .production_id = 10),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EnumCase, 4, .production_id = 7),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_MatchCaseList_repeat1, 2, .production_id = 4),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ParamList_repeat1, 2, .production_id = 4),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Enum, 5, .production_id = 10),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_typedef, 1, .production_id = 1),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_let, 1, .production_id = 1),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_fun, 1, .production_id = 1),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Def_enum, 1, .production_id = 1),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [369] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start, 1),
  [371] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Fun, 9, .production_id = 13),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Fun, 10, .production_id = 15),
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
