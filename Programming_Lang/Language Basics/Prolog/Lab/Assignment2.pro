f2r1(N,(R,C),Visited,X):-
    R_ is R+2,
    C_ is C+1,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X  = [(R_,C_)|Visited].

f2r_1(N,(R,C),Visited,X):-
    R_ is R+2,
    C_ is C-1,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].
f_2r1(N,(R,C),Visited,X):-
    R_ is R-2,
    C_ is C+1,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].
f_2r_1(N,(R,C),Visited,X):-
    R_ is R-2,
    C_ is C-1,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].

r2f1(N,(R,C),Visited,X):-
    R_ is R+1,
    C_ is C+2,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].

r2f_1(N,(R,C),Visited,X):-
    R_ is R-1,
    C_ is C+2,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].

r_2f1(N,(R,C),Visited,X):-
    R_ is R+1,
    C_ is C-2,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].

r_2f_1(N,(R,C),Visited,X):-
    R_ is R-1,
    C_ is C-2,
    R_ =< N,
    C_ =< N,
    C_ > 0,
    R_ > 0,
    \+ member((R_,C_),Visited),
    X = [(R_,C_)|Visited].

head(List,RetHead):- 
    List = [RetHead | Tail].

knightsTourC(N,(R,C),Visited,X):- 
        f2r1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).

knightsTourC(N,(R,C),Visited,X):- 
        f2r_1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).

knightsTourC(N,(R,C),Visited,X):- 
        f_2r1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).
knightsTourC(N,(R,C),Visited,X):- 
        f_2r_1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).
knightsTourC(N,(R,C),Visited,X):- 
        r2f1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).
knightsTourC(N,(R,C),Visited,X):- 
        r2f_1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).
knightsTourC(N,(R,C),Visited,X):- 
        r_2f1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).
knightsTourC(N,(R,C),Visited,X):- 
        r_2f_1(N,(R,C),Visited,UpdatedVisit),
        head(UpdatedVisit,HEAD),
        knightsTourC(N,HEAD,UpdatedVisit,X).
knightsTourC(N,(R,C),Visited,X):-
        length(Visited,Len),
        Len =:= N*N,
        X = Visited.

knightsTour(N,(R,C),X):-
    knightsTourC(N,(R,C),[(R,C)],X).