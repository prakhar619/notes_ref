#include<iostream>
#include<time.h>

#include "goldenRatio_fb.cpp"
#include "recursive_fb.cpp"
#include "shifting_fb.cpp"
#include "matrix_fb.cpp"

using namespace std;

int main()
{   
    long long  n = 25;
    cout << "n" << " " << "nth fib" << " " << "Time taken" << endl;


    for(int i = 0; i < n; i++)
    {
    clock_t start, end;

    start = clock();
    //long long  nth =  golden_ratio_fibo(i) ;
    //long long  nth =  dynamic_fibo(i) ;
    //long long nth = recursive_fibo(i);
    long long nth = matrix_fib0(i);
    end = clock();

    int time_taken =  ((double)end -start )/ CLOCKS_PER_SEC;

    cout << i << " " << nth << " " << time_taken << endl;
    }
    return 1;

}
