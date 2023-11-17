#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j)
        {
            if(nums[i] + nums[j] > res)
                res = nums[i] + nums[j];
            i++, j--;
        }
        return res;
    }
};