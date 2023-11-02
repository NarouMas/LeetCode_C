#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(target - nums[i]) == map.end())
                map[nums[i]] = i;
            else
            {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    cout<<"["<<ans[0]<<", "<<ans[1]<<"]"<<endl;
    return 0;
}