%is a comment
/* is also a comment */

elephant(fred).
elephant(mary).
elephant(joe).
animal(mary) :- elephant(mary).
animal(joe) :- elephant(joe).
animal(fred) :- elephant(fred).

/*
Query: animal(fred),animal(mary),animal(joe).

1. elephant(fred),animal(mary),animal(joe).
2. animal(mary),animal(joe).
3. elephant(mary),animal(joe).
4. animal(joe).
5. elephant(joe).
6. EMPTY

true.

*/

%no need of BACKTRACK here as each match result in removal of query.


