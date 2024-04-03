module.exports = grammar({
    name: 'FuncLang',
    rules: {
        Expr: $ => choice($.Expr_add, $.Expr_apply, $.Expr_cond, $.Expr_eql, $.Expr_lambda, $.Expr_mul, $.Expr_name, $.Expr_neg, $.Expr_numb, $.Expr_paren, $.Expr_pow),
        ExprSequenceSeparatedByCommaBracketedByParentheses: $ => seq('(', optional(seq($.Expr, repeat(seq(',', $.Expr)))), ')'),
        Expr_add: $ => prec.left(2, seq(field('0', $.Expr), field('1', choice('+', '-')), field('2', $.Expr))),
        Expr_apply: $ => prec.left(6, seq(field('0', $.Expr), field('1', $.ExprSequenceSeparatedByCommaBracketedByParentheses))),
        Expr_cond: $ => seq('if', field('0', $.Expr), '{', field('1', $.Expr), '} else {', field('2', $.Expr), '}'),
        Expr_eql: $ => prec.left(1, seq(field('0', $.Expr), field('1', choice('==')), field('2', $.Expr))),
        Expr_lambda: $ => seq('!', field('0', optional($.Name)), field('1', $.NameSequenceSeparatedByCommaBracketedByParentheses), '.', field('2', $.Expr)),
        Expr_mul: $ => prec.left(3, seq(field('0', $.Expr), field('1', choice('*', '/')), field('2', $.Expr))),
        Expr_name: $ => field('0', $.Name),
        Expr_neg: $ => prec(5, seq(field('0', choice('-')), field('1', $.Expr))),
        Expr_numb: $ => field('0', $.Int),
        Expr_paren: $ => field('0', $.ExprSequenceSeparatedByCommaBracketedByParentheses),
        Expr_pow: $ => prec.right(4, seq(field('0', $.Expr), field('1', choice('^')), field('2', $.Expr))),
        Int: $ => /[0-9]+/,
        Name: $ => /[a-zA-Z_][0-9a-zA-Z_]*/,
        NameSequenceSeparatedByCommaBracketedByParentheses: $ => seq('(', optional(seq($.Name, repeat(seq(',', $.Name)))), ')')
    }
})
