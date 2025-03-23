#include <regex>
#include <string>
#include <iostream>
using namespace std;
    /*REGEX BASICS
    [a-z]
        exactly one lowercase char
    [A-Za-z0-9]
        one single uppercase or one lowercase or one digit
    +
        occurrence of pattern one or more than once
        [a-z]+
            (a,aa,abdc,anything) but not this <space>
        (xYz)+
            (xYz,xYzxYz,xYzxYzxYz,)
    * 
        occurrence of pattern zero or more times
        [a-z]*
            (a, ,abcd,anything)
    
    Ex:
        “[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+”
        
    */
void regex_sample()
{
    cout << regex_match("softwareTesting",regex("(soft)(.*)")) << endl;
    cmatch cm;
    cout << regex_match("softwareTesting",cm,regex("(soft)(.*)")) << endl;
    smatch sm;
    cout << regex_match("softwareTesting",sm,regex("(soft)(.*)")) << endl;
}

int main()
{
    regex_sample();
    return 1;
}