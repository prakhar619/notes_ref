// ------incomplete-------------check for negative pow and no---------------

// int number, int power_raised  ---> int number^power_raised
// uses mod
// time Complexity: O(log n * M(n)) 
// time complexity: O(1)


/* int pow ( a, b)
	if b == 0
	then return 1
	
	c = pow( a, b/2)
	c = c*c
	
	if(b is odd)
	c = c*a
	
	return c
*/
	
int pow(int a,int b)
{
	if(b == 0)
	return 1;
	if(b == 1)
	return a;
	
	int c = pow(a,b>>1);
	c = c*c;		// O(M(n))
	if( (b>>1)<<1 -b  != 0)
	c= c*a;			// O(M(n))
	return c;
}


