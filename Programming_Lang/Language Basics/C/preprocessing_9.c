/*
Preprocessor Directives
    #include
    #define         //macros    #define LEFT 1; #define ABS(a) (a) < 0 ? -(a) : (a)
    #if             
    #elif
    #else
    #endif          
    #ifdef          //alt is #if defined MACRO
    #ifndef
    #undef
    #line
    #pragma
    #error
*/
/*
Each prep dir must have its own line
# and ## operator
    #s means "s"    ;automatically adds quotes (stringize)
    a ## b          ;automatically concatenates a and b
*/   

#include <stdio.h>
#define MAX  100
#define makeString(s) #s
int main()
{
    #if MAX > 100
    printf("This line will not even be compiled\n");
    #elif MAX < 100
    printf("This line will also not be compiled\n");
    #else
    printf("This wil be compiled\n");
    #endif

    #ifdef MAX  //(if defined )
    printf("MAX IS DEFINED\n");
    #endif

    #if defined MAX
    printf("MAX IS DEFFINED\n");
    #endif

    #ifndef MIN 
    printf("MIN IS UNDEFINED\n");
    #endif

    printf(makeString(rn its not a string\n));

    #undef MAX
    return 1;
}