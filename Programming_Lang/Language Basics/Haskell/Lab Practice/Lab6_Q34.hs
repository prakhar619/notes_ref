tuple::Monad m=>m a ->m b->m (a,b)
tuple mx my = mx >>= \x->
              my >>= \y->
                return (x,y)

foldM::Monad m=> (a->b->m a)->a->[b]->m a 
foldM f v [] = return v 
foldM f v (x:xs) = (foldM f v xs)>>=(\a->f a x)

