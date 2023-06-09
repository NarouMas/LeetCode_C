#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n)
    {
        vector<int> squareTable;
        vector<int> dp(n + 1, 1000);
        dp[0] = 0;
        for(int i = 1, j = 1; j <= 10000; i++)
        {
            j = i * i; 
            squareTable.push_back(j);
        }
        for(int i = 0; i <= n; i++)
            for(const auto &j : squareTable)
            {
                if(i + j <= n)
                {
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                }
                else
                    break;
            }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout<<sol.numSquares(12)<<"\n"; //3
    cout<<sol.numSquares(13)<<"\n"; //2
    cout<<sol.numSquares(9999)<<"\n";
}