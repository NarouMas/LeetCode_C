#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0, n = piles.size() / 3;
        sort(piles.begin(), piles.end());
        for(int i = piles.size() - 2, j = 0; j < n; i -= 2, j++)
            res += piles[i];
        return res;
    }
};