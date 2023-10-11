
#include<string>
using namespace std;

int substring_present(string s, string part)
{
	int flag = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == part[0])
            {
                for(int j = 0; j < part.size(); j++)
                {
                    if(part[j] != s[i+j])
                    {
                        flag = 0;
                        break;
                    }
                    flag  = 1;
                }
            }
            if(flag == 1)
            return 1;
        }
        return 0;
}




#include<string>
#include<utility>
using namespace std;

pair<int,int> substring_present(string s, string part)
{
	int flag = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == part[0])
            {
                for(int j = 0; j < part.size(); j++)
                {
                    if(part[j] != s[i+j])
                    {
                        flag = 0;
                        break;
                    }
                    flag  = 1;
                }
            }
            if(flag == 1)
            {
                pair<int,int> out;
                out.first = 1;
                out.second = i;
                return out;
            }
        }
        pair<int,int> out;
        out.first = 0;
        out.second = -1;
        return out;
    }
