main = do 
        --3 basic functions in IO; IO actions
        --putChar:: Char->IO ()
        --getChar:: IO Char
        --return:: a-> IO a
        putChar 'a'
        getChar
        return 'a'

        --Bigger actions/Functions
        --putStrLn:: String-> IO ()
        --getLine:: IO String
        --print:: Show a=>a-> IO ()
            --same as putStrLn.show
        empty<-putStrLn "Hello World"
        name<-getLine
        print 10
        let pure_exp = map (*2) [1,2,3]
        putStrLn name





-- ######################################################because of buffering or issue; getChar is executed first;
--do combines multiple IOaction into one
-- also all the input is taken at once; Like this main should have inputtype <char><string> => aHello World
--getChar returns IO a and not a; a is pure whereas IO a is not pure
-- return is not like imperative return; code is still executed after return
--  <- this is a binding operator: IO a -> a
-- using binding on putStrLn does nothing except giving unit/empty tuple
-- use binding on any except last statement of do (for implicit binding of main to that statement)
-- last expression of do should be an expression(IO)
--  kinds of purify the value; removes IO type (opposite of return) and assign to a name
-- let is used to bind name to a pure expression
-- name = getLine does nothing except as an alias; now use word name as getLine; (ghci only)


