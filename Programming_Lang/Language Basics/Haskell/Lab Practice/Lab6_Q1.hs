import System.IO



main = do   
        fileHandle <- openFile "foo.txt" ReadMode 
        st <- hGetContents fileHandle
        putStrLn st
        hClose fileHandle

