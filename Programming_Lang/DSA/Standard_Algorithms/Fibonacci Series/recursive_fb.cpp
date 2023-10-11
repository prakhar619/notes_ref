// int fibo_seq_number(0,1,2,3,4,...) ----> long long fibonacci number
//
// Time Complexity:	O(2^n)
	/* 		O(1)
		O(1)		O(1)
	      O(1) O(1)       O(1) O(1)
	*/
	
// Space Complexity:    O(1)

/* 
F_n = F_n-1 + F_n-2
*/

long long recursive_fibo (int  n)
{
	if( n == 0 || n ==1)
		return n;
	return recursive_fibo(n-1)+recursive_fibo(n-2);
}



