
var server = require("./server");
var router = require("./router");
var req_handler = require("./requestHandler");

var handle = {};
handle["/"] = req_handler.form_handler;
handle["/index"] = req_handler.base_handler;
handle["/form"] = req_handler.form_handler;
handle["/StudentForm_style.css"] = req_handler.form_handler_css;
handle["/formUpload"]=req_handler.form_upload;
server.start(router.route,handle);
