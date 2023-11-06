#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, num = prices[prices.size() - 1];
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            if(prices[i] > num)
                num = prices[i];
            else
                ans += num-prices[i], num=prices[i];
        }
        return ans;
    }
};