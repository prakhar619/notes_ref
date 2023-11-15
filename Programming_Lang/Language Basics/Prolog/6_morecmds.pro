%Manipulating Facts, Rules.
    % assert(term)
    % retract(term)             (removes first unifying term)
    % retractrtall(term)        (removes all unifying term)
    % assertz(term)             (add term at last rather than at beginning).
    


%BUILT IN predicates
    %cannot appear as principal functor in fact or rule head.

% EQUALITY = (X,Y) same as X=Y
    bigger(elephant,dog).
    is_bigger(X,Y):- bigger(Z,A), Z=X, A=Y.

    %building and executing predicates on go
    test(X,Y):- G = [X,Y], G.
        % X is predicate and Y is values
        % G calls X(Y).
    % in general G= [p,x1,x2,x3,...]
    %   p(x1,x2,x3,...)


% consule/1
    %consult('basic.pl').
    %to compile prolog file

% write/1
    %to write
    %write('Helo world')

% nl/0
    %to skip a line 
    %write('Helo world'),nl 

% atom/1
    %to check if element is an atom or not

% compount/1
    %to check if element is a atom or not 

%Arithmetic Predicates

% is/2      is(M,N) is same as M is N.
    %evaluates term N (eg: N = 10 + 2      != 12)
    X is 3 + 5
        X=8
    8 is 3 + 5
        true
    3 + 5 is 8
        false.\

%Function
%All these function directly gives values and should be used on right side of is-operator
    % max/2
    % **/2              (exponentiation)
    % min/2
    % abs/1
    % sqrt/1
    % sin/1
    % round/1
    % float/1           (int to float)

%Relation
% is-operator is not needed
    %   >, <, =<, >=, =:=, =\=
        % = is like matching(unification operator)
        % =:= is the mathematical equality.
    
% List
/*Built in for List Manipulation
    length/2
        length(List,Length)
    member/2
        member(List,SearchVal)          (true or false)
    append/3
        append(List,List,List_FINAL)
    last/2
        last(List,LastVal)
    reverse/2
        reverse(List,RevList)
    select/3
        select(Val,List,ListWithoutVal)

*/

% current_op/3 
    %current_op(Precedence,Associativity, *)    %where * is the op (operator)

% op/3 
    %op(300, xfx , isBigger)            %300 is precedence, xfx is associativity and isBigger is predicate
        %converting to infix operator
