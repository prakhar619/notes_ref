#include <bits/stdc++.h>
using namespace std;

int main()
{
    // (a+b) mod m =( (a mod m) + (b mod m) )mod m;
    // (a.b) mod m =( (a mod m) . (b mod m) )mod m;

    //also divident is pos then remainder pos
    //-10 / 3 = -3  rem = -1
    cout << "-10/3:" << "Q:" << -10/3 << " R:" << -10%3 << "\n";
    cout << "10/-3:" << "Q:" << 10/-3 << "R:" << 10%-3 << "\n";

    return 1;
}

