
// A language of arithmetic expressions with variables and function application...

module.exports = grammar({
    name: 'ArithLang',
    rules: {
      // Expressions
      Expr: $ => choice(
        // Variable names
        /[a-zA-Z_][0-9a-zA-Z_]*/,
        // Infix operators of increasing precedence
        prec.left(1, seq($.Expr, choice('+', '-'), $.Expr)),
        prec.left(2, seq($.Expr, choice('*', '/'), $.Expr)),
        prec.right(3, seq($.Expr, '^', $.Expr)),
        // Prefix negation operator with higher precedence
        prec(4, seq('-', $.Expr)),
        // Function application with highest precedence
        prec(5, seq($.Expr, '(', optional(seq($.Expr, repeat(seq(',', $.Expr)))), ')')),
        // Parentheses
        seq('(', $.Expr, ')'),
      ),
    }
})
