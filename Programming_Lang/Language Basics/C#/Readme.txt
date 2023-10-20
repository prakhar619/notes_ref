C Sharp 
    extension .cs
    compiler csc
    case sensitive
    strongly Typed  
        var x = 12
        x = 12.2 will result error
    

    Identifiers:
        Variable name
            Cant start with digit
            use @ at start if you want to use keyword as Identifiers
                @for = 1; if(@for == 1)
        
    DataTypes:
        Value Types 
        Reference Types 

    Literals
        
    Variable 
        2 Types of Variable:
            Value Type Variable
            Object Reference Variable   

        Features:
            Dynamic Initialisation
                int x = pow(10,2);
            Implicitly Typed Variable
                var x = 12.2
                    finding x datatype from literal; here x is double
                    only one var at a time; var x  =5, y = 10 is error
            Block Scope
            Name Hiding Not Allowed   
                int x = 10;
                if( x > 5)
                {
                    int x = 20; //error
                } 
    Array
        Implemented as objects

    String
        Immutable
        Implemented as object
        Built in datatype
        String Comparison:
            Ordinal
                Ascii value(AZaz)
            Culture-Sensitive
                InvariantCulture
                    (aAbBcC...)
                CurrentCulture
    
    Methods 
        Call by value vs Call by references
            Value type variable(primitive) => call by value
            Object Reference variable => call by ref   
        ClassFactory
            when for security purpose constructor is prohibited
            function returns a class object
        Method Overloading
            type and/or no of parameter should be different
            return type do not provide sufficient info to differentiate             
    Class   
        Data Members
        Function Members    
            Methods
            Constructors
            Destructors
            Operators 
            Indexers
            Event 
            Properties

        Function Member:
            Unreachable code gives error
        Access Specifier:
            public
            private
            protected
            internal

    Garbage Collection
        system reclaims object automatically
        when no references to an object exist, that object is assumed to be no longer needed

    .NET Framework Class Library
        System.Math
            System.Math.Sqrt()        --System is namespace, Math is class, Sqrt is a function

            