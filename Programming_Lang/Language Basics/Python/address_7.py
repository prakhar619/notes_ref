a = 5
b = 5
print(id(a))
print(id(b))

class A:
    var = 10

print(id(A.var))
i = A
print(id(i.var))
i.var = 20
