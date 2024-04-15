/* A simple readers/writers program using a one-word shared memory. */
#include <sys/types.h>
#include <unistd.h>          
#include <stdio.h>
#include <sys/mman.h>
#include <sys/sem.h>

#define SIZE sizeof(int)   /* size of [int] integer */
#define run_length 10       /* number of iterations in test run */
#define mutex0 0
#define mutex1 1        /* semaphore index for mutual exclusion to buffer*/

int sem_create(int num_semaphores)
{  /* procedure to create specified number of semaphores */
   int semid;

   /* create new semaphore set of semaphores */
   if ((semid = semget (IPC_PRIVATE, num_semaphores, IPC_CREAT | 0600)) < 0)
     {  perror ("error in creating semaphore");/* 0600 = read/alter by user */
        exit (1);
     }
   return semid;
}

void sem_init(int semid, int index, int value)
{  /* procedure to initialize specified semaphore to given value */
   if (semctl (semid, index, SETVAL, value) < 0)
     {  perror ("error in initializing first semaphore");
        exit (1);
     }
}

void P(int semid, int index)
{/* procedure to perform a P or wait operation on a semaphore of given index */
  struct sembuf sops[1];  /* only one semaphore operation to be executed */
   
   sops[0].sem_num = index;/* define operation on semaphore with given index */
   sops[0].sem_op  = -1;   /* subtract 1 to value for P operation */
   sops[0].sem_flg = 0;    /* type "man semop" in shell window for details */

   if (semop (semid, sops, 1) == -1)
     {  perror ("error in semaphore operation");
        exit (1);
     }
}

void V(int semid, int index)
{/* procedure to perform a V or signal operation on semaphore of given index */
   struct sembuf sops[1];  /* define operation on semaphore with given index */

   sops[0].sem_num = index;/* define operation on semaphore with given index */
   sops[0].sem_op  = 1;    /* add 1 to value for V operation */
   sops[0].sem_flg = 0;    /* type "man semop" in shell window for details */

   if (semop (semid, sops, 1) == -1)
     {  perror ("error in semaphore operation");
        exit (1);
     }
}

int main (void)
{  pid_t pid;               /* variable to record process id of child */
   caddr_t shared_memory;   /* shared memory base address */
   int i_parent, i_child;   /* index variables */
   int value;               /* value read by child */

   /* set up shared memory segment */
  shared_memory=mmap(0, SIZE, PROT_READ | PROT_WRITE, 
                              MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    int semid = sem_create(2);
    sem_init(semid, mutex0, 0);
    sem_init(semid, mutex1,1);

  if (shared_memory == (caddr_t) -1)
    { perror ("error in mmap while allocating shared memory\n");
      exit (1);
    }
  
   if ((pid = fork()) < 0)  /* apply fork and check for error */
     { perror ("error in fork");  
       exit (1);
     }

   if (0 == pid)             
     { /* processing for child */
       printf ("The child process begins.\n");
       for (i_child = 0; i_child < run_length; i_child++)
         {  
            P(semid, mutex0);
         /* wait for memory to be updated */
           value = *shared_memory;
           printf ("Child's report:  current value = %2d\n", value);
           V(semid, mutex1);
         }
       printf ("The child is done\n");
     }
  else 
     { /* processing for parent */
       printf ("The parent process begins.\n");
       for (i_parent = 0; i_parent < run_length; i_parent++)
          {
          P(semid, mutex1);
         *shared_memory = i_parent * i_parent;/* square into shared memory */
           printf ("Parent's report: current index = %2d\n", i_parent );
          V(semid, mutex0);
         }
       wait(pid);
       printf ("The parent is done\n");
     }
   exit (0);
}

