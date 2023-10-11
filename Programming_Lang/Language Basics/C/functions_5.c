#include <stdio.h>
//goto cannot make jump between different functions
int call_byValue(int x,int y)
{
    x,y = y,x;
    return 1;
}
int call_byRef(int* x,int *y)
{
    *x,*y = *y,*x;
    return 1;
}
//   Not allowed  (C++ feature)
// int call_byRef(int &x, int &y)
// {
//     x,y = y,x;
//     return 1;
// }



//FUNCTION PROTOTYPE
    //Not technically required but stronger type checking for compiler
    int square(int y);  //also helps with definition    //therefore function can now be present anywhere
    int c();        //in c means no argument information (hence anything) ; while in cpp means no argument present
int main(int argc,char* argv[]) //pointer to character pointer is array of strings
{   
    //argc counts no of argument passed
    //argv stores strings passed as argument
    if(argc!= 2)    //argc is always 1; function name qualifies as args
        printf("Type your name");
    else
    {
        printf("Hello %s\n",argv[1]);
    }
    printf("Square of 10:%d\n",square(10));
    return 1;   //for void function () no need of return statement
}

//not only definition is later;
//but also implicit int used;   
    //when no return type defined then automatically int
    //also for register c;  means int register c;
square(int x)
{
    return x*x;
}

//inline keyword for optimising function call; compiler dependent like register