#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//backtracking
// O(2^n)
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    // Loop to choose from different elements present
    // after the current index 'index'
    for (int i = index; i < A.size(); i++) {
 
        // include the A[i] in subset.
        subset.push_back(A[i]);
 
        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);
 
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
 
    return;
}
 
// below function returns the subsets of vector A.
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
 
    // keeps track of current element in vector A
    // and the number of elements present in the array subset
    int index = 0;
    subsetsUtil(A, res, subset, index);
 
    return res;
}

// O(n*2^n)
void printPowerSet(char* set, int set_size)
{
    // Set_size of power set of a set with set_size
    // n is (2^n-1)
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    // Run from counter 000..0 to 111..1
    for (counter = 0; counter < pow_set_size; counter++) {
        for (j = 0; j < set_size; j++) {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if (counter & (1 << j))
                cout << set[j];
        }
        cout << endl;
    }
}
