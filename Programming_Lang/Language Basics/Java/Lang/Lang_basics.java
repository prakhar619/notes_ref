public class Lang_basics{
    public void txt_info()
    {
        //java.lang is automatically imported to all programs

            /*Primitive Wrappers
             * Number   (abstract class)
             *      byte
             *          byte byteValue()
             *      short
             *          short shortValue()
             *      int
             *          int intValue()
             *      long
             *          long longValue()
             *      float 
             *          float floatValue()
             *      double
             *          double doubleValue()
             * 
             *      Concrete Subclasses of Number:
             *          Double
             *              Double(<any Value for convertion like string>)
             *              Functions( isNaN(), isInfinite(), parseDouble())
             *              DataMembers
             *          Float
             *          Byte
             *          Short
             *          Integer
             *          Long
             * 
             * Process  (abstract class)
             *      encapsulates process
             * Runtime
             *      encapsulates run-time env
             * ProcessBuilder
             * System
             * Object
             *      superclass of all other classes
             * Clonable     (interface)
             * Class
             *      encapsulates runtime state of class or interface
             * Math
             * Runnable     (interface)
             * Compiler
             * StrictMath
             * Package
             * Module
             * Comparable   (interface)
             * Iterable     (interface)
             * Readable     (interface)
             */
    }
    public static void main(String args[])
    {
            //isNaN()
            //isInfinite()
            //java allows division by zero and zero/zero
                //therefore to check value TypeWrapper.isNaN(0/0.0)  => True

    }
}