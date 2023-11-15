sumList([],0).
sumList([Head|Rest],Sum):-
    sumList(Rest,X),
    Sum is Head + X.

%dont know why recursive X = 2
gcd(M,0,C):- C = M.
gcd(M,N,C):- 
     M >= N,
     M_ is M - N,
     gcd(M_,N,C).
gcd(M,N,C):-
     N > M,
     gcd(N,M,C).

init([X],[]).
init([Head|List],[Head|Rest]):-
     init(List,Rest).

secondLast(List, Val):-
     init(List,Rest),
     last(Rest,Val).

dupli([],[]).
dupli([Head|List],[Head| [Head | Rest]]):-
     dupli(List,Rest).

element_at(Head,[Head|List],0).
element_at(X,[Head|List],K):-
     K_ is K-1,
     element_at(X,List,K_).

compress([],[]).
compress([Head|List1],[Head|List2]):-
     compress(List1,List2),
     \+member(Head,List2).
compress([Head|List1],List2):-
     compress(List1,List2),
     member(Head,List2).

subset(L,[]).
subset(L,[Head | Rest]):-
     member(Head,L),
     select(Head,L,L_),
     subset(L_,Rest).

prefixk(P,0,L).
prefixk([Head|P],K,[Head|L]):-
     K_ is K -1,
     prefixk(P,K_,L).

reverse([],Temp,Temp).
reverse([Head|List],Temp,Rev):-
     reverse(List,[Head|Temp],Rev).
reverseMain(L,K):-
     reverse(L,[],K).

is_palindrome([]).
is_palindrome([X]).
is_palindrome([Head|Tail]):-
     last(Tail,Lastt),
     Head = Lastt,
     init(Tail,NewTail),
     is_palindrome(NewTail).

merge([],L,L).
merge(L,[],L).
merge([Head1|List1],[Head2|List2],[Head1|Rest]):-
     Head1 =< Head2,
     merge(List1,[Head2|List2],Rest).
merge([Head1|List1],[Head2|List2],[Head2|Rest]):-
     Head2 < Head1,
     merge([Head1|List1],List2,Rest).

