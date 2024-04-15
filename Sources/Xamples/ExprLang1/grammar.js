
// A language of arithmetic expressions with variables and function application...

module.exports = grammar({
    name: 'ExprLang',
    rules: {
      // An expression can be either...
      Expr: $ => choice(
        // a variable name,
        $.Expr_name,
        // a parenthesized expression,
        $.Expr_paren,
        // an application of a prefix or infix operator (grouped by precedence and associativity, with higher values binding more tightly),
        $.Expr_add,
        $.Expr_mul,
        $.Expr_pow,
        $.Expr_neg,
        // or a function applied to a sequence of arguments.
        $.Expr_apply,
      ),
      Expr_name: $ => $.Name,
      Expr_paren: $ => seq('(', $.Expr, ')'),
      Expr_add: $ => prec.left(1, seq($.Expr, choice('+', '-'), $.Expr)),
      Expr_mul: $ => prec.left(2, seq($.Expr, choice('*', '/'), $.Expr)),
      Expr_pow: $ => prec.right(3, seq($.Expr, '^', $.Expr)),
      Expr_neg: $ => prec(4, seq('-', $.Expr)),
      Expr_apply: $ => prec(5, seq($.Expr, '(', field('args', optional($.ExprList)), ')')),

      ExprList: $ => seq($.Expr, repeat(seq(',', $.Expr))),

      Name: $ => /[a-zA-Z_][0-9a-zA-Z_]*/,
    }
})
