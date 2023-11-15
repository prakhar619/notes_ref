%Cuts
    %Problems with Backtracking

removeDup([],[]).
removeDup([Head|Tail],Result):-
    member(Head,Tail),removeDup(Tail,Result).
removeDup([Head|Tail],[Head|Result]):-
    removeDup(Tail,Result).

/* Try the query
removeDup([a,b,c,a,b],X).         X = [c, a, b] ;X = [b, c, a, b] ;X = [a, c, a, b] ;X = [a, b, c, a, b].
*/
    %introducing cuts
removeDupp([],[]).
removeDupp([Head|Tail],Result):-
    member(Head,Tail),!,removeDupp(Tail,Result).
removeDupp([Head|Tail],[Head|Result]):-
    removeDupp(Tail,Result).

        %! is cut-operator
            % no backtrack behind it.
            % here after member is true, then cut
            % even if removeDupp(Tail,Result), the next removeDupp(head tail ,head,resutl) is not executed.


%NAF
    %Closed world assumption => if not present as true here then false.
    %Negation as a failure
    %  \+ operator
    % gives true if predicate is false

    % \+ true.  
        %false.
    % \+ false.
        %true.

%Disjunction
    %Make 2 clauses
    % or
    % use ;
    
