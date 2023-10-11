 {-- 1. a) Valid (list of Int)
 	b) Invalid (list is homogeneous type)
 	c) Valid (tuple of int,int,int,int)
 	d) Valid list of tuple with tuple as (list of char,bool)
 	e) Valid list of list of bool
 	f) Valid list of function with function type [a]->[a]
 	g) Valid
 	h) Valid list of list of list char 
 		or
 		list of list of string
 		[["x"]]
 	i) Bool
 	j) Function
 	k) Empty list
 	l) Empty tuple
 	m) string
 	n) VALID (although read need target type but here - 2 implicitly gives away the target type)
 		read "5" :: Int
 		
2. a) (a,b)->a
b) a->a
c) (Num a, Num b):: (a,b)->(a,b)->(a,b)
d) [a]->Bool
e) a->b->a
f) Int->[b]->([b],[b])
g) (a->b)->a->b
h) (a->a)->a->a
i) (a->b)->(c->a)->c->b
j) (a->b->c)->b->a->c
k) ( a->b, a->c ) -> a -> (b,c)
--}
emptyList::[a]->Bool
emptyList [] = True
emptyList _ = False

safetail::[a]->[a]
safetail [] = []
safetail xs = tail xs

safetail1::(Eq a)=>[a]->[a]
safetail1 xs = if xs == [] then [] else tail xs

majority::Bool->Bool->Bool->Bool
majority a b c = if a then if b then a else c else if b then c else a

replaceHead::[a]->a->[a]
replaceHead [] x = []
replaceHead xs x = x:tail xs

plus::Num a=>(a,a)->a
plus(x,y)=x+y

curry1::((a,b)->c)->a->b->c
curry1 f = \x y->f (x,y)

plus_unc x y = x+y

uncurried::(a->b->c)->((a,b)->c)
uncurried f (x,y) = f x y


