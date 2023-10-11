#Tactical mode vs strategic mode
#short supply vs long term product development

#python support multiple inheritance
#attributes of a class are shared by instances and subclasses
class c1:
    pass
class c2:
    pass
class superclass(c1,c2):
    i1 = c1()   #instance of the class1
    i2 = c2()   #instance of class2




#2 types of object: 
    #1.class object
        #class is an executable statement
        #classes are attributes in module
            #import module1; module1.class1()
    #2.instance object
        #calling a class object like a function makes a new instance object
        #each instance object inherit class attributes



##################################################

#class 
    #shared Data
    #methods
        #constructor
        #static method
        #class methods
        #normal method

class SharedData:
    spam = 1
    def __init__(self):         #__init__ function or CONSTRUCTOR
        pass
    def x(self):
        self.data = "helo"
        self.spam = 2
print("CLASS FUNCTIONALITIES")
x = SharedData()
print(x.spam)       #1
x.x()               # 1-> 2
print(x.spam)       #2
y = SharedData()    # -> 1
print(y.spam)       #1
print(x.spam)       #2
#shared data spam is shared across function; not across instance

#OOPS Principal
    #Operator Overloading ( __named function__)
    #Inherit(superclass01.__init__(self))
    #Customize(change superclass function by creating function with same name)
    #Extend(create new function with new name)
    
#CLASS INTERFACE TECHNIQUE
    #SUPER              (main class)
    #INTERITOR          (just inherits)
    #REPLACER           (change methods)
    #EXTENDER           (new methods)
    #PROVIDER           (implement full functionality)

#INTERFACE LIKE IMPLEMENTATION
class superduper:
    def action(self):
        assert False,'action must be defined'
    def delegatea(self):
        raise NotImplementedError('delegate must be defined')

    #create subclass and implement the method

#2nd method DECORATOR
#  @abstractmethod


#NAMESPACE FINALLY OVER
import oops_6
X = 11
def f():
    print(X)        #global
def g():
    X = 22
    print(X)        #local
class C:
    X = 33
    def m(self):
        #print(X)       #error
        print(self.X)   #class attrib shared 
        self.X = 55     
        X = 99          #local
        print(X)        #local
        print(self.X)
        print(oops_6.X) #import module itself then attrib of module

print("NAMESPACE")
f()
g()
cl = C()
cl.m()

'''
X = 11          # Global in module
def g1():
print(X)        # Reference global in module
def g2():
global X
X = 22          # Change global in module
def h1():
X = 33          # Local in function
def nested():
print(X)        # Reference local in enclosing scope
def h2():
X = 33          # Local in function
def nested():
nonlocal X      # Python 3.0 statement
X = 44          # Change local in enclosing scope
'''

#STATIC METHODS
    #function with no self argument
    #data processing rather of instance data processing
    #keep record of data across all instances
    #python 2.6 doesnt allow method without self args; 3.0 allows but if called from instance object then error; safe to call from class object like class1.static_method()
    #alternative use function outside the class and use it
    #staticmethod and classmethod keyword
    #decorators @staticmethod
#CLASS METHODS
    #change class object rather than instance object
    #even if called from instance object; still does its job

#TO USE A STATIC VARIABLE: use class object only; instance object creates a new variable within its own scope
class typeofMethods:
    numInstance = 9
    def printNumInstances():
        print("Number of instances created:",typeofMethods.numInstance)

print("CLASS FEATURES")
i1 = typeofMethods()
i2 = typeofMethods()
print("CLASS ATTIB:",typeofMethods.numInstance)
print("INSTANCE ATTIB:",i1.numInstance)
print("Address Class var : ", id(typeofMethods.numInstance))
print("Address Object var : ", id(i1.numInstance))
typeofMethods.numInstance += 1
print("CLASS ATTIB:",typeofMethods.numInstance)
print("INSTANCE ATTIB:",i1.numInstance)
print("Address Class var : ", id(typeofMethods.numInstance))
print("Address Object var : ", id(i1.numInstance))
i1.numInstance = 5
print("CLASS ATTIB:",typeofMethods.numInstance)
print("INSTANCE ATTIB:",i1.numInstance)
print("Address Class var : ", id(typeofMethods.numInstance))
print("Address Object var : ", id(i1.numInstance))
typeofMethods.numInstance += 1
print("CLASS ATTIB:",typeofMethods.numInstance)
print("INSTANCE ATTIB:",i1.numInstance)
print("Address Class var : ", id(typeofMethods.numInstance))
print("Address Object var : ", id(i1.numInstance))
print(i2.numInstance)



class method:
    def m1():
        pass
    def m2():
        pass
    m1 = staticmethod(m1)
    m2 = classmethod(m2)
method.m1()
i1 = method()
i1.m1()

class method2:
    @staticmethod
    def m1():
        pass





#NOT COVERED STILL
#Class and Module relation with __dict__ , __bases__ etc
#Overloading in depth
#Decorators
#Metaprogramming
