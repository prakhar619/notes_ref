// matrix A (2d vector m*n), matrix B(2d vector m*n), k = 1(for add k = 1, subtract k = -1)---matrix_add----> matrix A+B (2d vector m*n)
// A and B of same size; A and B passed without reference; all kinds of matrix
// Time Complexity: O(n*m) 	+(m*n times) 	=> O(b1*m*n)
// Space Complexity: O(n*m)

#include <vector>
vector<vector<int>> matrix_add(vector<vector<int>> A, vector<vector<int>> B, int k = 1)
{
	vector<vector<int>> C(A.size(), vector<int>(A[0].size(),0));
	for(int i = 0; i< A.size(); i++)
	for(int j = 0; j<A[0].size(); j++)
	C[i][j] = A[i][j] + (k*B[i][j]);
	return C;
}

