#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> seen(mat.size(), vector<bool>(mat[0].size(), false));
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> qu;
        int step = 0, row, col;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                if(mat[i][j] == 0)
                {
                    seen[i][j] = true;
                    qu.push({i, j});
                }
            }
        }
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
                auto pair = qu.front();
                qu.pop();
                ans[pair.first][pair.second] = step;
                for(int i = 0; i < 4; i++)
                {
                    row = dir[i][0] + pair.first;
                    col = dir[i][1] + pair.second;
                    if(row >= 0 && row < mat.size() && col >= 0 && col < mat[0].size() && !seen[row][col])
                    {
                        qu.push({row, col});
                        seen[row][col] = true;
                    }
                }
            }
            step++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    //vector<vector<int>> mat = {{0, 0, 0},{0, 1, 0},{1, 1, 1}};
    vector<vector<int>> mat = {{1,1,0,0,1,0,0,1,1,0},
                                {1,0,0,1,0,1,1,1,1,1},
                                {1,1,1,0,0,1,1,1,1,0},
                                {0,1,1,1,0,1,1,1,1,1},
                                {0,0,1,1,1,1,1,1,1,0},
                                {1,1,1,1,1,1,0,1,1,1},
                                {0,1,1,1,1,1,1,0,0,1},
                                {1,1,1,1,1,0,0,1,1,1},
                                {0,1,0,1,1,0,1,1,1,1},
                                {1,1,1,0,1,0,1,1,1,1}};
    vector<vector<int>> ans = sol.updateMatrix(mat);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}