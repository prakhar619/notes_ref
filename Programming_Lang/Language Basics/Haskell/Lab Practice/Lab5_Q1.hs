
repeatcharK::String->Int->String 
repeatcharK st k = [x | x <- st, m <-[1..k]]

main = do
        putStrLn "Enter a string:"
        st<-getLine
        putStrLn "Enter a number:"
        num<-getLine
        let numm = read num::Int
        let stNew = repeatcharK st numm
        putStrLn stNew