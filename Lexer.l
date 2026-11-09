%option noyywrap nounput noinput
%{
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "token.h"

double yylval;
%}

DIGITO  [0-9]

%%

[ \t\r]+                    { /* ignora espaços, tabs e o '\r' (CRLF) */ }

"+"                         { return PLUS;  }
"-"                         { return MINUS; }
"*"                         { return TIMES; }
"/"                         { return DIV;   }

{DIGITO}+"."{DIGITO}+       { yylval = atof(yytext); return NUM; }
{DIGITO}+                   { yylval = atof(yytext); return NUM; }

\n                          { return EOL; }

.                           { return ERROR; /* erro léxico é reportado como erro sintático */ }

%%
