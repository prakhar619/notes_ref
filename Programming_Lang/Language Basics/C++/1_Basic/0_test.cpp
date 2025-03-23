#include <iostream>
using namespace std;
class test
{
    private:
    int x,y;
    public:
        test(): x{0}, y(0) {}
        test(int x,int y): x{x},y{y}{}
        void setx(int val){x = val;}
        void sety(int val){y = val;}
        int getx(){return x;}
        int gety(){return y;}
};

int main()
{
    cout << "HELLO WORLD" << endl;
    class test classObj;                //DEFAULT CONSTRUCTOR INVOKED
    cout << "CLASS OBJECT:" << classObj.getx() << endl;
    class test* instanceObj = new test(10,70);
    cout << "INSTANCE OBJECT:" << instanceObj->getx() << endl;
    class test classObj1(10,30);
    //class test classObj1; classObj1(10,20); THIS IS NOT ALLOWED
    return 1;
}