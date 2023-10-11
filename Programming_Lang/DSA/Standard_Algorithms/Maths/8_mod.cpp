/* 
STL mod()
Library: Universal
Gives -ve ans also
*/




// Method 1
// int a(can be negative), int b(should be positive) ----> int a%b
// answer will always be positive and inverse is not calculated only normal mod

// Time complexity: O(logn ^2)
// Space complexity: O(1)

int mod(int a, int b)
{
	int q = a/b;
	int r = a - q*b;
	if(r < 0)
	r+=b;
	return r;
}
