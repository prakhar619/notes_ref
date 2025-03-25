/*  Lexical Structure
        Case sensitivity,spaces,line breaks
        Comments
        Literals
        Identifiers, Reserved words
        Unicode
        Optional Semicolons
*/

//  Literals
//  12,12.2,"eh",'eh',true,false,null       //no specific char support

//  Identifier  
//  i,i_9,$h,_h_

//  Escape Sequence
//      \u03AF      (4 exact hexa digit)
//      \u{3AF}     (one to 6 hexa digit in curly braces)

//  Line Breaks and Optional Semicolons
//      Semicolon not required if line break is given
//      Line break does not always works usually when statement begin with (,[,/,+,-
//      Therefore use semicolon like this ;[x,x+1,x+2]
//      Mostly line breaks are not taken as ; and 2 lines are taken in continuation

//          return true, continue, break should be one line code, no line break else ; automatically
//          ++, -- should be in one line
//          => one line

//Types, Values, Variable
//  Primitive Types and Object types
//      Primitive
//          number,string,boolean,null,undefined,Symbol(ES6)
//      Object  (collection of property, each property has name and value[either primitive or object itself])
//              Unordered collection
//          Array
//          global object
//              
        //Classes and functions are themselves are specialized kind of object that can be manipulated in code

//always use let and not var
let binary_en= 0b1011;     
let hexa_en=0xAf1e;
let float_en = 1.23424E-21

//Arithmetic
        //Arithmetic operators do not give overflow error simply infinity or -infinity (also during divide by zero)
        //0/0 is NaN (not a number)   Infinity/Infinity -> NaN

        console.log(Number);
        console.log(Number.POSITIVE_INFINITY);
        console.log(Number.EPSILON);    //smallest difference b/w number

        let x = NaN;
        console.log(x === NaN); // == is no longer used
        console.log(x != x);    //check NaN variable like this 



//String
        let string1 = "helo'everyone'";
        let string2 = `now interpolate ${x}`;
        //escape sequence
                //      \0
                //      \b
                //      \t
                //      \n
                //      \v
                //      \f
                //      \r
                //      \"
                //      \r
                //      \\
        console.log(string1.length);

        //      RegExp(Regular expression)
        //      ?

//Symbols
        let syn = Symbol("propname");
        console.log(typeof syn);
        console.log(syn);
        syn = Symbol("propname");
        console.log(syn);


//Global Object Properties
        //undefined,Infinity,NaN                                Constants
        //isNaN(),parseInt(),eval()                             Functions
        //Date(),ReqExp(),String(),Object(),Array()             Constructors
        
//use globalThis(in nodejs) and window(browser) to access this global object

//All primitive datatypes (except objects and array) are immutable including string       //s.toUpperCase() do not change value
        
        //Data object
                let timestamp = Date.now();
                console.log(timestamp); //ms since 1970

//Type Conversion
//      automatic conversion for wide range of stuff
        console.log(typeof Number("3"));
        console.log(typeof String(3));  //or 4.toString() or false.toString()
        console.log(Boolean([]));       //true

        //Number only base 10
        //parseInt() and parseFloat() converts "0xAA" to AA in hexa
        //parseInt("ff",16);    base 16
        //parseInt("zz", 36)    base 36


        //object to primitive type conversion function availiable


//let vs var
//block scope vs function scope
//globally if var is declared then it becomes property of global object but not with let and const
//var has hoisting

//Assignment
//      let [x,y] = [1,2]
//      let [x,y] = [1,2,3]
//      let [,x,,y] = [1,2,3,4]
//      let [x, ...y] = [1,2,3,4]

let o = {x:1,y:{z:3}};
let a = [o,4,[5,6]];
console.log(o.x);       //doesnt work if key is using spaces or number or invalid identifier name or when key name itself is computed
console.log(o["x"]);    //o[x] gives undefined  //square bracket notation always gives ans
console.log(a["1"]);

//Operators
console.log("x" in o);  //left of in: string symbol or value    right: object
console.log(o instanceof Object);     //left side object        right: class of object
eval("3+3");
delete o.x;
delete o;

let data = [1,2,3,4,5,6,7,8,9];
let sum = 0;
for(let element of data)
{
        sum+=element;
}
//let k of Object.keys(o);
//let v of Object.values(o);
//let [k,v] of Object.entries(o))

//let s of "string"


//label
label1: while(true)
        {
                if(10 <  2)
                continue label1;
                else
                break label1;
        }

console.log("Error Handling");
//Error handling 
        //either runtime error or throw is encountered, exceptions are thrown
        //Error class
let x_1 = -1;
//Error object has name property and message property. Name specifies type of error. Message holds the string passed to constructor.
if (x_1 > 0) throw  new Error("x_1 must be negative")

try{}
catch(e){}
finally{}
//use of finally: even if try has return or continue or break; whenever control leaves try, finally will be executed;

try{}
catch{}
finally{}
        //to stop propogation of error
        //dont care  about error type but want to stop propogation


