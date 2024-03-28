#include <stdio.h>
#include <string.h>
int main()
{
  char arr[20] = "abcde";
  char* pointer = &arr;
  int ppointer = (int)  pointer;
  printf("String:%s\n",arr);
  printf("Pointer:%p\n",pointer);
  printf("PPointer:%p\n",ppointer);
  printf("String by pointer:%s\n",pointer);
  //printf("String by ppointer:%s\n",(char *)ppointer);
  
  char newAr[30];
  strcpy(newAr,arr);
  printf("Copied String:%s\n",newAr);
  
  return 1;
  }
