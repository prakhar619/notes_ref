#Comment



vector1 = c(1,2,3,4,5)
len  = length(vector1)
vector2 <- c(1,3,5,7,9)

vectorAlt = seq(1,10,2)
vector2Alt = seq(1,10,length=2)         #length defines length size and not the increment
vector3Alt = 1:10

#vector Operations
vector3 = vector1 + vector2
    # +,-,*,/,sqrt(),^

A = matrix(data = c(1,2,3,4), nrow = 2, ncol = 2)
B = matrix(c(1,2,3,4), 2, 2, byrow = TRUE)
C = matrix(1:16, 4,4)

a11 = A[1,1]            #matrix indexing from 1,1
A1_21 = A[c(1,2),1]     #1st col of row 1 and 2 # returns a matrix
A1 = A[1,]
A_minus = A[-1,]        #all except 1st row

order = dim(A)      

#Vector with random values
A_r = rnorm(50,mean = 10, sd = .1)      #size of vector is 50
B_r = rnorm(50)                         #mean = 0, sd = 1

cor(A_r,B_r)                            #correlation = covariance/mean

#random no gen
set.seed(10101)
C = rnorm(40)

#Matrix Operations
mu = mean(A)
variance = var(A)
standardDeviation = sd(A)

