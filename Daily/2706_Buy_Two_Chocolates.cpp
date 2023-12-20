#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n1 = prices[0], n2 = INT32_MAX;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < n1)
                n2 = n1, n1 = prices[i];
            else if(prices[i] < n2)
                n2 = prices[i];
        }
        if(money >= n1 + n2)
            money -= n1 + n2;
        return money;
    }
};