import socket
import thread6

host = 'localhost'
port = 45557
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((host,port))
print(s.recv(1024).decode())
username = input()
s.send(username.encode('utf-8'))

def listen(socket):
	while(True):
		msg_from_server = socket.recv(1024).decode()
		print(msg_from_server)
	

thread6.run_threaded(listen,s)
print("Enter text or type quit to exit the lobby")
while(True):
	text = input()
	if(text == "quit"):
		s.send("EXIT".encode('utf-8'))
		break
	s.send(text.encode('utf-8'))


s.close()
print("You are disconnected to the server")
	
	
