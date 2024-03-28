%{
	#include <stdio.h>
	#include <string.h>
	#include "practice.tab.h"
%}

%%

int|float|double|long		{strcpy(yylval.str, yytext); return TYPE;}

[0-9]+				{yylval.val = atoi(yytext); return NUMBER;}

\".*\"				{strcpy(yylval.str,yytext); return STRING;}

[a-zA-Z][a-zA-Z_$0-9]*		{strcpy(yylval.str,yytext); return ID;}

\+|\-|\*|\/|=			{return yytext[0];}

\{|\}|\(|\)			{return yytext[0];}

[ \t] 				{}

[\n]  				{}

\;				{return SEMICOLON;}

\,				{return COMMA;}
 
. 				{printf("\nInvalid character sequence found\n"); exit(0);} 
  
%%

int yywrap()
{
	return 1;
}


