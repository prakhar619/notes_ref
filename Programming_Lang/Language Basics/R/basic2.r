Auto = read.csv("D:/GitHub/notes_ref/Programming_Lang/Language Basics/R/DataSet/Auto.csv",header=T,na.strings="?")

A = dim(Auto)
n = A[1]        #no of observations
p = A[2]        #no of predictors

# missing data observation removal  (? marked data)
Auto = na.omit(Auto)
A_ = dim(Auto)
n_ = A_[1]

#predicators names
p_name = names(Auto)

#using predictor names in plots
plot(Auto$cylinders,Auto$mpg)

#or use attach to directly use predictor names
attach(Auto)
plot(weight,horsepower)

#converting quantitative predictor to qualitative predictor
#causes box plot
cylinders = as.factor(cylinders)
plot(cylinders,mpg)
plot(cylinders,mpg,col="red",varwidth=T,horizontal=T,xlab="Cylinders",ylab="MPG")

hist(mpg)
hist(mpg,col=2,breaks=15)


pairs(~mpg+displacement+horsepower+weight+acceleration,Auto)

plot(horsepower,mpg)  
identify(horsepower,mpg,name)

summary(Auto)
summary(mpg)


#to present the data in excel form
fix(Auto)