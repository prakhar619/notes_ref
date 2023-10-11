// int a, int b ---euclid_gcd()----> int gcd(a,b)
// swap function used
// best case: O(logn ^3)
	/* Explanation: Let algo takes N steps
			then min(a,b) = F_n+1	 F_n denotes fibonacci nth seq number 		Proof needed	
			     max(a,b) = F_n+2							Proof needed
			
			Also F_n = phi^n	(phi: Golden ratio)
			     phi^n+1 = min(a,b)
			     n+1 = log(min(a,b))/log(phi)
			     n = O(log(min(a,b))
			     
			     Then each steps takes O(log ^2)    MOD FUNCTION
			     
			     Therefore 
			     O(log n ^3)
			     
//Space complexity: O(1)

/*
	Formula: 1. gcd(a, b) = gcd(b%a, a) = gcd( b, a%b)
		 2. gcd(a, xa) = a
	
	So we are finding gcd(a,b) like this 	a = b() + r0		gcd(a,b) 	where () is a/b and r0 is a%b
						b = r0() + r1		gcd(b,r0)
						r0 = r1() + r2
	we do this till last mod (r0, r1, r2) becomes zero
	then ans is term before it( b, r0, r1). 
	This is because when mod becomes zero it means it is now factor of the no.		
*/

int mod( int divident, int divisor)
{
	int q = divident / divisor;
	int r = divident - (q*divisor);
	return r;
}
int euclid_gcd(int a, int b)
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
		return a;
	
	
	
	return euclid_gcd(b,mod(a,b));		
}

		
	
	
