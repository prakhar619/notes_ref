rowChecker(N,H,[]).
rowChecker(N,(Row,Col),[(R,C) | Rest]):-
    Row > 0,
    Row =< N,
    \+ Row=:=R,
    rowChecker(N,(Row,Col), Rest).

colChecker(N,H,[]).    
colChecker(N,(Row,Col),[(R,C) | Rest]):-
    Col > 0,
    Col =< N,
    \+ Col =:= C,
    colChecker(N,(Row,Col),Rest).

diagonalL(N,(R,C),[]).
diagonalL(N,(Row,Col),Rest):-
    Row =< N,
    Col =< N,
    \+ member((Row,Col),Rest),
    Row_ is Row+1,
    Col_ is Col+1,
    diagonalL(N,(Row_,Col_),Rest).
diagonalL(N,(K,_),Rest):- K is N+1.
diagonalL(N,(_,K),Rest):- K is N+1.

diagonalLMain(N,(R,C),Rest):-
    R_ is R-R,
    C_ is C-R,
    diagonalL(N,(R_,C_),Rest).

diagonalR(N,(R,C),[]).
diagonalR(N,(Row,Col),Rest):-
    Row =< N,
    Col > 0,
    \+ member((Row,Col),Rest),
    Row_ is Row+1,
    Col_ is Col-1,
    diagonalR(N,(Row_,Col_),Rest).
diagonalR(N,(K,_),Rest):- K is N+1.
diagonalR(N,(_,K),Rest):- K is 0.

diagonalRMain(N,(R,C),Rest):-
    R_ is R - R,
    C_ is C + R,
    diagonalR(N,(R_,C_),Rest).

/*
3,1     3,2     3,3
2,1     2,2     2,3
1,1     1,2     1,3
*/
nQueensCheck(N,[]).
nQueensCheck(N,[Head | Rest]):-
    rowChecker(N, Head, Rest),
    colChecker(N,Head,Rest),
    diagonalLMain(N,Head,Rest),
    diagonalRMain(N,Head,Rest),
    nQueensCheck(N,Rest).

nQueenM(N,_,List,X):-
    length(List,N),
    nQueensCheck(N,List),
    X = List.

nQueenM(N,(SR,SC),List,X):-
    LList = [(SR,SC)|List],
    SR =< N,
    SC_ is SC+1,
    (SC_ =:= N+1 -> SR_ is SR+1, SC__ is 1; SR_ is SR, SC__ is SC_),
    nQueenM(N,(SR_,SC__),LList,X).

nQueenM(N,(SR,SC),List,X):-
    LList = List,
    SR =< N,
    SC_ is SC+1,
    (SC_ =:= N+1 -> SR_ is SR+1, SC__ is 1; SR_ is SR, SC__ is SC_),
    nQueenM(N,(SR_,SC__),LList,X).


nQueenN(N,(R,C),X):-
    R =< N,
    C =< N,
    (nQueenM(N,(R,C),[],L) ->
        X = L
    ;
        C_ is C+1,
        (C_ =:= N+1->
            R_ is R+1,
            nQueenN(N,(R_,1),X)
        ;
            nQueenN(N,(R,C_),X)
        )
    ).
        
nQueen(N,X):-
    nQueenN(N,(1,1),X).
    

