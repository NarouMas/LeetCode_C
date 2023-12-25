#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int count = 0, ans = 1;
        vector<int> dp(45, 1);
        dp[1] = 2;
        for(int i = 2; i < dp.size(); i++)
           dp[i] = dp[i - 1] + dp[i - 2];
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '3')
            {
                if(i < s.size() - 1 && s[i + 1] == '0')
                    return 0;
                ans *= dp[count], count = 0;
                continue;
            }
            if(i < s.size() - 1 && s[i + 1] > '0')
            {
                if(s[i] == '2' && s[i + 1] <= '6' && !(i + 2 < s.size() && s[i + 2] == '0' ))
                    count++;
                else if(s[i] == '1' && !(i + 2 < s.size() && s[i + 2] == '0' ))
                    count++;
            }
            if(s[i] == '0')
            {
                if(i == 0 || s[i - 1] > '2' || s[i - 1] == '0')
                    return 0;
                ans *= dp[count], count = 0;
            }
        }
        ans *= dp[count], count = 0;
        return ans; 
    }
};