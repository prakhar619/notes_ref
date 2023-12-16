filter(N,V,[],[]).
filter(N,Visited,[Head|List1],[Head|Rest]):-
    (R,C) = Head,
    R > 0,
    C > 0,
    R =< N,
    C =< N,
    \+ member((R,C),Visited),
    filter(N,Visited,List1,Rest).

filter(N,Visited,[Head|List1],Rest):-
    filter(N,Visited,List1,Rest).

getNeighbour(N,(R,C), Visited, Neigh):-
    R_2 is R+2, 
    R_1 is R+1, 
    R_1_ is R-1, 
    R_2_ is R-2 ,
    C_1 is C+1, 
    C_1_ is C-1, 
    C_2_ is C-2, 
    C_2 is C+2,
    AllPt = [(R_2,C_1),(R_2,C_1_),(R_2_,C_1),(R_2_,C_1_),(R_1,C_2),(R_1,C_2_),(R_1_,C_2),(R_1_,C_2_)],
    filter(N,Visited,AllPt,Neigh).

getDegree(N,[],[]).
getDegree(N,[Head|List],[(Head,D)|Rest]):-
    D2 = [(1,1),(N,N),(1,N),(N,1)],
    N_ is N-1,
    D3 = [(1,2),(1,N_),(2,1),(2,N),(N_,1),(N_,N),(N,N_),(N,2)],
    D4 = [(1,_),(N,_),(_,1),(_,N)],
    D6 = [(2,_),(N_,_),(_,2),(_,N_)],
    member(Head,D2)->
        D = 2,
        getDegree(N,List,Rest)
    ;
    (member(Head,D3)->
        D = 3,
        getDegree(N,List,Rest)
    ;
    (member(Head,D4)->
        D = 4,
        getDegree(N,List,Rest)
    ;
    (member(Head,D6)->
        D = 6,
        getDegree(N,List,Rest)
    ;
        D = 8,
        getDegree(N,List,Rest)
    ))).

minDegree([],Min,X):-
    X = Min.
minDegree([Head|Rest],Min,X):-
    ((R,C),D) = Head,
    ((R_,C_),D_) = Min,
    D < D_,
    minDegree(Rest,Head,X).
minDegree([Head|Rest],Min,X):-
    ((R,C),D) =  Head,
    ((R_,C_),D_) =  Min,
    D >= D_,
    minDegree(Rest,Min,X).

knightsTourC(N,P,Visited,DNei,L):-
    print(P),
    nl,
    print(DNei),
    nl,
    \+ DNei = [],
    nl,
    last(DNei,Minn),
    minDegree(DNei,Minn,(Pt2,D)),
    getNeighbour(N,Pt2,[Pt2|Visited],Nei),
    % \+ Nei = [],
    getDegree(N,Nei,DNei_new),
    knightsTourC(N,Pt2,[Pt2|Visited],DNei_new,L).

knightsTourC(N,P,Visited,DNei,L):-
    % \+ DNei = [],
    print("Back"),nl,select((Pt2,D),DNei,DN),knightsTourC(N,P,Visited,DN,L).

knightsTourC(N,P,Visited,L):-
    length(Visited,Len),
    N_ is N*N,
    Len =:= N_,
    L = Visited.

knightsTour(N,P,L):-
    getNeighbour(N,P,[P],Nei),
    \+ Nei = [],
    getDegree(N,Nei,DNei),
    knightsTourC(N,P,[P|[]],DNei,M),
    reverse(M,L).