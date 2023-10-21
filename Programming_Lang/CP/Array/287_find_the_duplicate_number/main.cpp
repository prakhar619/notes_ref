#include <bits/stdc++.h>
using namespace std;
    
int findDuplicate(vector<int>& nums) {
vector<int> allN (nums.size()-1,0);
for(int x : nums)
{
    ++allN[x-1];
    if(allN[x-1] == 2)
    return x;
}
return -1;
}