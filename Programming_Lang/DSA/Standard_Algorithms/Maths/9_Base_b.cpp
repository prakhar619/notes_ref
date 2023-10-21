#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*Base Converion and Manipulation
Like (55)10 in ()2  [Decimal to Binary]
Generalising the base convertion to any finite base 
*/

/*
Private:
	Data Member:
		vector<int> x
	Function Member:
		int mod(divident,divisor)
		vector<int> positiveNo_basechange(int number,int base)
		vector_add(vector<int> num1, vector<int> num2, int base, int carry)
		vector<int> negativeNo_basechange(int n, int base)
Public:
	Constructor:
		base_b()
		base_b(int num)
	Function Member:
		base_b<int b> operator+(base_b<int b>obj), 
		base_b<int b> operator-, 
		base_b<int b> operator*, 
		base_b<int b> operator/, 
		base_b<int b> operator++ , 
		base_b<int b> ++operator, 
		printv()
		print()
*/

template<int B> class base_b
{
	private:
	vector<int> x;
	
	//mod function  //int, int -> int 
	int mod(int divident,int divisor)
	{
		int q = divident/divisor;
		int remainder = divident -(q*divisor);
		return remainder;
	}
	
	// int(decimal no), int(base b) -> 32 element vector(base b no)
	// uses mod
	/* 	2 |  64
	   	2 |  32		0
	   	2 |  16		0
	   	2 |  8		0
	   	2 |  4		0
	   	2 | 2		0
	   	2 |  1		
	   so base is mod(64,2) till no is smaller than base (2) then reverse 
	  */	  
	vector<int> positiveNo_basechange(int n, int b)
	{
		vector<int> rev_out;
		while(b<=n)
		{
			rev_out.push_back(mod(n,b));
			n/=b;
		}
		if(n>0)
		rev_out.push_back(n);
		
		while(rev_out.size() < 32)	//converting to 32 bit representation
		{
			rev_out.push_back(0);
		}
		
		vector<int> out;		// reversing to get actual base_b
		for(int i = rev_out.size()-1;i>=0; --i)
		{
			out.push_back(rev_out[i]);
		}
		return out;
	}
	
	//  vector, vector, int(base), int -> vector
	// uses mod
	vector<int> vector_add(vector<int> a, vector<int> b,int base = 10,int carry = 0)
	{
		vector<int> add;
		for(int  i= 0; i < 32;i++)
		add.push_back(0);
		for(int i = 31; i>=0;i--)
		{
			int sum = a[i]+b[i] + carry;
			carry = sum/B;
			sum= mod(sum,base);
			add[i] = sum;
		}
		return add;
	}	

	// b's complement
	// int(decimal no with minus sign), int (base) -> 32 element vector (base b no)
	// uses positive_basechange()
	/* -45  ->  45  -- base_b  --> 12:23 -- 1's complement --> 32:19 -- 2's complement --> 32:20 --> appending sign bits
	*/
	vector<int> negativeNo_basechange(int n, int b)
	{
		vector<int> complement;
		vector<int> base_b_no = positiveNo_basechange(-n,b);
		
		//b-1's complement
		for(int i =0; i<32;i++)
		complement.push_back((b-1)-base_b_no[i]);
		
		//b's complement
		vector<int> one;
		for(int i = 0; i<32;i++)
		one.push_back(0);
		one[31] = 1;
		complement = vector_add(complement,one,B);	
	
		return complement;
	}
		
	
	public:

	
	//constructor
	// int 
	// positiveNo_basechange , negativeNo_basechange
	base_b(int n)
	{
		if(n>=0)
		x = positiveNo_basechange(n,B);
		else
		x = negativeNo_basechange(n,B);
	}
	
	base_b()
	{
		for(int i=0;i<32;i++)
		x.push_back(0);
	}
	
	// object(vector) -> object(vector)
	// vector_add
	base_b<B> operator+ (base_b<B> b)
	{
		base_b<B> added_obj;
		added_obj.x = vector_add(x,b.x,B);
		return added_obj;
	}
	
	// object(vector) -> object(vector)
	// vector_add
	base_b<B> operator- (base_b<B> b)
	{
		base_b<B> sub_obj;
		
		vector<int> complement;
		//b-1's complement
		for(int i =0; i<32;i++)
		complement.push_back((B-1)-b.x[i]);
		
		//b's complement
		vector<int> one;
		for(int i = 0; i<32;i++)
		one.push_back(0);
		one[31] = 1;
		complement = vector_add(complement,one,B);	
		
		sub_obj.x = vector_add(x,complement,B);
		return sub_obj;
	}
	
	// object(vector) -> object(vector)
	
	base_b<B> operator* (base_b<B> b)
	{
		vector<int> rev_mult;
		for(int i = 0; i<b.x.size()+x.size();i++)
		rev_mult.push_back(0);
		
		int sum=0;
		int carry = 0;
		
		for(int i = 0; i<b.x.size();i++)
		{
			carry = 0;
			int j;
			for(j = 0; j<x.size();j++)
			{
				sum = b.x[b.x.size() -1 -i]*x[x.size() -1 -j] +carry;
				rev_mult[i+j]+=sum;
                    		carry = rev_mult[i+j]/B;
                    		rev_mult[i+j] = mod(rev_mult[i+j],B);
                    	}
                    	if(carry >0)
                	rev_mult[i+j] = carry;
                }
                
                class base_b<B> mult;
        	for(int i =rev_mult.size()-1; i >= 0; --i)
        	{
            		mult.x.push_back(rev_mult[i]);
        	}
        	return mult;
        }
        
        //based on minus till divident becomes negative
        base_b<B> operator/ (base_b<B> b)
        {
        	base_b<B> dup;
        	dup.x = x;
        	
        	int counter = 0;
        	while(dup.x[0] != B-1)
        	{

        		dup = dup - b;
        		counter+=1;
        	}
        	// converting the ans to base b
        	base_b<B> dev(counter-1);
        	return dev;
        }
        
        base_b<B> operator++ ()
        {
            vector<int> one_s_1;
            for(int i=0;i<32; i++)
            one_s_1.push_back(0);
            one_s_1[31] = 1;
            
            base_b<B> incre;
            incre.x = vector_add(x,one_s_1,B,0);
            
            x=incre.x;
            return incre;
        }
        
        base_b<B> operator++ (int)
        {
            vector<int> one_s_1;
            for(int i=0;i<32; i++)
            one_s_1.push_back(0);
            one_s_1[31] = 1;
            
            base_b<B> incre;
            incre.x = vector_add(x,one_s_1,B,0);
            
            base_b<B> dup;
            dup.x = x;
            x=incre.x;
            return dup;
            
        }
        
        
        void printv()
        {
        	for(int i = 0; i < x.size(); i++)
        	cout << x[i] << ":";
        	cout << endl;
        }
        
        void print()
        {
            int flag = 0;
            for(int i = 0; i <x.size() ; i++)
            {
                if( x[0] == B-1)
                {
                    if(x[i] != B-1)
                    flag =1;
                    if(x[i] != (B-1) || flag == 1)
                    {
                        cout << x[i] << ":";
                    }
                }
                else
                {   
                    if(x[i] != 0)
                    flag =1;
                    if(x[i] != 0 || flag == 1)
                    {
                        cout << x[i] << ":";
                    }
                }
            }   
            cout << endl;   
        }

};
int main()
{

	base_b<4> obj1(745);
	obj1.printv();
	base_b<4> obj2(68);
	obj2.printv();
	base_b<4> obj3 = obj1+obj2;
	obj3.printv();
	base_b<4> obj4 = obj1-obj2;
	obj4.printv();
	base_b<4> obj5 = obj2-obj1;
	obj5.printv();
	base_b<4> obj6 = obj1*obj2;
	obj6.printv();
	
	base_b<4> obj7 = obj1/obj2;
	obj7.printv();
	++obj7;
	obj7.printv();
	return 1;
	
}

        
