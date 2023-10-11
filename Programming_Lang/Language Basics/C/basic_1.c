#include <stdio.h>
//Foundational C
//C89   ANSI Standard for C

//C is middle lvl language
    //Java, C++ also middle lvl language

//Not strongly type language    (auto allowed)
//structured language (goto not allowed/rare usage)
//function inside function not allowed
//case sensitive

//main must be present

//Memory Management in C

//Source Code ----compiler----> Object Code





/*
DATA TYPES          (Five Foundational data types)
    char
    int
    float
    double
    void            (no value/generic pointer)
*/

/*
Modified Data types
    signed
    unsigned
    long            (long is 32 bit and long long 64 bit)
    short
*/

/*
Variables (where we can declare)
    local variables         (block scope)
    formal parameters
    global variables        (outside any function)
*/

//DECLARE ALL VARIABLES AT START OF PROGRAM else error
    //this is only in c89
    //int i; i = 10; int j; is legal in c99 and c++


/*
4 C Scopes
    File Scope  (global variables)
    Block Scope
    Function prototype  
    Function scope      (applies to label only, goto)
*/

/*Type Qualifier
    const
    volatile        (for variables that are allowed to change outside of code like by os clock)
    restrict        (only in c99)
*/

/*
4 Storage Class specifier
    extern          #helps to declare variable without defining it; we can define it much later than from where we use; global scope therefore can be used outside file
    static          #permanent variable; not known outside function/file; local static variable(scope unchanged) and static global variable; static local variables are initialised only once (at start of program) and not when control enters block, unlike normal variable;static global variables hav internal linkage therefore cannot be used across file
    register        #to store variable(except array) in register rather than main memory; only local variable and formal parameter can be register; global not allowed; &register_variable may not work
    auto
*/


/*
C defines 3 categories of linkage: external, internal, none
    function and variables have external linkage (meaning they are available to all files that constitute a program)
    static have internal linkage (meaning file scope within the file only)
    local variable have non linkage
*/

//declaration vs definition
/*
    declaration means type and name declared
    definition means storage allocation for object
        same object may have many declaration but only one definition
        most time declaration is also the definition
    */

/*
Character constant defines multibyte character and wide character(16bit long)
Normally char 8 bit or 1 byte

#include <stddef.h>
wchar_t wide_char_var = L'Ac';

int hex = 0x80;
int oct = 0123; //decimal
int bin = 0b101;

C has string constant but not data type for it;
*/

/* Type promotion
            in expression if we operate on different data type output data type is one with larger bit size
            long double > double > float > unsigned long > long > unsigned int > int > char
            unsigned int + long -> long or unsigned long(if unable to represent in long)
*/
void typeCasting()
{
    //think of char as dependent on int
        //although int cant take symbols but char can take; internal symbol are converted to number and saved as int (char is int)
        //therefore to print character use %c either on char variable or int variable;

    int x_1 = 2606174491; //1001_1011_0101_0111_0001_0001_0001_1011 32bit
    char c = '}';       //125   0111_1101 in ascii
    float f = 1234.53;
    int ch = 65;

    c = x_1; //truncation //last 8bits or 1byte taken from int (insignificant side)(or low ordered bits)
    printf("Char Encoded Symbol:%c\n", c);//esc character
    printf("Char Ascii Code:%d\n",c);//27
    printf("Int variable Encoded to Ascii Symbol:%c\n",ch);

    //earlier we saw autocasting
    //now explicit casting
    int x = 10;
    int y = 3;
    int x_y = x/y;  //integer div
    float _x_y = x/y;
    float x_y_ = (float) x/y;

    printf("Integer div with int var and no casting:%d\n",x_y);
    printf("Integer div with float var and no casting:%f\n",_x_y);
    printf("Integer div with float var and with casting:%f\n",x_y_);

}

void easy_DeclarationAndAssignment()
{
    int x,y,z;
    x = y = z = 10;
    int x1 = 10, y1 = 20, *y_ptr;
    printf("Easy Assigment and declarations:%d,%d,%d,%d,%d\n",x,y,z,x1,y1);
}

void pointers()
{
    int count =10;
    int* count_pointer = &count;    //& gives always addr

    int count_dup = *count_pointer; //deferencing to count
    int count_dupp = count;

    printf("Count:%d\n",count);
    printf("Count_dup(through pointer):%d\n",count_dup);
    printf("Count_dupp(through direct assigment):%d\n",count_dupp);
    count++;
    printf("Count:%d\n",count);
    printf("Count_dup(through pointer):%d\n",*count_pointer);   //dont use count_dup as it itself is a normal variable
    printf("Count_dupp(through direct assigment):%d\n",count_dupp);
    
    //pointers need data types for dereferencing to know how much bits of data to load/give as output
}

int main()
{
    typeCasting();
    // easy_DeclarationAndAssignment();
    // pointers();
    // extern int gEInt;
    // printf("Accessing extern variable:%d\n",gEInt);
    //printf("Accessing static variable:%d",gSInt);
    return 1;
}

int gEInt = 10;

