#Package (collection of modules)  -> Modules (collection of variable/functions)
'''
1.import dir1.dir2.module1
    dont use dir1/dir2/ or something like this
2. __init__.py file
    each package dir must contain atleast an empty file __init.py to make sure python package is correctly import and not some other dirs
        #dir1 and dir2 both must contain __init__ file
    each init file are automatically run (all the code)
    each time full path is required
        #like x  = dir2.module1 wont work
        #use from
'''
#import
#from
#imp.reload()
# *
# as

'''Object defined by a module is created at runtime'''

#Python STL roughly 200 Modules

#import
    #if byte code absent for file
        #compiler to byte code and then execute
    #if byte code present
        #check timestamp for file and bytecode
            #if bytecode older than file
                #automatically regenerate bytecode
            #else use the same bytecode

#STEPS
#1. MODULE SEARCH PATH
    #how import statements searches for module
'''         1. home dir
                first search and override
            2. PYTHONPATH dir
                env variable which contains dir left to right which are searched
                import sys; sys.path.append('C:\\users')
            3. STL dir
            4. contents of pth. files (if present)
                a file containing dir name line by line
                alternative to PYTHONPATH
                this file maybe placed at top lvl of python install dir C:\python30
        '''
    #These become the component of sys.path
        #module search path
        #python configures it at program startup, automatically merging the home dir of the top lvl file
        #import sys      sys.path

#2.Module File Selection
    #keep in mind import statement omit .py 
    #import can load variety of things
        #source code (name.py)
        #byte code  (name.pyc)
        #dir        (name)
        #COMPILED EXTENSION MODULE  (to import c and c++)
        #zip file
        #in-memory image for frozen executables
        #java class
        #.NET component



##########################
#Creating Modules
    #Create python module by writing in external lang like c,c++,java. 
        #MODULE EXTENSION
        #generally wrap up external lib for use in python scripts
    
'''
    import module1
    import funct1 from module1
        from module1 import funct1
    import * from module1
        from module1 import *
    del module1 
    '''
#RELOAD
    #function, not a statement
    #must import itself ; from imp import reload   reload()

'''RELATIVE PATH IMPORT'''
#ISSUE with python  
    #if stl named module you create; then creating that module in name dir then import it means you cant import stl module

#. and ..
#from . import spam         <->  import spam
#from .spam import name     <->  from spam import name
#from .. import string      parent dir checked


''' Some module A.B.C
from . import D     # Imports A.B.D (. means A.B)
from .. import E    # Imports A.E (.. means A)
from .D import X    # Imports A.B.D.X (. means A.B)
from ..E import X   # Imports A.E.X (.. means A)
'''


#DATA PRIVACY for importing (specially with *)
'''
1. Use name like _hello (single underscore at start)
2. _all_ = ["var1","var2","var3"]  #export only these variables when imported
3.
'''


#MAIN AND IMPORTED FILE
#each module has built-in attribute called __name__
    #if file is being run at top lvl program __name__ = "__main__"
    #if file is being imported then __name__ = module_name_as_client_know
#to do self checking functionalities
