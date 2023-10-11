import socket
import thread6

socket_connection_var = []
username_var = []
client_no = 0
quit = 0

host = 'localhost'
port = 45557
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host,port))


def broadcaster(message):
	for i in socket_connection_var: 
		i.send(message.encode('utf-8'))
		
	



def client_to_server(connection_socket,username):
	while(True):
		msg = connection_socket.recv(1024).decode()
		if(msg == "EXIT"):
			break
		total_msg = username+":"+msg
		print(total_msg)
		broadcaster(total_msg)
	broadcaster(username+" is offline now")
	socket_connection_var.remove(connection_socket)
	username_var.remove(username)
	print("Database adjusted")
	connection_socket.close()
	print("Connection Closed with " , username)
		
		





def quit_fun():
	print("To stop the server type quit")
	quit_msg = input()
	if(quit_msg == "quit"):
		quit = 1
	

def main():
	thread6.run_threaded(quit_fun)
	s.listen(1)
	print("Server is online")
	while(True):
		global client_no
		if(quit == 1):
			break
		#accepting new client
		connection_socket,addr = s.accept()
		#accepting username
		connection_socket.send("ENTER YOUR USERNAME".encode('utf-8'))
		username = connection_socket.recv(1024).decode()
		client_no = client_no +1
		#saving username and connection_socket
		name = "SERVER =>"+"New Login "+"Username:"+username+" Total Client:"+str(client_no)
		print(name)
		broadcaster(name)
		socket_connection_var.append(connection_socket)
		username_var.append(username)
		thread6.run_threaded(client_to_server,connection_socket,username)
	s.close()	
			
main()
print("Server is offine")


