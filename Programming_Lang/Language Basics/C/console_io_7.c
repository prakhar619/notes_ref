#include <stdio.h>      //getchar and putchar       gets and puts       printf and scanf
#include <conio.h>      //getch and getche

//io not in c itself (no io keyword)

/*
Standard C
<stdio.h> 
both console and file io
tty based output
not graphic based output/neither cursor position
*/

//Reading and Writing Characters
    //int getchar(void);  //assign to char variable   //EOF if error occurs; EOF is macro defined in stdio.h equalling to -1
    //int putchar(int c);

void readAndwriteCHAR()
{
    printf("Enter a char\n");
    int c = getchar();

    printf("Entered char is:%c\nUsing putchar:",c);
    int c_st = putchar(c);
    printf("\n");
}

void readAndwriteString()
{
    int c;
    printf("Enter a string. To quit use .'period'");
    do{
        c = getchar();  //user can enter data in single go  //Os system will buffer and code will take value one by one char
        putchar(c);
    }while(c != '.');
    printf("\n");
}

//Line Buffered Input
    //buffer till enter is pressed

/*
non standard
<conio.h>
    int getch(void)       or _getch(void)
    int getche(void)      or _getche(void)
*/

void readAndwriteCH()
{
    printf("Enter a char. Now using getch.\n");
    int c = getch();    //as soon as char is pressed  //no need of enter //line buffer skipped

    printf("Entered char is:%c\nUsing putchar:",c);
    int c_st = putchar(c);
    printf("\n");

    printf("Enter a char. Now using getche.\n");
    c = getche();    //as soon as char is pressed //key is echoed  //no need of enter //line buffer skipped

    printf("\nEntered char is:%c\nUsing putchar:",c);
    c_st = putchar(c);
    printf("\n");
}

/* 
Standard C
<stdio.h> 
    char* gets(char *str)    //automatically adds null at last
    int puts(const char* str)
*/
void readAndwriteString_()
{
    char str[10];
    gets(str);        
    //usr can enter more char than array can hold; works fine unless runtime error on unaccessible memory accessed
    printf("String is:%s\n",str);
    puts("String using puts is:");
    puts(str);      //should encounter null \0 to end this statement and move on.
}

/*Formatted Console I/O
    read and write data of various types
    built in datatypes and auto null terminated string

        int printf(const char* control_string ,...);
        int scanf(const char* control_string, ...);
*/
void readAndwrite()
{
    printf("Sample input");
    int count;
    printf("1234a%n count value will be 5\n",&count);
    printf("count:%d\n",count);

    //Format Modifiers
        //<int number>% acts as minimum field width specifier
                //padding if less; nothing if more
    
    double it = 1.123456789;
    printf("%f\n",it);
    printf("%10f\n",it);    //invisible padding
    printf("%010f\n",it);     //padding with 0s

        //<float number>% acts as integer part for padding; decimal part of pecision
    printf("%10.3f\n",it);  //padding of 10 with precision of 3rd decimal digit

        //default right justified; -(minus sign) for left justified
    printf("%-10f,%-10f",it,it);
    printf("\n\n");
    //# and * modifier act on different flgs to give different data





    //scanf(control string,...);
        //control string:   format specifier
                        //  whitel space
                        //  non white space char
    int j;
    printf("Enter value for j\n");
    scanf("%d",&j);       
    
    int k;
    char ch[100];
    char ch1[100];
    //scanset (very nice feature)
    scanf("%d%[abcde]%s",&k,ch,ch1);
    printf("Value of ch:%s\n",ch);
    printf("Value of ch1:%s\n",ch1);
    printf("Value of j:%d\n",k);

    //%[A-Z] for scanset in range

    //Format Modifiers
        //<integer num>%   max field length
    scanf("%20s",ch);   //read no more than 20 char

}



int main()
{
    //readAndwriteCHAR();
    //readAndwriteString();
    //readAndwriteCH();
    //readAndwriteString_();
    readAndwrite();
    return 1;
}