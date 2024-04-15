module.exports = grammar({
    name: 'ExprLang',
    rules: {
        Expr: $ => choice($.Expr_add, $.Expr_apply, $.Expr_mul, $.Expr_name, $.Expr_neg, $.Expr_paren, $.Expr_pow),
        ExprSequenceSeparatedByComma: $ => seq($.Expr, repeat(seq(',', $.Expr))),
        Expr_add: $ => prec.left(1, seq(field('0', $.Expr), field('1', choice('+', '-')), field('2', $.Expr))),
        Expr_apply: $ => prec(5, seq(field('0', $.Expr), '(', field('1', optional($.ExprSequenceSeparatedByComma)), ')')),
        Expr_mul: $ => prec.left(2, seq(field('0', $.Expr), field('1', choice('*', '/')), field('2', $.Expr))),
        Expr_name: $ => field('0', $.Name),
        Expr_neg: $ => prec(4, seq(field('0', choice('-')), field('1', $.Expr))),
        Expr_paren: $ => seq('(', field('0', $.Expr), ')'),
        Expr_pow: $ => prec.right(3, seq(field('0', $.Expr), field('1', choice('^')), field('2', $.Expr))),
        Name: $ => /[a-zA-Z_][0-9a-zA-Z_]*/
    }
})
