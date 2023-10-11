#include <stdio.h>
#include <stdlib.h>

/*After you compile you can see the problem that sizeof is failing to work
Reason is that array_input(int ar[]) = array_input(int *ar)
C turns array into pointer when passed as argument to a function.
Using sizeof(ar)/sizeof(int) will give you 2 so less than org array.
*/
void array_input(int ar[])   
{   int array_length = sizeof(ar);  //Here lies the problem

    printf("The no of element in passed array is %d \n",array_length);
    printf("The input array is [using array method]:");
    for(int i =0; i < array_length;i++)
      printf("%d  ",ar[i]);

    printf("\n");

    printf("Pointer way of using array values:");
    for(int j = 0; j < array_length; j++)
      printf("%d  ",*(ar+j)); //*ar will print the first element

    printf("\n");

    //using bigger value than allowed 
    printf("Using not allowed index \n");
    printf("Using array rep %d \n",ar[array_length]);
    printf("Using pointer rep %d \n",*(ar+array_length));

}
//We cant return an array from a funtion rather we use pointer to return the memory address of first element

/*[segmentation fault] problem is the following code is that the function is kind of destroyed and we
 we are trying to access a local memory */
int* array_output ()
    {
       int  output_ar[] = {1,2,3,4,5,6,7};

        printf("Method 1:");
      return output_ar;
       printf("Method 2:");
     //  return output_ar[0];
       printf("Method 3:");
      // return *output_ar;
       printf("Method 4:");
     //  return *(output_ar+0);
       printf("Method 4:");
     //  return *output_ar[0];

    }
/*Method 1: use static keyword
Method 2: use malloc instead of array formation or calloc(default is 0 instead of garbage value)
Method 3: pass an array as argument then edit it then return the same (nothing new)
Method 4: using struct*/

//Method 2:
int* array_output_malloc ()
    {   int n = 5;
        int* ar = (int* ) malloc(sizeof(int)*n);
        *(ar)= n;           //using first element as represent size of pointer assigned to prevent segmentation fault
        for(int i = 1;i<n;i++) 
        {
        *(ar+i) = i+i;
        printf("%d ",*(ar+i));
        }
        printf("\n");
        return ar;
    }

//Method 3 same array as argument and return
int* array_output_same(int ar[])
{
  ar[1] = 10;
  ar[4] = 20;
  ar[10]  = 100;
  return ar;  
}

int  main ()
    {
        int main_test_array[6];
        for(int i = 0; i<6;i++)
        {
          printf("Enter the %dth element:",i);
          scanf("%d",&*(main_test_array+i));
        }
        printf("The size of main test array is %d \n",sizeof(main_test_array)/sizeof(int));
        array_input(main_test_array);

    //  int* n = array_output();  
    // printf("Value of array output %d \n",n[0]);
    /*[segmentation fault] problem is the above code is that the function is kind of destroyed and we
    we are trying to access a local memory */

    //[Method 2]
    printf("Size of malloc returned pointer:%d \n",sizeof(array_output_malloc())/sizeof(int));  //wont work
    /*Use a function to get index pos of \o to get size of string or array*/
    array_output_malloc();
    printf("\n");
    printf("Value of array output when malloc is used Method 1: %p \n",array_output_malloc);    //wont call the function
    printf("Value of array output when malloc is used Method 2: %d \n",*array_output_malloc);   //calls the function
    printf("Value of array output when malloc is used Method 3: %p \n",array_output_malloc());  //calls the function
    printf("Value of array output when malloc is used Method 4: %d \n",*array_output_malloc()); //only this correct
    printf("Value of array output when malloc is used Method 5: %d \n",*(array_output_malloc()+4)); //this also works
    //for all element
    int* ptr_output_malloc = array_output_malloc();
    printf("Printing pointer element using pointers method \n");
    for(int i = 0; i< *ptr_output_malloc;i++)
        printf("%d ",*(ptr_output_malloc+i));

    printf("\n");

    printf("Printing pointer element using array method \n");
    for(int i = 0; i< ptr_output_malloc[0];i++)
        printf("%d ",ptr_output_malloc[i]);
        
    printf("\n");

    //[Method 3]
    int array_same[] = {1,2,4,5,6,7};
    printf("Value of array output when same array is used:%d \n",*(array_output_same(array_same)+4));

    printf("Here original array also changes so no big deal. Proof:%d \n",array_same[4]);
    

    free(ptr_output_malloc);
    free(array_output_malloc());
    
    
    
    
    // 2d array
    int **ar;
    ar[i][j];
    return 1;


    }
