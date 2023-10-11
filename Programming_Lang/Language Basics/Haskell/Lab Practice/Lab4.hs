data Nat = Zero | Succ Nat
--defining instance just for display of data
instance Show Nat where
 show Zero = "Zero"
 show (Succ n) = "Succ("++show n++")"

toInt::Nat->Int
toInt Zero = 0
toInt (Succ n) = 1+(toInt n)

fromInt::Int->Nat
fromInt 0 = Zero
fromInt n = Succ (fromInt (n-1))





data Complex1 a = C1 a a
instance Show a=>Show (Complex1 a) where
 show (C1 x y) = show x++"+"++show y++"i"
 
data Complex2 = C2 Int Int
instance Show Complex2 where
 show (C2 x y) = show x++"+"++show y++"i"
 
data Prop = Basic Bool | Var Char | Not Prop | Prop:/\:Prop | Prop:\/:Prop | Prop:->:Prop
instance Show Prop where
 show (Basic x) = show x
 show (Var x) = show x
 show (Not x) = "!"++show x
 show (x:/\:y) = "("++show x++"/\\"++show y++")"
 show (x:\/:y) = "("++show x++"\\/"++show y++")"
 show (x:->:y) = "("++show x++"->"++show y++")"
 
vars::Prop->[Char]
vars (Basic x) = []
vars (Var x) = [x]
vars (Not x) = vars x
vars (x:/\:y) = vars x ++ vars y
vars (x:\/:y) = vars x ++ vars y
vars (x:->:y) = vars x ++ vars y

beval::Prop->[(Char,Bool)]->Bool
beval (Basic b) l = b
beval (Var c) l = foldr (\(ch,bo) bol-> if c==ch then bo else bol) False l
beval (Not c) l = not(beval c l)
beval (x:/\:y) l = (beval x l)&&(beval y l)
beval (x:\/:y) l = (beval x l)||(beval y l)
beval (x:->:y) l = not(beval x l)||(beval y l)
