let fs = require('fs');
let path = require("path");
let querystring = require("querystring");
let ejs = require("ejs");



function dbAccess(sql,query)
    {
        console.log("Accessing DB");
        sql.query(query, function(err,result)
                            { if(err)
                                { 
                                console.log("Failed to Access Database");
                                } 
                             else
                                {
                                console.log("Database Access Successful");
                                console.log(result);
                                }
                            });
    }

function queryGenerator(postData)
{
    let queryObj = querystring.parse(postData);
    return queryObj;
}

function formUploadResponse(response,application_id)
{
    response.writeHead(200,{'Content-Type':'text/html'});
    response.write(`<!DOCTYPE html>
    <html>      
        <head>  
            <meta charset="utf-8">  
            <title>Form</title>     
        </head>     
           <body>
           <h2>Application Successfully Generated!<h2>
           <p>Use user email id to track your application</p>
             `);
    return response.end()
}

function formUpload(response,postData,sql)
{
    console.log("Form Uploaded to server");
    let queryObj = queryGenerator(postData);
    console.log(queryObj);
    let queryGen = 'INSERT INTO unapproved SET ' + sql.escape(queryObj);
    dbAccess(sql,queryGen);
    formUploadResponse(response);
}


function medicalOffice(response,postData,sql)
{
    console.log("Medical Office form successfully generated");
    query = 'SELECT * from unapproved where medical_request="1" and medical_approval="0" ';
    fs.readFile(path.resolve(__dirname,"./../html/medicalOffice.ejs"), 'utf-8',function(err,data){
        if(err) throw err;
        function dbAccess(sql,query)
        {
        console.log("Accessing DB");
        sql.query(query, function(err,result)
                            { if(err)
                                { 
                                    console.log("Failed to Access Database");
                                } 
                             else
                                {
                                    console.log("Database Access Successful");
                                    console.log(result);
                                    dbOutput_variable = result;
                                    let htmlRendered = ejs.render(data,{ObjArray: dbOutput_variable});
                                    response.writeHead(200,{'Content-Type':'text/html'});
                                    response.write(htmlRendered);
                                    response.end();
                                }
            })
        }
        dbAccess(sql,query);
    });
    
}
function baseForm(response,postData,sql)
{
    fs.readFile(path.resolve(__dirname,"./../html/Form.html"),function(err,data){
        response.writeHead(200,{'Content-Type':'text/html'});
        response.write(data);
        return response.end();
    }
    )
    console.log("Base Form Handled");
}

function medUpload(res, data,sql)
{
    console.log(data);
    let queryObj = queryGenerator(data);
    console.log(queryObj);
    if( queryObj["medical_approval"]=== "1")
    {
        let query = `update unapproved set medical_approval="1" where application_id = ${queryObj["application_id"]}`;
        dbAccess(sql,query);
        console.log("DB Updated")
    }
    else if ( queryObj["medical_reject"]=== "1")
    {
        let query = `update unapproved set medical_reject="1" where application_id = ${queryObj["application_id"]}`;
        dbAccess(sql,query);
        console.log("DB Updated")
    }
    medicalOffice(res,data,sql);
}
    

exports.baseForm = baseForm;
exports.formUpload = formUpload;
exports.medicalOffice = medicalOffice;
exports.medUpload= medUpload;
