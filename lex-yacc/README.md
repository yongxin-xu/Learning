## Lex / FLEX
- Lex is a scanner generator
  - Input is a set of regular expressions and associated actions (written in C).
  - Output is a table-driven scanner. (lex.yy.c)

- Flex: an open-source implementation of the original UNIX lex utility.

- Lex Input
```text
FIRST PART
%%
pattern     action
....
%%
THIRD PART
```

## YACC / Bison 
- **lex**: semantic analysis  
  - splits the input file into tokens.  

- **yacc**: **y**et **a**nother **c**ompiler **c**ompiler  
  - parses and does semantic processing on the stream of tokens produced by lex.  

- **bison**: GNU parser parser, upward compatibility with yacc.  

- Yacc Input
```text
FIRST PART      // C declarations enclosed in %{%} 
                // or yacc definitions %start / %token / %union / %type
%%
production      action  // grammar of language
                        // The left-hand side is followed by a colon and
                        // a right-hand side
                        // Multiple right-hand sides may follow separated by a '|'
                        // Actions associated with a rule are entered in braces

                        // $1, $2, .. $n can be refered to the values associated with
                        // symbols
                        // $$ refer to the value of the left
                        // Default action $$ = $1 --> first production
                        // e.g. => statement: identifier '+' identifier
                        //      {$$ = $1 + $3;}
%%
THIRD PART      // valid C code that supports the language processing.
                // symbol table implementation
                // functions that might be called by actions associated with productions
                // in the second part
```