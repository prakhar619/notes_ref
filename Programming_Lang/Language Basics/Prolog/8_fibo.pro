fibo(0,0).
fibo(1,1).
fibo(N,F):-
    N1 is N-1,
    fibo(N1,F1),
    N2 is N-2,
    fibo(N2,F2),
    F is F1+F2.

%using accumulators
fib(2,F1,F2,F):-
    F is F1+F2.
fib(N,F1,F2,F):-
    N_ is N-1,
    F_ is F1+F2,
    fib(N_,F2,F_,K),
    F is K+F1.
