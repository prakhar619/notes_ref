#include <stdio.h>
/*
Custom data type
    structure
    union
    bit-field
    enumeration
    typedef
*/
typedef float new_name;//compiler just replaces all new_name with float


struct addr         //we can either omitt name (addr) or obj2,ob3 but not both simulatenously
{
    char name[10];
    char street[10];
    char city[10];
    char state[10];
    unsigned long int zip;
}obj2,obj3;  //structure declaration is a statement therefore terminated by ;
// --no-- actual variable has been created till now
int structures()
{
    struct addr obj;        //addr obj allowed in c++ (shorted form)
    obj.zip = 276421;

    struct {
        char* name;
        int x;
    }insideObj;

    struct addr array_of_structures[100];

    //Struct pointers
    struct addr *ptr_struct;
        //why use pointers in struct
        //to pass whole struct stack has to be adjusted //overhead is too much
    
    ptr_struct = &obj;
    printf("Pointers in use:%lu",ptr_struct->zip);

    return 1;
}

/*
struct fred
{
char x;
int y;
float z;
char s[10];
} mike;

func(&mike.x); //passes address of character x //
func2(&mike.y); // passes address of integer y //
func3(&mike.z); // passes address of float z //
func4(mike.s); // passes address of string s //
func(&mike.s[2]); // passes address of character s[2] //

func_str(mike);
    void func_str(struct fred objj)
*/



//UNIONS
    //shared memory for efficient memory usage
    //union variable has size of largest union member
    //use one member at a time
union uni
{
    int i;
    char ch;   //4byte memory for this whole union  // 1byte(char+int shared) 3byte(int only)  union of memory space
};   //no variables actually created

void unions()
{
    union uni obj;
    obj.i = 20;
    obj.ch = 'a';
    printf("Integer union is:%d\n",obj.i);
    printf("Char union is:%c\n",obj.ch);

}

struct bitfield_used
{
    //<type> <name> : <length>
        //type can be int, signed, unsigned or bool(c99 only)
    unsigned wifi: 1;
    unsigned bluetooth: 1;
    unsigned volumn : 7;    //2^7 = 128
    int status;
    float opCode;
}analyser;

void bitfield()
{
    analyser.wifi  = 1;
    analyser.bluetooth = 2; //stored as 0
    analyser.volumn=  328;  //take mod 128  //-1 stored as 127 
    analyser.status = 124;
    analyser.opCode = 9.9;

    printf("Analyser Wifi:%u\n",analyser.wifi);
    printf("Analyser Bluetooth:%u\n",analyser.bluetooth);
    printf("Analyser Volumn:%u\n",analyser.volumn);
    printf("Analyser Status:%d\n",analyser.status);

}

enum coin{
    penny,nickle,dime,quarter,half_dollar,dollar
};

//changing symbol int value ourself
enum change{
    coin_1 = 1, coin_2, coin_5 = 5, coin_10 = 10
};//coin_2 will be coin_1+1;

void enumeration()
{
    enum coin money;
    money = dime;
    if(money==dime) printf("Money is dime\n");
    printf("Enumeration symbol stands for integer value like penny:%d;nickle:%d;dime:%d\n",penny,nickle,dime);
}



int main()
{
    unions();
    bitfield();
    enumeration();
    return 1;
}
