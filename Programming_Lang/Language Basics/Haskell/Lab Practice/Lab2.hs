flip1::[(a,b)]->[(b,a)]
flip1 xs = [(b,a) | (a,b)<-xs]
--flip is prelude function which takes a function and argument and applies argument in flipped fashion
--f a b = f b a

dupli::[a]->[a]
dupli xs = [x | x<- xs , y<-[1,2]]

vowels::[Char]->[Char]
vowels xs = [x | x<-xs, x=='a' || x=='e' || x=='i'|| x=='o' || x=='u']

repli::[a]->Int->[a]
repli xs n= [x | x<-xs, y<-[1..n]]

doubleEven::[Int]->[Int]
doubleEven xs = [(x+x)*((x+1)`mod`2)+x*(x`mod`2) | x<-xs]

elem1::Eq a=>[a]->a->Bool
elem1 xs a = or[ x==a | x<-xs]

kthElem::[a]->Int->a
kthElem xs n = head (drop (n-1) xs)

riffle::[a]->[a]->[a]
riffle [] xs = xs
riffle xs [] = xs
riffle xs ys = head xs:head ys:riffle (tail xs) (tail ys)

rotate::[a]->Int->[a]
rotate xs n = (drop n xs)++(take n xs) 

merge::Ord a=>[a]->[a]->[a]
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys) | x <= y = x:merge xs (y:ys)
		    | otherwise = y:merge (x:xs) ys
		  
mergesort::Ord a=>[a]->[a]
mergesort [a] = [a]
mergesort (x:xs) = merge [x] (mergesort xs)

dropEvery::[a]->Int->[a]
dropEvery [] n = []
dropEvery xs n = (take (n-1) xs)++(dropEvery (drop n xs) n) 
