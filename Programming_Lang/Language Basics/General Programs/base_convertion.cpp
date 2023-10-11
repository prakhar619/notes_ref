//General Base (0 to INFI)
//Alphabets not used
#include <iostream>
#include <algorithm>    //reverse function
#include <vector>

using namespace std; 
template <int base> class base_convertion
{
    private:
    vector<int> converted_no;
    public:
    base_convertion(int num)
    {
        while(num != 0)
        {
            converted_no.push_back(num % base);
            num = num/base;
        }
        reverse(converted_no.begin(),converted_no.end());
    }

    //Operator overload

    void print()
    {
        for (int temp : converted_no)
        cout << temp <<":";
        cout << endl;
    }
};

int main()
{
    cout << 51%5 << endl;
    base_convertion<5>obj(51);
    obj.print();
}

