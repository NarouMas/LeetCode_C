#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int sum = 0;
        int ans = nums[0];
        for(int i = 1; i < nums.size() + 1; i++)
        {
            sum = sum + nums[i - 1];
            if(sum > ans)
                ans = sum;
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5,4,-1,7,8};
    vector<int> nums4 = {-1};
    vector<int> nums5 = {-2, 1};
    cout<<sol.maxSubArray(nums)<<"\n"; //6
    cout<<sol.maxSubArray(nums2)<<"\n"; //1
    cout<<sol.maxSubArray(nums3)<<"\n"; //23
    cout<<sol.maxSubArray(nums4)<<"\n"; //-1
    cout<<sol.maxSubArray(nums5)<<"\n"; //1
}