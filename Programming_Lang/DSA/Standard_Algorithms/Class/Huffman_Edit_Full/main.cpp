//2103126
//2103131

#include "encoding.cpp"
#include "print_Edit_Distance.cpp"
#include <string>
using namespace std;
int main() 
{
    // Write C++ code here
    string s= "HELLO WORLD";
    string p = "MELLO EORDL";
    string c = edit_distance_dp(s,p);
    cout << "Operated String:" << c <<endl;
    cout << "Encoded DATA:" << encoding(c) << endl;
    return 0;
}
