#include <iostream>
#include <string>
using namespace std;

string add(string nu1, string nu2, int pos)
    {
        if(nu1 == "" && nu2 == "")
        return "0";
        string added = "";
        int nu1_index = nu1.size()-1;
        int nu2_index = nu2.size()-1;
        while(pos != 0 && nu1_index >= 0)
        {
            added = nu1[nu1_index] + added;
            pos--;
            nu1_index--;
            
        }
        while(pos != 0)
        {
            added = "0" + added;
            pos--;
        }
        //cout << added << endl;
        //cout << "NU1 index:"<<nu1_index << endl;
        //cout << "NU2 index:"<<nu2.size()-1 << endl;
        string big;
        string small;
        if(nu1_index >= nu2_index )
        { 
            big =  nu1.substr(0,nu1_index+1);
            small =  nu2;
        }
        else
        {
            small =  nu1.substr(0,nu1_index+1);
            big =  nu2;
        }

        //cout <<"SMALL:" << small << endl;
        //cout <<"BIG:" << big << endl;
        int big_index = big.size()-1;
        int small_index = small.size()-1;
        int carry = 0;
        while(small_index >= 0)
        { 
            int adde = (big[big_index] - '0') + (small[small_index] - '0') + carry;
            added = to_string(adde % 10) + added;
            carry = adde/10;
            big_index--;
            small_index--;
        }
        while(big_index >= 0)
        {
            int add = (big[big_index] - '0') + carry;
            added = to_string(add % 10) + added;
            carry = add/10;
           big_index--;
        }
        if(carry != 0)
        added = to_string(carry) + added;
        return added;
    }

void multiply(string s1,string s2, string& final,int index_do)
{
    //assuming s1 > s2
    if(index_do >= s2.size())
    return;
    int lower_mul  = s2[s2.size()-1-index_do] - '0';
    int carry = 0;
    string newFinal = "";
    for(int i = s1.size()-1;i >= 0; i--)
    {
         int mult = (s1[i]-'0')*lower_mul + carry;
         carry = mult/10;
        newFinal  = to_string(mult%10) + newFinal;
    }
    if(carry != 0)
    newFinal = to_string(carry) + newFinal;
    //cout << newFinal << endl;
    final = add(final,newFinal,index_do);
    cout << final << endl;
    multiply(s1,s2,final,++index_do);
    return;
}
int main()
{
    //cout << add("","0",0) << endl;
    string s = "";
    multiply("123456789","987654321",s,0);
    cout << s << endl;
    return 1;

}