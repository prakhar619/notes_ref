main = do
    line <- getLine
    if null line 
        then  return ()
        else do
            putStrLn $ reverseWords line
            main
reverseWords::String->String
reverseWords = unwords.map reverse.words 
-- ##############################################
--reverseWords st = unwords (map reverse (words st))

--reverseWords take a String
--right association therefore map f  where f is reverse.words where words take String -> [String]
--words "Hello World" -> ["Hello","World"]
--unwords ["Hello","World"] -> "Hello World"
--if else format: if <condiction> then IO_action else IO_action
--  therefore as then and else accept only one IO_action therefore if multiple io action then combine using do
