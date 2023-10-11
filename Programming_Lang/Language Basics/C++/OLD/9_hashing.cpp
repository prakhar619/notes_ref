#include <functional>
#include <iostream>
using namespace std;

int main()
{
    hash<int> funcHash;
    cout << funcHash(35) << endl;
    cout << funcHash(111000) << endl;

    hash<string> sHash;
    cout << sHash(" Hello world");
}