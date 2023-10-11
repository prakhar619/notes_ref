//Huffman_code
// character_array (string array) , frequency_of_character array (int array) , len ----------huffman_encoding----------> code_map ( character_array(string array), code_array (string array) )

// Edit code_map if no of types of character exceed 50

#include "Node_priortyQueue.cpp"
#include <string>

class code_map
{
    public:
	string s[50];
	string code[50];
	int len;
	
	code_map()
	{
		len = 0;
	}
	
	void push_back(string s_, string _code)
	{
		s[len]=  s_;
		code[len] = _code;
		len++;
	}
	void print()
	{
	       for(int i = 0; i < len ; i++)
	       cout << s[i] << ":" << code[i] << endl;
	}
	
};


void _preOrderTrav(node* NNode,string s,code_map &map)
	{
	   if(NNode == NULL)
	   {    
	       return;
	   }
	   if(NNode->leaf == 1)
	   {
	   	map.push_back(NNode->c,s);
	   }
	    _preOrderTrav(NNode->left,s+"0",map);
	    _preOrderTrav(NNode->right,s+"1",map);
	}
// is not optimised for frequency = 0
code_map huffman_encoding(string c[],int frequency[],int len)
{
    asc_priortyQ_heap obj(c,frequency,len);
    while(obj.len > 1)
    {
        node* node1 = obj.peek();
        obj.pop();
        node* node2 = obj.peek();
        obj.pop();
        node* NewNode = new node(node2->freq+node1->freq,node1,node2);
        obj.insert(NewNode);
    }
    node* root = obj.peek();
    code_map map;
    _preOrderTrav(root,"",map);
    return map;
}

