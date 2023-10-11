function route(path,handle,response,postData,sql)
{
	if(typeof handle[path] === 'function')
	{
		handle[path](response,postData,sql);
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
