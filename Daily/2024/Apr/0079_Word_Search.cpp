#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(board, word, 0, j, i))
                    return true;
            }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int depth, int x, int y)
    {
        if(depth == word.size())
            return true;
        char temp;
        bool result = false;
        if(board[y][x] == word[depth])
        {
            if(depth + 1 == word.size())
                return true;
            temp = board[y][x];
            board[y][x] = ' ';
            if(x - 1 >= 0)
                result = dfs(board, word, depth + 1, x - 1, y);
            if(!result && y - 1 >= 0)
                result = dfs(board, word, depth + 1, x, y - 1);
            if(!result && x + 1 < board[0].size())
                result = dfs(board, word, depth + 1, x + 1, y);
            if(!result && y + 1 < board.size())
                result = dfs(board, word, depth + 1, x, y + 1);
            board[y][x] = temp;
        }
        return result;
    }
};

int main()
{
    vector<vector<char>> board = {{'A','B'}};
    string word = "BA";
    Solution s;
    cout << s.exist(board, word) << endl;
    return 0;
}