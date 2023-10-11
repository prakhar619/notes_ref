/*
Array:
        zero based indexing
        dynamic array
        32 bit indexes
        length property
        Inherits from Array.prototype
            generic methods
*/

function creating_array()
{
    //creating literal
        let empty = [];
        let mis = [1.1, true, 'a',"hello",];
        let count = [1,,3];
        console.log("count Length:"+count.length);
        console.log("count[0]:"+count[0]+" count[1]:"+count[1]+" count[2]:"+count[2]);

    //spreading string or another array
        let spread = [1,3,4,5,6];
        let spread1 = [1,...spread,10];
        let spread2 = [ ..."Hello world"];
    
    //Array Constructor
        let const_array = new Array();
        let const_array1= new Array(10);            //array of size 10
        let const_array2= new Array(10,2,3,4,5,6);  //array of size 6 with args as element
    //Array.of()
        //to address the problem of array constructor to create array of length 1 and one element
        let array_of = Array.of(10);     //array of 1 length with element 10 
        let array_of1 = Array.of(10,3);   //array of size 2 and element
    
    //Array.from()
        //array[] Array.from(<iterable>)
        let truearray = Array.from(const_array);

    //MultiDArray
        let a = new Array(10);
        for(x in a)
            x = new Array(10);
    
        console.log(a[9][9]);
}

function read_writing_length_deleting_adding_checking()
{
    let b = [[1, {x: 1, y: 2}], [2, {x: 3, y: 4}]];
    console.log(b[1]);
    b[2] = "Hello world";
    b["3"] = "wow";
    b[1.00] = 1234;
    b[-1.2] = true          //this creates property of array instead of element/value

    //Length
        console.log([].length);
        a = [1,2,3,4,5]; // Start with a 5-element array.
        a.length = 3; // a is now [1,2,3].
        a.length = 0; // Delete all elements. a is [].
        a.length = 5; // Length is 5, but no elements, like new Array(5)

    //Adding and deleting
    a.push({1:"h",2:"value"});
    a.push(1,2,3);
    delete a[1];

    //checking
    console.log(5 in a);

}

function iterating_ar()
{
    let arrays = [ ..."I dont know anything"];
    
    //1.for/in
        for(let c in arrays)
        {
            console.log(c);
        }
      
    //2.for/of   entries
        for( let [index,c] of arrays.entries())
        {
            console.log("Index:"+index+" Character:"+c);
        }
    
    //3.forEach function
        arrays.forEach(c =>{ console.log(c);});
            //forEach takes a function(2 args) and in its code passes each item of array to that function with index
        
}
function array_methods()
{
    //1.    forEach()
        let data = [1,2,3,4,5,6];
        data.forEach(function(v,i,a){ console.log("value:"+v+" index:"+i+" arrayItself:"+a);});

    //2.map()
    
    //3.filter()

    //4.find() and findindex()

    //5.every() and some()

    //6.reduce() and reduceright()

    //7.flat() and flatMap()

    //8. concat()

    //9.Stack and Queue Functions
        //Stack
            data.push(10);      //increases length
            data.pop();         //decreases length
            data.push(10,11,[1,2,3]);
        
        //Queue
            data.push(120);
            data.shift();       //decrease length; removes from front
        
            data.unshift(111);   //increase length; adds element in front

    
    //10. slice(),splice(),fill(),copyWithin() for subarrays
    //11. indexOf() and lastIndexOf()
    //12. includes()
    //13. reverse()
    //14. join(),toString() String Array
    //15. Array.isArray()
}

function string()
{
    //string behave like array of char
    let s = "test";
    s.charAt(0);
    s[0];
}

creating_array();