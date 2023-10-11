#include <iostream>
#include <vector>
using namespace std;
bool directional(int row,int col, vector<vector<char>> board, string rm_word)//index char is not present in rm_word
    {
        // 1st example: 0,0 index; rm_word: BCCED
        if(rm_word == "")
        {   
            cout << "Word ended. Returning."<<endl;
            return true;
        }
        cout << "Current WORD:" << rm_word << endl;
        //boundary
        int col_min = 0;
        int col_max = board[0].size()-1;
        int row_min = 0;
        int row_max = board.size()-1;
        bool l = false;bool r = false;bool b = false; bool t = false;
        
        //left check
        if(col > col_min)
        { 
            if(board[row][col-1] == rm_word[0])
            {
                cout << "Found:" << rm_word[0] << " Index:" << row << "," << col-1<< endl;
                board[row][col-1] = ' ';
                l = directional(row,col-1,board,rm_word.substr(1));
                                if(l == true)
                return true;
            }
        }
        if(col < col_max)
        {
            if(board[row][col+1] == rm_word[0])
            {
                cout << "Found:" << rm_word[0] << " Index:" << row << "," << col+1<< endl;
                board[row][col+1] = ' ';
                r = directional(row,col+1,board,rm_word.substr(1));
                if(r == true)
                return true;
            }
        }
        if(row < row_max)
        {
            if(board[row+1][col] == rm_word[0])
            {
                cout << "Found:" << rm_word[0] << " Index:" << row+1 << "," << col<< endl;
                board[row+1][col] = ' ';
                b =  directional(row+1,col,board,rm_word.substr(1));
                                if(b == true)
                return true;
            }
        }
        if(row > row_min)
        {
            if(board[row-1][col] == rm_word[0])
            {
            cout << "Found.4 x:" << rm_word[0] << " Index:" << row-1 << "," << col<< endl;
            board[row-1][col] = ' ';
                t = directional(row-1,col,board,rm_word.substr(1));
                                if( t== true)
                return true;
            }
        }

        return t ||  b || l || r;
    }
bool exist(vector<vector<char>>& board, string word) {

        int row = 0;
        for(vector<char> vx : board)
        {
            int col = 0;
        for( char x : vx)
        {
            if(x == word[0])
            {
                cout << "Found:" << x << " Index:" << row << "," << col<< endl;
                board[row][col] = ' ';
                bool m = directional(row,col,board,word.substr(1)); 
                if(m == true)
                return true;
            }
            col++;
        }
        row++;
        }
        return false;
    }

    
int main() {
    // Write C++ code here
   vector<vector<char>> te {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
   string c= "ABCB";
    cout << exist(te,c);
    return 0;
}

