#include <math.h>
#include <iostream>  
using namespace std;

class fibonacci_series
{

	public:
	double golden_ratio(int n)
	{
		n-=1;
		const double fi = (1+sqrt(5))/2;
    		const double fi_i = (1-sqrt(5))/2;
	
    		long long f_nth = ( pow(fi,n) - pow(fi_i,n) ) / sqrt(5);
    		return f_nth;
    	}  	
};

int main()
	{
    		cout << "Enter the term of Fibonacci Series" << endl;
    		int n;
    		fibonacci_series obj;
    		cin >> n;
    		cout << "OUTPUT:"<< obj.golden_ratio(n) << endl;
    		return 1;
	}


