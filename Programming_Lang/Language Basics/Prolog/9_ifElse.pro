%   A->B;C means if A then B else C
%   try A 
%     if True
%       go on with B and ignore C
%     else
%       try C and ignore B


%    -> ; IMplementation
%  p:-A,!,B
%  p:-C

max(X,Y,Z):-
    (X =< Y -> Z = Y; Z = X).