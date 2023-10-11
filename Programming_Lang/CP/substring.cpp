#include <string>
#include <iostream>
using namespace std;

//No of substring : O(n^2)      Actually n char in string then: n+n-1+n-2+n-3+n-4+....2+1 =(n^2+n)/2

// O(n^3) Time Complexity
// O(1) Space Complexity (directly print from there)
// i is start index of substring
// j is end index of substring
// k to iterate from i to j
void substring1(string s)
{
    int len  = s.length();
    for(int i = 0; i< len; i++)
    {
        for(int j = i; j< len; j++)
        {
            string sub = "";
            for(int k = i; k <= j; k++)
            {
                sub += s[k];
            }
            //if used char array append \0 null
           // printf("%s\n",sub);       //printf does not work with c++ string type
            cout << sub << endl;  
        }
    }
}

// O(n^2) Time Complexity
// O(n) Space Complexity
// i is start of substring
// j is end of substring + using previous substring
void substring2(string s)
{
    int len = s.length();
    for(int i = 0; i < len; i++)
    {
        string sub ="";
        for(int j = i; j < len; j++)
        {
            sub += s[j];
            cout << sub << endl;
        }
    }
}

int main()
{
    string m ="abcd";
    substring2(m);
    return 1;
}