// incomplete
#include<iostream>
using namespace std;


//deference between passed by reference and without reference
// int* means pointer to an integer value
// int ** means pointer to a space which itself holds a pointer to integer (usually can be treated as 2d matrix)
// pointer can be to anything like class, struct, int, array etc;
// ** can also be 2d matrix of class
void nonRef(int a, int b)
{
	a = 10;
	b = 23;
}

void ref(int *a , int *b)			// parameter are pointer to integer (address)
{
	*a = 10;			// *(address) = value
	*b = 23;
}

void ref_mod(int& a, int &b)		// -----------?????----------
{
	a = 20;
	b = 30;
}	



//defining class object using new vs  defining class object
class test
{
	public:
	int val;
	test* next;
};



int main()
{
	int a = 5;
	int b = 12;
	nonRef(a,b);
	cout << a << " " << b << endl;
	ref(&a,&b);			// &a will give us pointer to a (address to a)
	cout << a << " " << b << endl;
	ref_mod(a,b);
	cout << a << " " << b << endl;
	cout << endl;
	cout << endl;
	
	class test new_test;			//creates memory object which is temporary; scope ends outside block  // dont return as function return
	class test* new_test1 = new test();     // create memory object which is permanent unless free + return pointer to the object
	class test* new_test2;
//	class test new_test4 = new test();	// syntax error


	string* st_array = new string[10];  	string array of size 10;
	new T[size]	std template
	
	new_test.val = 10;
	new_test.next = NULL;
	cout << new_test.val << endl;
	
	new_test1->val = 20;
	new_test1->next =NULL;
	cout << new_test1->val << endl;
	
//	new_test2->val = 30;	//This will result in segmentation dump 
//	new_test2->next = NULL;
	new_test2 = &new_test;
	cout << new_test2->val << endl;
	
	delete new_test1;
}
//use of ampersand;
	// ampersand to a value/object given its memory
	// used in pass by ref and printf
	



//-> vs .
// can directly be seen above 
// -> with pointers and . with object



