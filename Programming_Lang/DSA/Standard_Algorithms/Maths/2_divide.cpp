// ------------------check for negative integers too-----------------

// int divident, int divisor ---------> pair<int,int>   ( first -> quotient, second -> remainder)
// no *, /, mod used; only relational operators and bit shift
// Time complexity: O(logn*(logm - logn)) or O(log n ^2)		or in bits O(b1*(b1-b2)) or O(b ^2)
// Space Complexity: 

/*(q,r) divide(x,y)
	{
		if (x = 0)
		return 0
		
		(q1,r1) = divide(x/2,y)
		q2 = 2q1;
		r2 = 2r1;
		
		if x = odd
		r3= r2+1; q3 = q2
		if x = even
		r3= r2; q3 = q2
		// now r may greater than y // 0 < r < 2y+1
		
		if(r3>y)
			r4 = r3 -y
			q4 = q3 +1
		
		
		return (q4,r4)
		
	}
*/

pair<int,int> divide(int a, int b)
{
	if(a == 0)
	{ pair<int,int> x; x.first = 0; x.second = 0; return x;}
	
	pair<int,int> div;
	div = divide(a>>1,b);
	div.first = div.first << 1;
	div.second = div.second << 1;
	
	if( ((a>>1)<<1)-a != 0)
	{
		div.second+=1;	// O(1) because remainder and quotient both even. 
	}
	
	if(div.second >= b)
	{
		div.second = div.second -b;	//
		div.first++;
	}
	
	return div;
}


