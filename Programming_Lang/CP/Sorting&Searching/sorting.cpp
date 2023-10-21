#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;



//O(n^2)
void bubblesort(vi& ar)
{
    
}

//O(nlogn)
void mergesort(vi& ar)
{

}

//O(n)
void countsort(vi& ar)
{
    //  ar[i]<9
}

//O(n)
void radixsort(vi& ar)
{

}

class P
{
    public:
    int x;
    int y;
    //user defined compartor operator
    bool operator<(const P &obj)
     {   if(x!=obj.x) return x < obj.x; //return true if element is smaller than para
        else return y < obj.y;
     }
};

bool com(string a, string b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    return a<b;
}

int main()
{
    vi ar {1,2,3,4,5,6,56,2,7,7,8,5,4,2};
    sort(ar.begin(),ar.end());

    vector<pair<int,int>> ar_p;
    ar_p.push_back({1,2});
    ar_p.push_back({4,3});
    ar_p.push_back({5,2});
    sort(ar_p.begin(),ar_p.end());//sorting based on 1st element if equal then 2nd element

    tuple<int,int,int,int> k;
    k = {1,2,3,5};

    //user defined data types
    P ob,ob2,ob3;
    ob.x = 1;
    ob.y = 2;
    ob2.x = 2; ob2.y = 3;
    ob3.x = 2; ob3.y = 4;
    vector<P> v_P;
    v_P.push_back(ob2);
    v_P.push_back(ob3);
    v_P.push_back(ob);
    sort(v_P.begin(),v_P.end());
    for(P m : v_P)
    {
        cout << m.x << " "<< m.y << "\n";
    }

    //another method
    //sort(v.begin(),v.end(),comp);

}
