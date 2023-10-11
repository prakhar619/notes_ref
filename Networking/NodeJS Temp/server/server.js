let http = require('http')
let url = require('url')
function start(route,handle,sql)
{
    function onRequest(request,response)
    {
        console.log("Request Made");
        console.log("URL Request:"+request.url);

        let path = url.parse(request.url).pathname;
        let query = url.parse(request.url).query;

        let postData = "";
        request.addListener("data",function(postDatachunk){ console.log("Receiving Listener Data.");postData += postDatachunk;});
		request.addListener("end",function(){
		
							console.log("Request for "+path+" received. Sending request to 'route'");
							route(path,handle,response,postData,sql);
						    }
				   );
    }
    function sqlConnect(mysql)
    {
        mysql.connect(function(err){
                                    if(err) throw err;
                console.log("Database Connected");
                });
    }
    
    sqlConnect(sql);
    http.createServer(onRequest).listen(8080);
    console.log("Server has started");
}

exports.start =  start;
