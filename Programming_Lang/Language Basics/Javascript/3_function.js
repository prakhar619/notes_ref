/*
Function:
        definition and invokation
        is called method when its a property of object
        functions are objects
        nested functions allowed
        some cases of function declarations are hoisted
        constructor can return value/object
*/


/*
Defining a function:
    1. function keyword [Name]
    2. function keyword [Anonymous]
    3. Function() constructor
    4. Arrow sign
*/
function defining_a_function()
{
    //1. one way
    return 1;
}
defining_a_function();

//2.
const fun1 = function(){return 1};
fun1();
    //carefull with this
    const value1 = (function(x){return x+2;}(10));
        //here value1 is not a function but a variable with value 12
        //function creation and invokation with 10 as args
    console.log(value1);

//3.


//4.
const fun2 = (x,y)=>{return x+y;};
const fun2_ = (x,y)=> x+y;
const fun2__ = x => x+10;   //if one argument only
const fun2___ = ()=>42;
fun2();
console.log("Function accessed as variable:",fun2);

const f = x => { return { value: x }; }; // Good: f() returns an object
const g = x => ({ value: x }); // Good: g() returns an object
const h = x => { value: x }; // Bad: h() returns nothing
//const i = x => { v: x, w: x };  

    //Arrow functions do not have prototype property
    //cannot be used as constructor function for class


/* Invoking a function
1. As a function
2. As a method
3. As constructor
4. Indirectly by call() and apply()
*/

//1. Obivious

//2.
o = {};
o.m = f;
o.m(10);

obj = {
    ad_f() { return 10;},
    var1 : 10,
};
obj.ad_f();

//const complexx = o.m().obj.ad_f();
//means invoke o.m() function on output of obj.ad_f()
//doesnt work, dkw

obj1 = {
    m : function(){
        return 20;
    }
}
obj1.m();

//3.
const F_const = new Function("x","y","return x*y;");

//4.
//JS functions are like object; have methods like call() and apply()



/*Argument and Parameter
1. function(a,b,c){}       function(a); b,c = undefined
    to check if passed or not: b = b || 0;  kind of default becomes 0 for b
2. function(a,b,c=0){}      //default parameter
3. function(a,b, ...rest)   function(a,b,c,d,e); rest is array that stores arguments; rest may be empty but never undefined
    //variadic function,variable arity function, vararg function
4. function(x){argument[i],argument.length}     function(a,b,c,d,e);    argument is object (array like object)



Unpacking Parameter
function vectorAdd({x: x1, y: y1},{x: x2, y:y2, z:z2 = 0}){}
*/

let a = [x=>x**3,20]
console.log(a[0](a[1]));


/*Function as object
1. Defining function properties
        when we need static variable to store value across invocation, property is useful

2. Properties, Method and Constructor

*/

//1.
fun_with_pops.counter = 0;
function fun_with_pops()
{
    return fun_with_pops.counter++;
}
    //Very useful with DP as you can create array to store intermediate value;


//CLOSURES
/* //Fucking Hoisting
let scope = "1.SCOPE:GLOBAL";
function checkscope()
{
    let scope = "1.SCOPE:LOCAL";
    function named()
    {
        return scope;
    }
    return named();
}
console.log(checkscope());  //returns 1.SCOPE:LOCAL
*/
let scope1 = "2.SCOPE:GLOBAL";
function checkscope()
{
    let scope1 = "2.SCOPE:LOCAL";
    function named()
    {
        return scope1;
    }
    return named;
}
console.log(checkscope()());    //return local scope rather than global scope   //Closure: binding of outer function
console.log(checkscope());      //function returns object of inner function


let norm_var = (function(){ let counter = 0; return function(){return counter++;}}());
console.log(norm_var());
console.log(norm_var());
        //norm_var was supposed to be variable (const) and not a function
        //but we return a function therefore norm_var became a function
        //how does it retain state: counter is binded to outer anonymous function;
        //counter is update and is accessed by return function
        // kind of using counter out of scope;
        // Now remember the logic: inner function ko use karoge toh outer function ke members ko bhi use kar sakte ho

//Combining more; Complexity inc
//instead of returning functions; return object with members as multiple functions

function counter()
{
    let n = 0;
    return {
        count: function() { return n++; },
        reset: function() { n = 0; }
        };
}
let c = counter(), d = counter(); // Create two counters // now c and d are objects
c.count() // => 0
d.count() // => 0: they count independently
c.reset(); // reset() and count() methods share state
c.count() // => 0: because we reset c
d.count() // => 1: d was not reset

//more complex by using get and set (functions as variables)



/*
2. Properties
    length (readonly)
    name   (readonly)   :gives name of function
    prototype  (except arrow function)
    call()
    apply()
    bind()
    toString()

2. Constructor
    const f= new Function("x","y","return x*y;");
        //can take any no of string
    //dynamic creation of functions
    //each time it is called a function is created
    //do not use lexical scoping; therefore cannot be used as closure

*/

let scope = "global";
function constructFunction() {
let scope = "local";
return new Function("return scope");
// Doesn't capture local scope!
}
// This line returns "global" because the function returned by the
// Function() constructor does not use the local scope.
constructFunction()() // => "global"

//Higher Order Functions
    //Input: Multiple functions
    //Output: Functions
    
