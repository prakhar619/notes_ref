%{ 
   /* Definition section */
  #include<stdio.h> 
  int flag=0;
  int yyerror();
  int yylex(); 
%} 
  
%token NUMBER 
  
%left '+'
  
%left '*'
  
  
/* Rule Section */
%% 
  
ArithmeticExpression: E { 
  
         printf("\nResult=%d\n", $1); 
  
         return 0; 
  
        }; 
 E:E'+'E {$$=$1+$3;}   
  
 |E'*'E {$$=$1*$3;} 
    
 | NUMBER {$$=$1;} 
 
 ; 
  
%% 
  
//driver code 
void main() 
{ 
   		printf("\nEnter arithmetic expression:");
   		yyparse(); 
   		if(flag==0) 
   			printf("\nEntered arithmetic expression is Valid\n"); 
		else
			printf("\nINVALID expression.\n");
} 
  
int yyerror() 
{ 
   flag=1; 
} 


