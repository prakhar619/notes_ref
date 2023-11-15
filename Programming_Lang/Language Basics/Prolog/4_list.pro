animal = [elephant,horse,donkey,dog].
zodiac = [ god | [cat | [rat | [dragon | [rooster | [dog | [horse | [tiger | [sheep | [ox | [rabbit | [snake | [ boar | [monkey | []]]]]]]]]]]]]]].
% List Representation
 % [Head | Tail] where head is definitely an element and tail can be an empty list 


% Non Homogenous List

head(List,RetHead):- 
    List = [RetHead | Tail].
            % empty list gives false

tail(List,RetHead):-
    List = [Head | RetHead ].
            % empty list gives false

index(List,0,Val):- !,head(List,Val).
index([Head|NewList],M,Val):-
    N is M-1,
    index(NewList,N, Val).

concat_list([],List,List).
concat_list([Head | List1],List2, [Head| List3]):-
    concat_list(List1,List2,List3).
/* Try the following query:
1. concat_list([1,2,3],[d,e,f],X).              concats list1 and list2
2. concat_list([1,2,3],[d,e,f],[1,2]).          return false
3. concat_list([1,2,3],[d,e,f],[1,2,3]).        return false.
4. concat_list(X,Y,[1,2,3,d,e,f])               returns all possible permutation of X, Y

*/
male(john).
male(kleif).

extract(_,[],[]).
extract(cond,[X|Others],[X|Rest]):-
    Condition = [cond,X],
    Condition,
    extract(cond, Others, Rest).
extract(cond,[X|Others],Rest):-
    Condition = [cond,X],
    \+ Condition,
    extract(cond,Others,Rest).




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
