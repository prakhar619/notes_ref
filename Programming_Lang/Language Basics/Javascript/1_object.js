/*Miscellaneous Statement
1.with (invalid in strict mode)
    obsolete

    with(obj1)
    {
        name = "user";
        addr = "address";
        email = ".com";         //no need of writing obj1.email=
    }
2."use strict"
    ES5
    only at start of script
*/

//Declarations: let,const,var,function,class,import,export
    //Declarations are different from statements.

/*
Objects : unordered collection of properties, each of which has a name and a value;
          dynamic in nature (property add or delete or value changed during execution)
          All values in JS except String,Number,Symbol,true,false,null or undefined is an object
                even these can behave as immutable objects
          Objects are mutable
          Objects are loosely typed in Js; no fixed no. of properties; runtime creation and deleting of properties;


    Property :  has a name and a value
                no object have 2 properties with same name
                value may be a JS value (variable or function or object) or getter or setter function
                Each object has 2 kinds of properties: 
                                                        1.Own Property
                                                        2.Inherited Property
                Each property itself can have attributes to it:
                                                                1.writable          (value of property can be changed or not)
                                                                2.enumerable        (can property be present in for/in loop)
                                                                3.configurable      (can property be deleted or value be altered)

    Prototypes: Almost every JS object has second JS object associated with it. This second object is called PROTOTYPE
                Object inherits properties from prototype
                Object.prototype is rare that has no prototype.

*/

function creating_object()
{
    //1.Object Literal
        //All object created by literals have same prototype object = Object.prototype
        let obj_lit = {}
        let obj_lit1 = { x: 0, y: 0};
        let obj_lit2 = { x: obj_lit1.x, y: obj_lit1.x};
        let obj_lit3=  { "main title": "JavaScript", for:"all audiences", author : { firstname:"David",surname:"Flangan"}};
    //2.new Object
        //Constructor invocation use the value of prototype property of constructor function as their prototye.
        //Therefore Object() inherit from Object.prototype; Array() uses Array.prototype
        let obj_new = new Object();         //empty object
            let obj_new_ = new Object;              //equivalent to above statement
        let arr = new Array();              //empty array
        let obj_date_new = new Date();      //date object
    //3.Object.create()
        let obj_cr = Object.create({x:1,y:2});  //inherits from object literal; Object.Prototype
        let obj_cr1 = Object.create(null);      //does not inherit Object.prototype
        let obj_cr2 = Object.create(Object.prototype);

        //actual use of create function: to guard against obj modification.
        let obj_cr3 = Object.create(obj_cr);    //properties will not be affected in original object(obj_cr)

}

function quering_and_setting_prop()
{
    //either (.) operator or [""] boxes with string
    book = {author: "David",isbn:"12344"};
    let author = book.author;
    let isbn = book["isbn"]

    book2.author = "New object";
    book2.isbn = "hi";
    book2["copyright"] = "pearson";

    // (.) is too much conservative as allows object properties before runtime.
    // [""] much flexible because property manipulation of newly created property during runtime

}

/*
Object Inheritance:
                    own properties
                    inherited properties
                                example: toString()
                        Access(read):
                                if property is queried and found in own property => access given;
                                else if property is checked in inherited prototype of main obj => if found access given; 
                                else if property is checked in inherited prototype of prototype and so on
                        Duplicate:
                                if prototype and main obj both have property then changing will result change only in main obj
                        Assignment:
                                All assignment of property and value affect main object only
                                Never affect inherit values and properties
                       
                        **EXCEPTION: 

                        Access error:
                                if nowhere found: undefined assigned; no error given
                                but operation on this(undefined) gives error

                                if(book)
                                {
                                    if(book.author)
                                    {
                                        surname = book.author.surname;
                                    }
                                }

                                or 

                                let surname = book?.author?.surname;
                            
                        Assigment error:
                                readonly properties of main obj;
                                trying to set property on null or undefined 

*/
function own_inherited_check()
{
    let book = {author : {firstname:"David",surname:"Finch"},isbn:123422 };
    // OwnProperty + Enumerable  => propertyIsEnumerable()
    book.propertyIsEnumerable("author");
    //OwnProperty =>hasOwnProperty() 
    console.log(book.hasOwnProperty("author"));
    // OwnProperty + Inherited Property => in
    console.log("toString" in book);

        //   !== undefined can be used instead of in but not when property has value undefined;
        //      avoid !==
}

