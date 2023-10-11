--Functions Definition

--1. New from OLD
	
--2. Conditional Expression
	--if else (else is not optional)
		--avoids dangling else ambiguity
-- myabs :: Ord a => a -> a
myabs :: (Num a,Ord a) => a->a
myabs n = if n >= 0 then n else -n

mysignum n = if n < 0 then -1
	     else 
	     	if n == 0 then 0
	     	  else 1
	     	  
	--Guarded equation
myabs_g n | n > 0 = n
	| n < 0 = -n
	| otherwise = 0
	
--3. Pattern Matching
myNot False = True
myNot True = False

myAnd True True = False
myAnd True False = False
myAnd False _ = False
	--Wildcard Pattern _
		--Lazy evaluation
		
myfst :: (a,b) -> a	--cant take (1,2,3)
myfst (x,_) = x

mysnd :: (a,b) -> b	--cant take (1,2,3)
mysnd (_,y) = y		
	--Wildcard Pattern _
	-- Any one data (? like)
	
test :: [Char] -> Bool
test ['a',_,_] = True
test _ = False			--can take ['a','b']

test_m :: [Char] -> Bool
test_m ('a': _) = True		--can take ['a','b']		--Lazy evaluation	--always use parentheses
test_m _ = False
	
	
--4. Lambda Expression
	--nameless functions
--(\x -> x+x) 2
myadd = \x -> (\y -> x+y)	--take an args return a function which itself take a args

(#) = \x -> (\y -> x * y)

--5. Sections
(#) = \x -> (\y -> x*y)
(x #) = \y->x#y
(# y) = \x->x#y


--Each function is associated with 2 lines in code
	--Function definition
		--find :: Eq a => a-> [(a,b)] -> [b]
	--Function Functianality declaration
		--find k t = [v | (k' , v) <- t, k == k' ]	
		
--FUNCTION DEFINITION
	-- [a] means list	(any length)		[1,2,3,4]
	-- [(a,b)] means list with tuple type  (any length)	[(1,2),(2,3),(4,5)]

	--2 options 
		--Either for primitive types
			--myrecur_fac :: Int -> Int
		--or for TypeClasses	
			--myrecur_fac :: Integral n => n -> n

