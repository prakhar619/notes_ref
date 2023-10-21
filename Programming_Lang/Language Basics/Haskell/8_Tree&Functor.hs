data Tree a = LeafT a | NodeT a [Tree a] 

--as we dont know a; therefore show a is unknown; therefore derive from Show a
--Show [] is defined therefore no need for show xs
instance Show a => Show (Tree a) where
 show (NodeT a xs) = "Node "++ show a ++" -->"++show xs
 show (LeafT a) = "Leaf " ++ show a

data BinaryTree a = NULL | Node a (BinaryTree a) (BinaryTree a) deriving (Show)
--example: (Node 5 (Node 3 (Node 2 NULL NULL) (Node 4 NULL NULL)) (Node 7 (Node 6 NULL NULL) (Node 8 NULL NULL)))
        -- (Node 5 (Node 3 (Node 2 NULL NULL) (Node 4 NULL NULL)) (Node 8 (Node 6 NULL (Node 7 NULL NULL)) (Node 9 NULL NULL)))


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

leftmost::(BinaryTree a)->a
leftmost (Node v NULL _ ) = v
leftmost (Node v bt1 _ ) = leftmost bt1 

successor::(Ord a)=>(BinaryTree a)->a
successor (Node v bt1 (Node s NULL bt2 )) = s 
successor (Node v bt1 (Node s_ bt2 bt3 )) = leftmost bt2

delete::(Ord a)=>a->(BinaryTree a)->(BinaryTree a)
delete x (Node v NULL NULL)= if(x == v) then NULL else (Node v NULL NULL)
delete x (Node v bt NULL) | x == v =  bt
                          | x < v = Node v (delete x bt) NULL
                          | x > v = Node v bt NULL
delete x (Node v NULL bt) | x == v =  bt
                          | x > v = Node v NULL (delete x bt)
                          | x < v = Node v NULL bt
delete x (Node v bt1 bt2) | x == v = Node suc bt1 (delete suc bt2) 
                          | x > v = Node v bt1 (delete x bt2)
                          | x < v = Node v (delete x bt1) bt2
                           where suc = successor (Node v bt1 bt2)