
using namespace std;

#include <string>
    //String is mutable
int string_functions()
{
    string s = "HELLO WORLD";
    string add = s+" NEW WORLD";
    s[2] = 'i'; //String is mutable
    string substring = s.substr(2,5);
    s.replace(0,5,"WOW");
}

#include <iostream>
struct Entry{
    string name;
    int number;
};
ostream& operator<<(ostream& os,const Entry& e)
{
    return os<<"{\"" << e.name << "\"," << e.number << "}";
}
istream& operator>>(istream& is, Entry& e)
{
    // is >> c skips whitespace 
    // is.get(c) does not
    char c, c2;
    if(is >> c && c=='{' && is >> c2 && c2 == '"')
    {
        string name;
        while(is.get(c) && c!='"')
        {
            name+=c;
        }
        if(is >> c && c==',')
        {
            int number = 0;
            if(is >> number >> c && c=='}')
            {
                e = {name,number};
                return is;
            }
        }
    }
    return is;
}

int main()
{
    Entry e;
    cin >> e;
    cout << e;
}