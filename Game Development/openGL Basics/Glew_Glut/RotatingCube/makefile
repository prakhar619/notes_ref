all: main.out 
	./main.out
	clean

main.out: main.c Utils.h Utils.c
	gcc -o main.out $^ -lGLU -lGL -lGLEW -lglut -lm

clean: 
