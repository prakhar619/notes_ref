import Data.Char
{--
Functors -> fmap to apply function inside Structures(functor)
    fmap :: (Functor f)=> f (a->b)-> f a -> f b
Applicative Functors -> pure, <*> to apply Structures functions to Structures
    (<*>)::(Applicative f) => f(a->b)-> f a-> f b
Monads -> >>= to apply Structure functions to Structure
    (>>=):: (Monad m)=> m a->(a->m b)-> m b

class Applicative m => Monad m where
    return :: a-> m a
    (>>=):: m a->(a-> m b) -> m b                   (this bind operator is similar to left arrow bind <- which is not an operator)
    (>>) :: m a-> m b-> m b
    x >> y = x >>= \_ -> y
    fail :: String -> m a
    fail msg = error msg

Every monad is a applicative function.

Monad Laws
i. return x >>= f       = f x
ii. mx >>= return       = mx
iii. (mx >>= f) >>= g   = mx >>= (\x-> (f x >>= g ))

return is same as pure in applicative typeclass
>>= is bind operator. Takes a monadic value and a function (a-> m b) and gives m b

--}

data MyExpr = Val Int | Div MyExpr MyExpr
eval::MyExpr->Int
eval (Val n) = n 
eval (Div x y) = div (eval x) (eval y)

--problem when div by zero: eval(Div (Val 1) (Val 0))
--using safediv

safediv::Int->Int->Maybe Int 
safediv _ 0 = Nothing 
safediv n m = Just (div n m)

eval2::MyExpr->Maybe Int
eval2 (Val n) = Just n 
eval2 (Div x y) = case eval2 x of 
                    Nothing -> Nothing
                    Just n-> case eval2 y of 
                        Nothing->Nothing
                        Just m-> safediv n m
--eval2 works but too verbose

eval3::MyExpr->Maybe Int
eval3 (Val n) = pure n 
--eval3 (Div x y) = pure safediv <*> eval3 x <*> eval3 y
--above is wrong as safediv with pure should be of type (int->int->int)
--only safediv is also wrong as <*> should take functor type function

eval4::MyExpr->Maybe Int
eval4 (Val n) = Just n 
eval4 (Div x y) = eval4 x >>= \n->
                  eval4 y >>= \m->
                  safediv n m 

--eval4 y (monad) >>= \m->safediv n m (function which takes int and returns monad)      ====> monad ans
--eval4 x >>= \n-> monad     ===> monad



--General Sequencing:
{-- 
m1 >>= \x1 ->
m2 >>= \x2 ->
    ...
mn >>= \xn->
f x1 x2 ... xn

We evaluate each of expression m1 .. mn in turn and then combine their result values
x1 ... xn by applying function f.
--}

myMapM :: Monad m => (a-> m b)->[a]->m [b]
myMapM f [] = return []
myMapM f (x:xs) = do y<- f x                 --apply monadic function f(a->m b) and return only b (removing monad m)
                     ys <- myMapM f xs       
                     return (y:ys)          --take a:b and return m a:b


conv :: Char-> Maybe Int
conv c | isDigit c = Just (digitToInt c)
       | otherwise = Nothing 

--try mapM conv "1234" and mapM conv "123a"                   
--what happens when  f x gives Nothing in: y<- f x

