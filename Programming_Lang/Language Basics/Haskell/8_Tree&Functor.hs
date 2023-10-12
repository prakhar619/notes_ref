data Tree a = LeafT a | NodeT a [Tree a] 

--as we dont know a; therefore show a is unknown; therefore derive from Show a
--Show [] is defined therefore no need for show xs
instance Show a => Show (Tree a) where
 show (NodeT a xs) = "Node "++ show a ++" -->"++show xs
 show (LeafT a) = "Leaf " ++ show a

data BinaryTree a = NULL | Node a (BinaryTree a) (BinaryTree a) deriving (Show)
--example: (Node 1 (Node 2 (Node 3 (Node 4 NULL NULL) NULL) (Node 6 NULL NULL) )(Node 8 NULL NULL))


--takes concrete binary tree
bTsearch::(Ord a)=>(BinaryTree a)->a->Bool
bTsearch (Node v tree1 tree2) x | x == v = True
                                | x < v = bTsearch tree1 x
                                | x > v = bTsearch tree2 x
bTsearch NULL x = False


insert::(Ord a)=>a->(BinaryTree a)->(BinaryTree a)
insert x (Node v tree1 tree2) | x <= v = Node v (insert x tree1) tree2
                              | x > v = Node v tree1 (insert x tree2)
insert x NULL = Node x NULL NULL

{--
delete::(Ord a)=>a->(BinaryTree a)->(BinaryTree a)
delete
--}