%{ 
   /* Definition section */
  #include<stdio.h> 
  #include "samplec.tab.h" 
  extern int yylval; 
%} 
  
/* Rule Section */
%% 
[0-9]+ { 
          yylval=atoi(yytext); 
          return NUMBER; 
  
       }

\+ { return '+';}

\* { return '*';} 
  

[\n] {return 0;} 
 
. {printf("\nInvalid character sequence found\n"); exit(0);} 
  
%% 
  
int yywrap() 
{ 
 return 1; 
} 


