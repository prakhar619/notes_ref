import Data.Char
--getContents::IO String

--interact::(String->String)->IO ()

import System.IO
--openFile::FilePath(type synonym for string) -> IOMode->IO Handle              ; data IOMOde = ReadMode | WriteMode | AppendMode | ReadWriteMode
--hGetContents::IO Handle->String
--hClose:: Handle-> IO ()
--hGetLine,hPutStr,hPutStrLn,hGetChar
--readFile:: FilePath->IO String
--writeFile:: FilePath->String->IO ()
--appendFile::FilePath->String->IO ()

import System.Environment
--getArgs:: IO [String]
--getProgName::IO String
main  = do
         contents <- getContents
         putStr (map toUpper contents)




--cat file.txt | ./a.exe or interactive by direct ./a.exe 
--getContents read string till EOF is encountered; mostly like getLine except delimiter is EOF (end of file character)
--lazy evaluation is done is getContents; bind name with IO_string but actually not properly in memory; not till actually used

--interact takes a function (string->string) output string is printed; input string is entered by user everytime;
