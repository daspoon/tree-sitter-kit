module.exports = grammar({
    name: 'Fling',
    rules: {
        start: $ => $._expr,

        word: $ => $.name,

        name: $ => /[a-z]+/,
        numb: $ => /\d+/,

        _expr: $ => choice(
            $.name,
            $.numb,
            $.binary_op,
            $.unary_op,
            seq('(', $._expr, ')'),
        ),

        binary_op: $ => choice(
            prec.left(1, seq(field('lhs', $._expr), field('op', '+'), field('rhs', $._expr))),
            prec.left(2, seq(field('lhs', $._expr), field('op', '*'), field('rhs', $._expr))),
            prec.left(3, seq(field('lhs', $._expr), field('op', '^'), field('rhs', $._expr))),
        ),

        unary_op: $ => choice(
            prec(4, seq('-', $._expr)),
        ),
    }
});
