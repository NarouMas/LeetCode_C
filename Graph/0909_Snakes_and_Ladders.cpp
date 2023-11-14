#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int step = -1, width = board.size(), next, goal = width * width - 1;
        queue<int> qu;
        qu.push(0);
        while(!qu.empty())
        {
            step++;
            for(int size = qu.size(); size > 0; size--)
            {
                int curr = qu.front();
                qu.pop();
                if(curr == goal)
                    return step;
                for(int i = 1; i <= 6; i++)
                {
                    next = min(curr + i, goal);
                    int row = width - next / width - 1;
                    int col = ((row - width + 1) % 2 == 0) ? next % width : width - (next % width) - 1;

                    if(board[row][col] != -2)
                    {
                        if(board[row][col] != -1)
                        {
                            qu.push(board[row][col] - 1);
                            board[row][col] = -2;
                        }
                        else/* if(i == 6)*/
                        {
                            qu.push(next);
                            board[row][col] = -2;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> board1 = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    vector<vector<int>> board2 ={{-1,-1},{-1,3}};
    vector<vector<int>> board3 ={{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}};
    vector<vector<int>> board4 = {{-1,10,-1,15,-1},{-1,-1,18,2,20},{-1,-1,12,-1,-1},{2,4,11,18,8},{-1,-1,-1,-1,-1}};
    Solution sol;

    cout<<sol.snakesAndLadders(board1)<<"\n";  //4
    cout<<sol.snakesAndLadders(board2)<<"\n";  //1
    cout<<sol.snakesAndLadders(board3)<<"\n";  //2
    cout<<sol.snakesAndLadders(board4)<<"\n";  //3
}