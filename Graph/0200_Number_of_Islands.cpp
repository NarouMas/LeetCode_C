#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int r = grid.size(), c = grid[0].size();
       int ans = 0;
       vector<vector<bool>> visit(r, vector<bool>(c, false));

       for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            if(!visit[i][j] && grid[i][j] == '1')
            {
                ans++;
                dfs(grid, visit, i, j);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int r, int c)
    {
        int row, col;
        visit[r][c] = true;
        for(int i = 0; i < 4; i++)
        {
            row = r + dir_r[i]; col = c + dir_c[i];
            if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1' && !visit[row][col])
                dfs(grid, visit, row, col);
        }
    }
private:
    int dir_r[4] = {-1, 1, 0, 0};
    int dir_c[4] = {0, 0, -1, 1};
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};
    vector<vector<char>> grid2 = {{'1','1','0','0','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','1','0','0'},
                                  {'0','0','0','1','1'}};
    cout<<sol.numIslands(grid)<<"\n";  //1
    cout<<sol.numIslands(grid2)<<"\n"; //3
    return 0;
}