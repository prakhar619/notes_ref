// matrix A(2d vector m*n),  matrix B(2d vector n*o) ----matrix_mult...-----> matrix A*B(2d vector m*o)
#include<vector>
using namespace std;

// O(n^2) for 2d matrix addition
vector<vector<int>> matrix_add(vector<vector<int>> A, vector<vector<int>> B, int k = 1)
{
	vector<vector<int>> C(A.size(), vector<int>(A[0].size(),0));
	for(int i = 0; i< A.size(); i++)
	for(int j = 0; j<A[0].size(); j++)
	C[i][j] = A[i][j] + (k*B[i][j]);
	return C;
}

// matrix A(2d vector m*n),  matrix B(2d vector n*o) ----matrix_mult...-----> matrix A*B(2d vector m*o)
// general matrix multiplication
// Time complexity: O(n^3)	*(n^3 times)	+(n^3 times)
// Space complexity: O(m*o)

/* 
AB_ij = ADD_k_0_n Aik + Bkj
*/
vector<vector<int>> matrix_mult( vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> error(1,vector<int>(1,1));
	if(A[0].size() != B.size())
	{
		printf("Error order of matrix multiplied");
		return error;
	}
	vector<vector<int>> C(A.size(),vector<int>(B[0].size(),0));
	for(int i=0; i<C.size(); i++)
	for(int j = 0; j < C[0].size(); j++)
	for(int k = 0; k < A[0].size(); k++)
	C[i][j] += A[i][k] * B[k][j];
	return C;
}










// matrix A(2d vector m*n),  matrix B(2d vector n*o) ----matrix_mult...-----> matrix A*B(2d vector m*o)
// uses matrix_add; general matrix multiplication; 
// Time complexity: O(n^3)		 O(n^2) + O(n^2)+ 8T(n/2) + O(n^2)  = 3O(n^2) + 8T(n/2)  => O(n^3) Master's method
// Space complexity: O(m*o)

