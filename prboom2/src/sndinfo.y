%locations
%token IDENT RANDOM ALIAS OTHER BAD LB RB
%define api.pure

%code requires {
#include <stddef.h>
#include "sndinfo.h"
typedef void *yyscan_t;
}

%param { yyscan_t scanner }

%code {
#include "sndinfo.lex.h"
static void yyerror(YYLTYPE *loc, yyscan_t scanner, const char *message);
}

%union {
    string_t str;
    string_elem_t *strs;
}
%type<str> IDENT
%type<strs> sounds

%%

file : decl file |;
decl : random_decl
     | alias_decl
     | sound_decl
     ;
random_decl : RANDOM IDENT LB sounds RB {
    random_decl($2, $4);
}
            ;
sounds : IDENT sounds { $$ = malloc(sizeof(string_elem_t));
                        $$->next = $2;
                        $$->value = $1; }
       | IDENT        { $$ = malloc(sizeof(string_elem_t));
                        $$->next = NULL;
                        $$->value = $1; }
       ;
alias_decl : ALIAS IDENT IDENT;
sound_decl : IDENT IDENT;

%%

static void yyerror(YYLTYPE *loc, yyscan_t scanner, const char *message) {}
