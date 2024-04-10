
// A language of arithmetic expressions with variables and function application...

module.exports = grammar({
    name: 'ExprLang',
    rules: {
      // An expression can be either...
      Expr: $ => choice(
        // a variable name
        /[a-zA-Z_][0-9a-zA-Z_]*/,
        // a parenthesized expression
        seq('(', $.Expr, ')'),
        // an infix or prefix operator of varying precedence (higher values bind more tightly)
        prec.left(1, seq($.Expr, choice('+', '-'), $.Expr)),
        prec.left(2, seq($.Expr, choice('*', '/'), $.Expr)),
        prec.right(3, seq($.Expr, '^', $.Expr)),
        prec(4, seq('-', $.Expr)),
        // or a function application.
        seq($.Expr, '(', optional(seq($.Expr, repeat(seq(',', $.Expr)))), ')'),
      ),
    }
})
