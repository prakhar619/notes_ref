#include <vector>  
#include <iostream>
using namespace std;

vector<int> MultiplyAllValues(vector<int>& input, int multiplier)
{
	vector<int> output(input.size());
	for (vector<int>::const_iterator it = input.begin(); it == input.end(); it++)
	{
		output.push_back(*it * multiplier);
	}
	//we are returning a local variable
	//rvo or return value optimisation might be applied
		//RVO (return value optimisation or Copy Elision (omitting copy)
		//compiler can create temp copy using different constructor
	return output;
}

int basics() {
	//Auto
	//Earlier auto was used as a Storage Class Specifier (along with Static, Register and Extern)
	//Only one of these could be used on a given variable
	//Auto was default meaning: local scope and should be allocated in register if possible else program stack
	//In C++11 it is a Type Specifier
	vector<int> collections(10, 0);
	auto collections2 = collections;



	//Nullptr
	//Earlier null was used which is a macro for 0
	//Cause problem when cast to (void*) or (char*)

	//Foreach type loop
	for (int num : collections2)
	{
		std::cout << num << " ";
	}

	//Override
	//virtual keyword can lead to confusion because it makes no distinction between
		//introducing a new virtual function into a class
		//overriding an inherited virtual function
		//implementing a leaf function function that is not intended to be overriden by derived class
	//Also no virtual keyword is required when overiding is required

	//Overriding before a function means it is meant to override a virtual function
	//final means it cannot be overridden by derived class

	//Strongly typed enums
	enum class Color : int { Red, Green, Blue, White, Black };
	Color c = Color::Red;

	//Smart Pointers
	//unique_ptr, shared_ptr, weak_ptr
	//unique_ptr: Single Ownership over the object being referred
	//shared_ptr: Multiple Ownership 
	//weak_ptr: Multiple Ownership but are not counted/contribute to reference count; back pointers

	//Lambda Functions
	//anonmous function for inlining
	auto pos = find_if(begin(collections2), end(collections2),
		[](int n) { return (n % 2 == 1); });

	//Move Semantics and r value
	//atleast 2 copies
	collections2 = MultiplyAllValues(collections2, 5); //copy created when values transfered from return value to variable
	//copy variable thrown immediately
	//TO OPTIMISE THIS USE R VALUE CONSTRUCTOR
		//(vector<T>&& vector_constructor) /r value
		//r value itself is an l value but its values is r value

	return 0;
}
