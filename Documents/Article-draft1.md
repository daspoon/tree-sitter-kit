
## Example tree-sitter grammar 

Consider a Swift datatype *Term* representing terms of the untyped lambda calculus.
    ```
    indirect enum Term {
      case var(Var)
      case apply(Term, Term)
      case lambda(Binding, Term)
    }
    struct Var {
      let name : String
    }
    struct Binding {
      let name : String
    }
    ```

A corresponding tree-sitter grammar could be defined as follows:
    ```
    Term: $ => Binding(
      $.Var,
      prec.left(1, seq($.Term, $.Term)),
      seq("λ", $.Binding, ".", $.Term),
      seq("(", $.Term, ")"),
    ),
    Var: $ => /[a-z]+/,
    Binding: $ => /[a-z]+/,
    ```

Following are (the s-expression formats of) the parse trees for basic lambda terms:
    ```
    x    => (Term (Var))
    f x  => (Term (Term (Var)) (Term (Var)))
    λx.y => (Term (Binding) (Term (Var)))
    (x)  => (Term (Term (Var)))
 
    ```

Note on interpretation of s-expressions...

While the initial grammar is sufficient for recognizing valid terms, we must ultimately convert parse trees into instances of our *Term* data type.
There is no problem for the *Var* and *Binding* types which have only one production rule, 
but for types such as *Term* which have multiple production rules we need an effective means of distinguishing each case.
This can be achieved by adding named rules for each case:
    ```
    Term: $ => choice(
        $.Term_var,
        $.Term_apply,
        $.Term_lambda,
        $.Term_paren,
    ),
    Term_var: $ => $.Var,
    Term_apply: $ => prec.left(1, seq($.Term, $.Term)),
    Term_lambda: $ => seq("λ", $.Binding, ".", $.Term),
    Term_paren: $ => seq("(", $.Term, ")"),
    ```

The format of the parse trees becomes:
    ```
    x    => (Term (Term_var (Var)))
    f x  => (Term (Term_apply (Term (Term_var (Var))) (Term (Term_var (Var)))))
    λx.y => (Term (Term_lambda (Binding) (Term (Term_var (Var)))))
    (x)  => (Term (Term_paren (Term (Term_var (Var)))))
    ```

Note the redundancy of the Term nodes, with each having a single child...


## Translation to Swift data type

Assuming we can extract the underlying text from a *TSNode*, an obvious means of translating parse trees into Swift type instances via initializers:
    ```
    extension Term {
        init(_ node: TSNode) {
          precondition(node.name == "Term" && node.count == 1)
          let node = node[0]
          switch node.name {
            case "Term_name" :
              precondition(node.count == 1)
              self = .var(Var(node[0]))
            case "Term_apply" :
              precondition(node.count == 2)
              self = .apply(Term(node[0]), Term(node[1]))
            case "Term_lambda" :
              precondition(node.count == 4)
              self = .lambda(Binding(node[1]), Term(node[3]))
            case "Term_parent" :
              precondition(node.count == 3)
              self = Term(node[1])
            default :
              fatalError("unexpected case: \(node.name)")
          }
        }
    }
    extension Var {
        init(_ node: TSNode) { self.text = node.text }
    }
    extension Binding {
        init(_ node: TSNode) { self.text = node.text }
    }
    ```

This is straight-forward, but keeping the code synchronized with the grammar is generally tedious and error prone.


## Automation...

Ideally we should derive both the grammar rules and the tranlation methods from Swift code.
We will clearly need a Swift data type to represent tree-sitter grammar expressions such as `seq("(", $.Term, ")")`; 
let's call that type *TSExpr*, but leave it undefined for now.

We want to distinguish between struct and enum types (or more generally those with single vs multiple productions).
The former require only a single pairing of syntax expression and instance constructor.
The latter require collection of pairs labelled by their rule name.
    ```
    enum GrammarRule<Element> {
      case single(TSExpr, (TSNode) -> Element)
      case multiple([String: (TSExpr, (TSNode) -> Element)])
    }
    ```

The structure added to our *Term* type is 
    ```
    extension Term {
      var grammarRule : GrammarRule {
        .multiple([
          "Term_name": (.sym(Name), {t in .var(Var(t))}),
          "Term_apply": (.prec(.left, 1, seq([.sym(Term), .sym(Term)])), {t in .apply(Term(t[0]), Term(t[1]))}),
          "Term_lambda": (.seq([.lit("λ"), .sym(Name), .lit("."), .sym(Term)]), {t in .lambda(Binding(t[1]), Term(t[3]))}),
          "Term_paren": (.seq([.lit("("), .sym(Term), .lit(")")]), {t in Term(t[1])}),
        ])
      }
    }
    ```

Note that there needn't be a one-to-one correspondence with the enum type cases.
For our *Var* and *Binding* types, a single pairing of syntax expression and instance constructor is sufficient.
    ```
    extension Var {
      var grammarRule : GrammarRule {
        .single(.pattern("[a-z]+"), {t in Var(t)})
      }
    }
    ```

with a unified constructor interface
    ```
    extension GrammarRule {
      func construct(from node: TSNode) -> Element {
        switch self {
          case single(_, let f) :
            return f(node)
          case multiple(let choices) :
            guard let (_, f) = choices[node.type] else { fatalError() }
            return f(node)
        }
      }
    }
    ```
    
