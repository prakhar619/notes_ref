#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define f(i,x,y,z)  for(int i = x; i <= y; i+=z)

//O(n^3)
int maxSubArraySum_brute(vi ar)
{
    //subarray means continous elements

    //starting at 0, check sum at each length
        //like 0
        //then 0,1
        //then 0,1,2
    //then 1 
    //1,2
    //1,2,3
    int sum_max = INT_MIN;
    f(i,0,ar.size()-1,1)
    {
        f(j,i,ar.size()-1,1)
        {
            int sum = 0;
            f(k,i,j,1)
            {
                sum += ar[k];
            }
        sum_max = max(sum,sum_max);
        }
    }
    return sum_max;
}

//O(n^2)
int maxSubArraySum_bebrute(vi ar)
{
    int sum_max = INT_MIN;
    f(i,0,ar.size()-1,1)
    {
        int sum = 0;
        f(j,i,ar.size()-1,1)
        {
            sum+= ar[j];
            sum_max = max(sum,sum_max);
        }
    }
    return sum_max;
}

//O(n)
int maxSubArraySum_kadane(vi ar)
{
    int sum_max = INT_MIN;
    int sum = 0;
    f(i,0,ar.size()-1,1)
    {
        sum+= ar[i];
        if(sum <= 0)
        sum = 0;
        sum_max = max(sum,sum_max);
    }
    return sum_max;
}




int main()
{
    vi k{-1,2,4,-3,5,2,-5,2};
    //int max =  maxSubArraySum_brute(k);
    //int max = maxSubArraySum_bebrute(k);
    int max = maxSubArraySum_kadane(k);
    cout << "SubArrayMax:" << max << "\n";
}
