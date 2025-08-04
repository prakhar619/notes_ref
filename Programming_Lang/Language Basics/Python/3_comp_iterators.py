#for loop => generic;  
    #works for list,tuple,string,iterator object also

#iterable: 
#   either physically stored sequence
#   or object that result one object in one time
#   list , dict(view object), string, set, tuple, range (range doesnt give list)

#iterator:
#   __next__() (next()) or loop for loop to iterate
#           next() function calls __next__() method 
#   list, ...etc are iterables but do not have their own iterator. [Still support many iterator operation]
#   file have their own iterator (next())
#   map,zip,filter (can process iterables and return iterator)

#Iterator/iterable functions
#   sorted()        iterable sorted(iterable)
#   zip()           iterator zip(iterable,iterable)
#   filter()        iterator filter(function,iterable)
#   enumerate()    
#   map()           iterator map(function,iterable) 

#   sum()           takes iterable/iterator returns int or bool
#   any()
#   all()
#   max()
#   min()

#FILE ITERATORS
f = open('./resource/file.txt')
f.readline()
f.readline()
f.__next__() #gives error if reached end of file
f.close()

for line in open('./resource/file.txt'):
    continue
f.close()
for line in open('./resource/file.txt').readline():
    continue
f.close()
f = open('./resource/file.txt')
while True:
    line = f.readline()
    if not line: break
#Above 3 loop statements although same functionality; 2nd loop can cause memory explosion. 3rd loop is slower than first loop

#LIST ITERATOR
l = [1,2,3,4]
I = iter(l)
val1 = next(I)
val2 = next(I)
val3 = next(I)
val4 = I.__next__()

#VIEW OBJECTS
d = {'a':1,'b':2, 3: 'c'}
for keys in d.keys():
    print(type(keys))

I = iter(d)
key1 = next(I)
#values(),items()
    
    #view object are not iterators

#RANGE ITERABLE
r = range(5)
print(r)
print(type(r))
I = iter(r)
next(I)
next(I)
L = list(range(10)) #forcing to a list 

    #doesnt support sequence operation like list
    #supports iteration,indexing,len function
    ## special iterable as supports multible itertors over its result

r = range(5)
I = iter(r)
next(I)         #=>0
I2 = iter(r)
next(I2)        #=>0

#others
r = [0,1,2,3,4]
I = iter(r)
next(I)         #=>0
I2 = iter(r)
next(I2)        #=>1


#Argument ITERATOR
def args(a,b,*ag):
    print(type(*ag))
    #indefinite no of argument can be passed now
    #except first 2; all becomes part of *ar iterator
    #varargs

x = (1,2)
y = (3,4)
print(list(zip(x,y)))
print(list(zip(*zip(x,y))))
    # * in function call; unpacks the parameter; like def fun(a,b,c,d):              fun(*[1,2,3,4]) unpacking


#MAP
m = map(abs,(-1,0,1))
next(m)








################################################################################
'Comprehension'
#map vs list comprehension
    #list comprehension are faster

L = [x**2+y for x in [1,2,3,4,5] for y in [10,11,12,13,14] if x %2 == 0]
    #nested with filter 
    #   x: loop
    #       y:loop
    #           if condiction
print(L)

lines = [line.rstrip() for line in open('./resource/file.txt') if line[0] == 'p']
print(lines)


##########################################################################################################
#GENERATORS
    #support just one active iteration

    #Generator Function
        #functions (normal def) which yield (rather than return)
        #gives iterator
    #Generator Expression
        #similar to list comprehension


#GENERATOR FUNCTIONS
    #unlike normal functions; they suspend and resume their execution at each call
    #entire local scope retains information
    #yield returns a value
    # automatically created method __next__
def gensquares(N):
    for i in range(N):
        yield i**2
        print("FUNCTION CALLED",i)
print("GENERATOR OUTPUT:",gensquares(10))
x = gensquares(2)
print(next(x))
print(next(x))

#generator returns to caller after yield is executed

for x in gensquares(1):
    print(x)
    #here its x is iterated till gensquare gives error
    #so 0 -> function called 0,error


#GENERATOR EXPRESSIONS
    #()
    #(x**2 for x in range(4))
        #nothing as tuple comprehension

g = (x**2 for x in range(4))
next(g)
next(g)
next(g)





