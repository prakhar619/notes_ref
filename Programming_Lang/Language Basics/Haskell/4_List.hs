--list comprehensions

--Generators
list1 = [ x^2 | x<- [1,2,3,4] ]
	--  <- means take each element of this list one by one
list2 = [ (x,y) | x <-[1,2,3,4,5], y<-[x,5] ]

myconcat_inp = [ [1,2,3],[4,5],[6,7,8,9] ]
myconcat xss = [ x | xs <- xss, x<- xs ]	--x <- xs is more deeply nested

mylength:: [a] -> Int
mylength xs = sum[1 | _ <- xs ]


--Guards / Condictional Generators
factors n = [x | x <- [1..n] , n `mod` x == 0]	--still think of deeply nested part, but instead of adding more to each value, we are checkin each value
						--True means retains, False means dropped
						
	--String Comprehensions	
		--Strings are just list of characters. [NOT PRIMITIVE]
		--Therefore all polymorphic functions for string can be used with string
mystring = "abcde"
myoriginal_st = 'a':'b':'c':'d' : ['e']

myst_take = take 3 "abcde"
myst_length =  length mystring

myzip :: [a]->[b]->[(a,b)]
myzip [] _ = []
myzip _ [] = []
myzip (x:xs) (y:ys) = (x,y):myzip xs ys
	--cant use list comprehension because not nested; one to one pairing
--List Functions
{--
!!		( list indexing )
length		(lenght of list or tuple)
zip		(list and list into list of tuples
concat		(list of list into list
++		(appends list)

--}










































