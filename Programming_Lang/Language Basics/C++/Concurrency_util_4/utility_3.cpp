#include <chrono>
#include <iostream>
using namespace std;

int clock_util()
{
    auto  t0 =  chrono::high_resolution_clock::now();           //returns time_point type
    auto t1 = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(t0-t1).count() << " msec" << endl;
    return 1;
}

//TYPE Functions
//a function that is evaluated at compile time given a type as its argument or returning a type
//MetaProgramming or Template Metaprogramming
    //Eg: iterator_traits <iterator> and type predicates <type_traits> 
#include <limits>
void type_function()
{
    constexpr float min = numeric_limits<float>::min();
    cout << "MIN FLOAT VALUE:" << min << endl;
    constexpr int szi = sizeof(int);
}

#include <vector>
#include <forward_list>
#include <algorithm>

//Iterators_traits
#include <iterator>
template<typename ran>
void sort_helper(ran begin,ran end,random_access_iterator_tag)
{
    sort(begin,end);
}
template<typename forr>
void sort_helper(forr begin, forr end, forward_iterator_tag)
{
    vector<decltype(*begin)>v{begin,end};       //decltype function returns declared type of its argument //we are initialising a new vector with value of the iterator
    sort(v.begin(),v.end());
    copy(v.begin(),v.end(),begin);
}
//defining 2 type functions
template<typename C>
using Iterator_type = typename C::iterator;     //iterator type of C

template<typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;       //constructs a tag value indicating the kind of iterator

template<typename C>
void sort(C& c)
{
    using Iter = Iterator_type<C>;
    sort_helper(c.begin(),c.end(),Iterator_category<Iter>{});
}

//TYPE Predicates
#include <type_traits>
int type_predicates()
{
    bool b1 = is_arithmetic<int>();
    bool b2 = is_arithmetic<string>();
    //is_class
    //is_pod
    //is_literal_type
    //has_virtual_destructor
    //is_base_of
    return 1;
}


//Pair and Tuple
void data_str()
{
    pair<int,double> px {1,1.1};
    auto py = make_pair(1,"helo");
    px.first;
    px.second;

    //when more than 2 elements
        //compile time access
    tuple<string,bool,int> ty {"helooo",true,3};
    auto tx = make_tuple("helo",1,2,true);
    get<0>(tx);
    get<1>(tx);
}

//Vector for Numerical Calculations
#include <valarray>
int vector_arithmetic()
{
    valarray<double> a;
    return 1;
}

#include <limits>
void limit_lib()
{
    numeric_limits<char>::is_signed;
    constexpr float min = numeric_limits<float>::min();

}


int main()
{
    clock_util();
    type_function();
    vector<int> v {1,2,3,4,5,6,-1};
    forward_list<int> l {1,2,3,4,5,6,-1};
    sort(v);
   // sort(l);// ------------------------dont know what is wrong
   type_predicates();
   data_str();
   vector_arithmetic();
   limit_lib();
}