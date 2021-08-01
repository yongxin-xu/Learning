%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int symbols[52]; // limited to 1 character, only a-z A-Z
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

%union {int num; char id;}      // Yacc definitions
                                // different types to return
%start line
%token print
%token exit_command
%token <num> number             // <num> -> store in the `num` in union type
%token <id> identifier          // stores in the `id` in union type
%type <num> line exp term
%type <id> assignment

%%

/* descriptions of expected inputs  corresponding actions (in C) */
line        : assignment ';'        {;}
            | exit_command ';'      {exit(EXIT_SUCCESS);}
            | print exp ';'         {printf("Printing %d\n", $2);}
            | line assignment ';'   {;}
            | line print exp ';'    {printf("Printing %d\n", $3);}
            | line exit_command ';' {exit(EXIT_SUCCESS);}
            ;

assignment : identifier '=' exp { updateSymbolVal($1, $3); }
            ;
exp     : term          {$$ = $1;}
        | exp '+' term  {$$ = $1 + $3;}
        | exp '-' term  {$$ = $1 - $3;}
        ;
term    : number        {$$ = $1;}
        | identifier    {$$ = symbolVal($1);}
        ;

%%      /* C code */

/* map char token to array index */
int computeSymbolIndex(char token) {
    int idx = -1;
    if (0 != islower(token)) {
        idx = token - 'a' + 26;
    } else if (0 != isupper(token)) {
        idx = token - 'A';
    }
    return idx;
}

/* returns the value of a given symbol */
int symbolVal(char symbol) {
    int bucket = computeSymbolIndex(symbol);
    return symbols[bucket];
}

/* update the value of a given symbol */
void updateSymbolVal(char symbol, int val) {
    int bucket = computeSymbolIndex(symbol);
    symbols[bucket] = val;
}

int main(void) {
    /* init symbol table */
    for (int i = 0; i < 52; i++) {
        symbols[i] = 0;
    }

    return yyparse();
}

void yyerror(char *s) { fprintf(stderr, "%s\n", s); }
