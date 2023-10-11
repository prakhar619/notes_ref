// int inverse_no, int mod_base ----inverse_mod()-----> int integral_mod
// uses swap, This method of using extended gcd is only valid when inverse_no and mod_base have gcd = 1
// Time complexity: O(logn ^3)
// Space complexity: O(1)

/* Refer to extended euclid before inverse mod
	To solve a*x = 1 mod M			where x is to be found out
	x = 1/a mod M
	
	find x': x'a+yM = gcd(a,M) = 1	
	Then 
		x = (x'%M + M) %M
*/
int mod( int divident, int divisor)
{
	int q = divident / divisor;
	int r = divident - (q*divisor);
	return r;
}
int extended_euclid_gcd(int a, int b, int* x, int* y)
{

	if(a < b )
		swap(a,b);
	if(b == 0)
	{
		int gcd = a;
		*x = 0;
		*y = 1;
		return gcd;
	}
	
	int x1, y1;
	int gcd =  extended_euclid_gcd(b,mod(a,b), &x1, &y1);
	
	*x = y1 - (a/b) * x1;
	*y = x1;
	
	return gcd;
}

// if x^-1 mod y is given then inverted =  x and base = y
int inverse_mod(int inverted, int base)
{
	int x, y;
	int gcd = extended_euclid_gcd(inverted,base, &x,&y);
	int ans = -1;
	
	if(gcd != 1)
		cout << "Inverse dont exist";
	
	else
		ans = mod( (mod(x,base) + base), base);
	return ans;
}
	

