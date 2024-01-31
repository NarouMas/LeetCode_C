#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1}, MOD = 1e9 + 7;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <=k; j++)
                for(int x = 0; x <= min(j, i - 1); x++)
                    if(j - x >= 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            
        return dp[n][k];
    }
};