--Haskell is a purely functional language
main  = putStrLn "Hello World"

--compile this code using ghc filename.hs
--then run ./a.exe

--putStrLn:: String -> IO ()
--takes a string as input and return as IO () type;
--IO is a non contrete type; IO () is concrete
-- () empty tuple is called as unit

--putStrLn is a monad
--Monad is like container type; or structure like tree;
--IO is monad


