%{
	#include <stdio.h>
	#include <string.h>
%}

%%

int|float|double|long		{printf("Type Found:%s\n",yytext);}

[0-9]+				{printf("Number Found:%d\n",atoi(yytext));}

\".*\"				{printf("String Found:%s\n",yytext);}

[a-zA-Z][a-zA-Z_$0-9]*		{printf("ID Found:%s\n",yytext);}

\+|\-|\*|\/|=			{printf("Operator Found:%s\n",yytext);}

\{|\}|\(|\)			{printf("Bracket Found:%s\n",yytext);}

[ \t] 				{printf("Space Found:%s\n",yytext);}

[\n]  				{printf("NewLine Found:%s\n",yytext);}

\;|\,				{printf("Comma/Semicolon Found:%s\n",yytext);}
 
. 				{printf("\nInvalid character sequence found\n"); exit(0);} 
  
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter expression:\n");
	yylex();
	return 1;
}
