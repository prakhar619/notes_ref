#include <stdio.h>
void fun(int* a)
{}
void fun1(int a[])
{}
void fun2(int a[9])    //doesnt do anything extra
{
        printf("Accessing 11th element:%d\n",a[10]);
}

//String
void string_handling()
{
    char str[12]  = {'H','e','l','l','o',' ', 'W','o','r','l','d','\0'}; 
     //str = "HelloWorld" illegal
    printf("%s",str);
    char str_2ndMethod[12] = "Hello World"; //both are equivalent   //make sure array is long enought for automatic addition of null char

    //  #include <string.h> for powerful string manipulation
}

int main()
{
    //Sqr Bracket operator used for array
    int s[10];      //s[0] to s[9]
    int s_[20];     //s[0] to s[19]
    int TwoD[10][20];   //TwoD[][10] not allowed
    int infiD[10][20][30][40];
    //total size = sizeof(baseType)*LengthArray

    int* s_ptr = s;
    int *s__ptr = &s_[0];  //both equivalent


    for(int i = 20; i>0; i--)
    s_[20-i] = i;
    // *(s+20-i) is also equivalent //so s is pointer(addr); adding to addr we change addr(or index) then we dereference it using *

    //a[1][2] == *((int *)a+12)
    //a[0][3] == *((int *)a+3)
    //*((base type*)a+(j* rowlength)+k) == a[j][k]
    //pointer indexing faster than array indexing
    int defAndIn[10] = {1,2,3,4,5,6};
    int defAndInn[10][10] = { {1,1},{2,2},{3,3},{4,4},{5,5}};

    char unsized[]=  "Now we can directly assign\n";
    printf("Length of Array:%d\n",sizeof unsized);
    int halfsized[][2] = { {1,2},{2,4},{3,4},{25,45},{55,45}};

    extern int pointer(), dynamic_alloc();
    dynamic_alloc();
    pointer();
    fun2(s_);
    string_handling();
}

int pointer()
{
    //2 pointer operation
        // * and &
    int *ptrrr = 0;
    int *ptrrrr = NULL; //basic initialisation  //equivalent statements

    int x = 10;
    void* ptr_void = &x;    //generic pointer   //not explicit cast required when converting to other type
    double* ptr_dou = (double *) &x;    //all else require explicit casting
    //keep in mind that this type of casting result in info loss
        //int pointer has info for 4byte and double has info for 8byte
        //double -> int 
    double y = 20.223223;
    int *ptr_int =(int*) &y;
    printf("Value of double after int cast:%d\n",*ptr_int);

    //2 arithmetic pointer operation
        // ++ and -- and + and -    (ptr1+ptr2) is valid
        // ++ and -- works differently for each pointer type
            //char_ptr++ means increment of 1byte
            //int_ptr++ means increment of 4byte
        // * and / and etc ... illegal

    //Comparing Pointers
        //p > q allowed
    

    //ARRAY OF POINTERS         //Array of pointers to integer
    int *arr_ptr[10];

    int var = 10;
    arr_ptr[0] = &var;

    //Multiple indirection
    int ** ptr_ptr ;    //pointer to a (int pointer)
    int * ptr_;
    int var1 = 10;
    ptr_ = &var1;
    ptr_ptr = &ptr_;
    printf("Multiple Indirection:%d/n",**ptr_ptr);

    //Pointer to Functions
        //Then that pointer can be used to be passed as argument
    
    int (* funPtr)(int x,int y);    //pointer to a function which can take 2 int as args and returns 1 int
    //void check(char *a, char *b,int (*cmp)(const char *, const char *));  //example function ptr passed as argument
    //void check(char *a, char *b,int cmp(const char*, const char*))    //another way
    //void check(char *a,char *b, cmp_actual_fun);      //removing fun_ptr in first place and using function directly
        //then why need fun_ptr=> array of functions
    // funPtr = functionName;
    return 1;
}

int dynamic_alloc()
{
    char * ptr_ch = malloc(1000);   //automatic conversion of void* to char*    //happened earlier also
    //c++ requires explicit cast for void* also
    char * cpp_ptr_ch = (char *)malloc(1000);

    //malloc needs size in bytes; char 1byte therefore no need of adjustment
    //malloc(1000*sizeof (int)) 1000 integers

    free( ptr_ch);
    free( cpp_ptr_ch);  //very powerfull as it can affect allocation tables
}

