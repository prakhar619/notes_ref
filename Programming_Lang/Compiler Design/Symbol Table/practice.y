%{
	#include <stdio.h>
	#include <string.h>

/*Header File*/
	struct entry{
		char type[10];
		char id[100];
		struct entry* ptr;
		char arryType[10]; /*simple or array*/
		int width;
	};

	struct SymbolTable{
		struct entry table[100];
		int counter;
	}mainSymbolTable;

/*Essential Functions and Declarations */
	int flag = 0;
	int yyerror();
	int yylex();

/*Helper Functions*/
	void createEntries(char*, char(*)[100],int,struct SymbolTable*);
	void printTable(); 
	void assignVal(char*, int ,char*);
	void checkType2(char*, char*);
	void typeCast2(char*,char*);
	char* checkDec(char*,struct SymbolTable*);

/*Helper Declarations*/
	char currID[10][100];
	int idCount;

	struct SymbolTable* currTable;

%}

%union {
	int val;
	char str[100];
}

%token <str> TYPE
%token IF 
%token ELSE 
%token WHILE 
%token NUMBER
%token STRING
%token <str> ID
%token SEMICOLON COMMA
%token LT GT LE GE ET NT NB


%left '+' '-'
%left '*' '/'
%right '='
%start funcDef
%type <str> term exp factor

%%
funcDef: TYPE ID '(' ')' '{' declList stmtList '}'		{strcpy(currID[0],$2);	createEntries($1,currID,1,currTable); return 1;};
declList: declList decl | decl	| 				{};
decl: TYPE varList SEMICOLON					{createEntries($1,currID,idCount,currTable); idCount = 0;};
varList: ID COMMA varList 						{strcpy(currID[idCount],$1); idCount++;}
| ID											{strcpy(currID[idCount],$1); idCount++;};
stmtList: stmtList stmt | stmt	| 				{};
stmt: assignStmt | controlStmt					{};
assignStmt: ID '=' exp SEMICOLON				{checkType2(checkDec($1,currTable),$3);};
exp: exp '+' term 								{typeCast2($1,$3);strcpy($$,$1);}
| exp '-' term 									{typeCast2($1,$3);strcpy($$,$1);}
| term											{strcpy($$,$1);};
term: term '*' factor 							{typeCast2($1,$3);strcpy($$,$1);}
| term '/' factor 								{typeCast2($1,$3);strcpy($$,$1);}
| factor										{strcpy($$,$1);};
factor: ID										{strcpy($$,checkDec($1,currTable));};

controlStmt: ifControl | whileControl			{};
ifControl: IF '(' boolean ')' '{' declList stmtList '}'
ifControl: IF '(' boolean ')' '{' declList stmtList '}' ELSE '{' declList stmtList '}'
whileControl: WHILE '(' boolean ')' '{' declList stmtList '}'
boolean: ID comparisonOp ID | NB ID
comparisonOp: LT | GT | LE | GE | ET | NT
%%

void createEntries(char* type, char id[10][100], int count,struct SymbolTable* symbolTable)
{


	for(int c = 0; c < count; c++)
	{

		for(int i = 0 ; i < symbolTable->counter; i++)
		{
			if(strcmp(symbolTable->table[i].id,id[c]) == 0)
			{
				printf("Variable Already Declared:%s\n",id[c]);
				flag = 1;
				return;
			}
		}
		struct entry nth_entry;
		strcpy(nth_entry.type,type);
		strcpy(nth_entry.id,id[c]);
		nth_entry.ptr = -1;
	
		symbolTable->table[symbolTable->counter] = nth_entry;
		symbolTable->counter+=1;
	}
}


void checkType2(char type1[100], char type2[100])
{
	/*type1 x = type2 y*/
	if(strcmp(type1,type2) == 0)
	return;

	else if(strcmp("boolean",type1) == 0 && strcmp("int",type2) == 0)
	{
		flag = 1;
		printf("Semantic Error (cannot cast int to boolean)\n");
		return;
	}

	else if(strcmp("int",type1) == 0 && strcmp("boolean",type2) == 0)
	{
		flag = 0;
		printf("Semantic Warning (castting boolean to int)\n");
		return;
	}

	else
	{
		printf("CheckType2 Failed\n");
	}
}

void typeCast2(char type1[100], char type2[100])
{
	return;
}

char* checkDec(char id_name[100], struct SymbolTable* currTable)
{
	for(int i = 0 ; i < currTable->counter; i++)
	{
		if(strcmp(currTable->table[i].id,id_name) == 0)
		{
			return currTable->table[i].type;
		}
	}
	flag = 1;
	printf("Variable not declared:%s\n",id_name);
	char errorVal[10] = "";
	return errorVal;
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


