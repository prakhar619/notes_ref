
/*
Statements
    Selections      (if and switch)
    Iterations      (while for do-while)
    Jump            (break,continue,goto, return)
    Label           (case and default)
    Expression      (valid expressions)
    Block           (or compound statements)
*/

/*
Selection
    If
        if(<condiction>)
        {

        }
        else if(<condiction>)
        {

        }
        else 
        {

        }
    
    ? :
    Switch
        switch(<expression>)        //expression must evaluate to integer or char
        {
            case <constant1>

            break;
            case <constant2>

            break;
            default

        }
*/

/*
Iterations
    For Loop
        for(int y = 10; y <= n; y++)    //declaration allowed only in c99 and c++
        {

        }
        for(;;)     //infinite loop
    
    While Loop
        while(<condition>)
        {

        }

    Do While Loop
        do
        {

        }while(<condition>);
*/

/*
Jump 
    return      //non void function must return value in c99 and c++; c89 no need as garbage value is returneda automatically
    goto <label>
    break;      //inner most loop break
    continue;
    exit(<int return code>);     //end program //<stdlib.h>  //return code(0 usually) is returned to caller process usually OS//
    
*/

/*
Block or compound statement
*/
#include <stdio.h>
int main()
{
    int x = 10;
    {
        int y = 20;
        printf("%d,%d",y,x);
    }
    printf("%d",x);
    return 1;
}