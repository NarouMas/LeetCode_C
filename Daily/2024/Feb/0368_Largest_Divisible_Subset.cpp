#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), max = 0, index = -1;
        vector<int> count(n), pre(n), res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            count[i] = 1, pre[i] = -1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0 && count[j] + 1 > count[i])
                    count[i] = count[j] + 1, pre[i] = j;
            }
            if(count[i] > max)
                max = count[i], index = i;
        }
        while(index != -1)
        {
            res.push_back(nums[index]);
            index = pre[index];
        }
        return res;
    }
};