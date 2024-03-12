module.exports = grammar({
    name: 'FunLang',
    rules: {
        Expr: $ => choice(
            $.Expr_neg,
            $.Expr_add,
            $.Expr_name,
            $.Expr_numb,
            $.Expr_mul,
            $.Expr_pow,
            $.Expr_paren
        ),
        Expr_neg: $ => prec(6, seq('-', $.Expr)),
        Expr_add: $ => prec.left(3, seq($.Expr, '+', $.Expr)),
        Expr_name: $ => $.Name,
        Expr_numb: $ => $.Int,
        Expr_mul: $ => prec.left(4, seq($.Expr, '*', $.Expr)),
        Expr_pow: $ => prec.right(5, seq($.Expr, '^', $.Expr)),
        Expr_paren: $ => seq('(', $.Expr, ')'),

        Name: $ => /[a-z]+/,

        Int: $ => /[0-9]+/
    }
})
