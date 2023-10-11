#include <iostream> //cout and cin
using namespace std;

int first_program()
{
    cout << "Hello World";
    return 0;
}

#include <stdio.h>  //printf and scanf

/* data types in cpp
    int         %d  
    unsigned    %u
    float       %f
    double      %f
    char        %c
    
    string      %s
*/
int print_statement()
{
    int a = 1;
    cout << "Method" << " " << a << "for printing" << endl;
    a+=1;
    printf("Method %d for printing \n",&a);
    return a;
}

int read_value()
{
    int x;
    cin >> x;
    cout <<"Value of x" <<  x << endl;
    scanf("%d", &x);
    printf("Value of x %d \n",x);
    return x;
}

int condictional_statements()
{
    int y = 10;
    if(y < 10)
    {
        cout << "'If' is executed" << endl;
    }
    else if(y == 10)
    {
        cout << "'else if' is executed" << endl;
    }
    else
        cout << "'else' is executed" << endl;

    switch (y)
    {
        case 1:
        cout << "y is one" << endl;
        break;
        case 10:
        cout << "y is 10" << endl;
        break;
    }

    return y;
}

int loop_statement()
{
    for(int i = 0; i <= 10 ; i++)
    cout << i << endl;

    int j = 0;
    while (j != 10)
    {
        cout << j << endl;
        j+=1;
    }

    return j;
    // no do while in cpp
    // use modification of while 
}

int string_intro()
{
    char string1[200];
    scanf("%s", string1);
    printf("Your string is %s: \n", string1);

    printf("%d \n",string1);        // address of pointer is printed 
    printf("%c \n",*string1);       // prints first charactor     
    printf("%d \n",*string1);       // ascii code of first charactor is printed

    cout << endl;

    cout<< "String enumeration Method_1"<<endl;
    char c;
    int count = 0;
    for(c= *(string1); c != NULL ; count+=sizeof(char)) //dont use "\0"
    {
        cout << c << endl;
        c = *(string1+count);   
    }

    cout << endl;

    cout << "String enumeration Method_2" << endl;
    for(char c_1 : string1) //prints all 200 character
    cout << c_1 << endl; 

    return count;

}

#include <string>

int string_dataStructure()
{
    string s1 = "Hello";
    string s2 = "World";

    string s3 = s1+s2;

    string s3_1 = s1.append(s2);

    int len = s1.length();
    int size_allocated = s1.size();
    int capacity = s1.capacity();

    cout << "length of string:" << len << endl;
    cout << "size of string:" << size_allocated << endl;
    cout << "capacity of string:" << capacity << endl;

    s1.resize(40);
    s1.shrink_to_fit();

    string::iterator st;
    for(st = s1.begin(); st!=s1.end();st++)
    {
        cout << *st << endl;
    }

    return len;
}


int casting()
{
    
    //1.inter-numerical conversion
    //2.number->string,char
    //3.char,string->number
    //4.number->ascii_character
    //5.char->ascii_number

    //1
    int i = 12;
    double d = 34.54;
    cout << "double to int" << (int)d << endl;
    cout << "int to double" << (double)i<< endl;

    //2
    int i_1 = 12;
    string int_to_string = to_string(i_1);
    cout << "int to string" << int_to_string << endl;
    
    //3
    string st1 = "1232";
    int string_to_int = stoi(st1);  //stoll(line)   for long long 
    cout << "string to int" << string_to_int<< endl;

    //4
    int a = 65;
    char int_to_asciichar = (char)a;
    cout << "int to ascii" << int_to_asciichar << endl;

    //5
    char c = 'A';
    int char_to_ascii = (int)c ;
    cout << "character to ascii number" << char_to_ascii << endl;

    char a_1 = (char) a;        //ascii code to charactor
    char b_1 =  (int) 'A';      //charactor to ascii code
    int c_1 = (int) c;          // fully correct
    
    
    printf("Final a --> a_1 : %c \n",a_1);
    printf("Final b --> b_1 : %d \n", b_1);
    printf("Final c --> c_1 : %d \n", c_1);
    

    // checking non std method

    int non_std_1 = 'A';
    printf("%d \n",non_std_1);  //prints ascii

    char non_std_2 = 66;
    printf("%c \n",non_std_2);  //prints "c"

    int non_std_3 = '9' - '0';  
    printf("%d",non_std_3); //prints 9

    return 1;
}


int main()
{
    cout << "Helo" << endl;
    
    //string_intro();
    //string_dataStructure();
    casting();
    return 1;
}