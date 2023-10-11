// int a, int b ---------> int a*b
// no *, /, mod used; only bit shift and relational operators used;
// Time Complexity: O(log n * log m) or O(log n  ^2)			or in bits O(b1 * b2) or O(b1^2)
// Space Complexity: O(1)

/*multiply (x,y)
{
	if y = 1 return x
	
	if y = odd
	return x + 2*multiply(x,y/2)
	if y = even
	return 2* multiply(x,y/2)
	
}

min no of bits for a(m bits) and b(n bits)
then a*b requires m+n bits atleast to cover the worst case.
Proved by taking upper bound yet m+n-1 cannot cover the worst case
*/


int multiply(int a, int b)
{
	if(b == 0)
	return 0;
	int c = multiply(a,b>>1);
	c = c << 1;
	if(((b>>1)<<1)- b != 0)		// shift right by one bit once then shift left by one bit then compare with original 
	c = c+a;		//O(log n)	// if minus result zero then even else odd
	return c;
}





	
