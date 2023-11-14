#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int count0 = 0;
        ans[0] = nums[1];
        for(int i = 2; i < nums.size(); i++)
        {
            ans[0] *= nums[i];
            if(nums[i] == 0)
                count0++;
        }
        for(int i = 1; i < nums.size(); i++)
        {
            if(count0 > 1)
                ans[i] = 0;
            else if(nums[i] != 0)
                ans[i] = ans[0] / nums[i] * nums[0];
            else
            {
                for(int j = 0; j < nums.size(); j++)
                {
                    if(i != j)
                        ans[i] *= nums[j];
                }
            }

        }
        return ans;
    }
};