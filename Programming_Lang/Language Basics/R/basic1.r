x = rnorm(50)
y = rnorm(50)

plot(x,y)
plot(x,y,xlab = "X axis", ylab="y AXIS", main="title")
 
pdf("Fig.pdf")
plot(x,y,col="green")
dev.off()           #indicates that we are done creating the plot


#contour plot

x = 1:10
y = x 
z = matrix(1:100,10,10)

contour(x,y,z)

contour(x,y,z,nlevels=45,add=T)

image(x,y,z)

persp(x,y,z,theta=30,phi=20)