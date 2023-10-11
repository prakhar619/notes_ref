#include <bits/stdc++.h>
using namespace std;

//O(n)
bool linear_search(vector<int>& ar, int i)
{
    for(int x: ar)
    if(i == x)
    return true;
    return false;
}

//O(logn)
bool binary_search(vector<int>& ar, int i)
{
    int min_i = 0, max_i = ar.size()-1;
    while(max_i >= min_i)
    {
        int mid = (max_i+min_i)/2;
        if(i == ar[mid])
        {
            return true;
        }
        else if(i > ar[mid])
        {
            min_i = mid+1;
        }
        else if(i < ar[mid])
        {
            max_i = mid-1;
        }
    }
    return false;
}

//O(logn)
bool binary_search_alt(vector<int> ar,int i)
{
    int k =0;
    for(int b = ar.size()/2; b >=1 ; b/=2)
    {
        while(k+b < ar.size() && ar[k+b] <= i)
        {
            k+=b;
        }
    }
    if(ar[k] == i)
    return true;
    return false;
}

int main()
{
    vector<int> ar {1,2,3,4,5,6,7,8,9};
    int search = 6;
    cout << binary_search_alt(ar,search);

    //O(log n)  for lower and upperbound function
    //they assume array is sorted

    // iterator to 1st elem which has greater value than val
    auto k = lower_bound(ar.begin(),ar.end(),search);
    // k is vector<int>::iterator k
    int index = k - ar.begin();
    // index gives pos of that elem

    auto k_ = upper_bound(ar.begin(),ar.end(),search);
    //to get 1st elem which is smaller than search


    return 1;

}