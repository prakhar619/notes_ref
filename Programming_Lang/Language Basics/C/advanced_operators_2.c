#include <stdio.h>  //to use printf and scanf
//no need of using "using namespace std"

void printf_advanced()
{

}

void sizeof_op()
{
    int x;
    double y = 123.2324;
    printf("Size of int:%d\n",sizeof x);
    printf("Size of float:%d\n",sizeof (float));

    //use sizeof operator to get int value which will be the byte size of datatype

}

void commas()
{
    int y;
    int x = (y=10,y++,y+20);    //left sides operated as void//right side (most right) retured as output
    printf("x:%d",x);
}

int main()
{
    sizeof_op();
    commas();
}