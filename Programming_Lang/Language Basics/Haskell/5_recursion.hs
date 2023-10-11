--Recursion
	--never forget the base case (pattern matching)

myfac :: Integral n => n -> n
myfac n = product [1..n]

myrecur_fac :: Integral n => n -> n
-- or myrecur_fac :: Int -> Int
myrecur_fac 0 = 1
myrecur_fac n = n * myrecur_fac (n-1)
	--always when operator used on argument of function; use bracket
myproduct :: Num a => [a] -> a
myproduct [] = 1
myproduct (n:ns) = n * myproduct(ns)	--or myproduct ns

--Multiple Recursion
fibo :: Int -> Int
fibo 0 = 0
fibo 1 = 1
fibo n = fibo (n-2) + fibo (n-1)

--Mutual Recursion

