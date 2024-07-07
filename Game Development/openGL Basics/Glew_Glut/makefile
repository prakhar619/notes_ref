all: main.out 
	./main.out
	clean

main.out: main.c 
	gcc -o main.out  main.c  -lGLU -lGL -lGLEW -lglut 

clean: 
	rm main.out
