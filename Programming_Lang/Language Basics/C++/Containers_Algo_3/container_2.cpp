//vector
//list
//iterator
    //1.Container Iterators
    //2.Stream Iterators
//map (or associative array or dictionary)
    //binary tree
//unordered_map
    //provided with default hash functions for string

//Stream Iterators
#include <iterator>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Mimic writing into an array through pointer
    ostream_iterator<string> oo{cout};  //specify the stream in constructor parameter
    *oo = "HELLO,";
    ++oo;
    *oo = "WORLD!\n"; 

    
}