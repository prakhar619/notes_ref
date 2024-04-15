#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    char* myfifoSend = "/tmp/mypipeSendReader";
    char* myfifoReceive = "/tmp/mypipeRecReader";
    mkfifo(myfifoSend, 0666);
    mkfifo(myfifoReceive, 0666);
    int fk = fork();
    if(fk == 0)
    {
    char bufR[100];
    int fdRec = open(myfifoReceive,O_RDONLY);
    if( fdRec == -1)
    {
      printf("Receive Data FIFO failed");
      return -1;
    }
          //receive data pipe
          char exit[10] = "exit\n";
          while(1)
          {
              ssize_t x = read(fdRec,bufR,sizeof(bufR));
              if( x > 0)
              {
                bufR[x] = '\0';
                printf("RECEIVED:%s",bufR);
                if(strcmp(bufR,exit) == 0)
                  {
                    printf("Exitting Receiving Terminal\n");
                    close(fdRec);
                    return 1;
                  }
               }
          }
    }
    else
      {

    char bufW[100];
    int fdSend = open(myfifoSend,O_WRONLY);
    if (fdSend == -1)
    {
      printf("Send Data FIFO failed");
      return -1;
    }
      char exit[10] = "exit\n";
            while(strcmp(bufW,exit) != 0)
            {
                fgets(bufW,sizeof(bufW),stdin);
                write(fdSend,bufW,strlen(bufW)+1);

            }
      printf("Exit Sending Line\n");
      printf("Waiting for receiver line to close\n");
      fflush(stdout);
      wait(fk);
      printf("Receiver line closed\n");
      unlink(myfifoSend);
      unlink(myfifoReceive);
      return 1;
      }
}
    
      
    
