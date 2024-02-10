#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int i = n - 2; i >= 0; i--)
            for(int j = i + 1; j < n; j++)
                if(s[j] == s[i] && (j == i + 1 || dp[i + 1][j - 1]))
                        dp[i][j] = true, res++;          
        
        return res;
    }
};