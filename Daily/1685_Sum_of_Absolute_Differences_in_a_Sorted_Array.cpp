#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res(nums.size());
        int start = 0, end = 0;
        for(int i = 0; i < nums.size(); i++)
            start += nums[i];
        for(int i = 0; i < nums.size(); i++)
        {
            start -= nums[i];
            res[i] = (nums[i] * (i + 1) + start) - (nums[i] * (nums.size() - i) + end);
            end += nums[i];
        }
        return res;
    }
};