all: hello.out

hello.out : main.o sub.o 
			gcc -o hello.out main.o  sub.o 
		
main.o : main.c 
		gcc -c main.c 
	
sub.o : sub.c 	
		gcc -c sub.c 

clean : 
	rm main.o sub.o 