import numpy as math
p = 907
q = 773

n = p*q
print("Public Key:",n)

e= 65537
print("Default e value:",e)

totient_n = math.lcm(p-1,q-1)

d = 0


for i in range(0,totient_n,1):
    if( 1%totient_n == (i*e)%totient_n):
        d = i

print("Private Key:",d)