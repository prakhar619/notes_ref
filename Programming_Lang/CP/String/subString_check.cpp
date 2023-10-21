#include <string>
#include <iostream>
using namespace std;

//checks if s is totally made of sub
// like ab ababab -> true
// not ab abcabc -> true
bool substring_check(string sub,string s)
    {
        int subLen= sub.length();
        int len = s.length();
        int subIndex = 0;
        for(int i = 0; i< len; i++)
        {
            if(sub[subIndex] != s[i])
            return false;
            subIndex++;
            subIndex = subIndex % subLen;
        }
        if(subIndex == 0)
        return true;
        return false;
    }

//checks if sub is a substring of s or not
// ONE OF THE VERY BEST
// O(n^2) worst case time complexity
// O(n)  best casea time complexity
bool substring_normal_check(string sub,string s)
{
        int len = s.length();
        int subLen = sub.length();
        int j = 0;
        if(len < subLen)
        return false;
        for(int i = 0; i< len; i++)
        {
            if(sub[j] == s[i])
            {
                j++;
            }
            else
            {
                i = i - j;
                j = 0;
            }
            if(j == subLen)
            {
                return true;
            }
        }
        return false;
}

int main()
{
    string s = "bacababacababacababaca";
    string sub = "abacababacab";
    cout << substring_check(sub,s) << endl;
    cout << substring_normal_check(sub,s) << endl;
    cout << s.substr(2,3) << endl;
    return 1;
}