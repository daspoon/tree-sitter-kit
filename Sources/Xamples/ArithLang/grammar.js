
// A language of arithmetic expressions with variables and function application...

module.exports = grammar({
    name: 'ArithLang',
    rules: {
      // Expressions
      Expr: $ => choice(
        $.Expr_name,
        $.Expr_add,
        $.Expr_mul,
        $.Expr_pow,
        $.Expr_neg,
        $.Expr_apply,
        $.Expr_paren,
      ),
      // Variable names
      Expr_name: $ => $.Name,
      // Operators of increasing precedence
      Expr_add: $ => prec.left(1, seq($.Expr, choice('+', '-'), $.Expr)),
      Expr_mul: $ => prec.left(2, seq($.Expr, choice('*', '/'), $.Expr)),
      Expr_pow: $ => prec.right(3, seq($.Expr, '^', $.Expr)),
      Expr_neg: $ => prec(4, seq('-', $.Expr)),
      // Function application with highest precedence
      Expr_apply: $ => prec(5, seq($.Expr, '(', field('args', optional($.ExprList)), ')')),
      // Parentheses
      Expr_paren: $ => seq('(', $.Expr, ')'),

      // A sequence of one or more expressions separated by commas
      ExprList: $ => seq($.Expr, repeat(seq(',', $.Expr))),

      // A variable name
      Name: $ => /[a-zA-Z_][0-9a-zA-Z_]*/,

      // An integer
      Numb: $ => /[0-9]+/,
    }
})
