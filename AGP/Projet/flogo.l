%{
#include <stdio.h>
#include "structure.h"
#include "logo.tab.h"
#include <stdlib.h>
%}

%%
FORWARD return FORWARD;
LEFT return LEFT;
RIGHT return RIGHT;
REPEAT return REPEAT;
\[ return '[';
\] return ']';
\n ;
[ \t]+ ;
[0-9]+ {yylval.val=atoi(yytext); return VALUE;}
%%


