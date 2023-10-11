//SYSTEM CALL
#include <unistd.h>
//SYSCALLS
	//int create(char* filename, mode_t mode)		//-1 means error
	//int open(const char* path, int flags, mode_t mode)	//mode when O_CREAT is used	//returns file pointer as int
	//int close(int fd)					//flushes and disconnects stream
	//size_t read(int fd,void* buf, size_t cnt)		//read data till end of file or cnt(buffer size) or /n char encountered		//returns actual no of char read
	//size_t write(int fd, void*buf, size_t cnt)		//write data till \n or buffersize cnt or end of string.		//returns actual no of char written
	
	//lseek cmd
	
	//pid_t fork(void)		//returns pid of child in parent process and 0 in child process
	//getpid()			//returns pid of the process
	//getppid()			//returns parent pid (process id)

#include <fcntl.h>
	//mode_t data type	//for deciding file permission
	//flags macros for open

#include <errno.h>
	//errno integer variable	//0 at start
	
#include <stdlib.h>
	//malloc
	//wait()

#include <sys/wait.h>
	//waitpid()
	//WIFEXITED
	//WEXITSTATUS

#include <sys/mman.h>
	//mmap()

/* Forking
	Forking creates a new process from existing process (and not threads)
	All the data are duplicated(even above forking) and have their own memory space
	Even data in both process will have same memory address of data; (logical address); but actually the memory is different; not shared
	For shared Memory use shm_open, mmap, or others
*/
int forking()
{
	printf("Parent Process Id:%d\n",getpid());
	int size_m = 100;
	char* sharedMemory = mmap (NULL, sizeof(char)*size_m, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);
	int x =  fork();
	if( x == 0)
	{
		//child process only
		exit(0);
	}
	else
	{
		//parent process only
    		printf("Child process ID:%d\n",x);
		int status;
		waitpid(x,&status, 0);
 		if (WIFEXITED(status)) 
    			{
        			int exit_status = WEXITSTATUS(status);       
        			printf("Exit status: %d\n",exit_status);
    			}
		
	}
	return 1;
}


//SYSCALLs
int main()
{
	if(argc != 3)
	{
		printf("Pass exactly 2 File name/path\n");
	}
	int fobj = open(argv[1], O_RDONLY);
	int fobj2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	if(fobj == -1)
	{
		printf("File failed to open\n");
	}
	else if(fobj2 == -1)
	{
		printf("File failed to be created at target location\n");
	}
	else
	{
		char* c = (char*)malloc(100);		//buffer
		int k;
		while(k = read(fobj,c,100) != 0))	
		{
			write(fobj2,c,k);
		}
		free(c);	
	}
	printf("FILE CLOSE STATUS FOR READ FILE (0 means successful):%d\n",close(fobj));
	printf("FILE CLOSE STATUS FOR WRITE FILE (0 means successful):%d\n",close(fobj2));
	printf("FILE REMOVED STATUS FOR READ FILE (0 means successful):%d\n",remove(argv[1]));
}



