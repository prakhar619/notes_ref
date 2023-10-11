// int fibo_seq_number --> long long fibonacci number
// 
// Time Complexity: O(n)
// Space Complexity: O(1)

/* F_n = F_n-1 + F_n-2
*/
long long  dynamic_fibo(int n)
{
    long long  f_n_1 = 0;
    long long  f_n = 1;
    long long f_N;
    
    if(n == 0)
    return f_n_1;
    else if(n == 1)
    return f_n;
    
    for(int i = 1; i <n; i++)
    {
        f_N = f_n + f_n_1;
        f_n_1 = f_n;
        f_n = f_N;
    }

    return f_N;
}
