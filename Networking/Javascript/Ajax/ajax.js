function loadDoc() {
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function() {
      document.getElementById("demo").innerHTML = this.responseText;
      }
    xhttp.open("GET", "ajax_info.txt", true);
    xhttp.send();
  }


//The keystone of AJAX is the XMLHttpRequest object.

//Create an XMLHttpRequest object
//Define a callback function
//Open the XMLHttpRequest object
//Send a Request to a server


//open(method, url, async, user, psw)method: the request type GET or POST
//url: the file location
//async: true (asynchronous) or false (synchronous)
//user: optional user name
//psw: optional password

//