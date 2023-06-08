#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        vector<int> memo(nums.size() + 1, -1);
        memo[0] = 0, memo[1] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            memo[i + 1] = max(memo[i - 1] + nums[i], memo[i]);
        return memo[nums.size()];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,3,1}; //4
    vector<int> nums2 = {2,7,9,3,1}; //12
    cout<<sol.rob(nums1)<<"\n";
    cout<<sol.rob(nums2)<<"\n";
}