elephant(fred).
elephant(mary).
elephant(joe).
animal(X) :- elephant(X).


/*Query: animal(fred),animal(mary),animal(joe).

1.X = fred,elephant(X),animal(mary),animal(joe)
2.animal(mary),animal(joe)
3.X = mary,elephant(X),animal(joe)
4.animal(joe)
5.X=joe,elephant(X)
6.EMPTY

true.