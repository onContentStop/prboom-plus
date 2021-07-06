%option noyywrap reentrant bison-bridge bison-locations nodefault 

%{
#include "sndinfo.parse.h"
%}

%%

[a-zA-Z0-9/]+           { yylval->str.text = yytext; yylval->str.len = yyleng; return IDENT; }
"$random"               { return RANDOM; }
"$alias"                { return ALIAS; }
"$"[a-z]+               { return OTHER; }
"{"                     { return LB; }
"}"                     { return RB; }
[ \t\r\n\f]+            ;
.                       { return BAD; }
