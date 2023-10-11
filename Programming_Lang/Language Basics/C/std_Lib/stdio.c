#include <stdio.h>
/*
several macroes and types
*/

/*DATA TYPES
FILE: to declare file pointer
size_t: unsigned integer, sizeof return type
fpos_t: defines an object that can uniquely specify each location within file
*/

/*Macroes
EOF: value for end-of-file
FOPEN_MAX: defines max no of files that can be opened at any one time
SEEK_SET: seek from start of file   [text file][binary filel]
SEEK_CUR: seek from current file indicator  [binary file]
SEEK_END: seek from end of file [binary file]
*/

/*Variables
errno (globl integer variable): for checking error related to io
*/

/*Functions
void clearerr(FILE* stream)     //resets the error flg to zero and EOF indicator
    Related Functions: feof(), ferror(), perror()
int fclose(FILE* stream)        //flushes its buffer and disconnects the stream. Deallocates buffer
    0 means successful
    EOF unsuccessful
    Related Functions: fopen(), freopen(), fflush()
int feof(FILE* stream)          //determines end of file
    == 0 means end of file
    != 0 means not end of file
        EOF if read after feof = 0
    Related Functions: clearerr( ), ferror( ), perror( ), putc( ), and getc( )
int ferror(FILE *stream)        //checks for file error on given stream
    == 0 means no error
    != means error
        Check nature of error using perror()
    Related Functions:clearerr( ), feof( ), and perror( )
int fgetc(FILE * stream)        //returns char and increments file position indicator
    unsized char (int form)
    EOF if reached file end
    Related Functions:fputc( ), getc( ), putc( ), and fopen( )
int fgetpos(FILE * stream, fpos_t *pos) //File position indicator
    Value here is valid for subsequent call to fsetpos()
    Related Functions:fsetpos( ), fseek( ), and ftell( )
char* fgets(char*str,int num,FILE* stream)  //read chars upto num-1 and store them in buffer str;
    String(char*) upto newline or EOF or num-1 size; Each buffer string is accompanied by null at last (therefore full completed string);Newline char is retained
    NULL pointer if failure in reading
    Related Functions:fputs( ), fgetc( ), gets( ), and puts( )
FILE* fopen(const char *fname, const char* mode)   //mode here is not permission rather what to do with file (r or w or rw)
    NULL means failed to open
        //cannot do this output op->input op
        //first call fflush,fseek,fsetpos or rewind
    Related Functions:fclose( ), fread( ), fwrite( ), putc( ), and getc( )
int fprintf(FILE* stream, const char *format, ...)  //to (print) the string in file; like fprintf(stream_output,"HELLO world %d,%f",10,1.2)    will append this string in output stream
    Returns the no of char actually printed(inserted)
    < 0 if error
int fputc(int ch, FILE* stream) //writes char ch in file (current file pos indicator) and advances file pos indicator
    value of ch written
    EOF if failure
int fputs(const char*str, FILE* stream) //write string in file directly
    EOF if failure
    no of char  //null is not written
size_t fread(void *buf, size_t size, size_t count,FILE* stream) //reads the streams, stores in buffer, size_obj(like char = 1)(use sizeof) is needed aa size, count to set no of obj/char read at a time
    returns size of objects/char actually read 
    if return is < count either error or file end
FILE* freopen(const char* fname, const char *mode, FILE *stream)    //associate existing stream with different file
    returns a pointer to stream 
    NULL pointer if error
int fscanf(FILE* stream, const char *format, ...)   //works like scanf except stream is not stdin but file)
int fseek(FILE* stream, long int offset, int origin)    //set file position indicator according to offset and origin; offset in no of bytes from origin to seek to
    //origin must be one of these macroes: SEEK_SET, SEEK_CUR, SEEK_END
    //for text file: origin: SEET_SET , offset: value of ftell() on same file or 0
    0 means successful
int fsetpos(FILE* stream, const fpos_t *position)
long int ftell(FILE *stream)
size_t fwrite(const void *buf, size_t size, size_t count, FILE *stream)
int getc(FILE *stream)
int getchar(void)
char *gets(char *str)
void perror(const char *str)
int printf(const char *format, ...)
int putc(int ch, FILE *stream)
int putchar(int ch)
int puts(const char *str)
int remove(const char *fname)
int rename(const char *oldfname, const char *newfname)
void rewind(FILE *stream)
int scanf(const char *format, ...)
void setbuf(FILE *stream, char *buf)
int setvbuf(FILE *stream, char *buf, int mode, size_t size)
int snprintf(char * restrict buf, size_t num, const char * restrict format, ...)
int sprintf (char *buf, const char *format, . . .)
int sscanf(const char *buf, const char *format, ...)
FILE *tmpfile(void)
char *tmpnam(char *name)
int ungetc(int ch, FILE *stream)






*/