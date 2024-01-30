#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove <= 0)
            return 0;
        int MOD = 1e9 + 7, result = 0;
        vector<vector<int>> count(m, vector<int>(n, 0)), dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        count[startRow][startColumn] = 1;
        for(int step = 0; step < maxMove; step++)
        {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for(int r = 0; r < m; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    for(auto d: dirs)
                    {
                        int nr = r + d[0];
                        int nc = c + d[1];
                        if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                            result = (result + count[r][c]) % MOD;
                        else
                            temp[nr][nc] = (temp[nr][nc] + count[r][c]) % MOD;
                    }
                }
            }
            count = temp;
        }
        return result;
    }
};