#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<bool> used(nums.size(), false);
        if(sum % k != 0)
            return false;
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, sum/k, 0, 0, k, 0);
    }
    bool dfs(vector<int> nums, int target, int index, int cur, int k, int used)
    {
        int sum, new_used;
        if(k == 0)
            return true;
        if(cur == target)
            return dfs(nums, target, 0, 0, k - 1, used);
        for(int i = index; i < nums.size(); i++)
        {
            if(used & (1 << i))
                continue;
            sum = cur + nums[i];
            new_used = used | (1 << i);
            if(sum <= target)
            {
                if(dfs(nums, target, i + 1, sum, k, new_used))
                    return true;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++ ;
            if (!cur || cur + nums[i] == target)
                return false;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5309,7138,779,8949,8568,2250,1794,6539,4948,7189,4270,9866,5867,2112,9176,3162};
    vector<int> nums2 = {2,6,16,13,3,4,1,1,2,12};
    vector<int> nums3 = {4,1,5,8,7,2,5,4,10,2,2,6,5,4,7};
    vector<int> nums4 = {2,9,4,7,3,2,10,5,3,6,6,2,7,5,2,4};
    cout<<sol.canPartitionKSubsets(nums, 2)<<"\n"; //0
    cout<<sol.canPartitionKSubsets(nums2, 3)<<"\n"; //1
    cout<<sol.canPartitionKSubsets(nums3, 8)<<"\n"; //0
    cout<<sol.canPartitionKSubsets(nums4, 7)<<"\n"; //0
}