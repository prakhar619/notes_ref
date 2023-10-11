#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

char *Usage = "print-rand-matrix -r rows -c cols\n";

#define ARGS "r:c:"

int Rows;
int Cols;

int main(int argc, char **argv)
{
	int c;
	int i;
	int j;
	double r;
	struct timeval tm;
	unsigned long seed;

	while((c = getopt(argc,argv,ARGS)) != EOF) {
		switch(c) {
			case 'r':
				Rows = atoi(optarg);
				printf("Argument -r is present\n");
				break;
			case 'c':
				Cols = atoi(optarg);
				printf("Argument -c is present\n");
				break;
			default:
				fprintf(stderr,"unrecognized command %c\n",
					(char)c);
				fprintf(stderr,"usage: %s",Usage);
				exit(1);
		}
	}
    }
