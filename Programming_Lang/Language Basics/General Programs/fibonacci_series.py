class fibonacci_series:
    def golden_ratio(self,n):
        n-=1
        FI = (1+5**(1/2))/2
        FI_I = (1-5**(1/2))/2

        f_nth = (FI**n - FI_I**n)/ 5**(1/2)
        return f_nth
    
print("Enter the term of Fibonacci Series")
n = int(input())
obj = fibonacci_series()
print("OUTPUT:",obj.golden_ratio(n))