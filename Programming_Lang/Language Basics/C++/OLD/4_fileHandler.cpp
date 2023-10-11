#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream fobj;
    fobj.open("Stan_Lyrics.txt",ios::in | ios::out | ios::app);
    //ios::in | ios :: out     default  overwrites the content of file
    //ios :: in | ios :: out | ios :: app       appends
    //ios :: in | ios :: out | ios :: trunc     deletes all content before opening


    if(fobj.is_open())
    {
        string xline;
        while(getline(fobj,xline))
        {
            cout<< xline << endl;
        }
    }

    if(fobj.is_open())
    {
        fobj<<"The End \n";
    }

    fobj.close();
}