/*System call imports*/
#include <unistd.h>  //contains main function for system calls
#include <fcntl.h>    //contains macros and flags used in system call functions
#include <stdlib.h>     //malloc for buffer
/*Streams(file pointers) vs files
    streams acts as abstraction to behave similarly whether device is console, disk, tape drives etc.
    even if each device is very different, bufferd file system transforms each logical device into streams

    Streams are of 2 types
        text stream
        binary stream

    Files in C may be diskfile or printer or terminal; each associated with a stream by using open operation
    All streams are same but not files. 
        if file support position request, opening such file also initializes those values

    close operation to disassociate a file from a stream
    flushing happens when stream is closed; guarantees no data left in disk buffer
    close automatically when main() returns to OS or exit but not when crash happens
*/
#include <stdio.h>
//several macros for status;
//File, size_t, fpos_t

//FILE POINTER
    //file pointer is a pointer to a structure of type FILE
    //it points to information that defines various things about file like name status and current pos.
    //it is specific to a file and is used by stream to direct i/o operation

int main()
{
    FILE *file_ptr; //doesnt actually points to file in memory rather points to a c maintained structure
    
    //fopen opens a stream for use and links a file with that stream
    //then it returs the ptr associated with that file
    
    // FILE* fopen(const char* filename,const char* mode);
    file_ptr = fopen("input.txt","w");
    if(file_ptr == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }
    //r+ will not create file
    //w+ will 
    //w+ if file exist, destroys content
    //r+ if file exist, append


    //writing a char
    //int putc(int ch, File *fp)
    //int fputc(int ch, File *fp)

    //reading  a char
    //int getc(File *fp)
    //int fgetc(File *fp)

    //if  file ends getc give EOF so use it in loop; while(ch!= EOF)


    //max no of file that can be opened at a time is specified by FOPEN_MAX (macro).
    
    //int fclose(File *ptr);
    fclose(file_ptr);

}

/*
FEOF()
    feof() instead of getc() for checkin only;    
    will still use getc() to read
    in binary file EOF(-1) may be read therefore file may end before actual ending

        int feof(File *fp)
        while(!feof(fp))    //feof returns true when file actually ends
*/

//STRINGS
    //int fputs(const char* st,File *fp);
    //char* fgets(char *str, int length, file*fp)   //reads till new line char or length-1 chars have been read


//void rewind(File *fp)
//  file position to file beginning.

//int ferror(file *fp)
    //checks if file operation has produced an error during last operation
    //true means error

//int remove(const char *filename) ; to remove file; 0 if successfully removed

//int fflush(File* fp)
    //writes contents of any bufferd data to associated file
    //fflush(NULL) all opened file are flushed
    //0 if successful else EOF


//read and write longer than 1byte
    //fread()   size_t fread(void *buffer,size_t num_bytes,size_t count,File *fp);
    //fwrite()
            //fwrite(&d, sizeof(double), 1, fp); where double d = 12.3



//fseek and randmom-access i/o
//  int fseek(File *fp,long int numbytes,int origin)
                    //numbytes: no of bytes from origin
                    //origin:  Beginning of file  SEEK_SET  (this are macros)
                            //current position    SEEK_CUR
                            //end of file         SEEK_END

//long int ftell(File *fp)
    //-1 is failure








//fprintf() and fscanf()
//int fprintf(File *fp,const char*control_string,...)
//int fscanf(File *fp,const char*control_string,...)




//standard stream
//stdin
//stdout        putc(c,stdout);//standard streams are file pointers
//stderr        we can use these streams instead of file pointers

//fgets(str,80,stdin);

//freopen to redirect standard streams
    // File* freopen(const char* filename, const char*mode, File *stream)



//SYSTEM CALL IS FOR LINUX ONLY
int system_call()
{
    /*SYSTEM CALL
        create
        open
        close
        read
        write
    */

   //int create(char *filename, mode_t mode)
   //int open(const char* path,int flgs, int mode)      
   //int close(int fd);
   //int (size_str) read(int fd, void* buf,int buf_size)        //0 if file end; -1 if error
   //int (size_str) write(int fd,void* buf,int buf_size)        //return 0 on reaching file end;  -1 if error

    int fd =  creat("./Sample_Files/newHelloworld.txt", S_IRUSR | S_IRWXU );
    if(fd == -1)
    {
        printf("File failed to be created");
    }

    int fd1 = open("./Sample_Files/sample3.txt", O_RDONLY);
    if(fd1 == -1)
    {
        printf("File failed to open");
    }

    char* c = (char*) malloc(100);  //will act as buffer//during read we will paste our read data from file here then from here where ever needed
    int size = read(fd1,c,100);     //will read 100 bytes and will paste in buffer;
    write(fd,c,size);               //if 100 instead of size then binary data also enters file making it binary file; unreadable



    int status_fd = close(fd);      //0 means successful
    int status_fd1 = close(fd1);
    free(c);
    return 1;
}