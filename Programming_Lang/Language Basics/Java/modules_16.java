public class modules_16 {
    //modules to share packages
    //all java lib has been modularised
    //API modules (Api package now present in modules)
    //java.base modules contains fundamental packages for System Math and different package (java.util,java.io,java.lang)
    //therefore we do not worry about requiring each module during normal code
    //java.base is accessible to all modules and vice versa all module require java.base

    //backward compatibility
        //unnamed module is created, our new types code's module
        //unnamed module exports all packages and requires all other packages
        //use of class path rather than module path

    //exports requires
    //exports to  requires      //exports packageName to moduleNames;


    /*CASE 1:   A requires B 
                B requires C
            Sol1:   if A do not use C package then directly A requires B and B requires C
            Sol2:   if A uses C package indirectly(B package dependence)    Method1: A also requires C
                                                                            Mehtod2: B requires transitive C
                                                                */
}
