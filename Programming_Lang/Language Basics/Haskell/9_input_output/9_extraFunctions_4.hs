import Control.Monad
--when bool $ IO_action
--forever $ IO_action
--forM::(Monad m)=>[a]->(a->m b)-> m [b]

--sequence :: [IO a]->IO [a]
--mapM :: (Monad a)=>(a->m b)->[a]->m [b]



main = do 
        c<-getChar 
        when (c/= ' ') $ do putChar c 

        rs<-sequence [getLine,getLine,getLine]
        print rs

        let io_list = map print [1,2,3,4,5]
        sequence io_list

        mapM print [6,7,8,9,10]
        


--when is kind of control flow statement but actually a function;
--takes bool and IO action and if bool is true then IO action else return ()

--sequence:: [IO a]-> IO [a]
-- kind of takes a list of IO actions and executes them and returns a list containing ans

-- print executes the list and give the io_list as [IO (),IO (),IO (),IO (),IO ()] 
-- [print 1]:: [IO ()]
-- #######################but does not print the list
-- sequence io_list is [(),(),(),(),()] if binded

--combining sequence and map => mapM
--mapM (a-> m b)-> [a] -> [b]

--forever takes an IO function and repeats its forever (i mean forever)

--forM automatically executes too; better and complex than mapM
--function takes an argument and returns an IO_action for each element of list







