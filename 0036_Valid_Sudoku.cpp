#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool nine_row[10], nine_col[10];
        int row, col;
        for(int i = 0; i < 9; i++)
        {
            memset(nine_row, 0, 10);
            memset(nine_col, 0, 10);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(nine_row[board[i][j] - '0'])
                        return false;
                    nine_row[board[i][j] - '0'] = true;
                }
                if(board[j][i] != '.')
                {
                    if(nine_col[board[j][i] - '0'])
                        return false;
                    nine_col[board[j][i] - '0'] = true;
                }
            }
        }
        for(int i = 0; i < 9; i++)
        {
            memset(nine_row, 0, 10);
            for(int j = 0; j < 9; j++)
            {
                row = j / 3 + i / 3 * 3;
                col = j % 3 + i % 3 * 3;
                if(board[row][col] == '.')
                    continue;
                else if(nine_row[board[row][col] - '0'])
                    return false;
                
                nine_row[board[row][col] - '0'] = true;
            }
        }
        return true;
    }
};