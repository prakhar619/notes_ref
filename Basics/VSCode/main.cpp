#include <stdio.h>
using namespace std;
double Add(double a,double b)
{
    return a*b;
}

int main()
{
double a = 4.5;
double b = 2.5;
double ans = Add(a,b);
printf("%f + %f = %f\n",a,b,ans);
printf("Press enter to end the app\n");
return 0;
}