function deleting_enumerating()
{
    let book = {author : {firstname:"David",surname:"Finch"},isbn:123422 };
    
    console.log(delete book.author.firstname);
    console.log(delete book["author"]["surname"]);
    //delete => true if succeeded or if no effect [nonexistent property]
    //delete => for nonsense 

    //delete cannot delete non configurable properties
        //gives false or runtime-error

      
    //Enumerations
        //for/in loop
           
            //own + inherit - nonEnumerable properties
            let o = {x: 1, y: 2, z: 3};
            for(let p in o)
            { 
                console.log(p); // Prints x, y, and z, but not toString
            }
        //for/of
            //Object.keys()                         Own+Enumerable
            //Object.getOwnPropertyNames()          Own
            //Object.getOwnPropertySymbols()        OwnProperties+Name symbol
            //Reflect.ownKeys()                     All (everything)

     for(let key of Reflect.ownkeys(o))
     {}

}

function object_extention()
{
    //Object.assign()
        //In order: first object gives all its properties
        //          2nd object gives its properties, if same property then modify the value
        // and so on...
            let o1 = {x: 1, y: 2, z: 3};
            let defaults = {x:undefined}
            o = Object.assign({},defaults, o1);
    // ... Spread Operator
        //Same as assign 
        //also overwrites
            o = {...defaults, ...o};     
}

function JSON_convertion()
{
    let o = {x: 1, y: 2, z: 3};
    let s = JSON.stringify(o);
    console.log(s);
    let o_dup = JSON.parse(s);

    //JSON
        //subset of JS
        // NaN, Infinity, -Infinity => null      
}

function object_methods()
{
    let o = {x: 1, y: 2, z: 3};
    console.log(o.toString())        //non enumerable, inherited
    console.log(o.valueOf())
    console.log(o.toJSON())
}

function shortcut_and_hands()
{
    //1.
        let x = 1, y = 2;
        let o = {
                    x: x,
                    y: y
                };
                
        let x_1 = 1, y_1 = 2;
        let o_1 = { x_1, y_1 };
    //2.
        const PROPERTY_NAME = "p1";
        function computePropertyName() { return "p" + 2; }
        let p = {
                [PROPERTY_NAME]: 1,
                [computePropertyName()]: 2
                };
               
    //3.
        let position = { x: 0, y: 0 };
        let dimensions = { width: 100, height: 75 };
        let rect = { ...position, ...dimensions };
        let q = { ...o, x: 2 };
    //4.
        let square = {
                    area: function() { return this.side * this.side; },
                    side: 10
                    };
        square.area()

        let square_1 = {
                        area() { return this.side * this.side; },
                        side: 10
                    };
            square_1.area()
    //5.
            const METHOD_NAME = "m";
            const symbol = Symbol();
            let weirdMethods = {
                                "method With Spaces"(x) { return x + 1; },
                                [METHOD_NAME](x) { return x + 2; },
                                [symbol](x) { return x + 3; }
                                };
}   

function getter_setters()
{
    //JS supports accessor properties which are methods
    //2 accessor properties: getter and setter

    //set is kind of like constructor; function to change value of other properties
    //get gives value
    // to access setter and setter => dont use them as method or function but as data variable
    let o = {
        dataProp: null,
        get accessorProp() { return this.dataProp; },
        set accessorProp(value) { this.dataProp = value; }
        };
    o.accessorProp = 10;
    console.log(o.accessorProp);
}

getter_setters();

