
var para_process = require('child_process');
var fs = require('fs');

function base_handler(response,Data)
{
	console.log("Base Handler called");
	
	
	
}

function form_handler(response,Data)
{
	console.log("Form Handler called");
	// our first non blocking operation with a callback function
	fs.readFile('./../SampleWeb/StudentForm.html', function(err, data) {
    									response.writeHead(200, {'Content-Type': 'text/html'});
    									response.write(data);
    									return response.end();
    								     }
 		    );
 	//Blank unless client submit data;
 	console.log("Data:"+Data);
 		    
}

function form_handler_css(response,Data)
{
	console.log("Form Handler CSS called");
	fs.readFile('./../SampleWeb/StudentForm_style.css', function(err, data) {
    									response.writeHead(200, {'Content-Type': 'text/html'});
    									response.write(data);
    									return response.end();
    								     }
 		    );
}

function form_upload(response,Data)
{
	console.log("Form Upload called");
	console.log(Data);
	return response.end();
}

exports.base_handler= base_handler;
exports.form_handler= form_handler;
exports.form_handler_css = form_handler_css;
exports.form_upload = form_upload;
