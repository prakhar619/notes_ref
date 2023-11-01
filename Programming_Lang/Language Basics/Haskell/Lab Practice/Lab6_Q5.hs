
binToDec::Int->Int->Maybe Int
binToDec 0 n  = Just 0
binToDec bin n | rem bin 10 == 1 = fmap (\a->a+(rem bin 10)*(2^n))  (binToDec (div bin 10) (n+1))
               | rem bin 10 == 0 = fmap (\a->a+(rem bin 10)*(2^n))  (binToDec (div bin 10) (n+1))
               | otherwise = Nothing


main_::String->String
main_ st = show (binToDec (read st::Int) 0)

main = interact(unlines.map main_.lines)