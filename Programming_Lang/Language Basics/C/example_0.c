#include <stdio.h>
int global_int;
int main()
{
    auto x=10;
    printf("%d \n",x);
    x = 'a';
    printf("%c",x);
    return 1;
}