{--
Functors -> fmap to apply function inside Structures(functor)
    fmap :: (Functor f)=> f (a->b)-> f a -> f b
Applicative Functors -> pure, <*> to apply Structures functions to Structures
    (<*>)::(Applicative f) => f(a->b)-> f a-> f b
Monads -> >>= to apply Structure functions to Structure
    (>>=):: (Monad m)=> m a->(a->m b)-> m b

class Monad m where
    return :: a-> m a
    (>>=):: m a->(a-> m b) -> m b
    (>>) :: m a-> m b-> m b
    x >> y = x >>= \_ -> y
    fail :: String -> m a
    fail msg = error msg

Every monad is a applicative function.

return is same as pure in applicative typeclass
>>= is bind operator. Takes a monadic value and a function (a-> m b) and gives m b

--}