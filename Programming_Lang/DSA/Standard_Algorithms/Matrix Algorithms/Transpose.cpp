// matrix A(2d vector m*n) ---matrix_transpose----> matrix A_T (2d vector n*m)
// 
// Time complexity: O(n^2)
// Space Complexity: O(nm)

#include<vector>
using namespace std;

vector<vector<int>> matrix_transpose(vector<vector<int>> A)
{
	vector<vector<int>> A_T (A[0].size(), vector<int>(A.size(),0)
	
	for(int i = 0; i < A[0].size(); i++)
	for(int j = 0; j < A.size(); j++)
	A_T[i][j] = A[j][i];

	return A_T;
}
