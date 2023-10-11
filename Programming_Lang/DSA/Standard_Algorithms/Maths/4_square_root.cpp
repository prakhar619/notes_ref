/* 
STL sqrt() 
Library: <cmath>
time complexity: O(n^0.5)
space complexity: O(1)
*/ 








/* Method 1
Go from 1 to N and chech for every number
--------------But will work only for integer sqrt root or we can find floor sqrt
best case: O(sqrt(N))  or O(n^0.5)
Space Com : O(1)
*/


/* Method 2
Using same above method but using binary search as we have to find a number out of a sorted array 1 - N
------------ Integral square root only
best case: O(log x)
Space Com : O(1)
*/










// Method 3
// int number, double precision ---> double sqrt(number)
// 
// best case: O(M(n))  ----------------proof needed
// Space complexity: O(1)

/* Method 3
Newtons square root method
	N
	let x  = N
	while( N - (x*x) > precision_factor)
	x = (x + N/x ) * 0.5
*/
double sqrt(int N, double precision = 1e-10)
{
	double x = N;
	while( N - x*x > precision || N - x*x < -precision) 	
	x = (x + N/x) >> 1;					//O(M(n))
	return x;
}
	
