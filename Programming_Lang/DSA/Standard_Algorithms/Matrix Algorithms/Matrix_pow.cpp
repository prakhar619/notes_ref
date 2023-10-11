//matrix A(2d vector) , int power ------------> A^power (2d vector)
// uses matrix_multiplication
// Time complexity: O(lgp * n^3)		O(lgp * M(matrix))

#include <vector>
using namespace std;

vector<vector<int>> matrix_mult( vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> error(1,vector<int>(1,1))
	if(A[0].size() != B.size())
	{
		printf("Error order of matrix multiplied")
		return error;
	}
	vector<vector<int>> C(A.size(),vector<int>(B[0].size(),0));
	for(int i=0; i<C.size(); i++)
	for(int j = 0; j < C[0].size(); j++)
	for(int k = 0; k < A[0].size(); k++)
	C[i][j] += A[i][k] * B[k][j];
	return C;
}

vector<vector<int>> matrix_pow(vector<vector<int>> A, int p)
{
	vector<vector<int>> I (A.size(),vector<int>(A[0].size(),0);
	for(int i = 0; i<A.size(); i++)
	I[i][i] = 1;
	
	if(p = 0)
	return I;
	
	if(p = 1)
	return A;
	
	vector<vector<int>> C = matrix_pow(A,p/2);
	C = matrix_mult(C,C);
	
	if((p >> 1)<< 1 != p)
	C = matrix_mult(C,A);
	
	return C;
} 
