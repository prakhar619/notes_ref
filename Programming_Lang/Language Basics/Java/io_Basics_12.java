//Text based stream (unpopular)
/*
Streams:    Abstraction to either get information or give information
            Doesnt matter that input/output is socket or file or keyboard/console
            java.io Package

            java.io (Streams)
                |
            java.nio(Buffer and Channel based I/O)

Types of Stream:    Byte Stream         Character Stream(abstraction byte stream)

Byte Stream 2 Classes:        InputStream         OutputStream
Each of these abstract classes have subclasses for various input output devices like console, file, sockets
InputStream,OutputStream    read();write;

Character Stream 2 Classes:     Reader      Writer
Each of these classes have subclasses
read();write()
 */


/*
2 package preimported
java.lang; default package(package you are working on) 
            java.lang -> System
System class have various run time information like date, time etc
    System has 3 predefined stream variables
        in
        out
        err
    Each one is public static final

    System.out standard output stream(default console)
    System.in standard input stream(default keyboard)
    System.err stardard err stream(default console)

 */
/*  READING
Byte stream is easy as no other conversion required;
Directly use System.in

Character Stream:   Read byte using System.in
                    Use character Stream Reader class to convert to char
                    Use bufferedReader to get character as well as line
 */


 /*WRITING
  class PrintStream:    println and print
  System.out is a byte stream
  PrintStream is derived from OutputStream, therefore has write() function
  
  */

//System.in is actually line buffered; meaning no input passsed unless enter pressed
import java.io.*;
import java.io.BufferedReader;
public class io_Basics_12 {
    public static void main(String args[])
    {
        //fileHandling_read(args);
        //fileHandling_write(args);
        arm(args);
    }

    public static void readd()
    {
        char c;
        String s;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//inputStreamReader is subclass of reader class(character stream)
        // br is now a character based stream
        try{
             c=(char) br.read();
             s=(String) br.readLine();
            System.out.println("Character is "+c);
            System.out.println("string is "+s);
        }
        catch(IOException e)
        {
            System.out.println("Reading error:"+e);
        }
    }

    public static void writee()
    {
        int m = 10;
        System.out.write(m);

    }

    //PrintWriter Class
    /*
     One of the charcter based  classes
     */
    public static void  printwriter()
    {
        //PrintWriter(OutputStream,boolean flushingOn)
            //outputStream is obj of type outputStream
            //whether to flush output stream or not
                //if true: automatic flushing
                //else : flushing manual
        
        //Methods of PrintWriter
            //print, println
            //toString

        PrintWriter pw = new PrintWriter(System.out,true);
        pw.println("This is string");
        pw.println(10);
    }

    public static void fileHandling_read(String args[])
    {
        //Stream Classes
            //FileInputStream
            //FileOutputStream
        int store;
        FileInputStream fin;
        if(args.length != 1)
        {
            System.out.println("Usage:ShowFile filename");
            return;
        }
        try{
            fin = new FileInputStream(args[0]);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Cannot Open File");
            return;
        }
        catch(SecurityException e)
        {
            System.out.println("Cannot Open File. Access Issue");
            return;
        }
        //File openned
        try{
            do{
            store = fin.read();//reads byte //if -1 then means attempt to read at end of file
            if( store != -1)
            System.out.println((char) store);
            }
            while(store != -1);
        }
        catch(IOException e)
        {
            System.out.println("Error Reading File");
        }
        try{
            fin.close();
        }
        catch(IOException e)
        {
            System.out.println("Error closing file");
        }
    }

    public static void fileHandling_write(String args[])//can also create new file
    {
        char c[] = {'h','e','l','l','o',' ','w','o','r','l','d'};
        FileOutputStream fout= null;
        if(args.length != 1)
        {
            System.out.println("Usage:File filename");
            return;
        }
        try{
            fout = new FileOutputStream(args[0]);
            int i = 0;
            do
            {
                fout.write((int) c[i]);
                i++;
            }while(c.length > i);
            }
        catch(IOException e)
        {
            System.out.println("I/O error");
        }
        finally{
            try{
                if(fout != null)
                fout.close();
            }
            catch(IOException e)
            {
                System.out.println("Error during closing");
            }
        }
        }

        public static void arm(String args[])    //automatic resource management
        {
            //no need to close() explicitly

            //inside try, resource_specification can be used
            //outside the try, resource_specification will automatically be released
            char c[] = {'h','e','l','l','o',' ','w','o','r','l','d'};
            if(args.length != 1)
            {
                System.out.println("Usage:File filename");
                return;
            }
        //if two resource_specification then: try(resourceSpecs1;resourceSpecs2)
        try(FileOutputStream fout= new FileOutputStream(args[0], false)) 
        {
                int i = 0;
                do
                {
                    fout.write((int) c[i]);
                    i++;
                }while(c.length > i);
            }     
            catch(FileNotFoundException e)
            {
                System.out.println("File not found");
            }
            catch(IOException e)
            {
                System.out.println("i/o error");
            }
        }//suppressed exceptions: getSuppressed() defined in Throwable
        
    }


