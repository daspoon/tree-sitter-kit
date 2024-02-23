
// Define the grammar of 'funlang'.
// Note that rules whose names begin with '_' do not appear in syntax trees.

module.exports = grammar({
    name: 'funlang',
    rules: {
        // The first rule specifies the root node, and must be visible.
        start: $ => $.expr,

        // 'word' is a special rule which enables dismbiguating keywords from identifiers.
        word: $ => $.name,

        // Idenifiers
        name: $ => /[a-z]+/,

        // Integers
        numb: $ => /\d+/,

        // Expressions
        expr: $ => choice(
            $.name,
            $.numb,
            $.binary_op,
            $.unary_op,
            seq('(', $.expr, ')'),
        ),

        // Unary operators, with precedence.
        unary_op: $ => choice(
            prec(4, seq('-', $.expr)),
        ),

        // Binary operators, with precedence and associativity.
        binary_op: $ => choice(
            prec.left(1, seq(field('lhs', $.expr), field('op', '+'), field('rhs', $.expr))),
            prec.left(2, seq(field('lhs', $.expr), field('op', '*'), field('rhs', $.expr))),
            prec.left(3, seq(field('lhs', $.expr), field('op', '^'), field('rhs', $.expr))),
        ),
    }
});
