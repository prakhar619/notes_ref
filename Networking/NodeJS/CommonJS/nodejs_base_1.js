var assert = require('assert');

console.log("Program Started");
var sm_var=10;
var sm_st="10";
assert.equal(sm_var,sm_st);
const end = ()=>console.log("ALMOST AT END");

exports.newFunction = (args1,args2)=>{return add2(args1,args2)}
exports.ending= ()=>{end};



