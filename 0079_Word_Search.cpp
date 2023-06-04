#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

        // if word has too many duplicate chars at the beginning reverse the word
        // this allows to early shortcut before going too deep in the stack.
        // cuts total runtime from 1second to <10ms 
        char first = word[0];
        int count = 1, idx = 1;
        while(first == word[count++]);
        if (count>word.size()/2)
            reverse(word.begin(), word.end());
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                visit[i][j] = true;
                if(foo(board, visit, word, 0, i, j))
                    return true;
                visit[i][j] = false;
            }
        return false;
    }
    bool foo(vector<vector<char>>& board, vector<vector<bool>>& visit, string word, int depth, int row, int col)
    {
        if(depth >= word.size() || word[depth] != board[row][col])
            return false;
        if(depth == word.size() - 1)
            return true;
        if(col - 1 >= 0 && !visit[row][col - 1])
        {
            visit[row][col - 1] = true;
            if(foo(board, visit, word, depth + 1, row, col - 1))
                return true;
            visit[row][col - 1] = false;
        }
        if(col + 1 < board[0].size() && !visit[row][col + 1])
        {
            visit[row][col + 1] = true;
            if(foo(board, visit, word, depth + 1, row, col + 1))
                return true;
            visit[row][col + 1] = false;
        }
        if(row - 1 >= 0 && !visit[row - 1][col])
        {
            visit[row - 1][col] = true;
            if(foo(board, visit, word, depth + 1, row - 1, col))
                return true;
            visit[row - 1][col] = false;
        }
        if(row + 1 < board.size() && !visit[row + 1][col])
        {
            visit[row + 1][col] = true;
            if(foo(board, visit, word, depth + 1, row + 1, col))
                return true;
            visit[row + 1][col] = false;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'A', 'A','C','S'},{'S','F','C','S'},{'C','D','E','E'}};
    string word = "AAA";
    cout << sol.exist(board, word) << endl;
}