/* A = 	[ a | b ]
	[ c | d ] 
	
  B =	[ e | f ]
  	[ g | h ]
  	
  AB = 	[ ae+bg | af+bh ]
  	[ ce+dg	| cf+dh ]
  	
*/
vector<vector<int>> matrix_mult_DnC(vector<vector<int>> A, vector<vector<int>> B)
{
	// adjust if A and B are not square matrix of even order
	
	
	
	// A and B are now square matrix of same order
	vector<vector<int>> C(A.size(), vector<int>(A.size(),0));
	
	if(A[0].size() == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	int split_index = A[0].size()/2;
	
	// declaring submatrix
	vector<vector<int>>A_split_a (split_index,vector<int>(split_index,0));
	vector<vector<int>>A_split_b (split_index,vector<int>(split_index,0));
	vector<vector<int>>A_split_c (split_index,vector<int>(split_index,0));
	vector<vector<int>>A_split_d (split_index,vector<int>(split_index,0));
	
	vector<vector<int>>B_split_e (split_index,vector<int>(split_index,0));
	vector<vector<int>>B_split_f (split_index,vector<int>(split_index,0));
	vector<vector<int>>B_split_g (split_index,vector<int>(split_index,0));
	vector<vector<int>>B_split_h (split_index,vector<int>(split_index,0));
	
	vector<vector<int>>C_split_a (split_index,vector<int>(split_index,0));
	vector<vector<int>>C_split_b (split_index,vector<int>(split_index,0));
	vector<vector<int>>C_split_c (split_index,vector<int>(split_index,0));
	vector<vector<int>>C_split_d (split_index,vector<int>(split_index,0));
	
	// initialising submatrix
	for(int i = 0; i< split_index; i++)
	{
		for(int j = 0; j < split_index; j++)
		{
			A_split_a[i][j] = A[i][j];
			A_split_b[i][j] = A[i][j+split_index];
			A_split_c[i][j] = A[i+split_index][j];
			A_split_d[i][j] = A[i+split_index][j+split_index];
			
			B_split_e[i][j] = B[i][j];
			B_split_f[i][j] = B[i][j+split_index];
			B_split_g[i][j] = B[i+split_index][j];
			B_split_h[i][j] = B[i+split_index][j+split_index];
		}
	}	
	
	//8 multiplication part
		C_split_a = matrix_add(matrix_mult_DnC(A_split_a,B_split_e),matrix_mult_DnC(A_split_b,B_split_g));
		C_split_b = matrix_add(matrix_mult_DnC(A_split_a,B_split_f),matrix_mult_DnC(A_split_b,B_split_h));
		C_split_c = matrix_add(matrix_mult_DnC(A_split_c,B_split_e),matrix_mult_DnC(A_split_d,B_split_g));
		C_split_d = matrix_add(matrix_mult_DnC(A_split_c,B_split_f),matrix_mult_DnC(A_split_d,B_split_h));
	
	//creating one matrix out of 4 subparts
		for( int i = 0; i< split_index; i++)
		for( int j = 0; j< split_index; j++)
		{
			C[i][j] = C_split_a[i][j];
			C[i][j+split_index] = C_split_b[i][j];
			C[i+split_index][j] = C_split_c[i][j];
			C[i+split_index][j+split_index] = C_split_d[i][j];
		}
		
		
		A_split_a.clear();
		A_split_b.clear();
		A_split_c.clear();
		A_split_d.clear();
		
		B_split_e.clear();
		B_split_f.clear();
		B_split_g.clear();
		B_split_h.clear();
		
		C_split_a.clear();
		C_split_b.clear();
		C_split_c.clear();
		C_split_d.clear();
	return C;
}















// matrix A(2d vector m*n),  matrix B(2d vector n*o) ----matrix_mult...-----> matrix A*B(2d vector m*o)
// uses matrix_add; general matrix multiplication; 
// Time complexity: O(n^2.8)		 O(n^2) + O(n^2)+ 7T(n/2) + O(n^2)  = 3O(n^2) + 7T(n/2)  => O(n^2.8) Master's method
// Space complexity: O(m*o)


/* 
A = 	[ a | b ]
	[ c | d ] 
	
B =	[ e | f ]
  	[ g | h ]
  	
p1 =  a(f-h)
p2 = (a+b)h
p3 = (c+d)e
p4 = d(g-e)
p5 = (a+d)(e+h)
p6 = (b-d)(g+h)
p7 = (a-c)(e+f)

  
AB = 	[ p5+p4-p2+p6 | p1+p2 	    ]
	[ p3+p4	      | p1+p5+p3-p7 ]
	
*/		
  	
vector<vector<int>> C matrix_mult_strassen( vector<vector<int>> A, vector<vector<int>> B)
{
	//adjusting A and B to be even ordered matrix
	
		

	vector<vector<int>> C(A.size(), vector<int>(A.size(),0));
	
	if(A[0].size() == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	int split_index = A[0].size()/2;
	
	// declaring submatrix
	vector<vector<int>>A_split_a (split_index,vector<int>(split_index,0));
	vector<vector<int>>A_split_b (split_index,vector<int>(split_index,0));
	vector<vector<int>>A_split_c (split_index,vector<int>(split_index,0));
	vector<vector<int>>A_split_d (split_index,vector<int>(split_index,0));
	
	vector<vector<int>>B_split_e (split_index,vector<int>(split_index,0));
	vector<vector<int>>B_split_f (split_index,vector<int>(split_index,0));
	vector<vector<int>>B_split_g (split_index,vector<int>(split_index,0));
	vector<vector<int>>B_split_h (split_index,vector<int>(split_index,0));
	
	vector<vector<int>>C_split_a (split_index,vector<int>(split_index,0));
	vector<vector<int>>C_split_b (split_index,vector<int>(split_index,0));
	vector<vector<int>>C_split_c (split_index,vector<int>(split_index,0));
	vector<vector<int>>C_split_d (split_index,vector<int>(split_index,0));
	
	// initialising 
	for(int i = 0; i< split_index; i++)
	{
		for(int j = 0; j < split_index; j++)
		{
			A_split_a[i][j] = A[i][j];
			A_split_b[i][j] = A[i][j+split_index];
			A_split_c[i][j] = A[i+split_index][j];
			A_split_d[i][j] = A[i+split_index][j+split_index];
			
			B_split_e[i][j] = B[i][j];
			B_split_f[i][j] = B[i][j+split_index];
			B_split_g[i][j] = B[i+split_index][j];
			B_split_h[i][j] = B[i+split_index][j+split_index];
		}
	}	
	
	vector<vector<int>> p1 = matrix_mult_strassen(A_split_a,matrix_add(B_split_f,B_split_h,-1));
	vector<vector<int>> p2 = matrix_mult_strassen(matrix_add(A_split_a,A_split_b),B_split_h);
	vector<vector<int>> p3 = matrix_mult_strassen(matrix_add(A_split_c,A_split_d),B_split_e);
	vector<vector<int>> p4 = matrix_mult_strassen(A_split_d,matrix_add(A_split_g,A_split_e,-1));
	vector<vector<int>> p5 = matrix_mult_strassen(matrix_add(A_split_a,A_split_d),matrix_add(B_split_e,B_split_h));
	vector<vector<int>> p6 = matrix_mult_strassen(matrix_add(A_split_b,A_split_d,-1),matrix_add(B_split_g,B_split_h));
	vector<vector<int>> p7 = matrix_mult_strassen(matrix_add(A_split_a,A_split_c,-1),matrix_add(B_split_e,B_split_f));
	
		C_split_a = matrix_add(matrix_add(p5,matrix_add(p4,p6)),p2,-1);
		C_split_b = matrix_add(p1,p2);
		C_split_c = matrix_add(p3,p4);
		C_split_d = matrix_add(matrix_add(matrix_add(p1,p5),p3,-1),p7,-1);
	
	//creating one matrix out of 4 subparts
		for( int i = 0; i< split_index; i++)
		for( int j = 0; j< split_index; j++)
		{
			C[i][j] = C_split_a[i][j];
			C[i][j+split_index] = C_split_b[i][j];
			C[i+split_index][j] = C_split_c[i][j];
			C[i+split_index][j+split_index] = C_split_d[i][j];
		}
		
		
		A_split_a.clear();
		A_split_b.clear();
		A_split_c.clear();
		A_split_d.clear();
		
		B_split_e.clear();
		B_split_f.clear();
		B_split_g.clear();
		B_split_h.clear();
		
		C_split_a.clear();
		C_split_b.clear();
		C_split_c.clear();
		C_split_d.clear();
		
		p1.clear();
		p2.clear();
		p3.clear();
		p4.clear();
		p5.clear();
		p7.clear();
	
	return C;
	
}
		
		

	


		 
