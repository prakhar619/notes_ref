// int fibo_seq_number(0,1,2,3, ...)  --> long long fibonacci number
// uses sqrt() and pow()
// best case:	O(log n ^3)							sqrt: O(log n^ 2)
//										pow: O(log n ^3)
//		

/*
	F_nth  = phi^i - phi_not^i / 5^(1/2)
	phi = 1 + 5^(1/2)  / 2
	phi_not  = 1 - 5^(1/2)  / 2
*/
#include <math.h>
using namespace std;

long long golden_ratio_fibo(int n)
{
    const double fi = (1+sqrt(5))/2;
    const double fi_i = (1-sqrt(5))/2;
	
    long long f_nth = ( pow(fi,n) - pow(fi_i,n) ) / sqrt(5);
    return f_nth;
}

