library(MASS)
library(ISLR)

#fix(Boston)

p_names = names(Boston)
n_p = dim(Boston)
n = n_p[1]
p = n_p[2]


attach(Boston)
#lm(y~x) format;  
lm.fit <- lm(medv~lstat,data=Boston)

#lm.fit
    #to get coefficients
#summary(lm.fit)
    #to get all data related to coefficients like t value, p value, standard error
#names(lm.fit)
    #to get all variables related to lm.fit
#lm.fit$variables
    #to print related variables of lm.fit


#confint(lm.fit)
    #to get confident interval of coefficients

#predict(lm.fit,data.frame(lstat=c(5,10,15)),interval="confidence")
    #predict y and find the confidence interval y for given x

#predict(lm.fit,data.frame(lstat=c(5,10,15)),interval="prediction")
    #predict y and find the prediction interval y for given x

plot(lstat,medv)
abline(lm.fit)
dev.off()


plot(predict(lm.fit),residuals(lm.fit))
y_hat = predict(lm.fit)
rss = residuals(lm.fit)
#predict(lm.fit) gives fit value for each of observation
#residuals(lm.fit) gives rss of each prediction to y




#Multiple Regression

R_lm.fit = lm(medv~lstat+age,data=Boston)
summary(R_lm.fit)

ALL_lm.fit = lm(medv~.,data=Boston)


#?summary.lm
#summary(ALL_lm.fit)$sigma


#Interaction Terms
lm(medv~lstat*age,data=Boston)
    #lstat,age,lstat*age    (all 3 terms present)
lm(medv~lstat:age,data=Boston)
    #lstat*age              (only 1 predictor)
#Non Linear Predictor
lm(medv~lstat+I(lstat^2))
    #I() function called
    #medv~poly(lstat,5))
    #medv~log(lstat)

anova(lm.fit,ALL_lm.fit)
    #compare to fitted model

#R automatically deals with qualitative predictors
#contrast(Predictor) to see encoding
