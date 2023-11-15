%call is a built in predicate
    %call(true) => true
    %call(false) => false

and(A,B):- call(A),call(B).
or(A,B):- call(A),!.
or(A,B):- call(B).
neg(A):- \+ call(A).
implies(A,B):- call(A),!,call(B).
implies(_,_).
