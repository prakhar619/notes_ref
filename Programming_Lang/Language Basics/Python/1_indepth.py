#Numeric Type: Not a single object type but category of similar types
    #Integer
    #FloatingPoint
    #Complex

#Non CORE:
    #Sets
    #Decimal
    #Fraction
    #Booleans
    #UnlimitedIntegerPrecision

#CORE
   
#Numeric Literals
int_var = 10
float_var = 1.1020
hex_var = 0xA12     #0XA12
oct_var = 0o123     #0O123
bin_var = 0b1001    #0B1001
complex_var = 10+5j #10+5J
    #These are just rep; internally everything stored in base10
print("HEX String Directly",hex_var)
print("TO HEX String:",hex(hex_var))
print("TO OCTAL String:",oct(hex_var))
print("TO BIN String:", bin(hex_var))
hex_string = "A123F"
print("FROM HEX TO INT:",int(hex_string,16))
print("Complex Function:",complex(10,20))

#OPERATORS
# +,-,*,/,//,>>,&,|,<<,
    #// quotitent
    #/ true division
print("div_rem =",10//3)
print("div_rem2 =",-10//3)
print("div_true =",10/3)
print("div_true2 =",-10/3)

#METHOD
x = 10
y = 20
z = 12.21
zz = -3.6
zzz = 10.0
tuple_t = z.as_integer_ratio()
bool_t = zzz.is_integer()


#BUILT IN FUNCTIONS
#Python doesnt have int; just refer what it gives not actual dataType; also many may be overloaded;
    # string hex(int)
    # string bin(int)
    # string oct(int)
    # int int(string,base)
    # complex complex(int,int)
    # pow(int,int)
    # abs(int)
    # round(float)
    # int int(float)
    # float float(int)
    # eval(string)
    # min(Tuple)
    # max(Tuple)
    # sum(Tuple)
a = pow(x,y)
b = abs(zz)
c = round(zz)

#CASTING
    #INT -> FLOAT -> COMPLEX
d = int(2.3)
e = float(3)
f = (2.5).as_integer_ratio()
g = float('1.23')
h = int('10')



#VARIABLES
    #variables are created and assigned value at first time
    #cant use non assigned variable (unlike js where undefined used)

#DISPLAYING
    #2 Types: repr() and str() 
        #repr() how code actually stores data
        #str() user friendly rounded off
            #print() now shows repr format
print(10/3)
print(repr(10/3))


#LOGICAL
    #Chained Usage
int_x = 10
int_y = 10
int_z = 20
print(int_x <= int_y < int_z)



#SUPPORT LIB
import math
def math_help():
    print(math.pi)
    print(math.e)
    print(math.sqrt(2))
    print(math.floor(2.5))
    print(math.trunc(-2.5))
    print(math.trunc(-2.5))
    print(math.floor(2.54))

import random
def random_help():
    print(random.random())
    print(random.randint(1,10))
    print(random.choice([1,2,3,4]))


#NON CORE

#SET                Valueless Dictionary; Maths Set
    #MUTABLE 
        #Elements inside sets must be immutable (hashable)
x = set('abcd')
y = set([1,2,3,4,9,9])

#Operators
    # -     Difference
    # |     Union
    # &     Intersection
    # ^     XOR
    # >, <  Superset,subset check

#Methods
    #intersection()
    #add()
    #update()
    #remove
    #union()
    #issubset()


#Comprehension
k = { x ** 2 for x in [1,2,3,4]}
print(type(k))


#DECIMAL    fixed precision floating point value
def decimal_help():
    print("Need of Decimal",0.1+0.1-0.1-0.3)
    import decimal
    print("With decimal",decimal.Decimal('0.1')+decimal.Decimal('0.1')+decimal.Decimal('0.1')-decimal.Decimal('0.3'))
        #decimal.Decimal(string)
        #decimal.Decimal.from_float(0.1)

    decimal.getcontext().prec = 4
        #setting precision
        #no of decimal digit

#FRACTION           rational number
import fractions        
def fractions_help():
    x = fractions.Fraction(1,3)
    print(x)
    y = fractions.Fraction(2,3)
    print(x+y)
    z = fractions.Fraction('0.25')
    zz = fractions.Fraction.from_float(0.25)

#Booleans
    #bool
    #True => 1
    #False => 0

print(type(True))
print(isinstance(True,int))


###########################################
##########################################
#################STRING####################
##########################################
###########################################

#String Type
    #No char support in python; one character string
    #3 Types of string:
        #str
        #bytes
        #bytearray
    #Python doesnt have \0 as string terminator; it stores length and text both in memory
    #Non printable character are printed in hex
        #print('\o01\o02\x03') => \x01\x02\x03

#LITERALS
str1 = 'spa""m'
str2 = "spa'm"
str3 = '''MultiLine string
\n is automatically appended at each breakpoint'''
    #Horribly Hackish
str4 = 'escape sequence \tp\na'
    #escape char \n counted as one char
str5 = r"C:\new\test.spm"
    #raw string very useful
    #string consider as its seen; no escape sequence
    #raw string cannot end with \: "hello\"   INVALID
    #raw string cannot have odd \

#OPERATORS
    #none
str6 = "HELLO""WORLD"
    # *,+
        # "e" * 3 => "eee"
        # "e" + "e" => "ee";    "e"+1 gives error

#SEQUENCE OPERATIONS
    # [a:b:c]   non inclusive upper bound

#METHODS            (in 2.6 we have to import string)
    #slice()
    #replace()
    #find()
    #join()
    #split()
    #rstrip()
    #isalpha()
    #startswith()
    #endswith()


#CASTING
    # repr()    (as code string)
    # str()
    # ord()     (to convert string to ascii)
    # chr()     (to convert ascii to string)
    #REPR VS STR
print(str1)         #spa""m
print(str(str1))    #spa""m        
print(repr(str1))   #'spa""m'
print(repr(str2))   #"spa'm"
k = str(10)
f = str(1.2)
ch = ord("a")
i = chr(ch)

#STRING FORMATTING
    #2 options
        #Formatting expression
            #  %[][][][]typecode
                #  name, flag, width, .precision
        #Formatting method

f_str = 'That is %d %s bird' %(1,'dead')
f_str1 = 'That is not %s' %'you do it'
f_str2=  'precision used %.4f' %1.233342
f_str3 = 'width used %4f' % 10.121
print(f_str3) 


    #Formattiog method calls
str1 = '{0},{1} and {2}'
str1_1 = str1.format('hello','everyone','goodnight')
print(str1_1)
str2 = '{col1},{col2},{now}'
str2_2 = str2.format(col1="helow",col2="www",now="what")
print(str2_2)

#SUPPORT LIB
import re       #regular expression




###########################################################
######################################################
########################LIST##################################
######################################################
#############################################################

#list

l = [1,2,3] * 3     #one inner access in *
                    # [ 1,2,3,1,2,3, 1,2,3]


#OPERATORS
    # +     concat and returns a new obj
    # *     one inner access 
    # in
    # del

#METHODS
    #append()     mutate the list
    #sort()       mutate the list
    #extend()
    #pop()
    #reverse()
    #index()
    # insert()
    # remove()
    


#SEQUENCE OPERATIONS
    #[]         slicing;copying;indexing



#BUILT IN
    #reversed()  
    #len()   

######################################################################
##############################################################################
###############################################################################
####################DICTIONARY##############################
############################################################
#######################################################################################

#Dictionary
    #for sparse matrix

dictt = {'span': 1,'ham':20}
dictt['span']

#keys(), values(), items()
    #return view object and not list
    #view objects are iterables
    #also maintains the dictionary original order
    #any operations on them require conversion to list
    #loop constructs automatically force iterable object to produce one result on each iteration

    #even before conversion to list: some operations are allowed
        #dict_keys   => set-like; | (union) and intersection and other set operations (other operand can also be set)
        #dict_value  => 
        #dict_items  => also set-like (unique and hashable)
k = dictt.keys()
print(type(k))

#OPERATORS
    #in
    #del

#METHODS
    #keys()
    #items()
    #values()
    #get()
    #update()
    #pop()
    #dict.fromkeys()


#COMPREHENSION
D = { k : v for (k,v) in zip(["a","b","c"],[1,2,3])}

#BUILT IN FUNCTION 
    #zip()
    #list()
    #tuple()
    #dict()
    #sorted()





#####################################################################
###########################################################################
##################Tuples, Files, and everything else##############################
###########################################################################
############################################################################

#Tuple
    #python recognizes tuple without parentheses

x = (40)
print(type(x))
x = (40,)
print(type(x))

#OPERATORS
    # +,*

#METHODS
    #index()
    #count()


############################################################################
####################################################################################
#####################Files########################################################
#######################################################################################
##########################################################################################

#Files
    #content is string
    #add b for binary mode
    #close is optional
    #files are buffered and seekable

'''
>>> myfile = open('myfile.txt', 'w')    # Open for text output: create/empty
>>> myfile.write('hello text file\n')   # Write a line of text: string
16
>>> myfile.write('goodbye text file\n')
18
>>> myfile.close()                  # Flush output buffers to disk
>>> myfile = open('myfile.txt')     # Open for text input: 'r' is default
>>> myfile.readline()               # Read the lines back
'hello text file\n'
>>> myfile.readline()
'goodbye text file\n'
>>> myfile.readline()               # Empty string: end of file
'''


#METHODS
    #write()
    #read()
    #readline()
    
#BUILT IN
    #open()
    #close()

#SUPPORT LIB
import pickle
    #eval is too powerful to let user enter string directly
    #pickle to create object from file directly
    #pickle input and write on same file; data is encodes in pickle way

'''
D = {'a': 1, 'b': 2}
>>> F = open('datafile.pkl', 'wb')
>>> import pickle
>>> pickle.dump(D, F) # Pickle any object to file
>>> F.close()

Then, to get the dictionary back later, we simply use pickle again to re-create it:
>>> F = open('datafile.pkl', 'rb')
>>> E = pickle.load(F) # Load any object from file
>>> E
{'a': 1, 'b': 2}
'''