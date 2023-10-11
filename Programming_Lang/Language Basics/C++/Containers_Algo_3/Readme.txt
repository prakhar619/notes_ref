Standard Library Overview
1.Run Time Language support
    <chrono>
        duration
        time_point
2.String and I/O streams
    <string>
        string
        basic_string
    <fstream>
        fstream
        ifstream
        ofstream
    <iostream>
        istream 
        ostream 
        cin 
        cout 
    <sstream>
        istrstream
        ostrstream
3.Framework of Containers and Algo
    <algorithm>
        copy()
        find()
        sort()
    <utility>
        move()
        swap()
        pair
    <vector>
        vector
    <array>
        array
    <map>
        map
        multimap
    <set>
        set
        multiset
    <unordered_map>
        unordered_map
        unordered_multimap
4.Numerical Computation
    <cmath>
        sqrt()
        pow()
    <complex>
        complex
        sqrt()
        pow()
    <random>
        default_random_engine,normal_distribution
5.Regex
    <regex>
        regex
        smatch
6.Concurrent programming
    <future>
        future
        promise
    <thread>
        thread
    <mutex>
        unique_lock
        mutex
7.MetaProgramming
8.Smart pointers
    <memory>
        unique_ptr
        shared_ptr
        allocator
9.Special purpose containers such as array, bitset and tuple


Standard Library Namespace
    Standard Library is defined in namespace std;
    using namespace std; means make std names available without std:: prefix
