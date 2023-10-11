
// This program/file will start the server;identify which path/website asked then send the control to route;
var http = require('http')
var url = require('url')
function start(route,handle)
{
	function onRequest(request,response)
	{
		console.log("Request Base URL:"+request.baseUrl);
		console.log("Request URL:"+request.url);
		console.log("Request Body:"+request.body);
		console.log("Request Cookies:"+request.cookies);
		console.log("Request Fresh:"+request.fresh);
		console.log("Request Host:"+request.hostname);
		console.log("Request IP:"+request.ip);
		console.log("Request IPS:"+request.ips);
		console.log("Request Original URL:"+request.originalUrl);
		console.log("Request Parameter:"+request.params);
		console.log("Request Path:"+request.path);
		console.log("Request Protocol:"+request.protocol);
		console.log("Request Query:"+request.query);
		console.log("Request Route:"+request.route);
		console.log("Request Secure:"+request.secure);
		console.log("Request Cookies:"+request.signedCookies);
		console.log("Request Stale:"+request.stale);
		console.log("Request Subdomain:"+request.subdomains);
		console.log("Request XHR:"+request.xhr);
		console.log("Request Method:"+request.method);
		//request objects
		var path = url.parse(request.url).pathname; // url.parse helps to separate path and querystring
		var query = url.parse(request.url).query;
		
		var postData = "";
		request.addListener("data",function(postDatachunk){ console.log("Recieving Listener Data.");postData += postDatachunk;});
		request.addListener("end",function(){
		
							console.log("Request for "+path+" recieved. Sending request to 'route'");
							route(path,handle,response,postData);
						    }
				   );
					
		
	
		//response objects
		//response.writeHead(200, {"Content-Type" : "text/plain"});
		//response.write("Server Response: Hello World");
		//response.end();
	}
	
	http.createServer(onRequest).listen(8080);
	console.log("Server has started");
}

exports.start = start;
