//Function to create File.txt which contain matrix to form graph.
// userinput (no of vertices), userinput (probability that edge is present)  ---(max weight allowed)--------> no of vertex; matrix
//matrix [File]  --> matrix [RAM]
#include <cstdlib>	//for random function rand()
#include <iostream>
#include <fstream>
#define MaxWeight 10
using namespace std;
int main()
{
	fstream fobj;
    	fobj.open("./File.txt", ios::out);
    	
    	int N;
    	cout << "Enter no of vertices"<< endl;
    	cin >> N;
    	
    	int p;
    	cout << "Enter probability(p) for edge to not exist" << endl;
    	cin >> p;
    	
    	fobj << N << "\n";
    	for(int i = 0; i< N; i++)
    		{
    			for(int j = 0; j<N; j++)
    			{
	    			int random = rand();
	    			if((float)random/(float)RAND_MAX < p)	//random/rand_max gives [0,1] ans
	    			fobj << "0 ";
	    			else 
	    			fobj << random % (MaxWeight) << " ";
	    		}
    			fobj << "\n";
    		}
    	fobj.close();
    }
    			
