module.exports = grammar({
    name: 'ExprLang',
    word: $ => $.Word,
    rules: {
        start: $ => $._Expr,
        _Expr: $ => choice($.Expr_add, $.Expr_apply, $.Expr_mul, $.Expr_name, $.Expr_neg, $.Expr_paren, $.Expr_pow),
        ExprSequenceSeparatedByComma: $ => seq($._Expr, repeat(seq(',', $._Expr))),
        Expr_add: $ => prec.left(1, seq(field('0', $._Expr), field('1', $.OpAdd), field('2', $._Expr))),
        Expr_apply: $ => prec(5, seq(field('0', $._Expr), '(', field('1', optional($.ExprSequenceSeparatedByComma)), ')')),
        Expr_mul: $ => prec.left(2, seq(field('0', $._Expr), field('1', $.OpMul), field('2', $._Expr))),
        Expr_name: $ => field('0', $.Name),
        Expr_neg: $ => prec(4, seq(field('0', $.OpNeg), field('1', $._Expr))),
        Expr_paren: $ => seq('(', field('0', $._Expr), ')'),
        Expr_pow: $ => prec.right(3, seq(field('0', $._Expr), field('1', $.OpPow), field('2', $._Expr))),
        Name: $ => /[a-zA-Z_][0-9a-zA-Z_]*/,
        OpAdd: $ => choice('+', '-'),
        OpMul: $ => choice('*', '/', '%'),
        OpNeg: $ => choice('-'),
        OpPow: $ => choice('^'),
        Word: $ => /([a-zA-Z_][0-9a-zA-Z_]* | [!#%&*+-/<=>^|~]+)/
    }
})
