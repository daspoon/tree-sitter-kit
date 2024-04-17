module.exports = grammar({
    name: 'TypedLang',
    rules: {
        start: $ => $.Block,
        Block: $ => seq(field('0', optional($.DefSequenceDelimitedBySemicolon)), field('1', $._Expr)),
        DefSequenceDelimitedBySemicolon: $ => seq($._Def, ';', repeat(seq($._Def, ';'))),
        Def_enum: $ => field('0', $.Enum),
        Def_fun: $ => field('0', $.Fun),
        Def_let: $ => field('0', $.Let),
        Def_typedef: $ => field('0', $.Typedef),
        Enum: $ => seq('enum', field('0', $.Name), '{', field('1', $.EnumCaseSequenceSeparatedByComma), '}'),
        EnumCase: $ => seq(field('0', $.Name), field('1', optional($.ParamSequenceSeparatedByCommaBracketedByParentheses))),
        EnumCaseSequenceSeparatedByComma: $ => seq($.EnumCase, repeat(seq(',', $.EnumCase))),
        ExprSequenceSeparatedByComma: $ => seq($._Expr, repeat(seq(',', $._Expr))),
        Expr_add: $ => prec.left(4, seq(field('0', $._Expr), field('1', choice('+', '-')), field('2', $._Expr))),
        Expr_and: $ => prec.left(3, seq(field('0', $._Expr), field('1', choice('&&')), field('2', $._Expr))),
        Expr_block: $ => seq('{', field('0', $.Block), '}'),
        Expr_call: $ => prec.left(9, seq(field('0', $._Expr), '(', field('1', optional($.ExprSequenceSeparatedByComma)), ')')),
        Expr_eql: $ => prec.left(1, seq(field('0', $._Expr), field('1', choice('==')), field('2', $._Expr))),
        Expr_lambda: $ => seq('!', field('0', $.ParamSequenceSeparatedByCommaBracketedByParentheses), '->', field('1', $._Type), '.', field('2', $._Expr)),
        Expr_match: $ => seq('match', field('0', $._Expr), '{', field('1', $.MatchCaseSequenceSeparatedByComma), '}'),
        Expr_mu: $ => seq('!', field('0', $.Name), field('1', $.ParamSequenceSeparatedByCommaBracketedByParentheses), '->', field('2', $._Type), '.', field('3', $._Expr)),
        Expr_mul: $ => prec.left(5, seq(field('0', $._Expr), field('1', choice('*', '/', '%')), field('2', $._Expr))),
        Expr_name: $ => field('0', $.Name),
        Expr_neg: $ => prec(7, seq(field('0', choice('-')), field('1', $._Expr))),
        Expr_numb: $ => field('0', $.Int),
        Expr_or: $ => prec.left(2, seq(field('0', $._Expr), field('1', choice('||')), field('2', $._Expr))),
        Expr_paren: $ => seq('(', field('0', optional($.ExprSequenceSeparatedByComma)), ')'),
        Expr_pow: $ => prec.right(6, seq(field('0', $._Expr), field('1', choice('^')), field('2', $._Expr))),
        Expr_project: $ => prec.left(8, seq(field('0', $._Expr), '.', field('1', $.Int))),
        Fun: $ => seq('fun', field('0', $.Name), field('1', $.ParamSequenceSeparatedByCommaBracketedByParentheses), '->', field('2', $._Type), '{', field('3', $._Expr), '}'),
        Int: $ => /[0-9]+/,
        Let: $ => seq('let', field('0', $.Param), '=', field('1', $._Expr)),
        MatchCase: $ => seq(field('0', $.Name), field('1', optional($.NameSequenceSeparatedByCommaBracketedByParentheses)), '=>', field('2', $._Expr)),
        MatchCaseSequenceSeparatedByComma: $ => seq($.MatchCase, repeat(seq(',', $.MatchCase))),
        Name: $ => /[a-zA-Z_]+[0-9a-zA-Z_]*/,
        NameSequenceSeparatedByCommaBracketedByParentheses: $ => seq('(', optional(seq($.Name, repeat(seq(',', $.Name)))), ')'),
        Param: $ => seq(field('0', $.Name), ':', field('1', $._Type)),
        ParamSequenceSeparatedByCommaBracketedByParentheses: $ => seq('(', optional(seq($.Param, repeat(seq(',', $.Param)))), ')'),
        TypeSequenceSeparatedByComma: $ => seq($._Type, repeat(seq(',', $._Type))),
        Type_const: $ => prec(1, seq(field('0', $.Name), '(', field('1', optional($.TypeSequenceSeparatedByComma)), ')')),
        Type_func: $ => prec.right(1, seq(field('0', $._Type), '->', field('1', $._Type))),
        Type_name: $ => field('0', $.Name),
        Type_tuple: $ => seq('(', field('0', optional($.TypeSequenceSeparatedByComma)), ')'),
        Typedef: $ => seq('typedef', field('0', $.Name), '=', field('1', $._Type)),
        _Def: $ => choice($.Def_enum, $.Def_fun, $.Def_let, $.Def_typedef),
        _Expr: $ => choice($.Expr_add, $.Expr_and, $.Expr_block, $.Expr_call, $.Expr_eql, $.Expr_lambda, $.Expr_match, $.Expr_mu, $.Expr_mul, $.Expr_name, $.Expr_neg, $.Expr_numb, $.Expr_or, $.Expr_paren, $.Expr_pow, $.Expr_project),
        _Type: $ => choice($.Type_const, $.Type_func, $.Type_name, $.Type_tuple)
    }
})
