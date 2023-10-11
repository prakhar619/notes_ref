#include "character_frequency.cpp"
#include "Huffman_Code.cpp"
#include <iostream>
#include <string>
using namespace std;

string encoding (string s)
{
	string_int_array s_1 = character_frequency(s);
	code_map m_1 = huffman_encoding(s_1.c,s_1.freq,s_1.len);
	m_1.print();
	string output = "";
	for(int i = 0; i< s.length(); i++)
	{
	    string temp = "";
	    temp+=s[i];
		for(int j = 0; j < m_1.len; j++)
		{
		    if(temp == m_1.s[j])
			{
				output += m_1.code[j];
				break;
			}
		}
	}
	return output;
}	

