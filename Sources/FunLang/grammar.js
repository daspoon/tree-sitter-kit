module.exports = grammar({
    name: 'FunLang',
    rules: {
        Expr: $ => choice(
            $.Expr_add,
            $.Expr_and,
            $.Expr_apply,
            $.Expr_eql,
            $.Expr_lambda,
            $.Expr_match,
            $.Expr_mu,
            $.Expr_mul,
            $.Expr_name,
            $.Expr_neg,
            $.Expr_numb,
            $.Expr_or,
            $.Expr_pow,
            $.Expr_project,
            $.Expr_tuple
        ),
        Expr_add: $ => prec.left(4, seq($.Expr, choice('+', '-'), $.Expr)),
        Expr_and: $ => prec.left(3, seq($.Expr, choice('&&'), $.Expr)),
        Expr_apply: $ => prec.left(9, seq($.Expr, $.ArrayOfExpr)),
        Expr_eql: $ => prec.left(1, seq($.Expr, choice('=='), $.Expr)),
        Expr_lambda: $ => seq('!', $.ArrayOfParam, '->', $.Type, '.', $.Expr),
        Expr_match: $ => seq('match', $.Expr, $.ArrayOfMatchCase),
        Expr_mu: $ => seq('!', $.Name, $.ArrayOfParam, '->', $.Type, '.', $.Expr),
        Expr_mul: $ => prec.left(5, seq($.Expr, choice('*', '/', '%'), $.Expr)),
        Expr_name: $ => $.Name,
        Expr_neg: $ => prec(7, seq(choice('-'), $.Expr)),
        Expr_numb: $ => $.Int,
        Expr_or: $ => prec.left(2, seq($.Expr, choice('||'), $.Expr)),
        Expr_pow: $ => prec.right(6, seq($.Expr, choice('^'), $.Expr)),
        Expr_project: $ => prec.left(8, seq($.Expr, choice('.'), $.Int)),
        Expr_tuple: $ => $.ArrayOfExpr,

        ArrayOfExpr: $ => seq('(', optional(seq($.Expr, repeat(seq(',', $.Expr)))), ')'),

        ArrayOfMatchCase: $ => seq('{', optional(seq($.MatchCase, repeat(seq(',', $.MatchCase)))), '}'),

        ArrayOfName: $ => seq('(', optional(seq($.Name, repeat(seq(',', $.Name)))), ')'),

        ArrayOfParam: $ => seq('(', optional(seq($.Param, repeat(seq(',', $.Param)))), ')'),

        ArrayOfType: $ => seq('(', optional(seq($.Type, repeat(seq(',', $.Type)))), ')'),

        Int: $ => /[0-9]+/,

        MatchCase: $ => seq($.Name, $.ArrayOfName, '=>', $.Expr),

        Name: $ => /[a-zA-Z_]+[0-9a-zA-Z_]*/,

        Param: $ => seq($.Name, ':', $.Type),

        Type: $ => choice(
            $.Type_const,
            $.Type_func,
            $.Type_name,
            $.Type_tuple
        ),
        Type_const: $ => seq($.Name, $.ArrayOfType),
        Type_func: $ => prec.right(1, seq($.Type, '->', $.Type)),
        Type_name: $ => $.Name,
        Type_tuple: $ => $.ArrayOfType
    }
})
