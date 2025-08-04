#FUNCTIONS
    #def is executable => can be present inside if else; def inside def
    #def creates an object and assigns name to it => function object can have user-defined attributes attached to it
    #lambda creates an object and returns it as a result
    # yield  and return => yield stops the function temporarility (till next call) while return ends the function
    # global to declare a global variable => (either existing global or create new global)
    # nonlocal to declare existing enclosing variable   (enclosing means closure function variable) => def f1: x = 10(enclosing) def f2:print(x) return f2
    # all argument passed by reference

#def
    #true executable statement
    #def are not evaluated till called

#Polymorphism:
    #because no argument type, return type polymorphism is easy to implement

#Argument
    #All arguments are passed by ref (immutable cant be changed; mutable are chained change)
    #Way to pass argument
        #Positionals    (left to right)
        #Keywords       (argument name)
        #Default        (default value)
        #Varargs        (multiple parameter)
        #Varargs unpacking (unpacking list,tuple)
        #Keywords only argument (reverse = true)

def hello():
    pass

h1 = hello  #assign function object
h1()        #call function
h1.a = 10

#SCOPES
#lexical scoping => meaning scope depents entirely where variable is in the source code
    #Python has functional scope
        #BUILT INs  (__builtin__ module)(import builtins; dir(builtins))
        #GLOBAL
        #non local
        #local

    #local =>   inside function
            #   cannot be accessed outside function
            #   not remembered
            #   variable assigned inside def => local (unless global or nonlocal keyword used)
            
    #enclosing => inside outer function
                # remember if inner function called
                # nonlocal need to used when assigning new value
                # non local cannot create new enclosing variable like global; gives error; therefore only for exisiting enclosing variable
                # non local will not look in global scope if absent; rather error

    #Global     =>  file lvl access (single file only)

'''Method to access global  file.py
                    1. global var
                    2. import file; file.var
                    3. globl = sys.module['file']; globl.var                    ]
                 '''

    #NAME RESOLUTION (read access)
        #LEGB
            #local => enclosing(def or lambda) => global => built in
            # to read no need(optional) to use global or nonlocal


#CLOSURE or factory functions
def f1():
    X = 88
    def f2():
        print(X) # Remembers X in enclosing def scope
    return f2 # Return f2 but don't call it

action = f1() # Make, return function
action() # Call it now: prints 88


#LAMBDA
    #is an expression (not statement)
action1 = (lambda n, x=10: x**n )
print(action1(10,2))
x = (lambda a="free",b="fie",c="foe":a+b+c)
x("wee")

    

l  = [lambda x: 10*x, lambda x: 11*x, lambda x: 12*x]
l[0](5)
l[1](6)

#############################################
#Argument

#1.Normal
def f(a,b,c):
    pass
f(1,2,3)                                    

#2.Multiple Argument
def f1(a,*varargs):
    for i in varargs:
        pass
    pass
f1(1,2,3,4,6)

#3. Multiple Argument+keyword Multiple Argument
    #keyword argument always last
    #keyword only argument always at last
def f2(a,*varargs,**kargs):
    pass
f2(1,2,3,x = 10,y=20)

#4. Keyword ONLY argument without multiple argument
def f3(a,*,x,y):
    pass
f3(10,x = 10,y = 20)

#5 Defaults
def f4(x = 2,y = 4):
    pass
f4(1)




################################################
#Function object
    #indirect function call             #def f()    e = f  e()
    #introspection tool
        #func.__name__
        #dir(func)
        #func.__code__
        #func.__code__.co_varnames
        #func.__code__.co_argcount
    #function Attribute

#Annotations
def func10(a:'string',b:(1,10),c:float) -> int:
    pass
def func20(a:'string' = "HELLO WORLD",b:(1,10)=(2,2)):
    pass

#map
#filter


    