#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, max = prices[prices.size() - 1], num;
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            if(prices[i] > max)
                max = prices[i];
            else
            {
                num = max - prices[i];
                if(num > ans)
                    ans = num;
            }
        }
        return ans;
    }
};