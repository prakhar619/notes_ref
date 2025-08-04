#STATEMENTS
    # use ; if multiple statement in single line
    #if
        #parentheses are optional
        #indentation block not {}
        #elif else
    #try:   except:
    #while loop
        #while :
        #else:  (runs if while loop exited normally)
    #break;pass;continue;

[a,b,c] = (1,2,3)
a,b,c,d = "HELOOO"  #d gets rest of string
a,b,c,d = range(4)  #range gives list in 2.6 and iterator object in 3.0
#zip and map
#zip(*zip) for unzip
a = b = c = "kaise hua"


#TERNARY
    # X if Y else Z
    # [Z,Y][bool(X)]        #bool converts X into 0 or 1; then list indexing 

#PRINT STATEMENT
    #print([object, ...][, sep=' '][, end='\n'][, file=sys.stdout])
