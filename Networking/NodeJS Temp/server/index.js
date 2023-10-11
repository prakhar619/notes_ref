//This file connects all the file;
//Server file is for starting server(listening all requests)
//Router files checks if handling is possible; if possible routes the request to handler file; else BAD REQUEST
//Handler files performs all the handling.

var mysql = require('mysql');
var server = require("./server");
var router = require("./router");
var handler = require("./requestHandler");

let handle ={};
handle["/index"] = handler.baseForm;
handle["/formUpload"] = handler.formUpload;
handle["/medicalOffice"]= handler.medicalOffice;
handle["/medUpload"]= handler.medUpload;
let sql = mysql.createConnection( {
    host: 'localhost',
    user: 'root',
    password: '619@Lm10',
    database: 'leave_management_sys',
    });

server.start(router.route,handle,sql);
