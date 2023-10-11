#include <iostream>
#include <utility>
using namespace std;
template <int M> class ModN
{
	private:
	int mod_eq;

	pair<int,int> divide(int a, int b)
	{
		if(a == 0)
		{ pair<int,int> x; x.first = 0; x.second = 0; return x;}
		
		pair<int,int> div;
		div = divide(a>>1,b);
		div.first = div.first << 1;
		div.second = div.second << 1;
		
		if( ((a>>1)<<1)-a != 0)
		{
			div.second+=1;
		}
		
		if(div.second >= b)
		{
			div.second = div.second -b;
			div.first++;
		}
		return div;
	}

	int extended_euclid_gcd(int a, int b, int* x, int* y)
	{

		if(a < b )
		swap(a,b);
	if(b == 0)
	{
		int gcd = a;
		*x = 0;
		*y = 1;
		return gcd;
	}
	
	int x1, y1;
	int gcd =  extended_euclid_gcd(b,divide(a,b).second, &x1, &y1);
	
	*x = y1 - (a/b) * x1;
	*y = x1;
	
	return gcd;
	}
	
	int mod(int a,int b)
	{
	    return a%b;
	}

// if x^-1 mod y is given then inverted =  x and base = y
	int inverse_mod(int inverted, int base)
	{
	int x, y;
	int gcd = extended_euclid_gcd(inverted,base, &x,&y);
	int ans = -1;
	
	if(gcd != 1)
		cout << "Inverse dont exist";
	
	else
		ans = mod( (mod(x,base) + base), base);
	return ans;
	}
	


	public:
	ModN(int num)
	{
	    while(num < 0)
	    {
	        num+=M;
	    }
		mod_eq = divide(num, M).second;
		if(mod_eq < 0)
		mod_eq += M;
	}
	
	ModN()
	{
		mod_eq = 0;
	}

	ModN<M> operator+ ( ModN<M> b)
	{
		class ModN<M> new_mod(mod_eq+b.mod_eq);
		return new_mod;
	}
	
	ModN<M> operator- (ModN<M> b)
	{	
		class ModN<M> new_mod(mod_eq-b.mod_eq);
		return new_mod;
	}
	
	ModN<M> operator* (ModN<M> b)
	{
		class ModN<M> new_mod(mod_eq*b.mod_eq);
		return new_mod;
	}
	
	
		
	ModN<M> operator++()	//prefix
	{
		class ModN<M> new_mod(mod_eq+1);
		mod_eq = new_mod.mod_eq;
		return new_mod;
	}
	
	ModN<M> operator++(int)	//postfix
	{
		class ModN<M> new_mod(mod_eq+1);
		
		class ModN<M> dup;
		dup.mod_eq = mod_eq;
		
		mod_eq = new_mod.mod_eq;
		return dup;
	}
	
	void printv()
	{
		cout << mod_eq << endl;
	}
	
	ModN<M> findInverse( ModN<M> b)
	{
		if( b.mod_eq == 0)
		throw overflow_error("Divide by zero exception");
		class ModN<M> new_mod(inverse_mod(b.mod_eq, M));
		return new_mod;
	}
	
	ModN<M> operator/ (ModN<M> b)
	{
	     class ModN<M> new_mod2;
		try{new_mod2 = findInverse(b);}
		catch ( overflow_error &e)
		{
			cout << e.what() << "->" ;
			return 0;
		}
		class ModN<M> new_mod(mod_eq*new_mod2.mod_eq);
		return new_mod;
	}
		
};

int main()
{
	ModN<20> x(234);
	ModN<20> y(0);
	cout << "x: " ;
	x.printv();
	cout << "y: " ;
	y.printv();
	
	cout << "x+y:";
	ModN<20> z = x+y;
	z.printv();
	cout << "x-y:";
	ModN<20> z1 = y-x;
	z1.printv();

	cout << "x*y:";
	ModN<20> z2 = x*y;
	z2.printv();
	cout << "x/y:";
	ModN<20> z3 = x/y;
	z3.printv();
	cout << "x++:" ;
	ModN<20> z4 = x++;
	z4.printv();
	cout << "++x:" ;
	ModN<20> z5 = ++x;
	z5.printv();
	return 1;
}
	
	
	
	
	
	
	
	
		
			
	
