#include<stdio.h>
#include<pthread.h>
    //pthread_create( pthread_t th, attrib, function_th, function_args(void *))     0 when successful;  creates a new thread
    //pthread_join( pthread_t th, returnValue (void **) )                                               wait for thread to complete
    
//void * ptr cannot be dereferenced (as it does not refer to specific object)
// int a = 10
// void * ptr = &a
// printf( "%d",*ptr) gives error
  //using printf("%d",*(int*)ptr) also gives error
  //using printf("%d", *(int*)(&ptr) is CORRECT

void *thread_fn(void *arg){
  long id =*(long*)(&arg);
  printf("Starting thread %ld\n", id);
  sleep(5);
  printf("Exiting thread %ld\n", id);
  return NULL;
}

void *thread_fn2(void *args)
{
  int id = (int) args;
    printf("Starting thread %d\n", id);
  sleep(5);
  printf("Exiting thread %d\n", id);
  return NULL;
}
  

int main(){
 pthread_t t1,t2;
 
 pthread_create(&t1,NULL,thread_fn,(void *)1);
 pthread_create(&t2,NULL,thread_fn2,(void *)2);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 printf("Exiting main\n");
 return 0;
}
