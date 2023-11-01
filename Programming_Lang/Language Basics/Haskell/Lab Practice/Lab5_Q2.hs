table::Int->[IO ()]
table val = [putStrLn (show x++" * "++show val++" = "++show (x*val)) | x<-[1..10]]

main = do 
        putStrLn "Give a number:"
        num_st <-getLine
        let num = read num_st::Int
        let io_list = table num
        sequence io_list