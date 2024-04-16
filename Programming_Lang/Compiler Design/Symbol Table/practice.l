%{
	#include <stdio.h>
	#include <string.h>
	#include "practice.tab.h"
%}

%%

int|float|double|long|boolean		{strcpy(yylval.str, yytext); return TYPE;}

if					{return IF;}
else				{return ELSE;}
while				{return WHILE;}

[0-9]+				 {return NUMBER;}

\".*\"				 {return STRING;}

[a-zA-Z][a-zA-Z_$0-9]*		{strcpy(yylval.str,yytext); return ID;}

\+|\-|\*|\/|=			{return yytext[0];}

\{|\}|\(|\)			{return yytext[0];}

[ \t] 				{}

[\n]  				{}

\;				{return SEMICOLON;}

\,				{return COMMA;}

\<		{return LT;}
\>		{return GT;}
\<\=	{return LE;}
\>\=	{return GE;}
\=\=	{return ET;}
\!\=	{return NT;}
\!		{return NB;} 
. 				{printf("\nInvalid character sequence found\n"); exit(0);} 
  
%%

int yywrap()
{
	return 1;
}


