#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>
char *Usage = "Multiply Matrix -a rows -b cols -t threads\n";
#define ARGS "a:b:t:"

int a_rows;
int a_cols;

int b_rows;
int b_cols;

int c_rows;
int c_cols;

double A[100][100];
double B[100][100];
double C[100][100];

int t;
int thread_load;

void* matrix_mult(void* id)
{
  int start_row = (*(int*)(&id)) * thread_load;
   for (int i = 0+start_row; i< thread_load+start_row; i++)
   {
    if(i >= c_rows)
    break;
    for(int j = 0; j < b_cols; j++)
    {
      C[i][j] = 0;
      for(int k = 0; k < a_cols; k++)
      {
        C[i][j]+= A[i][k] * B[k][j];
      }
    }
  }
  return NULL;
}

int thread_main()
{
  thread_load = a_rows/t;
  if(thread_load*t - a_rows != 0)
  thread_load++;
  c_rows = a_rows;
  c_cols = b_cols;
  int thread_c = 0;
  pthread_t tlast;
  while (thread_c < t)
  {
    pthread_t t1;
    pthread_create(&t1,NULL,matrix_mult,(void *)thread_c);
    tlast = t1;
    thread_c++;
  }
  pthread_join(tlast,NULL);
  return 1;
}
  
  

int matrix_create(FILE* a,FILE* b)
{
  fscanf(a, "%d %d", &a_rows, &a_cols);
  fscanf(b, "%d %d", &b_rows, &b_cols);

  char buf[100];
  int row_counter = -1;
  int col_counter = 0;
  while(fscanf(a,"%s",buf) == 1)
  {
    if(buf[0] == '#')
    {
      row_counter++;
      col_counter = 0;
      fscanf(a,"%s",buf);
      fscanf(a,"%s",buf);

    }
    else
    {
      A[row_counter][col_counter] = atof(buf);
      col_counter++;
    }
  }
   row_counter = -1;
   col_counter = 0;
   while(fscanf(b,"%s",buf) == 1)
  {
    if(buf[0] == '#')
    {
      row_counter++;
      col_counter = 0;
      fscanf(b,"%s",buf);
      fscanf(b,"%s",buf);
    }
    else
    {
      B[row_counter][col_counter] = atof(buf);
      col_counter++;
    }
  }
}

void normal_multiplication()
{
  for(int i = 0; i< a_rows; i++)
  {
  for(int j = 0; j< b_cols; j++)
  {
  C[i][j] = 0;
  for(int k = 0; k< a_cols; k++)
  {
  C[i][j] =  A[i][k] * B[k][j];
  }
  }
  
  }
}

double CTimer() {
	struct timeval tm;

	gettimeofday(&tm,NULL);
	return((double)tm.tv_sec + (double)(tm.tv_usec/1000000.0));
}

int main(int argc, char **argv)
{
	int c;
	int i;
	int j;
	double r;
	FILE *matrix_A;
        FILE *matrix_B;

	while((c = getopt(argc,argv,ARGS)) != EOF) {
		switch(c) {
			case 'a':
				matrix_A = fopen(optarg,"r");
				if (matrix_A == NULL)
				{
				  printf("Matrix A file unable to open");
				  exit(1);
				}
				break;
			case 'b':
				matrix_B = fopen(optarg,"r");
				if (matrix_B == NULL)
				{
				  printf("Matrix B file unable to open");
				  exit(1);
				}
				break;
			case 't':
			        t = atoi(optarg);
			        break;
			default:
				fprintf(stderr,"unrecognized command %c\n",
					(char)c);
				fprintf(stderr,"usage: %s",Usage);
				exit(1);
		}
	}
	matrix_create(matrix_A,matrix_B);
	double start = CTimer();
	thread_main();
	double end = CTimer();
	printf("Multi Threaded Matrix Multiplication Time:%f \n",end-start);
	start = CTimer();
	normal_multiplication();
	end = CTimer();
	printf("Single Threaded Matrix Multiplication Time:%f \n",end-start);

	return 1;
      }
