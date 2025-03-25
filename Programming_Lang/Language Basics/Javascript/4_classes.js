/*
Classes
    Basics of Class:
        1.All object/function that inherit prototype from other object => other object is class, object/function objects of that class
          Prototype based inheritance: prototype of one object same as prototye of (class) object

        2.Also object creation(Object.create()) is used to create new object of a class (obj.prototype is usually passed as paramenter; not compulsory)
          
        3. Constructor function -> function which create and initialises newly created object which is object of a class
            let r = range(1,2)
            This range function is actually a contructor
            It takes args 1,2 and uses Object.create(range.methods) to create inherited object then returns it;
            Therefore r.method1()

        3.5 New with constructor function
            let r = new Range(1,2)
            Range need not to create Object.create()
            new keyword automatically create new object and Range.prototype is inherited
            But now Range.prototype is object that is inherited; Therefore any object of class cannot be inherited; flexibility lost ; standardised
            Therefore now define Range.prototype as per use

                //avoid => function sometimes; inheritance problem
        
        4.class keyword to ease the inheritance process;
        5.extends to inherit
    classes are not hoisted

        */

function range(i,j)
{
    this.x = i;
    this.y = j;
    return Object.create(range.method);
}
range.method = {
    method1 : function(){return this.x;},
    method2: function(){return {x: this.x,y :this.y}}
}

function Range(i,j)
{
    this.x = i;
    this.y = j;
}
Range.prototype = {
    method1 : function(){return this.x;},
    method2: function(){ return {x: this.x,y: this.y}}
}

classObj = range(1,2);
console.log(classObj.method2())
classObj_new = new Range(1,2);
console.log(classObj_new.method2())

function finding_inheritance_rel()
{
    //1. instanceof
        //class prototype inheritance check (other class object not checked)
        //also true for indirect inheritance
        //does not actually check for constructor use rather check.prototype == class.prototype
            //still new Strange() instanceof Range => true where Strange.prototype = Range.prototype

    console.log(classObj instanceof range);         //range.prototype not inherited
    console.log(classObj_new instanceof Range);     //Range.prototype inherited
        

    //2. isPrototypeOf()
        
}

finding_inheritance_rel();

class Range1 {
    constructor(i,j)
    {
        this.x = i;
        this.y = j;
    }

    method1()
    {
        return this.x;
    }

    method2()
    {
        return { x : this.x , y: this.y};
    }

    //constructor keyword
    //method/function need no function keyword
    //class keyword means strict mode
    //constructor is optional function

}

//inheritance using extends
class subclass extends Range1{
    constructor(i,j,k)
    {
        super(i,j);
        this.z = k;
        //new standardisation will include declaring without this keyword like z = k
    }
    static method3()
    {
        return this.z;
    }
    //static object without creating object of this class
    //subclass.method3() //ClassName.staticMethod()
    

    get first(){return this.z;}
    get last(){return super.x;}
    set first(y){this.z  = y;}
}
subclass.x = 10;
//static field should be define outside class

/*Adding method to existing classes */
Range.prototype.new_method = function(){return 10};


/* Function and class shorthand */
let square = function(x){return x*x;}
console.log(square(2));

let Square = class {constructor(x){this.area = x*x;}};
console.log(new Square(3).area);


