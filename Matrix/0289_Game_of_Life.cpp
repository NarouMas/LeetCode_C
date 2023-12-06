#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> count(board.size(), vector<int>(board[0].size(), 0));
        int dx[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
        int dy[8] = {-1, -1, -1, 0, 1, 1,  1,  0};
        int x, y;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                for(int k = 0; k < 8; k++)
                {
                    x = j + dx[k], y = i + dy[k];
                    if(x >= 0 && x < board[0].size() && y >= 0 && y < board.size() && board[y][x] == 1)
                        count[i][j]++;
                }
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 1 && (count[i][j] < 2 || count[i][j] > 3))
                    board[i][j] = 0;
                else if(board[i][j] == 0 && count[i][j] == 3)
                    board[i][j] = 1;
            }
    }
};