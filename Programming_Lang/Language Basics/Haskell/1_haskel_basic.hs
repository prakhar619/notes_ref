--Commenting
{- Multiline 
comment -}

--HELP (:type cmd)

--FUNCTIONS (Highest Priorty)
	--function name must begin with lowercase then 0 or more letters, digits, underscores, forward single quotes
	--function inside function always use () like f(g(x),h(x)) will be f (g x) (h x)
double x = x+x		--Function named double with one args x
double_y x y = x+y	--Function named double_y with 2 args x and y
double_t(x,y) = x+x+y	--Function named double_t with 1 args tuble with 2 datatypes
double_l[x,y] = x+y+y	--single list as args
double_amb x = double x * 10	--either double(x)*10 :) or double(x*10)	FUNCTION HAVE THE HIGHEST PRIORTY

--to run function: Main>double 10
--double(double 10);if double double 10;compiler thinks double takes 2 args

--FUNCTION STRUCTURE (space index)
sort (x:y) = sort smaller ++ [x] ++ sort larger
               where
                smaller = [a| a<-y, a<=x]
                larger = [b| b<-y, b> x]
     --ALTERNATIVE VERSION
mysum_fun a b = x+y
		 where
		  {
		  x = a;	--requires ; at each statement
		  y = b
		  };


--Standard Operator 
intsum = 10 + 3
intminus = 10 -3
intMult = 10 * 3
intRange = [1..10]
intExpo = 2^3
list_concat = [1,2,3] ++ [6,7,8]
intDiv = div 10 3
intDiv2 = 10 `div` 3
floatDiv = 10/3
-- (.):: (b->c)->(a->b) ->(a->c)
f x = x+1
g x = x/2
h x = (f.g) x
mycon = 1:2:3:[]
mymod = 3 `mod` 2





--Standard Prelude
myhead = head[1,2,3,4]			--head [a] -> a		1st element is the output
mytail = tail[1,2,3,4]			--tail [a] -> [a]	removes the first element
myinit = init[1,2,3,4]			--init [a] -> [a]	removes the last element
mytake n = take n [1,2,3,4]		--take a [a] -> [a]	take till nth element (including nth)
mydrop n = drop n [1,2,3,4]		--drop a [a] -> [a]	drop till nth element (including nth)
mylength = length [1,2,3,4]		--length [a] -> a
mysum = sum[1,2,3,4]			--sum [a] -> a
myproduct = product[1,2,3,4]		--product [a] -> a
myappend = [1,2,3,4] ++ [5,6,7,8]	-- ++ [a] [a] -> [a]	appends 2 list
myrev = reverse [1,2,3,4]		--reverse [a] -> [a]	
myindex = [0,1,2,3,4,5,6] !! 4		--bang bang [a] -> a

factorial n = product [1..n]

