/*
    Modules
        No built in support
        Modular approach to prevent globl namespace pollution

        import and export
        require()       ;node based function

*/

/*
const modules = {};
function require(moduleName) { return modules[moduleName]; }

    //modules will be a object consisting of object(subobject); using these subobject we can access functions and methods
                                                                            //these subobject are created inside function and returned 
                                                                            //member of these subobject are inside function (private)(closures) therefore no pollution


modules["sets.js"] = (function() {
                        const exports = {};
                        exports.BitSet = class BitSet { ... };
                return exports;
}());


modules["stats.js"] = (function() {
                    const exports = {};
                    const sum = (x, y) => x + y;
                    const square = x = > x * x;
exports.mean = function(data) { ... };
exports.stddev = function(data) { ... };
return exports;
}());

*/



//NODE
    //module.export
    //exports

        //use these objects to export function of value as their attribute
        //module.exports = {method1,method2};

    //require()
        //require('http')   //built in
        //require('./stat.js')
        //require('./stat')     //ignore js


        //Destructuring
            // const {stdev} = require('./stats.js')
                //let sd = stdev(data)

//ES6
    //export
        //export PI
        //export {Circle, degree}       //multiple export statements allowed; multiple item export in single object

        //export {Circle as oval, degree as angle}

        //export * from "./stats.js"    //non selective re-export

    //import
        //import BITSET from './bitset.js';     //convention to put at top; import statement hoisted
        //import {mean,stdev} from './stat.js';

        //import { mean as avg } from ...


        //NO EXPORT MODULE
            //import "./analytics.js";

