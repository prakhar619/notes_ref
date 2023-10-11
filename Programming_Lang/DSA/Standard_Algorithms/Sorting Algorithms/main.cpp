#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

#include "Bubble_sort.cpp"
#include "Selection_sort.cpp"

string path_correction(string incorr_path)
{
    string corr_path;
    for(char c : incorr_path)
        if(c == '\\')
            corr_path+="/";
        else if(c == '"')
            continue;
        else
            corr_path+= c;
    return corr_path;
}

int main()
{
    cout << "Enter the path of file" << endl;
    string path;
    cin >> path;
 //   cout << "Enter no of entries in file (No of numbers)"<< endl;
    const int len = 169984;
    long long ar[len];
    cout << path_correction(path) << endl;

    fstream file01;
    file01.open(path_correction(path),ios::in | ios::out);

    if(file01.is_open())
    {
        int i = 0;
        string xline;
        while(getline(file01,xline))
        {
            ar[i] = stoll(xline);
            ++i;
        }
    }
    file01.close();
/*
    //To check accuracy
    bubblesort(ar,len);
    // selectionsort(ar,len)
    // quicksort(ar,0,len)
    // mergesort(ar,0,len)
    // insertionsort(ar,len)
    // bucketsort( ar, len)
    // countsort( ar, len)
    for(int k: ar)
    cout<< k << endl;
*/
    for(int t = 0;pow(2,t)< len; t++)
    {
        clock_t start,end;

        start = clock();
        bubblesort(ar,pow(2,t));
        //selectionsort(ar,pow(2,t));
        //quicksort(ar,0,pow(2,t));
        //mergesort(ar,0,pow(2,t));
        //insertionsort(ar, pow(2,t));
        // bucketsort(ar,pow(2,t));
        //countsort(ar,pow(2,t));
        end = clock();

        double time_taken = ((double)end-start)/CLOCKS_PER_SEC;
 
        cout<< "Input array size:" << pow(2,t) << "  "<<"seconds taken:"<< time_taken <<endl;
    }

    return 1;
}
