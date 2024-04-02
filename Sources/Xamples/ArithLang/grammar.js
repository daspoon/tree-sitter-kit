
// A simple language of arithmetic expressions.

module.exports = grammar({
    name: 'ArithLang',
    rules: {
        // Expr is the start rule and the root node of every valid parse tree.
        // Its various are defined as named productions to simplify converting parse trees to Swift values.
        Expr: $ => choice(
          $.Expr_numb,
          $.Expr_add,
          $.Expr_mul,
          $.Expr_pow,
          $.Expr_neg,
          $.Expr_paren,
        ),

        // Non-negative integers.
        Expr_numb: $ => /[0-9]+/,

        // Infix binary operators with associated precedence.
        Expr_add: $ => prec.left(1, seq($.Expr, choice('+', '-'), $.Expr)),
        Expr_mul: $ => prec.left(2, seq($.Expr, choice('*', '/'), $.Expr)),
        Expr_pow: $ => prec.right(3, seq($.Expr, choice('^'), $.Expr)),

        // Prefix unary operators with associated precedence
        Expr_neg: $ => prec(4, seq(choice('-'), $.Expr)),

        // Parenthesized expressions.
        Expr_paren: $ => seq('(', $.Expr, ')'),
    }
})
