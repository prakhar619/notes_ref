
function route(path,handle,response,postData)
{
	console.log("Inside 'router'");
	if(typeof handle[path] === 'function')
	{
		handle[path](response,postData);
	}
	else
	{
	console.log("Bad Request made to server. No handler found for:"+path);
	response.writeHead(404,{"Content-Type":"text/plain"});
	response.write("404 Not Found");
	response.end();
	}
	
}

exports.route = route;
