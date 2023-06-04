#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


class Solution {
public:
    bool done = false;
    void solveSudoku(vector<vector<char>>& board)
    {
        foo(board, 0, 0);
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char val)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == val)
                return false;
        }
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == val)
                return false;
        }
        int c_row = row - row % 3;
        int c_col = col - col % 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                if(board[i + c_row][j + c_col] == val)
                    return false;
            }
        return true;
    }
    void foo(vector<vector<char>>& board, int row, int col)
    {
        int c_row = row, c_col = col;
        if(row == 9 || done)
        {
            done = true;
            return;
        }      
        if(board[row][col] != '.')
        {
            col += 1;
            if(col == 9)
            {
                col = 0;
                row += 1;
            }
            foo(board, row, col);
        }
        else
        {
            for(int i = 1; i < 10 && !done; i++)
            {
                if(isValid(board, c_row, c_col, i + '0'))
                {
                    board[c_row][c_col] = i + '0';
                    col = c_col + 1;
                    if(col == 9)
                    {
                        col = 0;
                        row = c_row + 1;
                    }
                    foo(board, row, col);
                }
            }
            if(!done)
                board[c_row][c_col]= '.';
        }
        
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'}, 
        {'.','9','8','.','.','.','.','6','.'}, 
        {'8','.','.','.','6','.','.','.','3'}, 
        {'4','.','.','8','.','3','.','.','1'}, 
        {'7','.','.','.','2','.','.','.','6'}, 
        {'.','6','.','.','.','.','2','8','.'}, 
        {'.','.','.','4','1','9','.','.','5'}, 
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    sol.solveSudoku(board);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++) 
            cout << board[i][j] << " ";
        cout << endl;
    }
}