//Matrix Builder
//Weight = 0 for src = Destination or i = j
//Non Existance Edge (weight) = -1

#include <cstdlib>	//for random function rand()
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int vertex;
    cout << "Enter no of Vertex\n";
    cin >> vertex;

    int maxWeight;
    cout << "Enter max Weight Value\n";
    cin >> maxWeight;

    float p;
    cout << "Enter Probability of no Edge\n";
    cin >> p;

    fstream fobj;
    fobj.open("./Matrix.txt", ios::out);

    fobj << vertex << "\n";
    for(int i = 0; i < vertex; i++)
    {
        for(int j = 0; j < vertex; j++)
        {	    			
                int random = rand();
                if(i == j)              //for same node distance
                {
                    fobj << "0 ";
                }
                else if((float)random/RAND_MAX < p)	//encoding for no existant edge
                {
                    fobj << to_string(INT_MAX) + " ";
                }
                else 
                {
                    fobj << random % (maxWeight) << " ";
                }
        }
        fobj << "\n";
    }
    fobj.close();
    return 0;
}