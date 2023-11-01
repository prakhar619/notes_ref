-- use of stack

type Stack a = [a]
pop::Stack a->Stack a
pop [x] = []
pop (x:xs) = x: pop xs

top::Stack a->a
top [x] = x 
top (x:xs) = top xs

push::Stack a->a->Stack a
push xs x = xs++[x]

isEmpty::Stack a->Bool
isEmpty [] = False
isEmpty xs = True

postFixSolver::String->Stack Int->Int
postFixSolver [] stack = top stack
postFixSolver (x:xs) stack  | x == '*' = postFixSolver xs (push (pop (pop stack)) ((*) (top stack) (top (pop stack)) ))
                            | x == '+' = postFixSolver xs (push (pop (pop stack)) ((+) (top stack) (top (pop stack)) ))
                            | x == '-' = postFixSolver xs (push (pop (pop stack)) ((-) (top stack) (top (pop stack)) ))
                            | x == '/' = postFixSolver xs (push (pop (pop stack)) (div (top stack) (top (pop stack)) ))
                            | x == ' '  = postFixSolver xs stack
                            | otherwise = postFixSolver xs (push stack (read [x]::Int) )


main_::String->String
main_ st = show (postFixSolver st [])

{--
main = go 
        where go = do 
                    st<-getLine
                    putStrLn (main_ st)
                    go
--}


main  = interact (unlines.map main_.lines)