--HigherOrder Functions
	--Function that takes a function as an argument or returns a function as a result is called higher order function.
--Multiple Arguments are usually defined using notion of curring
--Operator must be parenthasised when used as an argument

myMap :: (a->b) ->[a] -> [b]
myMap f xs = [f x | x <- xs]
--myMap f (x:xs) = f x : myMap f xs

myfilter :: (a -> Bool) -> [a] -> [a]
myfilter p [] = []
myfilter p (x:xs) | p x == True = x:myfilter p xs
		  | otherwise = myfilter p xs

{-General Form 	
	f [] = v
	f (x:xs) = x # f xs
-}

--foldr
{-
foldr f v [] = v
foldr f v (x:xs) = f x (foldr f v xs)
-}

mysum :: Num a => [a] -> a
mysum = foldr (+) 0

product :: Num a => [a] -> a
product = foldr (*) 1

or :: [Bool] -> Bool
or = foldr (||) False

and :: [Bool] -> Bool
and = foldr (&&) True
{-
sum [] = 0
sum (x:xs) = x + sum xs

product [] = 1
product (x:xs) = x * product xs

or [] = False
or (x:xs) = x || or xs

and [] = True
and (x:xs) = x && and xs
-}

--foldl
sum_l2r :: Num a => a->[a] -> a
sum_l2r v [] = v
sum_l2r v (x:xs) = sum_l2r (x+v) xs
mySum = sum_l2r 0

mySum_byfoldl:: Num a => [a] -> a
mySum_byfoldl = foldl (+) 0

--Composition Operator (.)		fog is f.g		--also need to check that output of f needs to match input of g
f :: Double -> Double
f x = x+x/2
g :: Double -> Double
g x = x/2
f' = f.g		--works
-- f' x y= f(g x y)	works
-- f' x y  = (f.g) x 	works       		is valid
-- f' x y  = (f.g) x y  does not work		gives error


