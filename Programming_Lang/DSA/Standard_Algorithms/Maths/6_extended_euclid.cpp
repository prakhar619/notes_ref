// int a, int b, int*x (return parameter), int*y (return parameter) -----extended_euclid_gcd------> gcd(a,b)   #also x and y
// swap function used
// Time complexity: O(logn ^3)
// Space complexity: O(1)

/* 	Pls first refer to euclid gcd to understand extended version
	ax + by = gcd(a,b)
	a = q0 b + r0		a/b		x,y
	b = q1 r0 + r1		b/r0		x1,y1
	r0 = q2 r1 + r2		r0/r1		x2,y2
	till r2 == 0				when r2 == 0 then xn,yn = 0,1 because yn is gcd
	then r1 is the ans
	r1 = q3 r2 + r3
	a       b
	
	After getting xn,yn we are going backward to get x,y from formula
	x_n-1 = yn - (b/a)x_n
	y_n-1 = x_n
	
		Proof: ax + by = gcd(a,b)
		       bx1 + (a%b)y1 = gcd(a,b)
		       therefore bx1 + (a%b)y1 = ax+by
		       also a%b  := b - (b/a)a		integer division
	
*/

int mod( int divident, int divisor)
{
	int q = divident / divisor;
	int r = divident - (q*divisor);
	return r;
}
int extended_euclid_gcd(int a, int b, int* x, int* y)
{
/* 	a = q0 b + r0		a/b
	b = q1 r0 + r1		b/r0
	r0 = q2 r1 + r2		r0/r1
	till r2 == 0
	then r1 is the ans
	r1 = q3 r2 + r3
	a       b
*/
	if(a < b )
		swap(a,b);
	if(b == 0)
	{
		int gcd = a;
		*x = 0;
		*y = 1;			//reason is that we are x_n and y_n for above recursion line; see theory given at start
		return gcd;
	}
	
	int x1, y1;
	int gcd =  extended_euclid_gcd(b,mod(a,b), &x1, &y1);
	
	*x = y1 - (a/b) * x1;
	*y = x1;
	
	return gcd;
}

		
	
	

