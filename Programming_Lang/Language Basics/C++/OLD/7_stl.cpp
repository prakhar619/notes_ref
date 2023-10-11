#include <iostream>
#include <utility>//pair
#include <list>//list
#include <deque>//deque
#include <queue>//queue
#include <stack>//stack
#include <set>//set
#include <map>//map
using namespace std;

/*STL has 4 components
	Algorithm
	Containers
	Functions
	Iterators

Containers
	Sequence Containers
		vectors
		list
		deque
		array
		forward list
	Container Adaptors
		queue
		priorty queue
		stack
	Associative Container (quickly search 0(logn))
		Set
		Multiset
		Map
		Multimap
	Unordered Associative Container
		Unordered_set
		Unordered_multiset
		Unordered_map
		Unordered_multimap
*/
int main()
{
//pair
    pair<int,char> pair1;
    pair1.first = 100;
    pair1.second = 'g';

    pair<string,double> pair2 = make_pair("String", 102.2);
    pair<string,int> pair3 = {"hello",3};

// vector
	vector<int> v1;
	v1.push_back(10);
	v1.pop_back()
	v1.assign()
	v1.size()
	v1.max_size();
	v1.capacity();
	v1.resize(20);
	v1.empty()
	v1.shrink_to_fit()
	v1.reserve()
	
	v1.at(g)	//reference to element at position g
	v1.front()
	v1.back()
	v1.data()	//direct ptr to memory array internally used
	
	v1.clear()
	v1.swap()
	v1.insert()
	v1.erase()
	
	sort(v.begin(),v.end());
	
	
	vector<int> v2(n,10);					//n element with values 10
	vector<int> v3{1,2,3,5};				// direct
	vector<int> v4(ar, arr + sizeof(ar)/sizeof(ar[0]));	//array element in vector
	
	vector<vector<int>> v_2d(n, vector<int>(m, 20));	// 2d vector with n rows and m columns
	
	

//list
    list<int> ll;
    ll.push_back(10);
    ll.push_front(30);

    ll.pop_back();
    ll.pop_front();

    ll.reverse();
    
    ll.sort();

    ll.size();
    
    list<int> ll{1,3,4,62,5,3};
    

//Deque
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);

    dq.pop_back();
    dq.pop_front();

    dq.size();
    dq.max_size();

    dq.back();
    dq.front();

    dq.at(2);

//Queue
    queue<int> qu;
    qu.empty();

    qu.push(10);
    qu.pop();

    qu.front();

    qu.back();

    qu.size();

//vector
    vector<int> v1;
    v1.push_back(10);
    v1[0];
    v1.pop_back();
    v1.size();
//array

//forward list

//stack
	stack<int> stk;
	stk.push(21);
	stk.pop();
	stk.top();
	stk.empty();
	stk.size();
//priorty queue


//set
	set<int> st;
	set<int> st_defined = {1,2,4,3,10,-1};//default ascending order
	set<int, greater<int>>st_des = {11,3,4,2,5};//default descending order
	st.insert(10); //O(N)
	//binary search tree 
	st.size();
	st.empty();
	st.begin();
	st.end();
	st.max_size();
	st.clear();
	st.erase(iterator);

//map
	map<string,int> mapp;
	mapp["one"] = 1;	//O(1)
	map<string,int>::interator it = mapp.begin();
	while(it != mapp.end())
	{
		it++;
	}

	map<int,int> p;
	p.insert(pair<int,int>(1,40));
	p.erase(2);


}
/*Iterators


//is an object like a pointer that points to an element inside the container.
// can increment iterator to get pointer to next element in container.


//Types of Iterators
// Random access
// Bidirectional
// forward
// Input and output

// Input Iterators
	//Single pass algorithms

// Output Iterators
	//Single pass algorithms

//Forward Iterators
	//Only forward and one step at a time

//Bidirectional Iterators
	//Can also move in backward direction
	
//Random Access Iterators
	//can randomly access any element inside container.
	
//Vector : RA
//List	 : BD
//deque  : RA
//Map    : BD
//Multimap : BD
//Set   : BD
//Multiset : BD
//Stack, queue, priorty queue : NOT SUPPORTED

	vector<int> :: iterator it;
	it = vect.begin();
	till( it != vect.end());
	it++;
*/
