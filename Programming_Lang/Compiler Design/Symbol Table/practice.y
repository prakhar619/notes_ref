%{
	#include <stdio.h>
	#include <string.h>

	struct entry{
		char type[10];
		char id[100];
		struct entry* ptr;
	};

	struct SymbolTable{
		struct entry table[100];
		int counter;
	}mainSymbolTable;


	int flag = 0;
	int yyerror();
	int yylex();
	void createEntries(char*, char(*)[100],int,struct SymbolTable*);
	void printTable(); 
	void assignVal(char*, int ,char*);

	char currID[10][100];
	int idCount;

	struct SymbolTable* currTable;

%}

%union {
	int val;
	char str[100];
}

%token SEMICOLON COMMA
%token NUMBER
%token <str> TYPE
%token <str> STRING
%token <str> ID
%left '+' '-'
%left '*' '/'
%right '='
%start funcDef
%type <val> term exp factor

%%
funcDef: TYPE ID '(' ')' '{' declList stmtList '}'		{strcpy(currID[0],$2);	createEntries($1,currID,1,currTable); return 1;};
declList: declList decl | decl					{};
decl: TYPE varList SEMICOLON					{createEntries($1,currID,idCount,currTable); idCount = 0;};
varList: ID COMMA varList 						{strcpy(currID[idCount],$1); idCount++;}
| ID											{strcpy(currID[idCount],$1); idCount++;};
stmtList: stmtList stmt | stmt					{};
stmt: assignStmt								{};
assignStmt: ID '=' exp SEMICOLON				{};
exp: exp '+' term 								{$$ = $1 + $3;}
| exp '-' term 									{$$ = $1 - $3;}
| term											{};
term: term '*' factor 							{$$ = $1 * $3;}
| term '/' factor 								{$$ = $1 / $3;}
| factor										{};
factor: ID										{};
%%

void createEntries(char* type, char id[10][100], int count,struct SymbolTable* symbolTable)
{
	for(int c = 0; c < count; c++)
	{
		struct entry nth_entry;
		strcpy(nth_entry.type,type);
		strcpy(nth_entry.id,id[c]);
		nth_entry.ptr = -1;
	
		symbolTable->table[symbolTable->counter] = nth_entry;
		symbolTable->counter+=1;
	}
}

void printTable()
{
	printf("Printing Symbol Table\n");
	for(int c= 0; c < mainSymbolTable.counter; c++)
	{
		struct entry nth_entry = mainSymbolTable.table[c];
		printf("Entry No:%d\tType:%s\tId:%s\tPtr:%d\n",c,nth_entry.type,nth_entry.id,nth_entry.ptr);

	}
}

void main()
{
	currTable = &mainSymbolTable;
	mainSymbolTable.counter = 0;
	idCount = 0;


	   	printf("Enter expression:");
   		yyparse();
   		printTable();
   		if(flag==0) 
   			printf("\nEntered expression is Valid\n"); 
		else
			printf("\nINVALID expression.\n");
}

int yyerror() 
{ 
   flag=1; 
} 


