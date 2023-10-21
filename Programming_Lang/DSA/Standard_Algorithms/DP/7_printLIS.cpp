/* We are starting from 0 -> len
{10,20,3,2,55,50,30,2,1}
So first we push 10 (0,0)
Then we iterate i = 1;
Look for all array and find array with max size in vector (also vector max value should be less than ar[j] ar[1]

10	20	3	2	55	50	30	2	1

10	10	3	2	10	10	10	2	1	
	20			20	20	20
				55	50	30
				
Using DP
*/				
#include <vector>
using namespace std;

vector<vector<int>> print_LIS(int *ar,int len)
{
    vector<int> vx (1,ar[0]);
    vector<vector<int>> v1;
    v1.push_back(vx);
    for(int i = 1; i < len; i++)
    {
        int max_len = 0;
        int index = -1;
        for(int j = 0; j < i; j++)
        {
            int size_jth = v1[j].size();
            if(size_jth > max_len && (v1[j][size_jth -1] < ar[i]))
            {
                max_len = v1[j].size();
                index = j;
            }
        }
        if(index == -1)
        {
            vector<int> vy (1,ar[i]);
            v1.push_back(vy);
            continue;
        }
        v1.push_back(v1[index]);
        v1[i].push_back(ar[i]);
    }
    return v1;
}
