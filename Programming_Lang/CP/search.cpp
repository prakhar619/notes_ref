// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
bool directional(int row,int col, vector<vector<char>> board, string rm_word)//index char is not present in rm_word
    {
        // 1st example: 0,0 index; rm_word: BCCED
        if(rm_word == "")
        return true;
        cout << "WORD:" << rm_word << endl;
        //boundary
        int left_max = 0;
        int right_max = board[0].size();
        int top_max = 0;
        int bottom_max = board.size();

        bool l = false;bool r = false;bool b = false; bool t = false;
        
        //left check
        if(col > left_max){ if(board[row][col-1] == rm_word[0]){
        l = directional(row,col-1,board,rm_word.substr(1));cout << "Found.1 x:" << rm_word[0] << " Index:" << row << "," << col-1<< endl;}}
        else if(col < right_max){if(board[row][col+1] == rm_word[0]){
        r = directional(row,col+1,board,rm_word.substr(1));cout << "Found.2 x:" << rm_word[0] << " Index:" << row << "," << col+1<< endl;}}
        else if(row < bottom_max){if(board[row+1][col] == rm_word[0]){
        b=  directional(row+1,col,board,rm_word.substr(1));cout << "Found.3 x:" << rm_word[0] << " Index:" << row+1 << "," << col<< endl;}}
        else if(col > top_max){if(board[row-1][col] == rm_word[0]){
        t = directional(row-1,col,board,rm_word.substr(1));cout << "Found.4 x:" << rm_word[0] << " Index:" << row-1 << "," << col<< endl;}}

        return t or b or l or r;
    }
bool exist(vector<vector<char>>& board, string word) {
        bool k = false;
        int row = 0;
        for(vector<char> vx : board)
        {
            int col = 0;
        for( char x : vx)
        {
            if(x == word[0])
            {
                cout << "Found.0 x:" << x << " Index:" << row << "," << col<< endl;
               bool m = directional(row,col,board,word.substr(1)); 
               k = k or m;
            }
            col++;
        }
        row++;
        }
        return k;
    }
    
int main() {
    // Write C++ code here
   vector<vector<char>> te {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
   string c= "ABCCED";
    cout << exist(te,c);
    return 0;
}