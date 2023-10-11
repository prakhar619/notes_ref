// int fibo_seq_number(0,1,2,3,4,...)  -----matrix_fibo()-----> long long fibonacci number
// uses remainder function
// Time Complexity: O(log n)				//Mutliplication * takes as O(1) else O(log n ^3)
// Space Complexity: O(1)

/* 	|F_n  |  =	|1	1|^n-1	* 	|F_1|
	|F_n-1| 	|1	0|		|F_0|
*/
#include <math.h>
using namespace std;
class matrix{
    public:
    long long  a11;
    long long  a21;
    long long  a22;
    long long  a12;
};

// matrix matrix(2*2), int power   ---> matrix^power
// 
// Time Complexity: O(log n)
// Space Complexity: O(1)

/* PSEDO CODE	//repeated squaring 
	exp(a,b)
	{
		if(b = 0)
		return 1;
		c = exp(a,b/2)
		c = c^2
		if(b = odd)
		c = c.a
		return c
*/
matrix exp(matrix arr_orig, int power)   
{   
    //defining indentity matrix => A^0 = I
    matrix I;
    I.a11 = 1;I.a12 = 0; I.a21=0;I.a22 = 1;
    
    
    
    if (power == 1)
    return arr_orig;
    if (power == 0)
    return I;

    matrix c;
    c = exp(arr_orig,power/2);

	//matrix multiplication  c = c^2
	matrix c1;
    	matrix c2;
    c1.a11 = c.a11*c.a11+c.a12*c.a21;
    c1.a12 = c.a11*c.a12+c.a12*c.a22;
    c1.a21 = c.a11*c.a21+c.a22*c.a21;
    c1.a22 = c.a21*c.a12+c.a22*c.a22;
    c = c1;
	
	// if b is odd
    if(remainder(power,2) != 0)
    {
        c2.a11 = c.a11*arr_orig.a11+c.a12*arr_orig.a21;
        c2.a12 = c.a11*arr_orig.a12+c.a12*arr_orig.a22;
        c2.a21 = arr_orig.a11*c.a21+c.a22*arr_orig.a21;
        c2.a22 = c.a21*arr_orig.a12+c.a22*arr_orig.a22;
        return c2;
    }
    else 
    return c;

}

long long matrix_fibo(int n)
{
	matrix arr;
    arr.a11 = 1;
    arr.a21 = 1;
    arr.a12 = 1;
    arr.a22 = 0;

	//first and second fibo sequence values
    int f_0 = 0;
    int f_1 = 1;
    //final f
    long long  f_I,f_i;
    
    if(n == 0)
    return f_0;
    else if(n==1)
    return f_1;
    	
        matrix new_arr = exp(arr,n-1);
        f_I = new_arr.a11*f_1 + new_arr.a12*f_0;		// 	|1	1|^n-1	|F1|
        f_i = new_arr.a21*f_1 + new_arr.a22*f_0;   		// 	|1	0|	|F0|
        
        
return f_I;
}

