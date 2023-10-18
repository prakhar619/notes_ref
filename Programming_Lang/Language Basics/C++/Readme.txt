C++ language features most directly support 4 programming styles
Procedural programming
Data Abstraction
Object Orientation programming
Generic programming

C++ type checking and data-hiding features rely on compile-time analysis of programs.
C is strongly typed, weakly checked language

C++ fundamental(built in) types, operators and statements are those that hardware deals directly with: numbers characters and addresses.

Except for new, delete, typeid, dynamic_cast and throw , try, individual c++ expression need no run time support

Good Design Patterns
    Macro substitution is almost never necessary in C++.
    Dont declare before you need it and initialize immediately.
    Dont use malloc(). Use new .  free() -> delete()
    Avoid void* , unions, cast except deep within implementation.
    Use STL extensibly.
    Variable is never implicitly a reference
    Function is not virtual by default.
    Abstract class as interfaces.
    Most minimal run time reflection: dynamic_cast and typeid

C++ Compiled Language
Statically typed Language
Source --compile--> Object file --link--> executable

Every C++ program must have exactly one global function named main()

Struct in C 
    cant take functions as members 
    only data members
    no non static members
    no constructor
    no access modifiers
    no references to Struct
    sizeof operator for struct generate 0
    struct keyword is important

Struct in C++
    can hold both functions and data members
    can have static members
    constructor is allowed
    struct keyword is not required
    supports access modifiers
    pointers as well as references are allowed
    sizeof operator for struct is 1
    struct is just public class
    
