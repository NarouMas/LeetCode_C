#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                dp[i][j] = (matrix[i][j] == '0') ? 0 : (j == 0 ? 1 : dp[i][j - 1] + 1);

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                int len = INT_MAX;
                for(int k = i; k < matrix.size(); k++)
                {
                    if(matrix[k][j] == 0)
                        break;
                    len = min(len, dp[k][j]);
                    ans = max(ans, len * (k - i + 1));
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    cout<<sol.maximalRectangle(matrix)<<"\n"; // 6
}