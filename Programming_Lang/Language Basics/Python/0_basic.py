# Comment

'''Multi line comment 
(actually multiline string)'''

"""or use this
doesnt matter
"""

'''
DataTypes
1. Primitive DataTypes
    int
    float
    bool
    str

2. Non Core DataTypes
    set
    list
    dict
    tuple

3. Special Type
    None
    
4. Other Types
    complex
    frozenset
    bytearray
    bytes
'''

s = "string"
n = 1010

#use help to get syntax and usage information for functions
help(s.replace)

#use type to get type/class of an object
print(type(s))

#KIND OF GENERIC OPERATORS
#in and is
    #in to check one data in bigger object
    #is to check both are same object or not

#OOPS subclassing:
    #dict
    #list
    #str
    #tuple
    #int
    #float
    #complex
    #byte
    #type
    #set
    #   and many more...

#Numeric Type
    #Number->integer type: extra precision
        #repr and str representation
            #repr : actual how code processes data
            #str : printed user friendly
    #OPERATORS
        # +,-,*,/,**,%,
    #IMMUTABLE
    
#SEQUENCE
        #group of dataTypes
        #arbitary collection bytes
        #left to right order
        #generic to list,tuple,string
        #items fetched by their relative order
        #LIST STRING TUPLE
        #Operations
            #len                                Sequence length
            #[<num>] with negative indexing     indexing
            #[<num>:<num>]                      slicing
            # +                                 concat

#ITERABLE
    #group of dataTypes
    #LIST STRING TUPLE DICTIONARY SET

#MUTABLE (not group; just of referencing)
    #LIST DICT SETS(*special)

#IMMUTABLE
    # NUMERIC STRING TUPLES FROZENSET

#Strings
    #IMMUTABLE
        #python cleans up object
        #new object created
    #BACKSLACH CHARACTERS or ESCAPE CHARACTER
        # \n 
    #OPERATORS
        # +,%
    #METHODS
        #string methods operations
    #SEQUENCE
        #SEQUENCE operations
        #OFFSET ACCESS
    

s = "WELCOME TO HELL"
s_mul = '''WELCOME TO
HELL'''
#Sequence operations
    #len                                Sequence length
    #[<num>] with negative indexing     indexing
    #[<num>:<num>]                      slicing
    # +                                 concat
print("1.len:",len(s))
print("2.[]:",s[2])
print("2.[]",s[-3])
print("3.[]:",s[3:6])
print(s+s_mul)

#Method operations (does not mutate; creates new object): dir(<string>) to get all methods
    #find()
    #replace()
    #split()
    #upper()
    #isalpha()
    #isdigit()
    #rstrip()
    #format()


#LISTS
    #MUTABLE
        #stores object reference
    #HETEROGENOUS
        #all types of data types in single list
        #list inside list (2d array) or more
            #M[1][2]
    #OPERATORS
        #in
    #METHODS
        #Method operations
    #SEQUENCE 
        #Sequence Operations
        #OFFSET ACCESS
    #ITERABLE
    #COMPREHENSIONS
        #generators
            #[row[1] +1 for row in M]
        #iterators
            #next(i) where i is iterator (not iterable)


l=[1,2,3,"ture",True]
#Sequence operations
    #[<num>]
    #[<num>:<num>]
    # +

#Method operations
    #append()
    #pop()
    #del
    #sort()
    #reverse()

#BUILT IN FUNCTIONS
    #len()

#Comprehensions
M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    #Generators
col1 = [row[1] for row in M]
col2 = [row[1] for row in M if row[1]%2 == 0]
    #Iterators
it = iter(col1)
next(it)
next(it)

#DICTIONARIES
    #MAPPING
        #key and value pair
        #stores object references
    #HETEROGENOUS
        #key: immutable dataType
        #value: all allowed
            #D['k1']['k1_1']
    #MUTABLE
    #OPERATORS
        #[]
            #read 
            #write
        #in
            #check key present of not
    #Methods
        #Methods operations
    #NON SEQUENCING
        #ACCESS BY KEY
    #ITERABLE

dict = { 1: "HELLO", "RO":'c'}
#Method Operations
    #keys()
    #items()
    #sorted()
    #get()
        #[] read with default value
dict['a'] = 'b'
dict.get('a',0)     #if 'a' key not present return 0


#TUPLES
    #IMMUTABLE
        #used as const list in program; when you dont want to change list value
    #HETEROGENOUS
        #all data types allowed even mutable
        #mutable members can be edited
    #Method
        #Method operation
    #SEQUENCE
        #Sequence operation
    #ITERABLE

#Method Operations
    #index()
    #count()

#FILE
    #BUILT IN FUNCTIONS
        #open()
        #close()
    #ACCESSING
        #read()
        #write()

# ** Booleans True is just 1; False is 0
# ** None for initialising names and object
y = None
print(y)




#SETS   (NON CORE)
    #MUTABLE
        #Element inside sets should be immutable
    #OPERATORS
        # &,|,-
    #NON SEQUENCE
    #ITERABLE
    #COMPREHENSION
    #BUILT IN FUNCTIONS
        #set() to create set out of SEQUENCE

x = set()
y ={1,2,"Ture",True}



'''
Dynamic TYPING
    Variable  ------->  [Object]
    Variable always link to object;
    Variables are always pointer
        Larger object may link to other object;
    Each object has 2 standard header fields:
        type designer           data type of object
        reference counter       to determine when to reclaim the space/object
            reference counter drops to zero meaning ready to be reclaimed
        IMPLICATION of this process
            a= 12
            a= [1,2,12]
        type live with object, not names
    Shared References
        a=3
        b=a
        2 variable ----> 1 object
        Any change in a will not reflect change in b
            As a change its object; but b points to same object
        This is all for non mutable type
        #FOR MUTABLE TYPE
            Change reflected up the chain
            l1 = [1,23,3]
            l2 = l1
            l1.append(222)

            Therefore for mutable type
            Copy operation
                slicing [:] like this for list  SEQUENCE OPERATOR
                SET and DICT use .copy() method 
                    import copy
                    copy.copy(SETS)         Shallow copy
                    copy.deepcopy(DICT)     Nested copy

'''
a = 10
b = a
print(a,b)
a= a+2
print(a,b)




    





