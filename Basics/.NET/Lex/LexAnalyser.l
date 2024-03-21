%option noyywrap
%{
	#include<stdio.h>
	#include<string.h>
    void keyword();
    void colon();
    void identifier();
    void number();
    void string();
    void comment();
    void comparisonOp();
    void bracket();
%}
%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while			{keyword(yytext);}
;|:				{colon(yytext);}
[_a-zA-Z][_a-zA-Z0-9]*		{identifier(yytext);}
[0-9]+\.?[0-9]+			{number(yytext);}
\".*\"				{string(yytext);}
\<|\>|\<=|\>=|==			{comparisonOp(yytext);}
\/\/.*\n			{comment(yytext);}
\/\*(.\n)*\*\/			{comment(yytext);}
\(|\)|\{|\}|\[|\]		{bracket(yytext);}

%%
void keyword(char* txt)
{
	printf("<%s>",txt);
}
void colon(char* txt)
{
	printf("<%s>",txt);
}
void identifier(char* txt)
{
	printf("<id,%s>",txt);
}
void number(char* txt)
{
	printf("<number,%s>",txt);
}
void string(char* txt)
{
	printf("<string,%s>",txt);
}
void comparisonOp(char* txt)
{
	printf("<comparison,%s>",txt);
}
void comment(char* txt)
{
	return;
}
void bracket(char* txt)
{
	printf("<%s>",txt);
}
int main()
{
	yylex();
	return 0;
}