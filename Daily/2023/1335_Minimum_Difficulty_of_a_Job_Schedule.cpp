#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(), maxD;
        if(n < d)
            return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for(int day = 1; day <= d; ++day)
        {
            for(int i = 0; i <= n - day; ++i)
            {
                maxD = 0, dp[i] = 1e9;
                for(int j = i; j <= n - day; ++j)
                {
                    maxD = max(maxD, jobDifficulty[j]);
                    dp[i] = min(dp[i], maxD + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};