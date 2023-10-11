nestedOdds::[[Int]]->[[Int]]
nestedOdds xss = [[x| x<-xs , x`mod`2/=0]| xs<-xss]




--foldr f b [a]    b
--foldl f b [a]    b
length1::[a]->Int
length1 xs = foldr (\x y->1+y) 0 xs
length2 xs = foldl (\x y->x+1) 0 xs

append1::[a]->[a]->[a]
append1 xs ys = foldr (\x ys->x:ys) ys xs
append2 xs ys = reverse(foldl (\xs y->y:xs) (reverse xs) ys)

product1::Num a=>[a]->a
product1 xs = foldr (\x y->x*y) 1 xs
product2 xs = foldl (\x y->x*y) 1 xs

or1 ::[Bool]->Bool
or1 xs = foldr (\x y->x||y) False xs
or2 xs = foldl (\x y->x||y) False xs

any1::(a->Bool)->[a]->Bool
any1 f xs = foldr (\x y-> (f x)||y) False xs
any2 f xs = foldl (\x y-> y||(f x)) False xs

all1::(a->Bool)->[a]->Bool
all1 f xs = foldr (\x y->(f x)||y) True xs
all2 f xs = foldl (\x y-> y||(f x)) True xs

map1::(a->b)->[a]->[b]
map1 f xs = foldr (\x y-> (f x):y) [] xs
map2 f xs = foldl (\x y-> x++[f y]) [] xs

reverse1::[a]->[a]
reverse1 xs = foldr (\x y-> y++[x]) [] xs
reverse2 xs = foldl (\x y-> y:x) [] xs

concat1::[[a]]->[a]
concat1 xss = foldr (++) [] xss
concat2 xss = foldl (++) [] xss

elem1::Eq a=>a->[a]->Bool
elem1 a xs = foldr (\x y-> (a==x)||y) False xs
elem2 a xs = foldl (\x y-> x||(y==a)) False xs

filter1::Ord a=>(a->Bool)->[a]->[a]
filter1 f xs = foldr (\x y-> if f x then x:y else y) [] xs
filter2 f xs = foldl (\x y-> if f y then x++[y] else x) [] xs

partition1::(a->Bool)->[a]->([a],[a])
partition1 f xs = foldr (\x (a,b)-> if f x then (x:a,b) else (a,x:b)) ([],[]) xs
partition2 f xs = foldl (\(a,b) x-> if f x then (x:a,b) else (a,x:b)) ([],[]) xs 

unzip1::[(a,b)]->([a],[b])
unzip1 xs = foldr (\(a,b) (c,d)->(a:c,b:d)) ([],[]) xs
unzip2 xs = foldl (\(c,d) (a,b)->(a:c,b:d))  ([],[]) xs

interperse::a->[a]->[a]
interperse a xs = init (foldr (\x y-> x:a:y) [] xs)
interperse2 a xs = init (foldl (\x y-> x++[y]++[a]) [] xs) 

takeWhile1::(a->Bool)->[a]->[a]
takeWhile1 f xs = foldr (\zs ys-> if length zs > length ys then zs else ys) [] (foldr (\x xss-> if f x then (x:head xss):tail xss else ([]:xss)) [[]] xs)
--first we are constructing a list of list containing subarray of satisfying elements like
--		even [1,2,3,4,5,6,8,10,1,4,6] will give [ [], [2], [4], [6,8,10], [4,6] ]
--				this part is second foldr 
--		then we are choosing the largest list inside this list of list

tails::[a]->[[a]]
tails xs = foldl (\xss x-> [xs++[x] | xs<-xss]++[[]]) [[]] xs
-- take first element of xs (a) add to each element of [[]] and also create a new element [] in [[]]
-- therefore we have at start [[]] 
-- [[a],[]]
-- [[a,b],[b],[]]
-- [[a,b,c],[b,c],[c],[]]
