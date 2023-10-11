--v::T means v have type T
--Types consists of collection of related values
--Classes are collection of related types that support certain overloaded operations called method; data types are called instance of class
--In haskell every expression has type T which is calculated prior to evaluation by process called type inference
--Therefore expr::T
--use :type expr/value to get type
mytype = False::Bool

{-Basic Types
1	Bool		True and False
2	Char		'a'
3	String		"a"
4	Int		64bit integer; -2^63 to 2^63 -1
5	Integer		Arbitary-precision int
6	Float		
7	Double
**Starts with caps
-}

{-List Types
1	[Bool]
2	[Char]
3	[String]

[[]] is singleton list like ['a'] consisting of 1 empty list
[[Char]] is a list contains char list
-- LIST ARE HOMOGENOUS
-}

--HASKELL LIST is not primitive datatype
	--construction of one element at a time starting with [] using : (cons)
sampleList = 1 : [2,3]		--[1,2,3] 1:[2,3] 1:2:[3] 1:2:3:[]
sampleList2 = 1:2:3:4:[]




{-Tuple Types
	Tuple can contains possibly different data types
	(1,'a',True,"YES")	
--TUPLE ARE HETEROGENOUS

Arity is length of tuple
	Arity 1 tuples are not allowed because of normal bracket use conflict

Type Tuple
(’a’,(False,’b’)) :: (Char,(Bool,Char))
([’a’,’b’],[False,True]) :: ([Char],[Bool])
[(’a’,False),(’b’,True)] :: [(Char,Bool)]

-}

--FUNCTIONS
	--Curried Function are function which return functions (functions are just maps)
	--  -> operator is Right Associative
add :: Int -> (Int -> Int)
	--we are giving an argument int and function is returning a function which itself takes an argument int and returns int
add x y =x+y
sub :: Int -> Int -> Int
sub x y = x-y

	--Polymorphic Functions
mylength x = length x		--works on
--Head, take, zip, id, etc...

	--Overloaded Types
-- + (double,int,float) 
-- abs

{- Basic Classes
		classes are collection of related types that support certain overlaoded operations called method; data types are called instance of class
	1.Eq class
		All 7 + 2
		== :: a->a->Bool
		/=
	2.Ord class 
		(Superclass: Eq)
		All 7 + 2
		< :: a->a->Bool
		>
		<=
		>=
		min :: a->a->a
		max
	3.Show class
		All 7 + 2
		show :: a-> String		--converts everytype to string
	4.Read class
		All 7 + 2
		read :: String-> a		--converts all string to respective types
	5.Num class
		Int,Integer,Float,Double
		+
		-
		*
		negate
		abs
		signum
	6.Integral class
		Int,Integer
		div
		mod
	7.Fractional class
		Float,Double
		/
		recip
-}

even' :: Integral a => a->Bool
even n = n `mod` == 0

--Dont ever write fun :: Int a => a->a->a->a
-- => means class used
-- write Int->Int->Int->Int


	





























