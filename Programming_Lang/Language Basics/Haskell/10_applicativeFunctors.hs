{--
fmap:: (a->b)->f a->f b

1.IO is an instance of Functor.

instance Functor IO where
    fmap f action  = do
                       result <- action
                       return (f result)

fmap takes a function and a non_concrete+concrete and applies function on concrete part
fmap (*2) Just 2 = Just 4
while defining instance of Functor we use only non concrete datatype
therefore action is concrete value

2. -> is an instance of Functor; -> is an operator for function

instance Functor ((->)r) where
    fmap f g = (\x-> f (g x))

here f and g both a functions!;
f::a->b   or (->) a b
g::a->c   or (->) a c
here fmap composes both f and g
fmap = (.)
fmap (*2) (+3) = \x->(* 2 (+ 3 x))

3. Rules of Functors: Functor Law
 i) id function over a functor should give back same functor; fmap id action = action
    (fmap id = id)
 ii)Composing 2 functions then mapping over functor should be same as mapping 1st function then 2nd function over functor; fmap (f.g) = fmap f.fmap g or fmap (f.g) F =  fmap f (fmap g F)
    (fmap (g.h) = fmap g.fmap h)
--}

{--
Applicative Functors:
    Applicative Typeclass
        Kind of Functor over functions rather than default type
            eg: Just (*3)  :: Maybe (a->a)
        Then defining <*> to apply those functions.

import Control.Applicative
    Applicative Typeclass
    <$> : just like fmap f a = f <$> a

class (Functor f) => Applicative f where
    pure :: a-> f a
    (<*>) :: f(a->b) -> f a -> f b

pure x                            = Just x
Just (+3) <*> Just 9              = Just 18
pure (+) <*> Just 10 <*> Just 20  = Just 30
[(*3),(+3)] <*> [1,2,3,4,5]       = [3,6,9,12,15,4,5,6,7,8]
(++) <$> getLine <*> getLine      = <$> is just infix for fmap [fmap f a = f <$> a] 
                                        (++) <$> getLine => IO (String->String)
                                         <*> getLine => IO String
  
 i) pure f <*> x = fmap f x
    f is normal function; x is a datatype(Just a); first pure f then <*> 

Applicative Laws
i) pure id <*> x = x
ii) pure (g x) = pure g <*> pure x
iii) x <*> pure y = pure (\g->g y) <*> x
iv) x <*> (y <*> z) = (pure (.) <*> x <*> y) <*> z

instance Applicative [] where
 pure x = [x] 
 fs <*> xs = [f x | f <- fs, x <- xs]

instance Applicative IO where
 pure = return
 a <*> b = do
            f <- a
            x <- b
            return (f x)
--}

class (Functor f) => MyApplicative f where
    mypure:: a-> f a
    ( <***> ) :: f(a-> b) -> f a -> f b

data MyMaybe a = MyJust  a | MyNothing deriving (Show)
instance Functor MyMaybe where
 fmap f MyNothing = MyNothing
 fmap f (MyJust a) = MyJust (f a)

instance MyApplicative MyMaybe where
 mypure = MyJust
 MyNothing <***> _ = MyNothing
 (MyJust f) <***> something  = fmap f something 