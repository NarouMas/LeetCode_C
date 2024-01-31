#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(2, 0);
        bool flag = false;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
                res[0] = nums[i];
            else if(nums[i] != nums[i - 1] + 1)
                res[1] = nums[i] - 1, flag = true;
        }
        if(!flag)
            res[1] = (nums[0] == 1) ? nums.size(): 1;
        
        return res;
    }
};