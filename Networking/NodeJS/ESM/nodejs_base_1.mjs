import assert from "node:assert";

console.log("Program Started");
var sm_var=10;
var sm_st="10";
assert.equal(sm_var,sm_st);
const end = ()=>console.log("ALMOST AT END");


export function newFunction(args1,args2){return add2(args1,args2)}
export function ending(){end};



