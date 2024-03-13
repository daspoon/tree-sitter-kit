module.exports = grammar({
    name: 'FunLang',
    rules: {
        Expr: $ => choice(
            $.Expr_project,
            $.Expr_pow,
            $.Expr_neg,
            $.Expr_lambda,
            $.Expr_add,
            $.Expr_numb,
            $.Expr_name,
            $.Expr_mul,
            $.Expr_apply,
            $.Expr_tuple
        ),
        Expr_project: $ => prec.left(6, seq($.Expr, '.', $.Int)),
        Expr_pow: $ => prec.right(4, seq($.Expr, '^', $.Expr)),
        Expr_neg: $ => prec(5, seq('-', $.Expr)),
        Expr_lambda: $ => seq('!', $.Name, '.', $.Expr),
        Expr_add: $ => prec.left(2, seq($.Expr, choice('+', '-'), $.Expr)),
        Expr_numb: $ => $.Int,
        Expr_name: $ => $.Name,
        Expr_mul: $ => prec.left(3, seq($.Expr, choice('*', '/', '%'), $.Expr)),
        Expr_apply: $ => prec.left(1, seq($.Expr, $.Expr)),
        Expr_tuple: $ => $.ArrayOfExpr,

        Name: $ => /[a-z]+/,

        Int: $ => /[0-9]+/,

        ArrayOfExpr: $ => seq('(', optional(seq($.Expr, repeat(seq(',', $.Expr)))), ')')
    }
})
